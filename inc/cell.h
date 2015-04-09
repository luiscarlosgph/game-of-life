/**
 * @class Cell represents a cell in the Game of Life's board. A cell can be dead or alive and it can be killed or revived.
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   26 Mar 2015.
 */

#ifndef CELL_H_
#define CELL_H_

class Cell {
public:
	Cell();

	void die();
	void revive();
	bool isAlive() const;

private:
	bool m_alive;
};

#endif  // CELL_H_
