#include "devices.h"
#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep


void test(){
chassis.setPose(0,0,0);

pros::delay(5000);


   

}

void test2(){
    Mogo.set_value(true);
    Hook.move(127);
    while(1){
    if(color.get_hue() > 30){
        Hook.move(-127);
    } else{
        pros::delay(180);
        Hook.move(127);
        pros::delay(20);
    }
    }
};

void BlueNeg4Ring(){
BlueTeam=true;
// BLUE NEG W/ ALLIANCE STAKE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(60,12, 180);

// score preload
LB.move(-127);
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
//grab mogo
chassis.turnToHeading(120, 250);
chassis.moveToPoint(22, 29, 2000, { .forwards = false, .maxSpeed = 80}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(7, 64, 0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(7, 67, 0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(26, 26, 330, 1500, {.forwards = false, .lead = .4, .minSpeed=70});
pros::delay(100);
chassis.moveToPoint(30, 45, 1000, {}, false);
pros::delay(400);
// score ring from 2 ring stack near alliance stake; ring on top of the stack. begin lb ladder touch
IntakePiston.set_value(true);
LB.move_relative(1200, 127);
chassis.moveToPose(48, 6, 180, 3000, {.lead = .4, .minSpeed = 70}, false);
IntakePiston.set_value(false);
// touch ladder
chassis.moveToPose(14, 12, 45, 4000, {.forwards = false, .lead = .4, .minSpeed=70}, false);
LB.brake();

// print coordinates to console
while(true){
}
};

void BluePos2(){
BlueTeam=true;

// BLUE NEG SOLO NO PUSH

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = true;
chassis.setPose(60,12, 180);

// score preload
LB.move(-127);
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
//grab mogo
chassis.turnToHeading(120, 250);
chassis.moveToPoint(22, 29, 2000, { .forwards = false, .maxSpeed = 80}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(6.5, 64, 0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(6.5, 67, 0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(28, 27, 330, 1500, {.forwards = false, .lead = .4, .minSpeed=65});
pros::delay(100);
chassis.moveToPoint(28, 50, 1000, {}, false);
// score ring from 2 ring stack near alliance stake; ring on top of the stack
pros::delay(300);
IntakePiston.set_value(true);
LB.move_relative(1350, 127);
chassis.moveToPose(50, 0, 180, 3000, {.lead = .4, .minSpeed = 80}, false);
Mogo.set_value(false);
Hook.move(127);
chassis.moveToPoint(48, -6, 2000, {.maxSpeed = 60}, false);
IntakePiston.set_value(false);
chassis.turnToPoint(24, -24, 700, { .forwards = false, .minSpeed = 60, .earlyExitRange = 3}, false);
//Hook.move(0);
//Intake.move(0);
chassis.moveToPoint(20, -20, 2000, { .forwards = false, .maxSpeed = 80}, false);
Mogo.set_value(true);
pros::delay(50);
Hook.move(-127);
Intake.move(127);
//chassis.turnToPoint(24, -48, 700);
chassis.moveToPose(24, -50, 180, 2000, {.lead = .4, .minSpeed = 80}, false);
//chassis.moveToPoint(8, -12, 3000, {.forwards = false}, false);
//LB.brake();

// print coordinates to console

}


void BlueNeg1(){
    BlueTeam = true;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(62,12, 0);
    chassis.moveToPose(62, 0, 0, 2000, {.forwards = false, .lead = .1, .minSpeed = 60});
    chassis.turnToHeading(270, 800);
    chassis.moveToPose(69.5, 0, 270, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(50, 13, 300, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(105, 1000);
    chassis.moveToPose(34, 23.7, 100, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.turnToHeading(0, 800);
    Hook.move(127);
    Hook.move(-127);
    chassis.moveToPose(36, 40, 345, 2000, {.lead = .25});
    chassis.turnToHeading(270, 800);
    chassis.moveToPose(20, 45, 280, 2000, {.lead = .4});
    chassis.swingToHeading(325, lemlib::DriveSide::LEFT, 800);
    chassis.moveToPose(20, 50, 305, 2000, {.lead = .6});
    pros::delay(500);
    chassis.moveToPose(36, 23.7, 305, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.turnToHeading(305, 800);
    pros::delay(400);
    Hook.move(0);
    Hook.move(0);
    chassis.moveToPose(24, 12, 135, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(400);
};

void RedPos1(){
    //Set up
int future2 = pros::millis() + 10000;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
chassis.setPose(-52,-57, -270);
// Get mogo and drive back

chassis.moveToPose( -15.5, -53.75 , -275, 2000, { .lead = .4, .minSpeed = 127},false);
Doinker.set_value(true);
chassis.moveToPose( -55, -58 , -205, 2000, { .forwards = false,  .lead = .4, .minSpeed = 127});
pros::delay(1600);
Doinker.set_value(false);
chassis.turnToPoint(-44, -55, 700, {.minSpeed = 80, .earlyExitRange= 3});
chassis.moveToPoint(-44, -30, 1000);
chassis.turnToHeading(-90, 700, {.minSpeed = 80, .earlyExitRange= 3});
chassis.moveToPose(-36, -60, -25, 2000, {.forwards= false, .minSpeed = 60}, false);
Mogo.set_value(true);
pros::delay(200);
Hook.move(-127);
pros::delay(1000);
Mogo.set_value(false);
IntakePiston.set_value(true);
//Mogo 2 + Stack by Alliance Stake
Hook.move(-127);
chassis.moveToPose(-50, -8, 30, 2000, {.forwards= true, .minSpeed = 85},  false);
Hook.move(-55);
chassis.swingToHeading(-45, lemlib::DriveSide::LEFT, 700, {.minSpeed = 80, .earlyExitRange= 3}, false);
IntakePiston.set_value(false);
chassis.moveToPose(-12.8, -30.75, -63, 2000, {.forwards = false, .maxSpeed = 54}, false);
Hook.move(0);
Mogo.set_value(true);
pros::delay(200);
Hook.move(-127);
//Grab ring + touch ladder
chassis.turnToHeading(-180, 700);
pros::delay(500);
chassis.moveToPoint(-23, -46, 1000, {}, false);
pros::delay(500);
chassis.moveToPoint(-48, -48, 2000, {}, false);


}


void RedNeg1(){
//SET UP
    BlueTeam = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-62,10.5, 0);
    //ALLIANCE STAKE
    chassis.moveToPose(-62,-1, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(90, 800);
    chassis.moveToPose(-69, -1, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(-50, 13, 120, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(285, 500);
    //GO TO MOGO
    chassis.moveToPose(-23, 23.7, 262, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.turnToHeading(0, 800);
    //GO TO MID STACK
    Hook.move(127);
    Hook.move(-127);
    chassis.moveToPose(-30, 42, -345, 2000, {.lead = .25});
    chassis.turnToHeading(-250, 800);
    chassis.moveToPose(-13, 44, -280, 2000, {.lead = .4});
    chassis.swingToHeading(-325, lemlib::DriveSide::RIGHT, 800);
    chassis.moveToPose(-12.5, 52, -295, 2000, {.lead = .6});
    pros::delay(500);
    chassis.moveToPose(-35 , 24.7, -285, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.turnToHeading(-295, 600);
    pros::delay(400);
    //LADDER TOUCH
    chassis.moveToPose(-18, 8, 135, 1000, {.lead = .25, .minSpeed = 100});
  
}

void RedNeg2(){
//SET UP
    BlueTeam = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-62,10.5, 0);
    //ALLIANCE STAKE
    chassis.moveToPose(-62,-1, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(90, 800);
    chassis.moveToPose(-69, -1, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(-50, 13, 120, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(285, 500);
    //GO TO MOGO
    chassis.moveToPose(-23, 23.7, 262, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.turnToHeading(0, 800);
    //GO TO MID STACK
    Hook.move(127);
    Hook.move(-127);
    chassis.moveToPose(-30, 42, -345, 2000, {.lead = .25});
    chassis.turnToHeading(-250, 800);
    chassis.moveToPose(-13, 44, -280, 2000, {.lead = .4});
    chassis.swingToHeading(-325, lemlib::DriveSide::RIGHT, 800);
    chassis.moveToPose(-12.5, 52, -295, 2000, {.lead = .6});
    pros::delay(500);
    chassis.moveToPose(-35 , 24.7, -285, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.turnToHeading(-295, 800);
    pros::delay(400);
}

void skills(){
    //SETUP
chassis.setPose(-63, 0, 90);
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
//Score Preload
Hook.move(-117);
pros::delay(300); 
// Move forward and get mogo on right
Hook.move(0);
chassis.moveToPose(-50, 0, 90, 2000, {.minSpeed = 50}) ;
chassis.turnToHeading(0, 700);
chassis.moveToPose(-50, -24, 0, 2200, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
//Motion Chaining to get 2 rings
Hook.move(-127);
pros::delay(500);
chassis.moveToPose(-24, -25, 90, 1500);
 chassis.moveToPose(
        -18,
        -25,
        90,
        1000,
        {.minSpeed=72, .earlyExitRange=2}
        // a minSpeed of 72 means that the chassis will slow down as
        // it approaches the target point, but it won't come to a full stop

        // an earlyExitRange of 8 means the movement will exit 8" away from
        // the target point
    );

    // go to target position
    chassis.moveToPose(0, -62, 150, 2000, {.minSpeed = 60});
//Swing 
    chassis.swingToHeading(270, lemlib::DriveSide::LEFT, 700);
//3 Rings and mogo drop
    chassis.moveToPose(-48, -52, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(500);
    chassis.moveToPose(-62, -52, 270, 2000, {.minSpeed = 45}, false);
     chassis.moveToPose(-63, -52, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(1000);
     chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 700);
    chassis.moveToPose(-51, -63,180, 1000, {.minSpeed = 50});
    pros::delay(800);
     chassis.moveToPose(-66, -66, 45, 2000, { .forwards = false, .minSpeed = 60}, false);
    pros::delay(1100);
     Hook.move(0);
    pros::delay(100);

    Mogo.set_value(false);

    pros::delay(100);
  //Mogo 2
    chassis.moveToPose(-50.5, -24, 0, 2000, {.minSpeed = 65});
      Hook.move(-127);
    chassis.turnToHeading(180, 700);
    chassis.moveToPose(-50.5, 20, 180, 2000, { .forwards = false, .minSpeed = 50}, false);
    Mogo.set_value(true);
    Hook.move(-127);
    pros::delay(500);
      chassis.moveToPose(-24, 18, 90, 1000,{ .lead= .5,.minSpeed=72, .earlyExitRange=2});
     // go to target position
    chassis.moveToPose(-8,55, 45, 2000, { .lead= .5,.minSpeed = 60}, false);
    //Swing 
    chassis.swingToHeading(270, lemlib::DriveSide::RIGHT, 700);
//3 Rings and mogo drop
    chassis.moveToPose(-48, 48, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(500);
    chassis.moveToPose(-64, 48, 270, 2000, {.minSpeed = 45}, false);
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 700);
    chassis.moveToPose(-53, 61,0, 2000, {.minSpeed = 50});
chassis.moveToPose(-66.5, 65, 145, 2000, { .forwards = false, .minSpeed = 60}, false);
    pros::delay(1200);
    Mogo.set_value(false);
    pros::delay(100);
    // 1 red ring
    chassis.moveToPose(12, 48, 90, 2000, {.minSpeed = 90});
    chassis.moveToPose(24, 18, 90, 2000, {.minSpeed = 70});
    pros::delay(800);
    Hook.move(0);

    // BLUE MOGO PUSH
    //chassis.moveToPose(48, 18, 60, 2000, {.minSpeed = 70});
    //chassis.moveToPose(60, 58, 0, 2000, {.minSpeed = 70});
    //Hook.move(0);
    //chassis.moveToPose(38, -16, 10, 2000, { .forwards = false, .minSpeed = 50}, false);
    //Mogo.set_value(true);
    //Hook.move(-127);
    //Hook.move(127);

    chassis.turnToHeading(310, 1000);
    chassis.moveToPoint(40.5, -5, 1900, { .forwards = false, .minSpeed = 60}, false);
    Mogo.set_value(true);
    pros::delay(150);
    Hook.move(-117);
    Hook.move(-127);
    pros::delay(1500);
    chassis.moveToPoint(18, -23, 2000, {.minSpeed = 75});
    chassis.moveToPose(15, -50, 135, 2000, {.minSpeed = 60}, false);
    chassis.moveToPose(34, -64, 90, 2000, {.minSpeed = 60}, false);
    pros::delay(500);
    chassis.moveToPose(9, -54, 90, 2000, {.forwards = false, .minSpeed = 60}, false);
    chassis.moveToPose(34, -52, 90, 2000, {.minSpeed = 60}, false);
    chassis.moveToPoint(18, -40, 2000, {.forwards = false, .minSpeed = 75}, false);
    pros::delay(1000);
    Mogo.set_value(false);
    pros::delay(100);
    Hook.move(-127);
    Hook.move(-127);
    chassis.moveToPose(54, 24, 25, 4000, {.minSpeed = 65}, false);
    chassis.moveToPose(59, 56   , 5, 2000, {.minSpeed = 70}, false);
    pros::delay(100);
    chassis.moveToPose(50, 24, 20, 2000, {.forwards = false, .minSpeed = 75});
    pros::delay(100);
    Hook.move(-127);
    Hook.move(0);
    chassis.moveToPose(43, 48, 0, 3000, {.minSpeed = 60}, false);
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.moveToPoint(43, 10, 10000, {.forwards = false, .minSpeed = 100}, false);
    chassis.turnToHeading(270, 1000);
    chassis.moveToPoint(64,1.25, 1500, {.forwards=false, .minSpeed=80}, false);
    pros::delay(500);
    Hook.move(-127);
    pros::delay(2000);
    chassis.moveToPoint(60,1.25, 1500, {.minSpeed=80}, false);
    chassis.turnToHeading(165, 700);
    Hook.move(-127);
    Hook.move(-127);
    chassis.moveToPoint(60,-60, 1500, {.minSpeed=100}, false);
    // chassis.moveToPoint(48, 1.5, 4000, {.forwards = false, .minSpeed = 50}, false);
    // chassis.turnToHeading(270, 1000);

}


void BlueSoloAwp(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(53,32, 0);
//Bump Robor
chassis.moveToPose(50.5, 45, 330, 2500, {.minSpeed = 100});
chassis.moveToPoint(55.5, 34, 1000, {.forwards = false, .minSpeed = 60}, false);
chassis.turnToPoint(24, 24, 700, {.forwards = false});
Hook.move(0);
chassis.moveToPoint(17, 21.25, 2000, {.forwards = false, .maxSpeed = 75}, false);
Mogo.set_value(true);
pros::delay(200);
Hook.move(-127);
pros::delay(400);
chassis.moveToPoint(24, 40, 1500, {}, false);
pros::delay(400);
chassis.moveToPoint(7, 48, 1500, {}, false);
chassis.moveToPoint(24, 38, 1500, {.forwards = false}, false);
pros::delay(400);
chassis.moveToPoint(44, 1.5, 3000, {.maxSpeed = 85});
pros::delay(1000);
IntakePiston.set_value(true);
chassis.moveToPoint(42, 12, 1000, {.forwards = false});
IntakePiston.set_value(false);

}

void RedSoloAwp(){
///Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(-53,32, 0);
//Bump Robor
chassis.moveToPose(-50.5, 45, -330, 2500, {.minSpeed = 100});
// Hook.move(-55);
chassis.moveToPoint(-55.5, 34, 1000, {.forwards = false, .minSpeed = 60}, false);
chassis.turnToPoint(-24, 24, 700, {.forwards = false});
Hook.move(0);
chassis.moveToPoint(- 20, 21.6, 2000, {.forwards = false, .maxSpeed = 75}, false);
Mogo.set_value(true);
pros::delay(200);
Hook.move(-127);
pros::delay(400);
chassis.moveToPoint(-24, 40, 1500, {}, false);
pros::delay(400);
chassis.moveToPoint(-7, 48, 1500, {}, false);
chassis.moveToPoint(-24, 38, 1500, {.forwards = false}, false);
pros::delay(400);
IntakePiston.set_value(true);
chassis.moveToPoint(-42, 0, 3000, { .forwards = false, .maxSpeed = 85}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(-42, 12, 3000, {.maxSpeed = 85});
}

void BlueSigSAwp(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(55.5,12, 0);
//Alliance Stake
chassis.moveToPose(55.5, 1, 3, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(270, 500,{lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.moveToPose(64,4,270, 700,{.forwards=false, .minSpeed=80}, false);
Hook.move(-127);
pros::delay(300);
chassis.moveToPoint(58, 0, 1000, {.minSpeed=80, .earlyExitRange=2});
//Get Mogo on Neg Side + Push Alliance bot
Hook.move(127);
chassis.moveToPose(57, 29, 345, 2000, { .minSpeed= 80, .earlyExitRange=1}, false);
Hook.move(0);
chassis.moveToPose(58, 13, 345, 700, {.forwards=false, .minSpeed=100, .earlyExitRange=1});
chassis.moveToPose(20,34, 120, 4000, { .forwards= false, .lead=.6, .minSpeed=70}, false);
Mogo.set_value(true);
Hook.move(-127);
chassis.moveToPoint(24, 46, 2000, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPoint(24, 36, 1500, { .minSpeed= 65, .earlyExitRange=1}, false);
Mogo.set_value(false);
Hook.move(-127);
//Mogo on Pos Side
chassis.moveToPoint(44, 0, 1500, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPoint(48, -28, 1500, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPose(20, -20, 120, 2000, {.forwards = false, .minSpeed=90}, false);
Mogo.set_value(true);
Hook.move(127);
chassis.moveToPose(24, -60, 180, 2000);

}

void BlueSigSAwp2(){
    //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
LB.move_relative(-30, 127);

BlueTeam = true;
chassis.setPose(55.5,-11.25, 180);
//Alliance Stake
chassis.moveToPose(55.5, -1, 180, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(270, 700);
chassis.moveToPose(70, -1, 270, 700, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
Hook.move(-127);
pros::delay(300);
// push robot and Hook 2nd preload
chassis.moveToPoint(58, 0, 1000, {.minSpeed=100, .earlyExitRange=2});
Hook.move(127);
chassis.moveToPose(57, -29, 205, 2000, { .minSpeed= 100, .earlyExitRange=1}, false);
Hook.move(0);
chassis.moveToPose(58, -13, 180, 700, {.forwards=false, .minSpeed=100, .earlyExitRange=1});
chassis.moveToPose(16,-33, 60, 4000, { .forwards= false, .lead=.6, .minSpeed=60}, false);
Hook.move(-127);
Mogo.set_value(true);
chassis.moveToPoint(24, -46, 2000, { .minSpeed= 100, .earlyExitRange=1}, false);
chassis.turnToHeading(270, 800, { .minSpeed= 80, .earlyExitRange=1}, false);
Mogo.set_value(false);
Hook.move(0);
LB.move_relative(1300, 127);
chassis.moveToPose(6.5, -55.4, 270, 2000, { .minSpeed= 100});
chassis.moveToPose(22, -24, 180, 2000, { .forwards = false, .minSpeed = 100, .earlyExitRange=1}, false);
LB.move_relative(-1300, 127);
chassis.moveToPoint(48, 0, 2000, { .forwards = false,  .minSpeed = 120, .earlyExitRange=1});
chassis.moveToPoint(52, 28, 2000, { .forwards = false,  .minSpeed = 100, .earlyExitRange=1});
chassis.moveToPoint(15, 19.5, 2000, { .forwards = false,  .minSpeed = 80}, false);
Mogo.set_value(true);
Hook.move(-127);
chassis.moveToPoint(14, 30, 1500, { .minSpeed = 100}, false);
pros::delay(400);
LB.move_relative(300, 127);
chassis.moveToPoint(12, 12, 1500, { .minSpeed = 60}, false);



}

void RedSigSAWP(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(-55.5,12, 0);
//Alliance Stake
chassis.moveToPose(-55.5, 1, -3, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(-270, 500,{lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.moveToPose(-64,4,-270, 700,{.forwards=false, .minSpeed=80}, false);
Hook.move(-127);
pros::delay(300);
chassis.moveToPoint(-58, 0, 1000, {.minSpeed=80, .earlyExitRange=2});
//Get Mogo on Neg Side + Push Alliance bot
Hook.move(127);
chassis.moveToPose(-57, 29, -345, 2000, { .minSpeed= 80, .earlyExitRange=1}, false);
Hook.move(0);
chassis.moveToPose(-58, 13, -345, 700, {.forwards=false, .minSpeed=100, .earlyExitRange=1});
chassis.moveToPose(-20,34, -120, 4000, { .forwards= false, .lead=.6, .minSpeed=70}, false);
Mogo.set_value(true);
Hook.move(-127);
chassis.moveToPoint(-24, 46, 2000, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPoint(-24, 36, 1500, { .minSpeed= 65, .earlyExitRange=1}, false);
Mogo.set_value(false);
Hook.move(-127);
//Mogo on Pos Side
chassis.moveToPoint(-44, 0, 1500, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPoint(-48, -28, 1500, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPose(-20, -20, -120, 2000, {.forwards = false, .minSpeed=90}, false);
Mogo.set_value(true);
Hook.move(127);
chassis.moveToPose(-24, -60, -180, 2000);


}

void RedSigSAWP2(){
    //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
LB.move_relative(-30, 127);
BlueTeam = true;
chassis.setPose(-55.5,-11.25, 180);
//Alliance Stake
chassis.moveToPose(-55.5, 0, -180, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(-270, 700);
chassis.moveToPose(-70, 0, -270, 900, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
Hook.move(-127);
pros::delay(300);
chassis.moveToPoint(-58, 0, 1200, {.minSpeed=100, .earlyExitRange=2});
Hook.move(127);
chassis.moveToPose(-57, -29, -205, 2200, { .minSpeed= 100, .earlyExitRange=1}, false);
Hook.move(0);
chassis.moveToPose(-58, -13, -180, 700, {.forwards=false, .minSpeed=100, .earlyExitRange=1});
pros::delay(750);
chassis.moveToPose(-16,-33, -60, 4000, { .forwards= false, .lead=.6, .minSpeed=60}, false);
Hook.move(-127);
Mogo.set_value(true);
chassis.moveToPoint(-24, -46, 2000, { .minSpeed= 100, .earlyExitRange=1}, false);
chassis.turnToHeading(-270, 700, { .minSpeed= 80, .earlyExitRange=1}, false);
Hook.move(0);
Mogo.set_value(false);
LB.move_relative(1300, 127);
chassis.moveToPose(-8, -54, -270, 2000, { .minSpeed= 100});
chassis.moveToPose(-24, -24, -180, 2000, { .forwards = false, .minSpeed = 100, .earlyExitRange=1}, false);
LB.move_relative(-1300, 127);
chassis.moveToPoint(-48, 0, 2000, { .forwards = false,  .minSpeed = 120, .earlyExitRange=1});
chassis.moveToPoint(-52, 28, 2000, { .forwards = false,  .minSpeed = 100, .earlyExitRange=1});
chassis.moveToPoint(-15, 19.5, 2000, { .forwards = false,  .minSpeed = 80}, false);
Mogo.set_value(true);
Hook.move(-127);
chassis.moveToPoint(-14, 30, 1500, { .minSpeed = 100}, false);
pros::delay(400);
LB.move_relative(300, 127);
chassis.moveToPoint(-12, 12, 1500, { .minSpeed = 60}, false);
 
}
void red4ring(){
       //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
chassis.setPose(-50, 36 ,270 );
//Grab Mogo
chassis.moveToPose(-24,24, 280, 2000, {.forwards = false, .minSpeed = 90}, false);
Mogo.set_value(true);
//Move LB push top blue ring and score red ring
LB.move_relative(825, 127);
chassis.moveToPose(-24, 40, 0, 2000, {.earlyExitRange = 2});
Hook.move(127);
Hook.move(-127);
//Ring Stack
chassis.moveToPose(-8, 45, 90, 1000);
pros::delay(100);
chassis.moveToPoint(-15, 45, 1000);
LB.move_relative(-825, 127);
chassis.turnToHeading(80, 1000);
chassis.moveToPoint(-8, 50, 1000);
pros::delay(100);
// Ladder Touch
chassis.moveToPose(-24, -10, 0, 1000, {.forwards = false}, false);
chassis.turnToHeading(180, 100);
pros::delay(100);
}

void blue4ring(){
       //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
chassis.setPose(50, 36 ,-270 );
//Grab Mogo
chassis.moveToPose(24,24, -280, 2000, {.forwards = false, .minSpeed = 90}, false);
Mogo.set_value(true);
//Move LB push top blue ring and score red ring
LB.move_relative(825, 127);
chassis.moveToPose(24, 40, -0, 2000, {.earlyExitRange = 2});
Hook.move(127);
Hook.move(-127);
//Ring Stack
chassis.moveToPose(8, 45, -90, 1000);
pros::delay(100);
chassis.moveToPoint(15, 45, 1000);
LB.move_relative(-825, 127);
chassis.turnToHeading(-80, 1000);
chassis.moveToPoint(8, 50, 1000);
pros::delay(100);
// Ladder Touch
chassis.moveToPose(24, -10, -0, 1000, {.forwards = false}, false);
chassis.turnToHeading(180, 100);
pros::delay(100);
}



