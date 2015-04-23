/**
 * @brief Implementation of the board class.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <omp.h>

// My includes
#include "board.h"
#include "exception.h"

/**
 * @brief Default constructor of the nested (i.e. internal use) class BoardProxy.
 *        This class is used to allow the user access the cells of the board with
 *        the syntax Board[i][j].
 * @param[in] row is a reference to the row of the board that the user selected with
 *            the first square brackets. The reference will be saved internally as a 
 *            pointer to the row so that then the user can access to a specific cell 
 *            in a specific column.
 */
Board::BoardProxy::BoardProxy(std::vector<Cell> &row) : m_row(&row) {
} 

/**
 * @brief Access to a cell in a specific column of the row provided to this proxy in the
 *        constructor.
 * @param[in] col is the column of the cell that the user wants to retrieve.
 * @returns a reference to the particular cell. This means that the user will be able to 
 *          modify it.
 */
Cell& Board::BoardProxy::operator[](const uint32_t col) {
	return const_cast<Cell&>(static_cast<const Board::BoardProxy*>(this)->operator[](col));
}

/**
 * @brief Access to a constant (i.e. returns constant reference) cell of the board.
 * @param[in] col is the column where the cell that the user wants to retrieve is located.
 * @returns a constant reference to the particular cell. The user will be able to create 
 *          a constant reference pointing to this cell in order to avoid it being modified
 *          after it has been retrieved.
 */
const Cell& Board::BoardProxy::operator[](const uint32_t col) const {
	if (col > m_row->size() - 1)
		throw IndexOutOfBounds();
	return m_row->operator[](col);
}

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
	reset(rows, cols);
}

/**
 * @brief Copy constructor.
 * @param[in] other Source Board for the copy.
 */
Board::Board(const Board &other) : m_rows(other.m_rows), m_cols(other.m_cols) {
	m_board = other.m_board;
}

/**
 * @brief Move constructor.
 * @param[in] other Object that will be moved to this one.
 */
Board::Board(Board &&other) {
	swap(*this, other);
}

/**
 * @brief Retrieves a cell of the board. You will be able to modify the cell
 *        after fetching it and the changes will be reflected in the board.
 * @param[in] row where the cell to be retrieved is located.
 * @param[in] col where the cell to be retrieved is located. 
 * @returns a reference to the cell of the board indicated in the parameters.
 */
Cell& Board::cell(const uint32_t row, const uint32_t col) {
	if (row > m_rows - 1)
		throw IndexOutOfBounds();
	if (col > m_cols - 1)
		throw IndexOutOfBounds();
	return m_board[row][col];
}

/**
 * @brief Retrieves a cell of the board. As it returns a constant reference
 *        you will not be able to modified the fetched cell.
 * @param[in] row where the wanted cell is located.
 * @param[in] col where the wanted cell is located. 
 */
const Cell& Board::cell(const uint32_t row, const uint32_t col) const {
	if (row > m_rows - 1)
		throw IndexOutOfBounds();
	if (col > m_cols - 1)
		throw IndexOutOfBounds();
	return m_board[row][col];
}

/**
 * Resizes the board (current state is discarded) and re-allocates memory.
 * @param[in] rows Desired number of rows.
 * @param[in] cols Desired number of columns.
 */
void Board::reset(const uint32_t rows, const uint32_t cols) {
	m_rows = rows;
	m_cols = cols;
	
	// Re-allocate the memory for the board and set all cells to alive.
	m_board.resize(rows);
	for (uint32_t i = 0; i < rows; i++) {
		m_board[i].resize(cols);
	}
}

/**
 * @brief Fills the board with random alive or dead cells.
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
 * @brief Swap operation for the Board class. Exchanges the data of two Board objects.
 *        It is used in move constructor and operator =  
 * @param[in] first  Board to be swapped.
 * @param[in] second Board to be swapped.
 */
void swap(Board &first, Board &second) { // No throw
	std::swap(first.m_rows, second.m_rows); 
	std::swap(first.m_cols, second.m_cols);
	std::swap(first.m_board, second.m_board);
}

/**
 * @returns the number of rows of the board.
 */
uint32_t Board::rows() const {
	return m_rows;
}

/**
 * @returns the number of columns of the board.
 */
uint32_t Board::columns() const {
	return m_cols;
}

/**
 * @brief Returns the number of alive neighbours. An 8-neighbourhood is
 *        used. This method considers that the board is a toroid. That is, all 
 *        the cells have exactly 8 neighbours, including the ones located in
 *        the edges.
 * @param[in] row Row of the cell whose number of neighbours we want to check.
 * @param[in] col Column of the cell whose number of neighbours we want to check.
 */
uint32_t Board::aliveNeighbours(const uint32_t row, const uint32_t col) const {
	uint32_t count = 0;
	std::vector<Cell> neighbours = getNeighbours(row, col); 	

	for (std::vector<Cell>::iterator it = neighbours.begin(); it != neighbours.end(); ++it)
		if (it->isAlive())
			count++;

	return count;
}

/**
 * @brief Obtain board from input stream.
 * @param[in] in Input stream that will be read.
 * @param[in] b  Board that will modified depending on the contents read from in.
 */
