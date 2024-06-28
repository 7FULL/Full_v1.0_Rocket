#include "headers/StateMachine.h"
#include <Arduino.h>

StateMachine::StateMachine() {
    // Initialize the state machine to the IDLE state
    currentState = IDLE;
}

State StateMachine::getState() {
    return currentState;
}

void StateMachine::update() {
    controlPanel.update();

    switch (currentState) {
        case IDLE:
            if (controlPanel.isWakeupInitiated()) {
                currentState = WAKING_UP_ROCKET;
            }
            break;
        case WAKING_UP_ROCKET:
            if (controlPanel.isLaunchPlatformInitiated()) {
                currentState = CHECKING_ROCKET;
            }
            break;
        case CHECKING_ROCKET:
            if (controlPanel.isCountdownInitiated()) {
                currentState = ROCKET_READY;
            }
            break;
        case ROCKET_READY:
            if (controlPanel.isCountdownInitiated()) {
                currentState = CHECKING_FOR_LAUNCH;
            }
            break;
        case CHECKING_FOR_LAUNCH:
            if (controlPanel.isCountdownInitiated()) {
                currentState = WAITING_FOR_LAUNCH;
            }
            break;
        case WAITING_FOR_LAUNCH:
            if (controlPanel.isCountdownInitiated()) {
                currentState = LAUNCHING;
            }
            break;
        case LAUNCHING:
            if (controlPanel.isLaunchStopped()) {
                currentState = IDLE;
            }
            break;
    }
}

void StateMachine::setup() {
    controlPanel.begin();
}
