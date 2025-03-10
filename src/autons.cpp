#include "devices.h"
#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep
#include <cstdio>
#include <cmath>

int pastVoltage = 0;

void ColorSort(){
    
    color.set_led_pwm(100);
    pastVoltage = Hook.get_voltage();

    if (BlueTeam) {
        if(color.get_hue() < 15){
            pros::delay(98);
            Hook.move(0);
            pros::delay(300);
            Hook.move(pastVoltage);
        }
    } else

    if (RedTeam) {
        if(color.get_hue() > 200){
            pros::delay(105);
            Hook.move(0);
            pros::delay(300);
            Hook.move(pastVoltage);
        }
    }
}

void BlueStop(){
    if (Auto && RedTeam){
        if(color.get_hue() > 200){
            Hook.move(0);
        }
    }
}

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

double prevError = 0;

void liftControl() {
    double kp = .015;
    double kd = 0.05;
    double error = target - rotationSensor3.get_position();
    double deriv = error - prevError;
    prevError = error;
    double velocity = kp * error + deriv * kd;
    LB.move(velocity);
}

void test(){
    //BlueTeam=false;
    RedTeam=true;
    pros::delay(100);
    Mogo.set_value(true);
Intake.move(127);
Hook.move(-127);



}

void test2(){
    chassis.setPose(0,0,0);
    chassis.turnToHeading(90, 10000);
};

