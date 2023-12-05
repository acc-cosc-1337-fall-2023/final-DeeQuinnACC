#include "shooter.h"

using std::vector;

Shooter::~Shooter()
{
    for(int i=0; i<rolls.size(); i++)
    {
        delete rolls[i];
    }
}

Roll* Shooter::throw_dice(Die& d1, Die& d2)
{
    Roll* r = new Roll(d1, d2);
    r->roll_dice();
    rolls.push_back(r);
    return r;
}

std::ostream& operator <<(std::ostream& out, Shooter& s)
{
    out<<"All Rolls: ";
    for(int i=0; i<s.rolls.size(); i++)
    {
        //Puts a comma after the first roll, but not after the last
        if(i != 0)
        {
            out<<", ";
        }
        out<<s.rolls[i]->roll_value();
    }

    return out;
}