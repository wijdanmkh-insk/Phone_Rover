#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorController {
public:
    MotorController(
        uint8_t ena,
        uint8_t in1,
        uint8_t in2,
        uint8_t enb,
        uint8_t in3,
        uint8_t in4
    );

    void begin();

    void setSpeed(int leftSpeed, int rightSpeed);

    void forward(int speed);
    void backward(int speed);

    void turnLeft(int speed);
    void turnRight(int speed);

    void stop();

private:
    uint8_t _ena;
    uint8_t _in1;
    uint8_t _in2;

    uint8_t _enb;
    uint8_t _in3;
    uint8_t _in4;

    void setMotor(
        uint8_t en,
        uint8_t inA,
        uint8_t inB,
        int speed
    );
};

#endif