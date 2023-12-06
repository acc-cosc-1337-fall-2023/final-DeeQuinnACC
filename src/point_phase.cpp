#include "point_phase.h"
#include <iostream>
/*
 Return RollOutcome::point when roll rolled_value equals private variable point
 Else if ---- return RollOutcome::seven_out when roll rolled_value equals 7
 Else return RollOutcome::nopoint 
*/

RollOutcome PointPhase::get_outcome(Roll* roll)
{
    int rolled_value = roll->roll_value();
    //std::cout<<"Rolled value: "<<rolled_value<<"\n";
    if(rolled_value == point)
    {
        return RollOutcome::point;
    }
    else if(rolled_value == 7)
    {
        return RollOutcome::seven_out;
    }
    else
    {
        //It will not return RollOutcome::nopoint for some reason, this is the only way I was able to get it working
        return RollOutcome(4);
    }
}