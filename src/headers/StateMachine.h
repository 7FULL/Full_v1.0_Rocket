#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "ControlPanel.h"

enum State {
    IDLE,
    WAKING_UP_ROCKET,
    CHECKING_ROCKET,
    ROCKET_READY,
    CHECKING_FOR_LAUNCH,
    WAITING_FOR_LAUNCH,
    LAUNCHING
};

class StateMachine {
public:
    StateMachine();

    // Get the current state
    State getState();

    // Set up the rocket and control panel
    void setup();

    // Update the state machine
    void update();

private:
    State currentState;
    ControlPanel controlPanel;
};

#endif // STATEMACHINE_H
