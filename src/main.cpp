#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>
#include <time.h>

using std::cout, std::cin;

int main() 
{
	//Initializing variables
	std::srand(time(NULL));
	Die die1, die2;
	Shooter shooter;
	Roll* roll = shooter.throw_dice(die1, die2);
	ComeOutPhase come_out_phase;

	//Main game begins here
	cout<<"Start of Come Out phase.\n";
	cout<<"Rolling until a natural or craps is NOT rolled.\n";

	//Come out roll
	//Roll while dice result is Natural or Craps, 
	while(come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps)
	{
		cout<<"Rolled value: "<<roll->roll_value();
		if(come_out_phase.get_outcome(roll) == RollOutcome::natural)
		{
			cout<<". Natural rolled!";
		}
		else
		{
			cout<<". Craps rolled!";
		}

		cout<<" Rolling again...\n";
		roll = shooter.throw_dice(die1, die2);
	}
	//Start of point phase
	//Roll until the previous roll or a 7 is rolled

	int rolled_value = roll->roll_value();
	cout<<"Rolled value: "<<roll->roll_value()<<"\n";
	cout<<"\nStart of the Point phase.\n";
	cout<<"Rolling until either the point ("<<rolled_value<<") or a 7 is rolled...\n";
	
	PointPhase point_phase(rolled_value);
	roll = shooter.throw_dice(die1, die2);
	while(point_phase.get_outcome(roll) == RollOutcome::nopoint)
	{
		cout<<"Rolled value: "<<roll->roll_value()<<", Rolling again...\n";
		roll = shooter.throw_dice(die1, die2);
	}

	cout<<"Rolled value: "<<roll->roll_value();
	if(point_phase.get_outcome(roll) == RollOutcome::point)
	{
		cout<<". Point rolled!\n";
	}
	else
	{
		cout<<". Seven rolled!\n";
	}
	cout<<"\nEnd of point phase.\n";
	cout<<shooter<<"\n";
	return 0;
}