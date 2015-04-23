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
	
	// Constants
	enum class State { Dead, Alive };
	static const char AliveChar = 'O';
	static const char DeadChar = 'X';

	// Constructors
	Cell();
	Cell(State state);    
	Cell(const Cell &other); // Copy constructor
	Cell(Cell &&other);      // Move constructor

	void die();
	void revive();
	bool isAlive() const;

	// Method to exchange the data of two cells, used in move constructor and operator =
	friend void swap(Cell &first, Cell &second); 
	
	// Operators
	Cell& operator=(Cell other);
	
private:
	State m_state;
};

#endif  // CELL_H_
