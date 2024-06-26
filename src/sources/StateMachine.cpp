#include "StateMachine.h"
#include <Arduino.h>

StateMachine::StateMachine() {
    // Initialize the state machine to the IDLE state
    currentState = IDLE;
}

State StateMachine::getState() {
    return currentState;
}

void StateMachine::update() {
    switch(currentState) {
        case IDLE:
            // Check if the rocket should wake up
            if(rocket.shouldWakeUp()) {
                currentState = WAKING_UP_ROCKET;
            }
            break;
        case WAKING_UP_ROCKET:
            // Perform wake-up procedures
            rocket.wakeUp();
            currentState = CHECKING_ROCKET;
            break;
        case CHECKING_ROCKET:
            // Perform rocket checks
            if(rocket.checkSystems()) {
                currentState = ROCKET_READY;
            } else {
                currentState = IDLE; // Go back to IDLE if checks fail
            }
            break;
        case ROCKET_READY:
            // Ready to proceed to launch checking
            currentState = CHECKING_FOR_LAUNCH;
            break;
        case CHECKING_FOR_LAUNCH:
            // Perform final launch checks
            if(rocket.finalCheck()) {
                currentState = WAITING_FOR_LAUNCH;
            } else {
                currentState = IDLE; // Go back to IDLE if final check fails
            }
            break;
        case WAITING_FOR_LAUNCH:
            // Wait for launch signal
            if(rocket.launchSignalReceived()) {
                currentState = LAUNCHING;
            }
            break;
        case LAUNCHING:
            // Perform launch procedures
            rocket.launch();
            currentState = ASCENDING;
            break;
        case ASCENDING:
            // Check for transition to inertia or descending
            if(rocket.hasReachedInertia()) {
                currentState = ASCENDING_WITH_INERTIA;
            } else if(rocket.isDescending()) {
                currentState = DESCENDING;
            }
            break;
        case ASCENDING_WITH_INERTIA:
            // Check if the rocket starts descending
            if(rocket.isDescending()) {
                currentState = DESCENDING;
            }
            break;
        case DESCENDING:
            // Check if the parachute is deployed
            if(rocket.hasDeployedParachute()) {
                currentState = DESCENDING_WITH_PARACHUTE;
            } else if(rocket.hasLanded()) {
                currentState = LANDED;
            }
            break;
        case DESCENDING_WITH_PARACHUTE:
            // Check if the rocket has landed
            if(rocket.hasLanded()) {
                currentState = LANDED;
            }
            break;
        case LANDED:
            // Perform landing procedures
            rocket.land();
            // Check if the rocket is ready to launch again
            if(rocket.isReady()) {
                currentState = ROCKET_READY;
            } else {
                currentState = IDLE;
            }
            break;
    }
}