std::istream& operator>>(std::istream &in, Board &b) {
	std::string line;
	std::string::iterator it;
	uint32_t rows, cols;
	uint32_t i, j;

	// Get rows and columns
	if (!getline(in, line))
		throw CouldNotReadNumberOfRows(); 		
	rows = std::stoi(line);
	if (!getline(in, line)) 
		throw CouldNotReadNumberOfColumns(); 		
	cols = std::stoi(line);

	// Resize the board according to the provided new size
	b.reset(rows, cols);

	// Read board status
	for (i = 0; i < rows; i++) {
		// Read a line that represents a row
		if (!getline(in, line)) 
			throw CouldNotReadRow(i);
		it = line.begin();
		for (j = 0; j < cols - 1; j++) {
			// b.cell(i, j, *it == Cell::AliveChar);
			if (*it == Cell::AliveChar)
				b[i][j].revive();
			else
				b[i][j].die();
			it += 2; // The character 'O' or another character representing a dead cell and the following space 
		}
		// b.cell(i, j, *it == Cell::AliveChar);
		if (*it == Cell::AliveChar)
			b[i][j].revive();
		else
			b[i][j].die();
	}

	return in;	
}

/**
 * @brief Stream extraction operator that returns the status of the board. 
 * The board is extracted as lines (corresponding to rows of the board) of
 * 'O' representing alive cells and 'X' representing the dead cells.
 *
 * @param[in] out Destination stream where the board will be plotted. 
 * @param[in] b   Board to be printed.
 */
std::ostream& operator<<(std::ostream& out, const Board &b){
	for (uint32_t i = 0; i < b.m_rows; i++) {
		for (uint32_t j = 0; j < b.m_cols; j++) {
			if (b.cell(i, j).isAlive())
				out << "O ";
			else
				out << "X ";
		}	
		out << std::endl;
	}	
	return out;
}

/**
 * @brief The board is copied to this object. New memory is allocated (unless self-assignment).
 * @param[in] other Source object for the copy.
 * @returns the new 
 */
Board& Board::operator=(Board other) {
	swap(*this, other);
	return *this;
}

/**
 * @brief Compare two boards. Same size and same state for every cell means
 *        that the boards are the same.
 * @param[in] lhs The first board.
 * @param[in] rhs The second board.
 */
bool operator==(const Board &lhs, const Board &rhs) {
	if (lhs.rows() != rhs.rows())
		return false;

	if (lhs.columns() != rhs.columns())
		return false;

	for (uint32_t i = 0; i < lhs.rows(); i++) {
		for (uint32_t j = 0; j < lhs.columns(); j++) {
			if (lhs.cell(i, j).isAlive() != rhs.cell(i, j).isAlive())
				return false;
		}
	}
	return true;
}

/**
 * @brief Opposite behaviour to the operator ==.
 * @param[in] lhs Left hand side board.
 * @param[in] rhs Right hand side board.
 */
bool operator!=(const Board &lhs, const Board &rhs) {
	return !operator==(lhs, rhs);
}

/**
 * @brief Proxy that permits the user to access (or modify) the cells of the board 
 *        with double square brackets.
 *        
 *        Some examples of use: 
 *           board[i][j].revive()
 *           board[i][j].die()
 *           board[i][j].isAlive()
 *
 * @param[in] row Row that the user wants to access.
 * @returns a proxy object that will allow the access to a particular element of the row.
 */
Board::BoardProxy Board::operator[](const uint32_t row) {
	if (row > m_rows - 1)
		throw IndexOutOfBounds();
	return Board::BoardProxy(m_board[row]); 
}

/**
 * @returns a list with the 8 neighbours of a particular cell.
 * @param[in] row Row of the cell whose neighbours we want to obtain.
 * @param[in] col Column of the cell whose neighbours we want to obtain.
 */
std::vector<Cell> Board::getNeighbours(const uint32_t row, const uint32_t col) const {
	std::vector<Cell> neighbours;

	uint32_t topRow, bottomRow, leftCol, rightCol;	
	
	// Checking boundaries, i.e. enforcing toroid
	if (row == 0) {
		topRow = m_rows - 1;
		bottomRow = row + 1;
	}
	else {
		topRow = row - 1;
		if (row == m_rows - 1)
			bottomRow = 0;
		else
			bottomRow = row + 1;
	}
	
	if (col == 0) {
		leftCol = m_cols - 1;
		rightCol = col + 1;	
	}
	else {
		leftCol = col - 1;
		if (col == m_cols - 1)
			rightCol = 0;
		else
			rightCol = col + 1; 
	}
	
	// Add neighbours to vector
	neighbours.push_back(m_board[topRow][leftCol]);
	neighbours.push_back(m_board[topRow][col]);
	neighbours.push_back(m_board[topRow][rightCol]);
	neighbours.push_back(m_board[row][leftCol]);
	// neighbours.push_back(m_board[row][col]);
	neighbours.push_back(m_board[row][rightCol]);
	neighbours.push_back(m_board[bottomRow][leftCol]);
	neighbours.push_back(m_board[bottomRow][col]);
	neighbours.push_back(m_board[bottomRow][rightCol]);

	return neighbours;
}
