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
}

TEST_CASE("Test ComeOutPhase::get_outcome() returns the correct RollOutcome")
{
	
	Die d1, d2;
	Roll* r = new Roll(d1, d2);
	ComeOutPhase coPhase;

	while(r->roll_value() != 7)
	{
		r->roll_dice();
	}

	REQUIRE(coPhase.get_outcome(r) == RollOutcome::natural);

	while(r->roll_value() != 11)
	{
		r->roll_dice();
	}

	REQUIRE(coPhase.get_outcome(r) == RollOutcome::natural);
	
	while(r->roll_value() != 2)
	{
		r->roll_dice();
	}

	REQUIRE(coPhase.get_outcome(r) == RollOutcome::craps);
	
	while(r->roll_value() != 3)
	{
		r->roll_dice();
	}

	REQUIRE(coPhase.get_outcome(r) == RollOutcome::craps);
	
	while(r->roll_value() != 12)
	{
		r->roll_dice();
	}

	REQUIRE(coPhase.get_outcome(r) == RollOutcome::craps);


	//Program might get stuck here
	while(r->roll_value() == 2 || r->roll_value() == 3 || r->roll_value() == 7
		|| r->roll_value() == 11 || r->roll_value() == 12)
	{
		r->roll_dice();
	}

	REQUIRE(coPhase.get_outcome(r) == RollOutcome::point);

	delete r;
}

TEST_CASE("Test PointPhase::get_outcome() returns the correct RollOutcome")
{
	Die d1, d2;
	Roll* r = new Roll(d1, d2);
	PointPhase pPhase{6};

	while(r->roll_value() != 6)
	{
		r->roll_dice();
	}

	REQUIRE(pPhase.get_outcome(r) == RollOutcome::point);

	while(r->roll_value() != 7)
	{
		r->roll_dice();
	}

	REQUIRE(pPhase.get_outcome(r) == RollOutcome::seven_out);
	
	while(r->roll_value() == 6 || r->roll_value() == 7)
	{
		r->roll_dice();
	}

	REQUIRE(pPhase.get_outcome(r) == RollOutcome::nopoint);

	delete r;
}