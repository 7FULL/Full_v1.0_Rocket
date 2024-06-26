#ifndef ROCKET_H
#define ROCKET_H

class Rocket {
public:
    Rocket();

    bool shouldWakeUp();
    void wakeUp();
    bool checkSystems();
    bool isReady();
    bool finalCheck();
    bool launchSignalReceived();
    void launch();
    bool isAscending();
    bool hasReachedInertia();
    bool isDescending();
    bool hasDeployedParachute();
    bool hasLanded();
    void land();

private:
    bool ready;
    bool ascending;
    bool descending;
    bool parachuteDeployed;
    bool landed;
};

#endif // ROCKET_H
