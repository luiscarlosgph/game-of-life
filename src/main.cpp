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
#include "commandlinereader.h"
#include "gameoflife.h"

int main(int argc, char **argv) {
	GameOfLife gol;

	// Read command line options
	if(!CommandLineReader::getInstance().processCmdLineOptions(argc, argv))
		return EXIT_FAILURE;

	// Read initial status of the game
	try {
		gol.readConfig(CommandLineReader::getInstance().getInputFilePath());
	}
	catch(...) {
		// TODO
		return EXIT_FAILURE;	
	}

	// Iterate a certain amount of times
	for (uint32_t i = 0; i < CommandLineReader::getInstance().getNumberOfIterations(); i++) {
		gol.iterate();	
	}

	// Write the history of the game in output file
	try {
		gol.writeOutputFile(CommandLineReader::getInstance().getOutputFilePath());
	}
	catch(...) {
		// TODO
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
