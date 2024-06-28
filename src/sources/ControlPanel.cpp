#include "headers/ControlPanel.h"
#include "utils/Comm.h"

ControlPanel::ControlPanel()
        : lcd(0x27, 16, 2) // Dirección I2C del LCD y tamaño (16x2)
        , radio(cePin, csPin)
        , readingAddress("00001")
        , writingAddress("00002")
        , pinLaunchPlatform(2)
        , pinWakeup(35)
        , pinCountdown(34)
        , pinStopLaunch(22)
        , pinEmergencyStop(26)
{
    // Initialize the radio
    radio.begin();
    radio.openReadingPipe(1, readingAddress);
    radio.openWritingPipe(writingAddress);
}

void ControlPanel::begin() {
    // Inicializar los pines de los botones
    pinMode(pinLaunchPlatform, INPUT);
    pinMode(pinWakeup, INPUT);
    pinMode(pinCountdown, INPUT);
    pinMode(pinStopLaunch, INPUT);
    pinMode(pinEmergencyStop, INPUT);

    // Inicializar el display LCD
    lcd.begin(16,2);
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Control Panel");

    Serial.println("Control Panel initialized");
}

bool ControlPanel::isLaunchPlatformInitiated() {
    return digitalRead(pinLaunchPlatform) == HIGH;
}

bool ControlPanel::isWakeupInitiated() {
    return digitalRead(pinWakeup) == HIGH;
}

bool ControlPanel::isCountdownInitiated() {
    return digitalRead(pinCountdown) == HIGH;
}

bool ControlPanel::isLaunchStopped() {
    return digitalRead(pinStopLaunch) == HIGH;
}

bool ControlPanel::isEmergencyStop() {
    return digitalRead(pinEmergencyStop) == HIGH;
}

void ControlPanel::updateDisplay(const char* message) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
}

void ControlPanel::update() {
    if (isLaunchPlatformInitiated()) {
        startPlatform();
    }

    if (isWakeupInitiated()) {
        wakeUp();
    }

    if (isCountdownInitiated()) {
        countdown();
    }

    if (isLaunchStopped()) {
        stopLaunch();
    }

    if (isEmergencyStop()) {
        emergencyStop();
    }
}

void ControlPanel::startPlatform() {
    radio.stopListening();

    char message[] = "start";

    char buffer[100];

    Comm::generateMessage(message, buffer);

    radio.write(buffer, sizeof(buffer));
    Serial.println("Message sent: " + String(buffer));
}

void ControlPanel::stopLaunch() {
    radio.stopListening();

    char message[] = "stop";

    char buffer[100];

    Comm::generateMessage(message, buffer);

    radio.write(buffer, sizeof(buffer));
    Serial.println("Message sent: " + String(buffer));
}

void ControlPanel::emergencyStop() {
    radio.stopListening();

    char message[] = "emergency";

    char buffer[100];

    Comm::generateMessage(message, buffer);

    radio.write(buffer, sizeof(buffer));
    Serial.println("Message sent: " + String(buffer));
}

void ControlPanel::countdown() {
    radio.stopListening();

    char message[] = "countdown";

    //Buffer
    char buffer[100];

    Comm::generateMessage(message, buffer);

    radio.write(buffer, sizeof(buffer));
    Serial.println("Message sent: " + String(buffer));
}

void ControlPanel::wakeUp() {
    radio.stopListening();

    char message[] = "wakeup";

    char buffer[100];

    Comm::generateMessage(message, buffer);

    radio.write(buffer, sizeof(buffer));
    Serial.println("Message sent: " + String(buffer));
}
