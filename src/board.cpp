/**
 * @brief Implementation of the board class.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#include <random>

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
Board::Board(const uint32_t rows, const uint32_t cols) {
	m_rows = rows;
	m_cols = cols;
	
	// Re-allocate the memory for the board and set all cells to alive.
	m_board.resize(rows);
	for (uint32_t i = 0; i < rows; i++) {
		m_board[i].resize(cols);
	}
}

/**
 * @returns true if the cell in row and col is alive. 
 * @param[in] row Row where the cell of interest is located.
 * @param[in] col Column where the cell of interest is located.
 */
bool Board::cell(const uint32_t row, const uint32_t col) const {
	return m_board[row][col].isAlive();
}

/**
 * @brief Modifies the state of a cell to the one provided in the alive parameter.  
 * @param[in] row Row where the cell is located.
 * @param[in] col Column where the cell is located.
 * @param[in] alive New state of the cell.
 */
void Board::cell(const uint32_t row, const uint32_t col, const bool alive) {
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
void Board::reset(const uint32_t rows, const uint32_t cols) {
	Board(rows, cols);
}

/**
 * @brief Fills the board with random cells.
 */
void Board::randomise() {
	std::default_random_engine generator;
	std::bernoulli_distribution distribution(0.5);
	
	for (uint32_t i = 0; i < m_rows; i++) {
		for (uint32_t j = 0; j < m_cols; j++) {
			if (distribution(generator)) 
				m_board[i][j].revive();
			else
				m_board[i][j].die();
		}
	}
}

/**
 * @brief Iterate the state of the board according to Conway's rules.
 */
void Board::evolve() {
	std::vector<std::vector<Cell> > newBoard;
	
	// Re-allocate the memory for the board and set all cells to alive.
	newBoard.resize(rows);
	for (uint32_t i = 0; i < rows; i++) {
		newBoard.resize(cols);
	}
	
	// Create the new board
	for (uint32_t i = 0; i < m_rows; i++) {
		for (uint32_t j = 0; j < m_cols; j++) {
			uint32_t nAlive = neighboursAlive(i, j);
			if (m_board[i][j].isAlive()) { // If cell is alive
				if (nAlive == 2 || nAlive == 3)
					newBoard[i][j].revive();
				else
					newBoard[i][j].die();
			}
			else {                         // If cell is not alive
				if (nAlive == 3)
					newBoard[i][j].revive();
				else
					newBoard[i][j].die();
			}
		}
	}
	
	// Update current board
	m_board = newBoard; 
}

/**
 * @brief Stream extraction operator. 
 * @param[in] out Destination stream where the board will be plotted. 
 * @param[in] b   Board to be printed.
 */
std::ostream& operator<<(std::ostream& out, const Board &b){
	out << std::endl;
	for (uint32_t i = 0; i < m_rows; i++) {
		for (uint32_t j = 0; j < m_cols; j++) {
			if (m_board[i][j].isAlive()) 
				out << "O ";
			else
				out << "X ";
		}	
		out << std::endl;
	}	
	out << std::endl;
	return out;
}

/**
 * @brief Returns the number of alive neighbours. An 8-neighbourhood is
 *        used. This method considers that the board is a toroid. That is, all 
 *        the cells have exactly 8 neighbours, including the ones located in
 *        the edges.
 * @param[in] row Row of the cell whose number of neighbours we want to check.
 * @param[in] col Column of the cell whose number of neighbours we want to check.
 */
uint32_t Board::neighboursAlive(const uint32_t row, const uint32_t col) const {
	const uint32_t NEIGHBOURHOOD = 8;

	uint32_t count = 0;
	uint32_t correctI, correctJ;

	for (uint32_t i = row - 1; i < NEIGHBOURHOOD / 2 - 1; i++) {
		for (uint32_t j = col - 1; j < NEIGHBOURHOOD / 2 - 1; j++) {
			if (i == row && j == col) // The neighbourhood of a cell does not include the cell
				continue;
			
			// Correcting indeces to avoid being out of boundaries
			correctI = i < 0 ? m_rows - 1 : i;
			correctI = correctI > m_rows - 1 ? 0 : correctI;  
			correctJ = j < 0 ? m_cols - 1 : j;
			correctJ = correctJ > m_cols - 1 ? 0 : correctJ;

			if (m_board[correctI][correctJ].isAlive())
				count++;
		}	
	}		

	return count;
}
