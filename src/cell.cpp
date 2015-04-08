/**
 * @brief Implementation of the cell class.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   26 Mar 2015.
 */

// My includes 
#include "cell.h"

Cell::Cell() : m_alive(true) {

}

void Cell::die() {
	m_alive = false;
}

void Cell::revive() {
	m_alive = true;
}

bool Cell::isAlive() const {
	return m_alive;
}
