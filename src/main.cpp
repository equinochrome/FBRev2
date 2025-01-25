#pragma once 
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep 
#include "liblvgl/llemu.hpp"
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
{"BlueSoloAWP", &BluePos2},
{"}BlueMidRush1", &BlueMidRush1},
{"BlueSoloAWAPPush", &BlueSoloAWAPPush},
{"RedMidRush1", &RedMidRush1},
{"RedMidRushExtropy", &RedMidRushExtropy},
{"RedMidRushPOSCORNER", &RedMidRushPOSCORNER},
{"BlueMidRushExtropy", &BlueMidRushExtropy},
{"BlueMidRushPOSCORNER", &BlueMidRushPOSCORNER},
{"RedSoloAWP", &RedSoloAWP},
{"RedAWPPush", &RedSoloAWPPush},
{"skills", &skills},
{"RedeNeg4_1", &RedNeg4_1},
{"RedNeg6_1", &RedNeg6_1},



});
ASSET(mogopath_txt);









void initialize() {
//rotationSensor3.set_position(-50);
rotationSensor3.reset_position();
chassis.calibrate();
pros::lcd::initialize();
 pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });


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
        //console.println("Erm what the sigma");
        LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	        //selector.run_auton();
    // REMOVE BEFORE COMPETITION    
    skills();
}






void opcontrol() {   
bool MogoState = false;
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
IntakePiston.set_value(false);
Doinker.set_value(false);
target=50;

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
    color.set_led_pwm(100);
    Hook.move(-127);
    Intake.move(127);
        } else if(controller.get_digital(DIGITAL_X)){
    color.set_led_pwm(0);
    Hook.move(127);
    Intake.move(-127);
        } else if(controller.get_digital(DIGITAL_L1)){
    color.set_led_pwm(0);
    Intake.move(127);
        } else {
    color.set_led_pwm(0);
    Hook.move(0);
    Intake.move(0);
}

	


        
        if(controller.get_digital(DIGITAL_LEFT)){
            Doinker.set_value(true);
        } else if(controller.get_digital(DIGITAL_RIGHT)){
            Doinker.set_value(false);
        }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        Mogo.set_value(false);
        } else 
        Mogo.set_value(true);
        
   

        // delay to save resources
pros::delay(25);

    }
}