#pragma once 
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep
#include "autons.h" // IWYU pragma: keep
#include "devices.h"
#include "lemlib/chassis/chassis.hpp" 
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "stormlib/api.hpp"
#include "liblvgl/core/lv_disp.h"// IWYU pragma: keep
#include "liblvgl/core/lv_obj_pos.h" // IWYU pragma: keep
#include "liblvgl/widgets/lv_img.h" // IWYU pragma: keep
#include "stormlib/led.hpp" // IWYU pragma: keep

stormlib::aRGB strand1(6, 45);


stormlib::aRGB_manager LEDmanager(&strand1, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr);
 using rd::Console;
   Console console;

  rd::Selector selector({
    {"test", &test},
   {"test2", &test2},
{"BlueNeg4_1", &BlueNeg4Ring},
{"BluePos2", &BluePos2},
{"}BlueSoloAwp", &BlueSoloAwp},
{"BlueNeg1", &BlueNeg1},
{"RedPos1", &RedPos1},
{"RedNeg1", &RedNeg1},
{"RedNeg2", &RedNeg2},
{"}RedSoloAwp", &RedSoloAwp},
{"BlueSigSAwp", &BlueSigSAwp},
{"BlueSigSAwp2", &BlueSigSAwp2},
{"RedSigSAWP", &RedSigSAWP},
{"RedSigSAWP2", &RedSigSAWP2},
{"skills", &skills},
{"red4ring", &red4ring},
{"blue4ring", &blue4ring}


});
ASSET(mogopath_txt);

const int numStates = 1;
//make sure these are in centidegrees (1 degree = 100 centidegrees)
int states[numStates] = {330};
int currState = 0;
int target = 0;

void nextState() {
        
    target = states[currState];
}

void liftControl() {
    double kp = .1;
    double error = target - rotationSensor3.get_position();
    double velocity = kp * error;
    LB.move(velocity);
}


void initialize() {
    pros::Task liftControlTask([]{
        while (true) {
            liftControl();
            pros::delay(10);
        }
    });

}


void disabled() {}

void competition_initialize() {}


void autonomous() {
    LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    pros::delay(100);
        console.println("Erm what the sigma");
        LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	        selector.run_auton();
}





void opcontrol() {   
bool MogoState = false;
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


    // loop forever
    while (true) {
        	   
               
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
			nextState();
		}
        // get left y and right y positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // move the robot
        chassis.tank(leftY, rightY);

        if(controller.get_digital(DIGITAL_R2)){
         Hook.move(-127);
         Intake.move(127);
        }
        else if(controller.get_digital(DIGITAL_X)){
            Hook.move(127);
            Intake.move(-127);

        } else{
            Hook.move(0);
            Intake.move(0);
        }

    	

	


        
        if(controller.get_digital(DIGITAL_LEFT)){
            Doinker.set_value(true);
        } else if(controller.get_digital(DIGITAL_RIGHT)){
            Doinker.set_value(false);
        }

    if (controller.get_digital(DIGITAL_A)){
        Mogo.set_value(true);
        } else if(controller.get_digital(DIGITAL_B)){
        Mogo.set_value(false);
        }

        // delay to save resources
        pros::delay(25);

    }
}