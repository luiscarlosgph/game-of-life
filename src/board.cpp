/**
 * @brief Implementation of the board class.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

// My includes
#include "board.h"

/**
 * @brief Default constructor. It initialises the size of the board to zero.
 * The reset method has to be called if this constructor is used (unless)
 * you want a zero-sized board which seems pointless.
 */
Board::Board() : m_rows(0), m_cols(0) {

}

/**
 * @brief Initialises a board with a certain size and allocates memory fot it.
 * @param[in] rows Desired number of rows.
 * @param[in] cols Desired number of columns.
 */
Board::Board(const size_t rows, const size_t cols) {
	m_rows = rows;
	m_cols = cols;
	
	// Re-allocate the memory for the board and set all cells to alive.
	m_board.resize(rows);
	for (int i = 0; i < rows; i++) {
		m_board[i].resize(cols);
	}
}

/**
 * @returns true if the cell in row and col is alive. 
 * @param[in] row Row where the cell of interest is located.
 * @param[in] col Column where the cell of interest is located.
 */
bool Board::cell(const size_t row, const size_t col) const {
	return m_board[row][col].isAlive();
}

/**
 * @brief Modifies the state of a cell to the one provided in the alive parameter.  
 * @param[in] row Row where the cell is located.
 * @param[in] col Column where the cell is located.
 * @param[in] alive New state of the cell.
 */
void Board::cell(const size_t row, const size_t col, const bool alive) {
	if (alive) 
		m_board[row][col].revive();
	else
		m_board[row][col].die();
}

/**
 * Resizes the board (current state is discarded) and re-allocates memory.
 * @param[in] rows Desired number of rows.
 * @param[in] cols Desired number of columns.
 */
void Board::reset(const size_t rows, const size_t cols) {
	Board(rows, cols);
}

/**
 * TODO
 */
void Board::evolve() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if (m_board[i][j].isAlive()) { // If cell is alive
			
			}
			else {                         // If cell is not alive
			
			}
		}
	}
}
