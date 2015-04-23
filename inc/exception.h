/**
 * @brief  Group of exception classes.
 *        
 * @author Luis Carlos Garcia-Peraza Herrera (luis.herrera.14@ucl.ac.uk).
 * @date   14 Mar 2015. 
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>

/**
 * @class CouldNotReadNumberOfRows represents an exception that is raised when
 *        the program fails to read the number of rows from a file that 
 *        describes the initial state of a board.
 */
class CouldNotReadNumberOfRows: public std::exception {
	virtual const char* what() const throw() {
		return "ERROR! Could not read the number of rows from file.";
	}
};

/**
 * @class CouldNotReadNumberOfColumns represents an exception that is raised 
 *        when the program fails to read the number of columns from a file that 
 *        describes the initial state of a board.
 */
class CouldNotReadNumberOfColumns: public std::exception {
	virtual const char* what() const throw() {
		return "ERROR! Could not read the number of columns from file.";
	}
};

/**
 * @class CouldNotReadRow represents an exception that is raised when the 
 *        program fails to read the description (state) of a row that should 
 *        be present in the stream. We know that a row should be present 
 *        because the number of rows has been previously read.
 */
class CouldNotReadRow: public std::exception {
public:
	CouldNotReadRow(uint32_t row) : m_row(row) {}
	virtual const char* what() const throw() {
		return std::string("ERROR! Could not read the row no. " + std::to_string(m_row) + " from the input file provided.").c_str();
	}
	uint32_t m_row;	
};

/**
 * @class  NotEnoughArgumentsException represents an exception that occurs when 
 *         the user calls the GameOfLife program without providing the enough 
 *         parameters.
 */
class NotEnoughArgumentsException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR! Not enough arguments provided to the program.";
	}
};

/**
 * @class  IndexOutOfBounds represents an exception that occurs when 
 *         an index outside the board is accessed.
 */
class IndexOutOfBounds: public std::exception {
public:
	virtual const char* what() const throw() {
		return "ERROR! Tried to access a cell out of bounds.";
	}
};

#endif // EXCEPTION_H_
