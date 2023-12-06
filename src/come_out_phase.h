#include "phase.h"

#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

class ComeOutPhase : Phase
{
public:
    virtual RollOutcome get_outcome(Roll* roll);
};

#endif