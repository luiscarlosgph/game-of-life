/**
 * @class Board represents a Game of Life's board. 
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <list>

// My includes
#include "cell.h"

class Board {
public:
	Board();
	Board(const uint32_t rows, const uint32_t cols);

	// Retrieve or change the state of a cell
	Cell cell(const uint32_t row, const uint32_t col) const;
	void cell(const uint32_t row, const uint32_t col, const bool alive);
	
	// Reset the size of the board and re-allocate memory
	void reset(const uint32_t rows, const uint32_t cols);

	// Fill the board with random alive or dead cells
	void randomise();

	// Iterate based on Conway's algorithm
	void evolve();

	// Operators
	friend std::ostream& operator<<(std::ostream &out, const Board &b);

private:
	std::list<Cell> getNeighbours(const uint32_t row, const uint32_t col) const;
	uint32_t aliveNeighbours(const uint32_t row, const uint32_t col) const; 

	uint32_t m_rows;
	uint32_t m_cols;
	std::vector<std::vector<Cell> > m_board;
};

#endif  // BOARD_H_
