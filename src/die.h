#include <stdlib.h>

#ifndef DIE_H
#define DIE_H

class Die
{
public:
    //Rolls once to generate a value for roll_value
    Die(){ roll(); }
    //Randomly assigns a value to roll_value in the range of 1 to int sides
    void roll();
    //Returns roll_value
    int rolled_value() const { return roll_value; }

private:
    //Stores a randomly assigned value 
    int roll_value;
    //Die sides; defaults to 6
    int sides{6};
};

#endif