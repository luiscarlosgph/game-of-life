/**
 * @brief Implementation of the class GameOfLife.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#include <fstream>
#include <regex>
#include <iostream>

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
	const std::regex UINT_REGEX("([1-9]\\d*)");
	Board b;
	std::ifstream inFile(path);
	std::string line;
	uint32_t rows, cols;
	std::smatch sm;

	// Activate IO exceptions
	inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	// Sanity check - file is correctly opened
	if (!inFile.is_open())
		throw std::runtime_error("ERROR! Unable to open input file -> " + path);

	// Read number of rows
	if (!getline(inFile, line))
		throw CouldNotReadNumberOfRows(); 
	if (!std::regex_match(line, sm, UINT_REGEX)) {
		std::cout << line << "@@" << std::endl;
		throw IncorrectSyntaxForNumberOfRows();
	}
	rows = (uint32_t)std::stoul(line); 

	// Read number of columns
	if (!getline(inFile, line)) 
		throw CouldNotReadNumberOfColumns(); 		
	if (!std::regex_match(line, sm, UINT_REGEX)) 
		throw IncorrectSyntaxForNumberOfColumns();
	cols = (uint32_t)std::stoul(line);

	// Reset the board so that it allocates space for the required rows and columns
	b.reset(rows, cols);

	// Read the initial state of the board, that is if the state of all cells
	inFile >> b;

	// Clear the game history and push the board as a the initial board state
	m_boardHistory.clear();
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
		throw std::runtime_error("ERROR! Output file " + path + " already exists.");
	
	outFile.open(path); 
	for (std::list<Board>::iterator it = m_boardHistory.begin(); it != m_boardHistory.end(); it++) {
		outFile << *it << std::endl;	
	}
}
