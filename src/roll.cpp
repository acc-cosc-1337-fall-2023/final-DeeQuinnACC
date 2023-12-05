#include "roll.h"

void Roll::roll_dice()
{
    //Roll both dice
    die1.roll();
    die2.roll();

    //save values, change rolled to true
    value = die1.rolled_value() + die2.rolled_value();
    rolled = true;
}