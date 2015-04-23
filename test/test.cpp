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

// My includes
#include "cell.h"
#include "board.h"
#include "commandlinereader.h"

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
		outFile.open(filePath);	
		outFile << "3" << std::endl;
		outFile << "4" << std::endl;
		outFile << "O X O X" << std::endl;
		outFile << "X O X O" << std::endl;
		outFile << "O X O X" << std::endl;
		outFile.close();
		
		// Read the file using the input operator
		inFile.open(filePath);
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
		a.reset(4, 3);
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
		outFile.open(filePath);	
		outFile << "4" << std::endl;
		outFile << "3" << std::endl;
		outFile << a;
		outFile.close();	

		// Read the file using the input operator
		inFile.open(filePath);
		inFile >> b;
		inFile.close();

		// Test that the written and read data are the same
		REQUIRE(a == b);	
	}
}

TEST_CASE("Successful manipulation of the GameOfLife class", "[GameOfLife]") {
	
	GameOfLife gol;
	Board a;

	SECTION("Checking that GameOfLife is able to read domain size and initial state with readConfig()") {
		// TODO
		a.reset(10, 5);

	
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
		a[0][0].revive();
		a[0][1].revive();
		a[0][2].revive();
		a[1][0].revive();
		a[1][1].revive();
		a[1][2].die();
		a[2][0].die(); 
		a[2][1].die();
		a[2][2].revive();
		// TODO: a.evolve();
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
		a[0][0].revive();
		a[0][1].die();
		a[0][2].die();
		a[1][0].revive();
		a[1][1].die();
		a[1][2].revive();
		a[2][0].revive(); 
		a[2][1].die();
		a[2][2].die();
		// TODO: a.evolve();
		REQUIRE(a[0][0].isAlive() == true);
		REQUIRE(a[0][1].isAlive() == false);
		REQUIRE(a[0][2].isAlive() == false);
		REQUIRE(a[1][0].isAlive() == true);
		REQUIRE(a[1][1].isAlive() == false);
		REQUIRE(a[1][2].isAlive() == true);
		REQUIRE(a[2][0].isAlive() == true);
		REQUIRE(a[2][1].isAlive() == false);
		REQUIRE(a[2][2].isAlive() == false);

	}

	SECTION("Test that writeOutputFile() works under normal circumstances") {
		// TODO
	}	

}
