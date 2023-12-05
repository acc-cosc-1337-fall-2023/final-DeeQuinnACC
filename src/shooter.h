#include "roll.h"
#include <vector>
#include <iostream>
#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
public:
    ~Shooter();

    Roll* throw_dice(Die& d1, Die& d2);
    friend std::ostream& operator <<(std::ostream& out, Shooter& s);

private:
    std::vector<Roll*> rolls;
};

#endif 