void BlueNeg4Ring(){
BlueTeam=true;
// BLUE NEG W/ ALLIANCE STAKE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
RedTeam = false;
chassis.setPose(60,12, 180);
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(24, 24, 700, { .forwards = false}, false);
chassis.moveToPoint(24, 24, 99999, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(7, 64, 0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(7, 67, 0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(26, 26, 330, 1500, {.forwards = false, .lead = .4, .minSpeed=70});
pros::delay(100);
chassis.moveToPoint(30, 47, 1000, {}, false);
pros::delay(400);
// score ring from 2 ring stack near alliance stake; ring on top of the stack. begin lb ladder touch
LB.move_relative(1200, 127);
chassis.turnToPoint(48,22, 700, {}, false);
chassis.moveToPoint(48,22, 1500, {}, false);
chassis.moveToPoint(48, -22, 200, {.minSpeed = 100});
chassis.moveToPoint(48, -22, 2500 ,{ .maxSpeed = 60}, false);
target=16000;
chassis.turnToPoint(24, 0, 700);
chassis.moveToPoint(24, 0, 1000, {.maxSpeed = 70}, false);
Tipper.set_value(true);

};

void BluePos2(){
    //BLUE SOLO AWP
// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(60,12, 180);
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(22, 24, 700, { .forwards = false}, false);
chassis.moveToPoint(22, 24, 500, { .forwards = false}, false);
chassis.moveToPoint(22, 24, 2000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(7, 64, 0, 2000, {.minSpeed = 30, .earlyExitRange = 1});
chassis.moveToPose(7, 65, 0, 1000, {.minSpeed = 40});
//score ring from single 2 ring stack
chassis.moveToPose(28, 27, 330, 1500, {.forwards = false, .lead = .4, .minSpeed=65});
pros::delay(100);
chassis.moveToPoint(28, 50, 1000, {}, false);
// score ring from 2 ring stack near alliance stake; ring on top of the stack
pros::delay(300);
IntakePiston.set_value(true);
chassis.moveToPose(48, 5, 180, 3000, {.lead = .4, .minSpeed = 80}, false);
Mogo.set_value(false);
Hook.move(127);
chassis.moveToPoint(48, -6, 2000, {.maxSpeed = 60}, false);
IntakePiston.set_value(false);
Hook.move(-30);
chassis.turnToPoint(22, -25, 700, { .forwards = false, .minSpeed = 60, }, false);
//Hook.move(0);
//Intake.move(0);
chassis.moveToPoint(22, -25, 2000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
Hook.move(-127);
Intake.move(127);
//chassis.turnToPoint(24, -48, 700);
chassis.moveToPose(24, -50, 180, 2000, {.lead = .4, .minSpeed = 80}, false);
chassis.moveToPose(14, -14, 200, 2000, {.forwards=false, .lead = .2, .minSpeed = 90});
pros::delay(700);
target=5500;



}

void skills(){

// 9123C SKILLS ROUTINE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
RedTeam = true;
chassis.setPose(62.75,0, 270);
target = 300;
Mogo.set_value(false);

/// score preload on alliance stake


Hook.move(-127);
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

pros::delay(300);

// grab mobile goal
chassis.moveToPoint(48, 0, 1000, {} , false);
Hook.move(0);
chassis.turnToHeading(180, 700);
chassis.moveToPoint(47.5, 26, 1000, {.forwards = false, .maxSpeed = 45}, false);
Mogo.set_value(true);
pros::delay(250);
// score first ring
chassis.turnToHeading(270, 700, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(28, 29, 1000);
// place ring in wall stake mechanism
chassis.turnToPoint(-24, 50, 700, {}, false);
pros::delay(100);
nextState();
chassis.moveToPoint(-24, 50, 1250);
// score wall stake and intake second ring to mobile goal
chassis.turnToPoint(-2, 44, 700, {.forwards = false}, false);
chassis.moveToPoint(-2, 44, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.turnToHeading(0, 700, {}, false);
Hook.move(-80); // extra push
chassis.moveToPoint(-2, 67, 800, {.maxSpeed = 100}, false);
Hook.move_relative(135, 127); // retract
nextState();
pros::delay(500);
// score third through fifth rings
chassis.moveToPoint(-2.5, 48, 1000, {.forwards = false}, false);
chassis.turnToPoint(60, 48, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(36, 48, 750);
chassis.moveToPoint(60, 48, 3000, {.maxSpeed=65});
pros::delay(1750);
// score sixth ring
chassis.turnToPoint(52, 60, 700);
chassis.moveToPoint(52, 60, 1000);
pros::delay(200); 
// drop mobile goal into corner
chassis.turnToPoint(58, 63, 700, {.forwards = false});
chassis.moveToPoint(58, 63, 1000, {. forwards=false}, false);
Mogo.set_value(false);
pros::delay(50);
Hook.move(127);
nextState();
// grab second mobile goal
chassis.moveToPoint(47, 56, 1000);
chassis.turnToHeading(0, 700, {}, false);
chassis.moveToPoint(48, 0, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.moveToPoint(48, -24, 1500, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(300);
// score first ring
chassis.turnToHeading(270, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(33, -26, 1000);
// primee wall stake and load with ring
chassis.turnToPoint(-30, -54, 700, {}, false);
chassis.moveToPoint(-30, -54, 1250, {}, false);
nextState();
// move to wall stake
chassis.turnToPoint(-2, -44, 700, {.forwards = false}, false);
chassis.moveToPoint(-2, -44, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.turnToHeading(180, 700, {}, false);
Hook.move(-80); // extra push
chassis.moveToPoint(-2, -66, 800, {}, false);
Hook.move_relative(105, 127); // retract
nextState();
pros::delay(500);
// score third through fifth rings
chassis.moveToPoint(-2, -48, 1000, {.forwards = false}, false);
chassis.turnToPoint(60, -48, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(36, -48, 750);
chassis.moveToPoint(60, -48, 3000, {.maxSpeed=50});
pros::delay(700);
// score sixth ring
chassis.turnToPoint(52, -60, 700, {}, false);
chassis.moveToPoint(52, -60, 1000);
pros::delay(200);
// drop mobile goal into corner
chassis.turnToPoint(58, -63, 700, {.forwards = false});
chassis.moveToPoint(58, -63, 600, {. forwards=false}, false);
Mogo.set_value(false);
pros::delay(50);
Hook.move(127);
nextState();// EVERYTHING BELOW IS UNTESTED


// grab a mobile goal with blue ring
chassis.moveToPoint(-12, -54, 1250, {}, false);
chassis.turnToPoint(-55, -23, 700, {.forwards = false}, false);
Intake.move(-127);
chassis.moveToPoint(-62, -23, 600, {.forwards = false, .minSpeed = 127}, false);
chassis.moveToPoint(-62, -23, 3000, {.forwards = false, .maxSpeed = 60}, false);
Mogo.set_value(true);
//Push corner
chassis.turnToPoint(-70, -54, 700, {.forwards = false}, false);
Intake.move(127);
chassis.moveToPoint(-70, -45, 1500, {.forwards = false}, false);
Mogo.set_value(false);
chassis.moveToPoint(-70, -54, 1000, {.forwards = false}, false);

//Ring and Empty Goal
pros::delay(100);
chassis.turnToPoint(-52, -50, 800);
chassis.moveToPoint(-45, -45, 1250, {.minSpeed = 127});
Hook.move(0);
chassis.moveToPoint(-64, -54, 1000, {.forwards=false});
chassis.turnToPoint(-24, -24, 700);
Hook.move_relative(-600, 127);
chassis.moveToPoint(-24, -24, 1500);
chassis.turnToPoint(-58, 11, 700, {.forwards = false}, false);
chassis.moveToPoint(-58 , 11, 2000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
chassis.turnToPoint(-24, 26, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(-24, 26, 1000, {}, false);
chassis.turnToPoint(-24, 48, 700, {}, false);
chassis.moveToPoint(-24, 48 , 1000, {}, false);
//Left stack
chassis.turnToPoint(-60, 52, 1000);
chassis.moveToPoint(-60, 52, 1000, {}, false);
chassis.moveToPoint(-40, 52, 800, {.forwards = false} , false);
//Right stack
chassis.turnToPoint(-48, 62, 700);
chassis.moveToPoint(-48, 62, 1000);
pros::delay(300);
//Corner    
chassis.turnToPoint(-60, 65, 700, {.forwards = false}, false);
pros::delay(100);
Mogo.set_value(false);

chassis.moveToPoint(-60, 65, 2000, {.forwards = false}, false);
Hook.move(127);
pros::delay(300);

chassis.moveToPoint(-38, 36, 1000, {}, false);
nextState();
nextState(); // hang up
chassis.turnToPoint(-0, 0, 700, {.forwards=false}, false);

pros::delay(200);
Hook.move(0);
chassis.moveToPoint(0, 0, 9999, {.forwards=false, .maxSpeed = 100});
pros::delay(500);
nextState();
nextState();


}


void BlueMidRush1(){
//Set up for BLUEMIDRUSH (QUALS)
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
RedTeam = false;
Doinker.set_value(true);
chassis.setPose(49.643,-60.256, 288.13);
Intake.move(127);
Mogo.set_value(false);
//Get mid mogo
chassis.moveToPoint(14, -48, 1000, {.minSpeed = 127}, false);
chassis.moveToPoint(30 ,-50.175, 15000, {.forwards=false}, false);
Clamp.set_value(true);
chassis.moveToPoint(35, -50.175, 700, {}, false);
Clamp.set_value(false);
Doinker.set_value(false);
pros::delay(100);
chassis.moveToPoint(30, -50.175, 1000, {});
chassis.turnToPoint(22.5, -24, 700, {.forwards=false}, false);
chassis.moveToPoint(22.5, -24, 1200, {.forwards=false, .maxSpeed=60}, false);
Mogo.set_value(true);
Doinker.set_value(false);
pros::delay(300);
Hook.move(-127);
chassis.turnToPoint(58, -30, 700);
chassis.moveToPoint(58, -30, 700, {}, false);
chassis.turnToPoint(63, -52, 700, {});
Doinker.set_value(true);
chassis.moveToPoint(63, -52, 1000, {}, false);  
chassis.turnToHeading(230, 700);
Doinker.set_value(false);
pros::delay(200);
Hook.move(0);
chassis.moveToPoint(50, -60, 700, {}, false);
Mogo.set_value(false);
pros::delay(50);
chassis.turnToPoint(24, -24, 700);
//Hook.move_absolute(20000, -127);
chassis.moveToPoint(24, -24, 1000, {}, false);
chassis.turnToPoint(6.5, -60, 1000, {.forwards=false});
chassis.moveToPoint(6.5, -60, 3500, {.forwards = false, .maxSpeed = 60}, false);
Mogo.set_value(true);
pros::delay(200);
Hook.move(-127);
chassis.moveToPose(36, -45, 90, 10000);

}

void BlueMidRushExtropy(){
//Get mid mogo
chassis.moveToPoint(16, -36, 1500, {.minSpeed = 127}, false);
pros::delay(50);
Doinker.set_value(true);
chassis.moveToPose(14.5, -36, 225, 80, {.minSpeed= 90, .earlyExitRange= 1});
chassis.turnToHeading(160, 750);
pros::delay(200);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(25.5, -16.5, 700, {.forwards = false, .minSpeed = 100});
chassis.moveToPoint(22.5, -16.5, 2000, {.forwards = false, .maxSpeed= 90}, false);
Mogo.set_value(true);
pros::delay(50);
///Stack
chassis.turnToPoint(55, 3, 900, {}, false);
Hook.move(-127);
chassis.moveToPoint(55, 3, 1000);
IntakePiston.set_value(true);
Intake.move(127);
pros::delay(100);
chassis.turnToPoint(66, -48, 700, {.forwards=false}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(66, -48, 1000, {.forwards=false}, false);
pros::delay(200);
Mogo.set_value(false);
//Grab Other mogo
Hook.move(0);
chassis.turnToPoint(12, -25.5, 700, {});
chassis.moveToPoint(12, -25.5, 1200, {});
chassis.turnToPoint(12, -60, 700, {.forwards=false}); 
chassis.moveToPoint(12, -60, 1500, {.forwards=false, .maxSpeed = 60}, false   );
Mogo.set_value(true);
pros::delay(50);
//Stack
Hook.move(-127);
chassis.turnToHeading(75, 700);
chassis.moveToPoint(24, -48, 1000, {}, false);
chassis.moveToPoint(15, -55, 1000, {.forwards = false});

}

void BlueMidRushPOSCORNER(){
//Get mid mogo
chassis.moveToPoint(16, -36, 1500, {.minSpeed = 127}, false);
pros::delay(50);
Doinker.set_value(true);
chassis.moveToPose(14.5, -36, 225, 80, {.minSpeed= 90, .earlyExitRange= 1});
chassis.turnToHeading(160, 750);
pros::delay(200);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(25.5, -16.5, 700, {.forwards = false, .minSpeed = 100});
chassis.moveToPoint(22.5, -16.5, 2000, {.forwards = false, .maxSpeed= 90}, false);
Mogo.set_value(true);
pros::delay(50);
///Stack
chassis.turnToPoint(55, 3, 900, {}, false);
Hook.move(-127);
chassis.moveToPoint(55, 3, 1000);
IntakePiston.set_value(true);
Intake.move(127);
pros::delay(100);
chassis.turnToPoint(66, -48, 700, {.forwards=false}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(66, -48, 1000, {.forwards=false}, false);
pros::delay(200);
Mogo.set_value(false);
//Grab Other mogo
Hook.move(0);
chassis.turnToPoint(12, -25.5, 700, {});
chassis.moveToPoint(12, -25.5, 1200, {});
chassis.turnToPoint(12, -60, 700, {.forwards=false}); 
chassis.moveToPoint(12, -60, 1500, {.forwards=false, .maxSpeed = 60}, false   );
Mogo.set_value(true); 
pros::delay(50);
//Stack
Hook.move(-127);
chassis.turnToHeading(75, 700);
chassis.moveToPoint(24, -48, 1000, {}, false);
pros::delay(200);
Intake.move(-127);
chassis.moveToPoint(50, -55, 1000, {});


}
void BlueSoloAWAPPush(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
BlueTeam=true;
Mogo.set_value(false);

// BLUE SOLO AWP PUSH W STAKE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(60,12, 180);
target = 400;

// score preload
target = 16100;
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
target=0;
pros::delay(200);
// Turn to alliance bot
chassis.moveToPoint(55, 24, 1000);
chassis.turnToHeading(0, 500, {lemlib::AngularDirection::CW_CLOCKWISE});
chassis.moveToPoint(55, 45 , 700);
Intake.move(80);
chassis.moveToPoint(55, 16, 1000, {.forwards = false}, false);
target = 16100;
//Turn to goal
chassis.turnToPoint(22, 25, 800, { .forwards = false});
chassis.moveToPoint(22, 25, 2000, { .forwards = false, .maxSpeed = 50}, false);
//Grab and turn to ring
Mogo.set_value(true);
pros::delay(100);
chassis.turnToPoint(24, 55, 1000, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(24, 55, 1000, {}, false);
pros::delay(500);
chassis.turnToPoint(55, 5, 700, {}, false);
IntakePiston.set_value(true);
chassis.moveToPoint(55, 5, 1500, {}, false);
IntakePiston.set_value(false);
chassis.turnToPoint(24, 36, 1000, {.forwards=false, .minSpeed=70});
chassis.moveToPoint(24, 36, 1000, {.forwards=false, .minSpeed=70});
chassis.moveToPoint(24, 18, 4000, {.forwards=false, .minSpeed=70});
chassis.turnToHeading(0, 700);
target = 6000;
chassis.moveToPoint(12, 18, 700, {.forwards=false});



}
void RedMidRush1(){
    //REd Mid rush 
// set up
RedTeam = true;
BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-49.643,-36.256, 108.13);
Mogo.set_value(false);


Doinker.set_value(true);
Intake.move(127);
chassis.moveToPoint(-12, -48, 1000, {.minSpeed=127, .earlyExitRange = 1} );
chassis.moveToPoint(-30, -46.56599, 15000, {.forwards=false, .minSpeed = 127}, false);
Clamp.set_value(true);
chassis.turnToHeading(90, 700, {}, false);
chassis.moveToPoint(-35, -46.56599, 1000);
Doinker.set_value(false);
chassis.moveToPoint(-22, -46.55599, 700);
Clamp.set_value(false);
chassis.turnToPoint(-22, -22, 700, {.forwards=false});
chassis.moveToPoint(-22, -22, 1000, {.forwards=false, .maxSpeed=60}, false);
Mogo.set_value(true);
pros::delay(150);
Hook.move(-127);
chassis.moveToPoint(-22, -56, 1000);
chassis.swingToHeading(270, lemlib::DriveSide::RIGHT, 700, {}, false);
Doinker.set_value(true);
chassis.moveToPoint(-56, -70.5, 1000, {});
Hook.move(0);
chassis.turnToHeading(330, 1000, {.minSpeed=100}, false);
pros::delay(50);
Hook.move(-127);
Doinker.set_value(false);
chassis.moveToPoint(-58, -48, 1000);
//chassis.swingToHeading(241, lemlib::DriveSide::RIGHT, 700, {}, false);
//chassis.moveToPoint(-61, -59, 700, {}, false);
Hook.move(0);
chassis.turnToPoint(-20, -20, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed=80});
pros::delay(200);
Mogo.set_value(false);
//Intake.move(0);
chassis.moveToPoint(-24, -20, 1000, {}, false);
chassis.turnToPoint(-6, -46, 700, {.forwards=false, });
chassis.moveToPoint(-6, -46, 1000, {.forwards=false, .maxSpeed = 80}, false);
Mogo.set_value(true);
pros::delay(100);
Hook.move(-127);
chassis.moveToPose(-20, -45, -90, 10000, {});

//Doinker.set_value(true);
//target = 16100;
//chassis.moveToPoint(-5, -29, 700);
//chassis.turnToHeading(45, 1500);
//chassis.swingToHeading(20, lemlib::DriveSide::RIGHT, 2000);
}

void RedMidRushExtropy(){
    //RED MID RUSH EXTROPY
// set up
RedTeam = true;
BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-51.25,-37, 90);
Mogo.set_value(false);

//Grab mid mogo
chassis.moveToPoint(-20.3, -36, 1500, {.minSpeed = 127});
pros::delay(700);
chassis.turnToHeading(-140 , 750);
pros::delay(105);
Doinker.set_value(true);
pros::delay(300);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(-22.5, -18.5, 700, {.forwards = false, .minSpeed = 100});
chassis.moveToPoint(-22.5, -18.5, 2000, {.forwards = false, .maxSpeed= 90}, false);
Mogo.set_value(true);
pros::delay(50);
//Go Stack and get ring
chassis.turnToPoint(-41, -1, 900, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(-41, -1, 1000);
IntakePiston.set_value(true);
pros::delay(100);
//Corner
chassis.turnToPoint(-55, -48, 700, {.forwards=false}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(-55, -48, 1000, {.forwards=false}, false);
pros::delay(200);
Mogo.set_value(false);
//Grab Other mogo
Intake.move(-127);
Hook.move(0);
chassis.turnToPoint(-6, -25.5, 700, {});
chassis.moveToPoint(-6, -25.5, 1200, {});
chassis.turnToPoint(-6, -63, 700, {.forwards=false}); 
chassis.moveToPoint(-6, -63, 1500, {.forwards=false, .maxSpeed = 60}, false   );
Mogo.set_value(true); 
pros::delay(50);
//Stack
Hook.move(-127);
Intake.move(127);
chassis.turnToHeading(-75, 700);
chassis.moveToPoint(-24, -48, 1000, {}, false);
chassis.turnToPoint(-12, -55, 700, {.forwards=false});
chassis.moveToPoint(-12, -55, 1000, {.forwards = false});


}
void RedMidRushPOSCORNER(){
//Red Mid Rush Pos Corner
 // set up
RedTeam = true;
BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-51.25,-37, 90);
Mogo.set_value(false);

//Grab mid mogo
chassis.moveToPoint(-20.3, -36, 1500, {.minSpeed = 127});
pros::delay(700);
chassis.turnToHeading(-140 , 750);
pros::delay(120);
Doinker.set_value(true);
pros::delay(500);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(-17.5, -20.5, 700, {.forwards = false, .minSpeed = 100});
chassis.moveToPoint(-17.5, -20.5, 2000, {.forwards = false, .maxSpeed= 90}, false);
Mogo.set_value(true);
pros::delay(50);
//Go Stack and get ring
chassis.turnToPoint(-40, -5, 900, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(-40, -5, 1000);
IntakePiston.set_value(true);
pros::delay(100);
//Corner
chassis.turnToPoint(-55, -48, 700, {.forwards=false}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(-55, -48, 1000, {.forwards=false}, false);
pros::delay(200);
Mogo.set_value(false);
//Grab Other mogo
Intake.move(-127);
Hook.move(0);
chassis.turnToPoint(-8, -25.5, 700, {});
chassis.moveToPoint(-8, -25.5, 1200, {});
chassis.turnToPoint(-6, -63, 700, {.forwards=false}); 
chassis.moveToPoint(-6, -63, 1500, {.forwards=false, .maxSpeed = 60}, false   );
Mogo.set_value(true); 
pros::delay(50);
//Stack
Hook.move(-127);
Intake.move(127);
chassis.turnToHeading(-75, 700);
chassis.moveToPoint(-24, -48, 1000, {}, false);
//Corner
Intake.move(-127);
chassis.moveToPoint(-48, -50, 1000);

}

void RedNeg4_1(){
//Red Neg 4_1

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = false;
RedTeam = true;
chassis.setPose(-60,12, -180);
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(-138, lemlib::DriveSide::RIGHT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(-24, 23, 700, { .forwards = false}, false);
chassis.moveToPoint(-24, 23, 100, { .forwards = false, .minSpeed = 127}, false);
chassis.moveToPoint(-24, 23, 99999, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(-325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(-7, 64, -0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(-7, 69, -0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(-26, 26, -330, 1500, {.forwards = false, .lead = .4, .minSpeed=70});
pros::delay(100);
chassis.moveToPoint(-30, 47, 1000, {}, false);
pros::delay(400);
// score ring from 2 ring stack near alliance stake; ring on top of the stack. begin lb ladder touch
chassis.turnToPoint(-46,22, 700, {}, false);
chassis.moveToPoint(-46,22, 1500, {}, false);
chassis.moveToPoint(-46, -24, 200, {}, false);
chassis.moveToPoint(-46, -24, 2500 ,{ .maxSpeed = 45}, false);
target=16100;
chassis.turnToPoint(-24, 0, 700);
chassis.moveToPoint(-22, 0, 1000, {.maxSpeed = 70}, false);
Tipper.set_value(true);


}

void RedSoloAWP(){
    //Red Solo AWP

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = false;
RedTeam = true;
chassis.setPose(-60,12, 180);
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(-138, lemlib::DriveSide::RIGHT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(-22, 24, 700, { .forwards = false}, false);
chassis.moveToPoint(-22, 24, 500, { .forwards = false}, false);
chassis.moveToPoint(-22, 24, 2000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(-325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(-7, 64, -0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(-7, 67, -0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(-27, 27, -330, 1500, {.forwards = false, .lead = .4, .minSpeed=65});
pros::delay(100);
chassis.moveToPoint(-27, 50, 1000, {}, false);
// score ring from 2 ring stack near alliance stake; ring on top of the stack
pros::delay(300);
IntakePiston.set_value(true);
LB.move_relative(1350, 127);
chassis.moveToPose(-48, 0, -180, 3000, {.lead = .4, .minSpeed = 80}, false);
Mogo.set_value(false);
Hook.move(127);
chassis.moveToPoint(-48, -6, 2000, {.maxSpeed = 60}, false);
IntakePiston.set_value(false);
chassis.turnToPoint(-20, -24, 700, { .forwards = false, .minSpeed = 60, .earlyExitRange = 3}, false);
//Hook.move(0);
//Intake.move(0);
chassis.moveToPoint(-20, -24, 500, { .forwards = false, .maxSpeed = 60, .earlyExitRange = 1}, false);
chassis.moveToPoint(-20, -24, 1000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
Hook.move(-127);
Intake.move(127);
//chassis.turnToPoint(24, -48, 700);
target=6000;
chassis.moveToPose(-24, -50, -180, 2000, {.lead = .4, .minSpeed = 80}, false);
chassis.moveToPose(-14, -14, -200, 2000, {.forwards=false, .lead = .2, .minSpeed = 90}, false);


}
void RedSoloAWPPush(){
 //RedSoloAWAPPush

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(-60,12, 180);
target = 400;
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(-138, lemlib::DriveSide::RIGHT, 700, {}, false);
target=0;
pros::delay(200);
// Turn to alliance bot
chassis.moveToPoint(-60, 24, 1000);
chassis.turnToHeading(-0, 700, {});
chassis.moveToPoint(-58, 45 , 700);
Intake.move(80);
chassis.moveToPoint(-55, 16, 1000, {.forwards = false}, false);
target = 16100;
//Turn to goal
chassis.turnToPoint(-22, 22.5, 800, { .forwards = false});
chassis.moveToPoint(-22, 22.5, 2000, { .forwards = false, .maxSpeed = 50}, false);
//Grab and turn to ring
Mogo.set_value(true);
pros::delay(100);
chassis.turnToPoint(-20, 52, 1000, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(-20, 52, 1000, {}, false);
pros::delay(500);
chassis.turnToPoint(-46, 6, 700, {}, false);
IntakePiston.set_value(true);
chassis.moveToPoint(-46, 6, 1500, {}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(-24, 20, 4000, {.forwards=false, .minSpeed=70});
chassis.turnToHeading(0, 700);
target = 6000;
chassis.moveToPoint(-14, 9, 700, {.forwards=false});
}

void RedNeg6_1(){
// 6 rings on mogo + 1 ring on allliance stake

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(-60,12, 180);
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(-138, lemlib::DriveSide::RIGHT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(-22, 24, 700, { .forwards = false}, false);
chassis.moveToPoint(-22, 24, 500, { .forwards = false}, false);
chassis.moveToPoint(-22, 24, 2000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(-325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(-7, 64, -0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(-7, 67, -0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(-28, 27, -330, 1500, {.forwards = false, .lead = .4, .minSpeed=65});
pros::delay(100);
chassis.moveToPoint(-28, 50, 1000, {}, false);
// clear corner and intake 2 rings from corner stack
chassis.turnToHeading(-270, 700);
chassis.moveToPose(-55, 50, -270, 2000, {.forwards = false, .minSpeed = 85}, false);
chassis.swingToHeading(-12, lemlib::DriveSide::RIGHT, 700, {}, false);
Doinker.set_value(true);

}

void BluePosQuals(){

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(60,-12, 0);
Mogo.set_value(false);

// score preload
Intake.move(-127);
target = 16100;
chassis.swingToHeading(42, lemlib::DriveSide::RIGHT, 700, {}, false);
target = 0;
pros::delay(300);
IntakePiston.set_value(true);
chassis.turnToPoint(48, 0, 700, {}, false);
Intake.move(127);
chassis.moveToPoint(52, -4, 700, {}, false);
IntakePiston.set_value(false);
chassis.turnToPoint(24, -24, 700, {.forwards = false}, false);
chassis.moveToPoint(24, -24, 300, {.forwards = false}, false);
chassis.moveToPoint(24, -24, 1000, {.forwards = false, .maxSpeed=55}, false);
Mogo.set_value(true);

}

void BlueNegElims(){
BlueTeam=true;
// BLUE NEG W/ ALLIANCE STAKE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(60,12, 180);
Mogo.set_value(false);

// score preload
target = 16100;
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(24, 23, 700, { .forwards = false}, false);
chassis.moveToPoint(24, 28, 99999, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(7, 64, 0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(7, 65, 0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(26, 26, 330, 1500, {.forwards = false, .lead = .4, .minSpeed=70});
pros::delay(100);
chassis.moveToPoint(30, 47, 1000, {}, false);
pros::delay(400);
//clear corner and intake 2 rings from corner stack
chassis.moveToPose(60, 65, 45, 1250, {.lead = .2, .minSpeed=85});
pros::delay(200);
Doinker.set_value(true);
chassis.turnToHeading(180, 1000, {.minSpeed=80}, false);
pros::delay(400);
//chassis.moveToPoint(48, 30, 1000, {}, false);

}

void DriveFwd(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(0,0, 180);
    chassis.moveToPoint(0, 12, 1000, {.forwards = false, .maxSpeed = 100});
}

void RedFakeRush(){
    //Red Fake Rush
    // set up

 RedTeam = true;
 BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-49.643,-36.256, 108.13);
Mogo.set_value(false);
//Drive to Ring
Intake.move(127);
chassis.moveToPoint(-24, -48, 1000, {}, false);
//Turn to Mogo and Clamp
chassis.turnToPoint(-22, -24, 700, {.forwards = false}, false);
chassis.moveToPoint(-22, -24, 1000, {.forwards = false, .maxSpeed = 60}, false);
Mogo.set_value(true);
pros::delay(150);
//Score Ring
//Turn to Alliance Stake Stack
chassis.turnToPoint(-48,0, 700, {});
IntakePiston.set_value(true);
chassis.moveToPoint(-48, 0, 1000);
Hook.move(-127);
IntakePiston.set_value(false);
//Corner Stack
// chassis.turnToPoint(-25, -55, 700, {.forwards = false});
chassis.moveToPoint(-25, -55, 2000, {.forwards = false, .minSpeed = 70});
pros::delay(200);
Hook.move(0);
chassis.turnToPoint(-54, -65, 700);
chassis.moveToPoint(-59, -65, 2500, {.maxSpeed = 80});
Hook.move(-127);
//Clear Stack
Doinker.set_value(true);
Hook.move(0);
chassis.turnToHeading(340, 700, {.minSpeed = 115}, false);
Doinker.set_value(false);
Hook.move(-127);
//Intake Ring 1
chassis.moveToPoint(-69, -44, 1000, {});
//chassis.moveToPoint(-63, -50, 700, {}, false);
//Turn to stack
chassis.turnToPoint(-70, -62, 700, {});
chassis.moveToPoint(-70, -62, 1000, {},false);
//BACKSHOTS
// chassis.moveToPoint(-66, -50, 1000, {.forwards = false}, false);
// chassis.moveToPoint(-66, -62, 1000);
//Corner
chassis.turnToPoint(-48, -48, 700, {}, false);
pros::delay(500);
Mogo.set_value(false);
pros::delay(50);
chassis.moveToPoint(-64, -64, 1000, {.forwards = false});
//Ladder
chassis.moveToPoint(-16, -16 , 1500, {}, false);
chassis.turnToHeading(-80, 700);

}
