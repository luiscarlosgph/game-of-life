/**
 * @brief Unit tests for Conway's Game of Life.
 *        
 * @author Luis Carlos Garcia-Peraza Herrera (luis.herrera.14@ucl.ac.uk).
 * @date   9 Apr 2015. 
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <iostream>

// My includes
#include "cell.h"
#include "board.h"

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
	
	SECTION("Checking cell access") {
		b.cell(999, 999, true);
		b.cell(998, 998, false);
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
		for (int i = 0; i < a.rows(); i++) {
			for (int j = 0; j < a.columns(); j++) {
				if (!a.cell(i, j).isAlive())
					atLeastOneDead = true;
			}	
		}
		REQUIRE(atLeastOneDead);
	}

	SECTION("Checking evolve()") {
		a.reset(3, 3);
		a.cell(0, 0, true);
		a.cell(0, 1, true);
		a.cell(0, 2, true);
		a.cell(1, 0, true);
		a.cell(1, 1, true);
		a.cell(1, 2, false);
		a.cell(2, 0, false); 
		a.cell(2, 1, false);
		a.cell(2, 2, true);
		a.evolve();
		REQUIRE(a.cell(0, 0).isAlive() == true);
		REQUIRE(a.cell(0, 1).isAlive() == false);
		REQUIRE(a.cell(0, 2).isAlive() == true);
		REQUIRE(a.cell(1, 0).isAlive() == true);
		REQUIRE(a.cell(1, 1).isAlive() == false);
		REQUIRE(a.cell(1, 2).isAlive() == false);
		REQUIRE(a.cell(2, 0).isAlive() == false);
		REQUIRE(a.cell(2, 1).isAlive() == true);
		REQUIRE(a.cell(2, 2).isAlive() == false);
	}

	// TODO: test input and output opreators

}
