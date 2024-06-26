#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "Rocket.h"

enum State {
    IDLE,
    WAKING_UP_ROCKET,
    CHECKING_ROCKET,
    ROCKET_READY,
    CHECKING_FOR_LAUNCH,
    WAITING_FOR_LAUNCH,
    LAUNCHING,
    ASCENDING,
    ASCENDING_WITH_INERTIA,
    DESCENDING,
    DESCENDING_WITH_PARACHUTE,
    LANDED
};

class StateMachine {
public:
    StateMachine();

    // Get the current state
    State getState();

    // Update the state machine
    void update();

private:
    State currentState;
    Rocket rocket; // Instancia de la clase Rocket
};

#endif // STATEMACHINE_H
