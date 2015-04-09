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
	a.die();
	b.revive();	

	SECTION("Die working") {
		REQUIRE(!a.isAlive());
	}

	SECTION("Revive working") {
		REQUIRE(b.isAlive());	
	}

}
