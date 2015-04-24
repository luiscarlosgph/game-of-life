/**
 * @brief Unit tests for Conway's Game of Life.
 *        
 * @author Luis Carlos Garcia-Peraza Herrera (luis.herrera.14@ucl.ac.uk).
 * @date   9 Apr 2015. 
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>

// My includes
#include "cell.h"
#include "board.h"
#include "commandlinereader.h"
#include "gameoflife.h"

// Test Cell class
TEST_CASE("Successful manipulation of the Cell class", "[Cell]") {

	Cell a;
	Cell b;

	SECTION("Die working") {
		a.die();
		REQUIRE(!a.isAlive());
	}

	SECTION("Revive working") {
		b.revive();	
		REQUIRE(b.isAlive());	
	}

}

TEST_CASE("Successful manipulation of the Board class", "[Board]") {
	
	Board a;
	Board b(1000, 1000);
	std::ofstream outFile;
	std::ifstream inFile;
	
	SECTION("Checking cell access") {
		b[999][999].revive();
		b[998][998].die();
		REQUIRE(b.cell(999, 999).isAlive());
		REQUIRE(!b.cell(998, 998).isAlive());
	}

	SECTION("Checking board size") {
		REQUIRE(a.rows() == 0);
		REQUIRE(a.columns() == 0);
		REQUIRE(b.rows() == 1000);
		REQUIRE(b.columns() == 1000);
	}

	SECTION("Checking reset()") {
		a.reset(22, 33);
		REQUIRE(a.rows() == 22);
		REQUIRE(a.columns() == 33);
	}
	
	SECTION("Checking randomise()") {
		a.reset(10, 10);				
		bool atLeastOneDead = false;
		a.randomise();
		for (uint32_t i = 0; i < a.rows(); i++) {
			for (uint32_t j = 0; j < a.columns(); j++) {
				if (!a.cell(i, j).isAlive())
					atLeastOneDead = true;
			}	
		}
		REQUIRE(atLeastOneDead);
	}
	
	SECTION("Testing stream input opreator >>") {
		// Create file with a valid representation of the board	
		const std::string filePath = "/tmp/.input_operator.tmp";
		a.reset(3, 4);
		outFile.open(filePath);	
		outFile << "3" << std::endl;
		outFile << "4" << std::endl;
		outFile << "O X O X" << std::endl;
		outFile << "X O X O" << std::endl;
		outFile << "O X O X" << std::endl;
		outFile.close();
		
		// Read the file using the input operator
		uint32_t rows, cols;
		std::string line;
		inFile.open(filePath);
		getline(inFile, line);
		getline(inFile, line);
		inFile >> a;
		inFile.close();
		
		// Test that the read board corresponds to the one in the file
		REQUIRE(a[0][0].isAlive() == true);
		REQUIRE(a[0][1].isAlive() == false);
		REQUIRE(a[0][2].isAlive() == true);
		REQUIRE(a[0][3].isAlive() == false);
		REQUIRE(a[1][0].isAlive() == false);
		REQUIRE(a[1][1].isAlive() == true);
		REQUIRE(a[1][2].isAlive() == false);
		REQUIRE(a[1][3].isAlive() == true);
		REQUIRE(a[2][0].isAlive() == true);
		REQUIRE(a[2][1].isAlive() == false);
		REQUIRE(a[2][2].isAlive() == true);
		REQUIRE(a[2][3].isAlive() == false);
	}

	SECTION("Testing output operator << and ==") {
		// Create file with the size and status of a board
		const std::string filePath = "/tmp/.output_operator.tmp";
		a.reset(5, 3);
		b.reset(5, 3);
		a[0][0].revive();
		a[0][1].die();
		a[0][2].revive();
		a[1][0].die();
		a[1][1].die();
		a[1][2].revive();
		a[2][0].die();
		a[2][1].die();
		a[2][2].die();
		a[3][0].revive();
		a[3][1].die();
		a[3][2].revive();
		a[4][0].revive();
		a[4][1].die();
		a[4][2].die();
		outFile.open(filePath);	
		outFile << "5" << std::endl;
		outFile << "3" << std::endl;
		outFile << a;
		outFile.close();

		// Read the file using the input operator
		std::string line;
		inFile.open(filePath);
		getline(inFile, line);
		getline(inFile, line);
		inFile >> b;
		inFile.close();

		// Test that the written and read data are the same
		REQUIRE(a == b);	
	}
}

TEST_CASE("Successful manipulation of the GameOfLife class", "[GameOfLife]") {
	
	GameOfLife gol;
	Board a;
	std::ofstream outFile;
	std::ifstream inFile;
	std::ifstream inFile2;

	/**
	 * Checking that GameOfLife is able to read domain size and initial state with readConfig()
	 * and also capable of writing the output files correctly.
	 */
	SECTION("Checking that readConfig() and writeOutputFile()") {
		const std::string file1 = "/tmp/.file1.tmp";
		const std::string file2 = "/tmp/.file2.tmp";
		const std::string file3 = "/tmp/.file3.tmp";
		a.reset(3, 5);
		a[0][0].revive();
		a[0][1].die();
		a[0][2].revive();
		a[0][3].revive();
		a[0][4].revive();
		a[1][0].die();
		a[1][1].revive();
		a[1][2].die();
		a[1][3].revive();
		a[1][4].die();
		a[2][0].die();
		a[2][1].revive();
		a[2][2].die();
		a[2][3].revive();
		a[2][4].revive();
		
		// Write domain size and initial state of the board to file
		outFile.open(file1);	
		outFile << "3" << std::endl;
		outFile << "5" << std::endl;
		outFile << a;
		outFile.close();	

		// Read the configuration from the file
		gol.readConfig(file1);
		
		// Write the configuration to the output file
		gol.writeOutputFile(file2);
		
		// Add domain size to the header of the output file
		outFile.open(file3);	
		outFile << "3" << std::endl;
		outFile << "5" << std::endl;
		outFile.close();	
		std::string s = "cat " + file2 + " >> " + file3;
		system(s.c_str());

		// Compare the two files, they should be the same if readConfig() and
		std::string line, line2;
		inFile.open(file1);
		inFile2.open(file3);
		do {
			getline(inFile, line);
			getline(inFile2, line2);
			REQUIRE(line == line2);
		} while (!inFile.eof());

		// Remove temporary files
		remove(file1.c_str());
		remove(file2.c_str());
		remove(file3.c_str());
	}

	SECTION("Checking that iterate() correctly creates the next generation") {
		/*
		
		Remember that we are using a toroid!

		Test A
		======
		 _____      _____
		|O|O|O|    |X|X|X|
      |O|O|X| => |X|X|X|
		|X|X|O|    |X|X|X|
		 -----      -----
		
		Test B
		======
		 _____      _____
		|O|X|X|    |O|X|X|
		|O|X|O| => |O|X|O|
		|O|X|X|    |O|X|O|
		 -----      -----

		*/
		
		// Test A
		a.reset(3, 3);
		a[0][0].revive();
		a[0][1].revive();
		a[0][2].revive();
		a[1][0].revive();
		a[1][1].revive();
		a[1][2].die();
		a[2][0].die(); 
		a[2][1].die();
		a[2][2].revive();
		
		// Write domain size and initial state of the board to file
		std::string filePath("/tmp/.test_iterate.tmp");
		outFile.open(filePath);	
		outFile << "3" << std::endl;
		outFile << "3" << std::endl;
		outFile << a;
		outFile.close();	

		// Reag config file
		gol.readConfig(filePath);
		remove(filePath.c_str());

		// Create next generation 
		gol.iterate();

		// Write result to file
		gol.writeOutputFile(filePath);
		
		// Read result from file  	
		std::string line;
		a.reset(3, 3);
		inFile.open(filePath);	
		getline(inFile, line);	
		getline(inFile, line);	
		getline(inFile, line);	
		getline(inFile, line);	
		inFile >> a;
		inFile.close();	

		// Remove temp file
		remove(filePath.c_str());

		REQUIRE(a[0][0].isAlive() == false);
		REQUIRE(a[0][1].isAlive() == false);
		REQUIRE(a[0][2].isAlive() == false);
		REQUIRE(a[1][0].isAlive() == false);
		REQUIRE(a[1][1].isAlive() == false);
		REQUIRE(a[1][2].isAlive() == false);
		REQUIRE(a[2][0].isAlive() == false);
		REQUIRE(a[2][1].isAlive() == false);
		REQUIRE(a[2][2].isAlive() == false);
		
		// Test B
		/*
		a.reset(3, 3);
		a[0][0].revive();
		a[0][1].die();
		a[0][2].die();
		a[1][0].revive();
		a[1][1].die();
		a[1][2].revive();
		a[2][0].revive(); 
		a[2][1].die();
		a[2][2].die();

		// Write domain size and initial state of the board to file
		outFile.open(filePath);	
		outFile << "3" << std::endl;
		outFile << "3" << std::endl;
		outFile << a;
		outFile.close();	

		// Reag config file
		gol.readConfig(filePath);
		remove(filePath.c_str());

		// Create next generation 
		gol.iterate();

		// Write result to file
		gol.writeOutputFile(filePath);
		
		// Read result from file  	
		a.reset(3, 3);
		inFile.open(filePath);	
		inFile >> a;
		inFile.close();	

		// Remove temp file
		remove(filePath.c_str());

		REQUIRE(a[0][0].isAlive() == true);
		REQUIRE(a[0][1].isAlive() == false);
		REQUIRE(a[0][2].isAlive() == false);
		REQUIRE(a[1][0].isAlive() == true);
		REQUIRE(a[1][1].isAlive() == false);
		REQUIRE(a[1][2].isAlive() == true);
		REQUIRE(a[2][0].isAlive() == true);
		REQUIRE(a[2][1].isAlive() == false);
		REQUIRE(a[2][2].isAlive() == false);
		*/
	}

}

TEST_CASE("Test that all the exceptions work", "[exception.h]") {
	
	SECTION("Checking access to an index out of bounds for the Board class") {
		// TODO	
	}

}
