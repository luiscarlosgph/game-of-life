/**
 * @brief Implementation of the class GameOfLife.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#include <fstream>

// My includes
#include "gameoflife.h"

GameOfLife::GameOfLife() {

}

/**
 * @brief Reads the board configuration from file and pushes it into the history stack.
 * @param[in] path Path to the file with the initial configuration of the board.
 */
void GameOfLife::readConfig(const std::string &path) {
	std::ifstream inFile;
	Board b;
	
	inFile.open(path); // TODO: exception if cannot open file
	inFile >> b;
	inFile.close();
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
	Board b = m_boardHistory.back();
	b.evolve();
	m_boardHistory.push_back(b);
}

/**
 * @brief Writes the state of the simulation for all the steps.
 * @param[in] path Path of the output file.
 */
void GameOfLife::writeOutputFile(const std::string &path) {
	std::ofstream outFile;
	
	outFile.open(path); // TODO: exception if cannot open file() or if it already exists!
	for (std::list<Board>::iterator it = m_boardHistory.begin(); it != m_boardHistory.end(); it++) {
		outFile << *it << std::endl;	
	}
	outFile.close();
}
