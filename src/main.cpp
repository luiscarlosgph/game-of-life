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
#include "exception.h"

int main(int argc, char **argv) {
	GameOfLife gol;

	try {
		// Read command line options
		CommandLineReader::getInstance().processCmdLineOptions(argc, argv);

		// If the user asks for help (i.e. --help or -h) print help and close program
		if (CommandLineReader::getInstance().justHelp()) {
			CommandLineReader::getInstance().printUsage(std::cout);
			return EXIT_SUCCESS;
		}
		
		// Check if the user wants a random board or provides an input file with the initial status of the game 
		if (CommandLineReader::getInstance().randomInitialisation()) 
			gol.randInit(CommandLineReader::getInstance().getSizeForRandomBoard());	
		else 
			gol.readConfig(CommandLineReader::getInstance().getInputFilePath());
		
		// Iterate a certain amount of times
		for (uint32_t i = 0; i < CommandLineReader::getInstance().getNumberOfIterations(); i++)
			gol.iterate();	

		// Write the history of the game in output file
		gol.writeOutputFile(CommandLineReader::getInstance().getOutputFilePath());
	}
	catch(const NotEnoughArgumentsException &e) {
		std::cerr << e.what() << std::endl;
		CommandLineReader::getInstance().printUsage(std::cerr);
		return EXIT_FAILURE;		
	}  
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;	
	}

	return EXIT_SUCCESS;
}
