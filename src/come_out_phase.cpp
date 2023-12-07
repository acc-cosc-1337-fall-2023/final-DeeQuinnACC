#include "come_out_phase.h"
#include <iostream>
/*
 Return RollOutcome::natural when roll rolled_value is 7 or 11
 Else if ---- return RollOutcome::craps when roll rolled_value 2, 3, or 12
 Else return RollOutcome::point 
*/
RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{
    int rolled_value = roll->roll_value();
    //std::cout<<"Rolled value: "<<rolled_value<<"\n";
    if(rolled_value == 7 || rolled_value == 11)
    {
        return RollOutcome::natural;
    }
    else if(rolled_value == 2 || rolled_value == 3 || rolled_value == 12)
    {
        return RollOutcome::craps;
    }
    else
    {
        return RollOutcome::point;
    }
}