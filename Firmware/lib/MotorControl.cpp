#include "MotorControl.h"

MotorController::MotorController(
    uint8_t ena,
    uint8_t in1,
    uint8_t in2,
    uint8_t enb,
    uint8_t in3,
    uint8_t in4
) {
    _ena = ena;
    _in1 = in1;
    _in2 = in2;

    _enb = enb;
    _in3 = in3;
    _in4 = in4;
}

void MotorController::begin() {
    pinMode(_ena, OUTPUT);
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);

    pinMode(_enb, OUTPUT);
    pinMode(_in3, OUTPUT);
    pinMode(_in4, OUTPUT);

    stop();
}

void MotorController::setMotor(
    uint8_t en,
    uint8_t inA,
    uint8_t inB,
    int speed
) {
    speed = constrain(speed, -255, 255);

    if (speed > 0) {
        digitalWrite(inA, HIGH);
        digitalWrite(inB, LOW);
    } else if (speed < 0) {
        digitalWrite(inA, LOW);
        digitalWrite(inB, HIGH);
    } else {
        digitalWrite(inA, LOW);
        digitalWrite(inB, LOW);
    }

    analogWrite(en, abs(speed));
}

void MotorController::setSpeed(
    int leftSpeed,
    int rightSpeed
) {
    setMotor(_ena, _in1, _in2, leftSpeed);
    setMotor(_enb, _in3, _in4, rightSpeed);
}

void MotorController::forward(int speed) {
    speed = constrain(speed, 0, 255);
    setSpeed(speed, speed);
}

void MotorController::backward(int speed) {
    speed = constrain(speed, 0, 255);
    setSpeed(-speed, -speed);
}

void MotorController::turnLeft(int speed) {
    speed = constrain(speed, 0, 255);
    setSpeed(-speed, speed);
}

void MotorController::turnRight(int speed) {
    speed = constrain(speed, 0, 255);
    setSpeed(speed, -speed);
}

void MotorController::stop() {
    setSpeed(0, 0);
}