#pragma once 
#include "main.h" // IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep
#include "autons.h" // IWYU pragma: keep
#include "devices.h" // IWYU pragma: keep
#include "lemlib/chassis/chassis.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp" // IWYU pragma: keep

#include "pros/motors.hpp" // IWYU pragma: keep

#include "stormlib/api.hpp"
#include "liblvgl/core/lv_disp.h"// IWYU pragma: keep
#include "liblvgl/core/lv_obj_pos.h" // IWYU pragma: keep
#include "liblvgl/widgets/lv_img.h" // IWYU pragma: keep





class Arm {
    private:
        float setPosition;
        float currentPosition;
        float error;
        lemlib::PID armPID;
        float stowPos;
        float readyPos;
        float scoreReadyPos;
        float scorePos;
        pros::Motor armMotor1;
        pros::Motor armMotor2;
        float gearRatio;

    public:
        Arm(pros::Motor armMotor1, pros::Motor armMotor2, lemlib::PID armPID, float stowPos, float readyPos, float scoreReadyPos, float scorePos, float gearRatio);
        enum States {
            STOW,
            READY,
            SCOREREADY,
            SCORE
        };
        States state;
        States getState();
        void toggleReady();
        void scoreButton();
        void updateState();
        void lowerPos();
        void raisePos();
        int posOffset;
        void setBrakeMode(pros::motor_brake_mode_e brakeMode);
        void setState(States newState);
    
};