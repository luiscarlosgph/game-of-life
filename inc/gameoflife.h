/**
 * @class GameOfLife represents a Conway's Game of Life. 
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include <string>
#include <stack>

// My includes
#include "board.h"
// #include "filereader.h"
// #include "filewriter.h"

class GameOfLife {
public:
	GameOfLife();
	
	void readConfig(const std::string &path);
	void iterate();
	void writeOutputFile(const std::string &path);
	
private:
	std::stack<Board> m_boardStack;
	// Board m_board;
	// FileReader m_fileReader;
	// FileWriter m_fileWriter;

};

#endif  // GAME_OF_LIFE_H_
