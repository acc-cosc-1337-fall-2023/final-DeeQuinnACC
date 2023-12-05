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

TEST_CASE("Test if Roll::roll_dice() generates a value between 2 and 12")
{
	std::srand(time(NULL));
	Die d1, d2;
	Roll r(d1, d2);
	for(int i=0; i<10; i++)
	{
		r.roll_dice();
		int roll = r.roll_value();
		REQUIRE(roll > 1);
		REQUIRE(roll < 13);
	}
}

TEST_CASE("Test that Shooter::shoot_dice()'s Roll generates a value between 2 and 12")
{
	std::srand(time(NULL));
	Shooter s;
	for(int i=0; i<10; i++)
	{
		Die d1, d2;
		int roll = s.throw_dice(d1, d2)->roll_value();
		REQUIRE(roll > 1);
		REQUIRE(roll < 13);
	}

	//Check Shooter << overload manually
	std::cout<<s<<"\n";
}
