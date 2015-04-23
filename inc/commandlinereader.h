/**
 * @class CommandLineReader reads the command line string provided by the user, parses it and extracts the relevant parameters. 
 *
 * @author Luis Carlos Garcia-Peraza Herrera.
 * @date   8 Apr 2015.
 */

#ifndef COMMAND_LINE_READER_H_
#define COMMAND_LINE_READER_H_

#include <iostream>
#include <string>

class CommandLineReader {
public:
	// Singleton: only one command line
	static CommandLineReader& getInstance();

	// Getters and setters
	std::string getInputFilePath() const;
	std::string getOutputFilePath() const;
	uint32_t getNumberOfIterations() const;
	uint32_t getSizeForRandomBoard() const;
	bool justHelp() const; 
	bool randomInitialisation() const;
	void processCmdLineOptions(int argc, char **argv);
	void printUsage(std::ostream &stream) const;
	
private:
	CommandLineReader();
	CommandLineReader(CommandLineReader const&) = delete;
	void operator = (CommandLineReader const&) = delete;

	static const std::string kUsageMsg;
	std::string m_inputPath;
	std::string m_outputPath;
	uint32_t m_iter;
	uint32_t m_sizeRandom;
	bool m_random;
	bool m_usage;
};


#endif  // COMMAND_LINE_READER_H_
