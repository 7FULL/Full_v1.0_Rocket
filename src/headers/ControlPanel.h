#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RF24.h"

class ControlPanel {
public:
    ControlPanel();

    void begin();

    bool isLaunchPlatformInitiated();
    bool isWakeupInitiated();
    bool isCountdownInitiated();
    bool isLaunchStopped();
    bool isEmergencyStop();

    void updateDisplay(const char* message);

    void update();

private:
    // Pines de los botones
    const uint8_t pinLaunchPlatform = 2; // INICIAR PLATAFORMA DE DESPEGUE
    const uint8_t pinWakeup = 35;         // DESPERTAR AL ORDENADOR DE ABORDO
    const uint8_t pinCountdown = 34;      // INICIAR CUENTA ATRAS
    const uint8_t pinStopLaunch = 22;     // PARADA DEL LANZAMIENTO
    const uint8_t pinEmergencyStop = 26;  // SETA DE EMERGENCIA

    const byte readingAddress[6] = "00001";
    const byte writingAddress[6] = "00002";
    const byte cePin = 4;
    const byte csPin = 5;

    // Display
    LiquidCrystal_I2C lcd;
    RF24 radio; // CE, CSN

    void startPlatform();
    void stopLaunch();
    void emergencyStop();
    void countdown();
    void wakeUp();
};

#endif // CONTROLPANEL_H
