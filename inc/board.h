/**
 * @class Board represents a Game of Life's board. 
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

// My includes
#include "cell.h"

class Board {
public:
	Board();
	Board(const size_t rows, const size_t cols);

	// Retrieve or change the state of a cell
	bool cell(const size_t row, const size_t col) const;
	void cell(const size_t row, const size_t col, const bool alive);
	
	// Reset the size of the board and re-allocate memory
	void reset(const size_t rows, const size_t cols);

	// Iterate based on Conway's algorithm
	void evolve();

private:
	size_t m_rows;
	size_t m_cols;
	std::vector<std::vector<Cell> > m_board;
}

#endif  // BOARD_H_
