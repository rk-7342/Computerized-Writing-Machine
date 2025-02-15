#include <AccelStepper.h>
#include <Servo.h>

// Stepper motor pins
#define X_STEP_PIN 3
#define X_DIR_PIN 2
#define Y_STEP_PIN 5
#define Y_DIR_PIN 4

// Servo pin
#define PEN_SERVO_PIN 6

AccelStepper stepperX(1, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepperY(1, Y_STEP_PIN, Y_DIR_PIN);
Servo penServo;

void setup() {
    stepperX.setMaxSpeed(1000);
    stepperX.setAcceleration(500);
    stepperY.setMaxSpeed(1000);
    stepperY.setAcceleration(500);
    
    penServo.attach(PEN_SERVO_PIN);
    penServo.write(90);  // Lift pen
}

void lowerPen() {
    penServo.write(0);  // Lower pen
    delay(500);
}

void liftPen() {
    penServo.write(90);  // Lift pen
    delay(500);
}

void drawRectangle() {
    lowerPen();
    stepperX.moveTo(100);
    stepperX.runToPosition();
    
    stepperY.moveTo(100);
    stepperY.runToPosition();
    
    stepperX.moveTo(0);
    stepperX.runToPosition();
    
    stepperY.moveTo(0);
    stepperY.runToPosition();
    
    liftPen();
}

void loop() {
    drawRectangle();
    delay(2000);
}
