#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "come_out_phase.h"
#include "die.h"
#include "phase.h"
#include "point_phase.h"
#include "roll.h"
#include "shooter.h"
#include <iostream>
#include <time.h>

TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}

TEST_CASE("Test if Die::roll() generates a value between 1 and 6")
{
	std::srand(time(NULL));
	Die d;
	for(int i=0; i<10; i++)
	{
		d.roll();
		int roll = d.rolled_value();
		REQUIRE(roll > 0);
		REQUIRE(roll < 7);
	}
	
}
