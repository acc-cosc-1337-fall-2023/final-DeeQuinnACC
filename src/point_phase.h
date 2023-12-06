#include "phase.h"

#ifndef POINT_PHASE_H
#define POINT_PHASE_H

class PointPhase : Phase
{
public:
    PointPhase(int p) : point{p}{}
    virtual RollOutcome get_outcome(Roll* roll);

private:
    int point;
};

#endif