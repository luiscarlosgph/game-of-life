/**
 * @brief Implementation of the cell class.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   26 Mar 2015.
 */

#include <algorithm>

// My includes 
#include "cell.h"

Cell::Cell() : m_state(Cell::State::Alive) {
}

Cell::Cell(Cell::State state) : m_state(state) {
}

Cell::Cell(const Cell &other) : m_state(other.m_state) {
}

/**
 * @brief Move constructor.
 * @param[in] other Object that will be moved to this one.
 */
Cell::Cell(Cell &&other) {
	swap(*this, other);
}

void Cell::die() {
	m_state = Cell::State::Dead;
}

void Cell::revive() {
	m_state = Cell::State::Alive;
}

bool Cell::isAlive() const {
	return m_state == Cell::State::Alive ? true : false;
}

void swap(Cell &first, Cell &second) {
	std::swap(first.m_state, second.m_state); 
}

Cell& Cell::operator=(Cell other) {
	swap(*this, other);
	return *this;
}
