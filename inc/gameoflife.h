/**
 * @class GameOfLife represents a Conway's Game of Life. 
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

// My includes
#include "board.h"
#include "filereader.h"
#include "filewriter.h"

class GameOfLife {
public:
	GameOfLife();
	
private:
	Board m_board;
	FileReader m_fileReader;
	FileWriter m_fileWriter;
}

#endif  // GAME_OF_LIFE_H_
