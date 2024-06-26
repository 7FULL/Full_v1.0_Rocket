#include "headers/Rocket.h"
#include <Arduino.h>

Rocket::Rocket() {
    ready = false;
    ascending = false;
    descending = false;
    parachuteDeployed = false;
    landed = false;
}

bool Rocket::shouldWakeUp() {
    // Implementar la lógica para determinar si el cohete debe despertarse
    return true; // Ejemplo: siempre despierta
}

void Rocket::wakeUp() {
    // Implementar la lógica para despertar el cohete
    Serial.println("Rocket waking up...");
    ready = false;
    ascending = false;
    descending = false;
    parachuteDeployed = false;
    landed = false;
}

bool Rocket::checkSystems() {
    // Implementar la lógica para comprobar los sistemas del cohete
    Serial.println("Checking rocket systems...");
    ready = true; // Ejemplo: siempre pasa el chequeo
    return ready;
}

bool Rocket::isReady() {
    return ready;
}

bool Rocket::finalCheck() {
    Serial.println("Performing final check...");
    return ready; // Ejemplo: siempre pasa la verificación final
}

bool Rocket::launchSignalReceived() {
    Serial.println("Launch signal received...");
    return true; // Ejemplo: siempre recibe la señal de lanzamiento
}

void Rocket::launch() {
    Serial.println("Launching rocket...");
    ascending = true;
}

bool Rocket::isAscending() {
    return ascending;
}

bool Rocket::hasReachedInertia() {
    return false; // Ejemplo: nunca alcanza la inercia
}

bool Rocket::isDescending() {
    return descending;
}

bool Rocket::hasDeployedParachute() {
    return parachuteDeployed;
}

bool Rocket::hasLanded() {
    return landed;
}

void Rocket::land() {
    Serial.println("Rocket has landed.");
    ascending = false;
    descending = false;
    parachuteDeployed = false;
    landed = true;
}
