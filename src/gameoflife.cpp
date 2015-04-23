/**
 * @brief Implementation of the class GameOfLife.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#include <fstream>

// My includes
#include "gameoflife.h"
#include "exception.h"

GameOfLife::GameOfLife() {

}

/**
 * @brief Reads the board configuration from file and pushes it into the history stack.
 * @param[in] path Path to the file with the initial configuration of the board.
 */
void GameOfLife::readConfig(const std::string &path) {
	Board b;
	std::ifstream inFile;

	// Activate exceptions
	inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	inFile.open(path);
	inFile >> b;
	m_boardHistory.push_back(b);
}

/**
 * @brief Same as readConfig but instead of reading the configuration from a file the
 *        user specifies the size of a square board and it is randomly initialised.
 * @param[in] boardSize Size of the board in rows (or columns, it will be a square).
 */
void GameOfLife::randInit(const uint32_t boardSize) {
 	Board b(boardSize, boardSize);
	b.randomise();	
	m_boardHistory.push_back(b);
 }

/**
 * @brief Runs an iteration of the Conway's algorithm.
 */
void GameOfLife::iterate() {
	Board newBoard = m_boardHistory.back();

	// Create the new board
	#pragma omp parallel for
	for (uint32_t i = 0; i < newBoard.rows(); i++) {
		for (uint32_t j = 0; j < newBoard.columns(); j++) {
			uint32_t nAlive = m_boardHistory.back().aliveNeighbours(i, j);
			if (m_boardHistory.back()[i][j].isAlive()) { // If cell is alive
				if (nAlive != 2 && nAlive != 3)
					newBoard[i][j].die();
			}
			else if (nAlive == 3) {                      // If cell is not alive
					newBoard[i][j].revive();
			}
		}
	}

	m_boardHistory.push_back(newBoard);
}

/**
 * @brief Writes the state of the simulation for all the steps.
 * @param[in] path Path of the output file.
 */
void GameOfLife::writeOutputFile(const std::string &path) {
	std::ofstream outFile;

	// Activate exceptions
	outFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	// Check if file already exists
	if (std::ifstream(path))
		throw OutputFileAlreadyExists();
	
	outFile.open(path); 
	for (std::list<Board>::iterator it = m_boardHistory.begin(); it != m_boardHistory.end(); it++) {
		outFile << *it << std::endl;	
	}
}
