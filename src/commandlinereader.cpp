/**
 * @class CommandLineReader represents the class that parses and stores the command line options
 *        provided by the user to the program.
 * @author Luis Carlos Garcia-Peraza Herrera (luis.herrera.14@ucl.ac.uk).
 * @date   14 Mar 2015. 
 */

#include <iostream>
#include <string>
#include <boost/program_options.hpp>
// #include <boost/filesystem.hpp>
#include <exception>

// My includes
#include "cxxopts.h"
#include "commandlinereader.h"
#include "exception.h"

const std::string kUsageMsg( 
	"\nThis program runs Conway's Game of Life (rectangular toroid board).\n"
	"Provide the input as a file with the number of rows in the first line,\n"
	"the number of columns in the second line, and the initial state of the\n"
	"board in the following lines.\n"
	"Represent each row of the game with a line in the file. Each alive cell\n"
	"must be represented by an 'O' and a space following it. The dead cells\n"
	"can be represented by any character (e.g. 'X') and a space following it.\n"
	"\nExample of valid input file:\n"
	"3\n"
	"4\n"
	"O X O O\n"
	"X X O X\n"
	"O O O X\n"
	"\nOther way to run this program is by using the parameter --random instead\n"
	"of specifying any input file with --input. If --random is used, the number\n"
	"provided represents the size of the board. For example:\n"
	"--random 1000 will create a 1000x1000 randomised board.\n"
	"\nOptions:\n"
	"--help   | -h   Prints help message.\n"
	"--input  | -i   Path to the file with the domain size and the initial state of the game.\n"
	"--output | -o   Path to the output file. The program will write the whole history of the game in this file.\n"
	"--niter  | -n   Number of iterations to execute.\n"
	"--random | -r   Size of a random initial board.\n"
);

CommandLineReader::CommandLineReader() : m_iter(0), m_sizeRandom(0), m_random(false), m_usage(false) {
}

CommandLineReader& CommandLineReader::getInstance() {
	static CommandLineReader instance; // Guaranteed to be destroyed and instantiated on first use.
	return instance;
}

std::string CommandLineReader::getInputFilePath() const {
	return m_inputPath;
}

std::string CommandLineReader::getOutputFilePath() const {
	return m_outputPath;
}

uint32_t CommandLineReader::getNumberOfIterations() const {
	return m_iter;
}

uint32_t CommandLineReader::getSizeForRandomBoard() const {
	return m_sizeRandom;
}

bool CommandLineReader::justHelp() const {
	return m_usage;
}

bool CommandLineReader::randomInitialisation() const {
	return m_random;
}

/**
 * @brief Reads and prints the command line arguments provided by the user. 
 * @param[in]  argc Number of command line arguments including the program.
 * @param[in]  argv Array of strings containing the parameters provided.
 * @returns true if the mandatory parameters are provided and they are correct (i.e. input files exist). 
 */
void CommandLineReader::processCmdLineOptions(int argc, char **argv) {
	// bool retval = false;

	// Program name
	const std::string programName = "GameOfLife";
	
	// Lightweight options parser, boost::program_options is a nightmare to compile with GCC in MAC OS X
	cxxopts::Options options(programName, desc);
	
	options.add_options()
		("h,help", "Prints this help message.")
		("i,input", "Path to the file with the initial state of the game.", cxxopts::value<std::string>())
		("o,output", "Path to the output file. The program will write the whole history of the game in this file.", cxxopts::value<std::string>())
		("n,niter", "Number of iterations to execute.", cxxopts::value<uint32_t>())
		("r,random", "Size of a random initial board.", cxxopts::value<uint32_t>())
	;
	
	// Parse command line options	
	// try {
	options.parse(argc, argv);

	// Print help if the user asks for it
	if (options.count("help")) {
		// printUsage(std::cout);
		// retval = true;
		m_usage = true;
	}
	else if (options.count("input") && options.count("output") && options.count("niter")) { // First way of using the program, an input file specifies the config og the board
		m_inputPath = options["input"].as<std::string>();
		m_outputPath = options["output"].as<std::string>();
		m_iter = options["niter"].as<uint32_t>();
		// retval = true;	
	}
	else if (options.count("random") && options.count("output") && options.count("niter")) { // Second way of using the program, a random square board will be created
		m_sizeRandom = options["random"].as<uint32_t>();
		m_outputPath = options["output"].as<std::string>();
		m_iter = options["niter"].as<uint32_t>();
		m_random = true;
		// retval = true;	
	}
	else {
		throw NotEnoughArgumentsException();
	}
	/*
	}
	catch(std::exception const &e) {
		std::cerr << "\nERROR! " << e.what() << std::endl << desc << std::endl;
		return false;
	}	

	return retval;
	*/
}

/**
 * @brief Print help message to the stream provided. 
 * @param[in] stream Output stream where the usage message will be printed (e.g. std::cout or std::cerr).
 * @returns nothing. 
 */
void CommandLineReader::printUsage(ostream &stream) const {
	stream << CommandLineReader::kUsageMsg << std::endl;
}
