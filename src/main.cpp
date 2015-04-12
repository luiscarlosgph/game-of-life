/**
 * Main program for the Game of Life coursework.
 * Module: Research Computing with C++.
 * University College London.
 * 
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   24 Mar 2015.
 */

#include <cstdlib>

// My includes 
#include "gameoflife.h"

int main(int argc, char **argv) {
	GameOfLife gol;

	// Read initial status of the game
	try {
		gol.readConfig("src/input.gol");
	}
	catch(...) {
		// TODO
		return EXIT_FAILURE;	
	}

	// Iterate a certain amount of times
	for (int i = 0; i < 20; i++) {
		gol.iterate();	
	}

	// Write the history of the game in output file
	try {
		gol.writeOutputFile("output.gol");
	}
	catch(...) {
		// TODO
		return EXIT_FAILURE;
	}

	
	return EXIT_SUCCESS;
}
