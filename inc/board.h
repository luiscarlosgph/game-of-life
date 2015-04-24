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
#include <memory>

// My includes
#include "cell.h"

class Board {
public:
	class BoardProxy {
	public:
		BoardProxy(std::vector<Cell> &row);
		BoardProxy(const std::vector<Cell> &row);
		Cell& operator[](const uint32_t col);
		const Cell& operator[](const uint32_t col) const;

	private:
		std::vector<Cell> *m_row;	
	};

	// Constructors
	Board();
	Board(const uint32_t rows, const uint32_t cols);
	Board(const Board &other); // Copy constructor
	Board(Board &&other);      // Move constructor

	void reset(const uint32_t rows, const uint32_t cols);
	void randomise();
	friend void swap(Board &first, Board &second); 
	uint32_t aliveNeighbours(const uint32_t row, const uint32_t col) const; 
	// void evolve();

	// Getters
	uint32_t rows() const;
	uint32_t columns() const;
	Cell& cell(const uint32_t row, const uint32_t col);
	const Cell& cell(const uint32_t row, const uint32_t col) const;

	// Operators
	friend std::istream& operator>>(std::istream &in, Board &b);
	friend std::ostream& operator<<(std::ostream &out, const Board &b);
	Board& operator=(Board other);
	friend bool operator==(const Board &lhs, const Board &rhs);
	friend bool operator!=(const Board &lhs, const Board &rhs);
	BoardProxy operator[](const uint32_t row);
	BoardProxy operator[](const uint32_t row) const;

private:
	std::vector<Cell> getNeighbours(const uint32_t row, const uint32_t col) const;

	uint32_t m_rows;
	uint32_t m_cols;
	std::vector<std::vector<Cell> > m_board;
};

#endif  // BOARD_H_
