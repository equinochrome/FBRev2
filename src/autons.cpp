#include "devices.h"
#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep
#include <cstdio>

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

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}


void liftControl() {
    double kp = .015;
    double error = target - rotationSensor3.get_position();
    double velocity = kp * error;
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
chassis.moveToPose(7, 69, 0, 1000, {.minSpeed = 30});
//score ring from single 2 ring stack
chassis.moveToPose(26, 26, 330, 1500, {.forwards = false, .lead = .4, .minSpeed=70});
pros::delay(100);
chassis.moveToPoint(30, 47, 1000, {}, false);
pros::delay(400);
// score ring from 2 ring stack near alliance stake; ring on top of the stack. begin lb ladder touch
IntakePiston.set_value(true);
LB.move_relative(1200, 127);
chassis.moveToPose(48, 6, 180, 3000, {.lead = .4, .minSpeed = 70}, false);
IntakePiston.set_value(false);
target=6000;

// touch ladder
chassis.moveToPose(15, 9, 45, 4000, {.forwards = false, .lead = .4, .minSpeed=70}, false);

// print coordinates to console
while(true){
}
};

void BluePos2(){
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
chassis.moveToPoint(22, 24.5, 2000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700);
Hook.move(-127);
Intake.move(127);
chassis.moveToPose(7, 64, 0, 2000, {.minSpeed = 40, .earlyExitRange = 1});
chassis.moveToPose(7, 66, 0, 1000, {.minSpeed = 30});
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
chassis.turnToPoint(20, -24, 700, { .forwards = false, .minSpeed = 60, .earlyExitRange = 3}, false);
//Hook.move(0);
//Intake.move(0);
chassis.moveToPoint(20, -27, 2000, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
Hook.move(-127);
Intake.move(127);
//chassis.turnToPoint(24, -48, 700);
target=6000;
chassis.moveToPose(24, -50, 180, 2000, {.lead = .4, .minSpeed = 80}, false);
chassis.moveToPose(14, -14, 200, 2000, {.forwards=false, .lead = .2, .minSpeed = 90}, false);



}

void skills(){

// 9123C SKILLS ROUTINE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = false;
RedTeam = true;
chassis.setPose(62.75,0, 270);
target = 300;
Mogo.set_value(false);

// score preload on alliance stake
Hook.move(-127);
pros::delay(300);
// grab mobile goal
chassis.moveToPoint(48, 0, 1000, {} , false);
Hook.move(0);
chassis.turnToHeading(180, 700);
chassis.moveToPoint(48, 24, 1000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
// score first ring
chassis.turnToHeading(270, 700, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(28, 26, 1000);
// place ring in wall stake mechanism
chassis.turnToPoint(-24, 48, 700, {}, false);
target=3700;
chassis.moveToPoint(-24, 48, 1250);
// score wall stake and intake second ring to mobile goal
chassis.turnToPoint(-3, 44, 700, {.forwards = false}, false);
chassis.moveToPoint(-3, 44, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.turnToHeading(0, 700, {}, false);
Hook.move(-80);
chassis.moveToPoint(-2.2, 66, 800, {}, false);
Hook.move_relative(75, 127);
target=16100;
pros::delay(500);
// score third through fifth rings
chassis.moveToPoint(-2.2, 48, 1000, {.forwards = false}, false);
chassis.turnToPoint(60, 48, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(36, 48, 750);
chassis.moveToPoint(60, 48, 3000, {.maxSpeed=70});
pros::delay(200);
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
target=100;
// grab second mobile goal
chassis.moveToPoint(48.5, 56, 1000);
chassis.turnToHeading(0, 700, {}, false);
chassis.moveToPoint(48.5, 0, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.moveToPoint(48.5, -24, 1500, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
// score first ring
chassis.turnToHeading(270, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(31, -26, 1000);
// primee wall stake and load with ring
chassis.turnToPoint(-28, -48, 700, {}, false);
chassis.moveToPoint(-28, -48, 1250, {}, false);
target=3700;
// move to wall stake
chassis.turnToPoint(-1, -44, 700, {.forwards = false}, false);
chassis.moveToPoint(-1, -44, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.turnToHeading(180, 700, {}, false);
Hook.move(-80);
chassis.moveToPoint(-1, -66, 800, {}, false);
Hook.move_relative(75, 127);
target=16100;
pros::delay(500);
// score third through fifth rings
chassis.moveToPoint(-1.65, -48, 1000, {.forwards = false}, false);
chassis.turnToPoint(60, -48, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(36, -48, 750);
chassis.moveToPoint(60, -48, 3000, {.maxSpeed=70});
pros::delay(200);
// score sixth ring
chassis.turnToPoint(52, -60, 700);
chassis.moveToPoint(52, -60, 1000);
pros::delay(200);
// drop mobile goal into corner
chassis.turnToPoint(58, -63, 700, {.forwards = false});
chassis.moveToPoint(58, -63, 600, {. forwards=false}, false);
Mogo.set_value(false);
pros::delay(50);
Hook.move(127);
target=100;
// grab a mobile goal with blue ring
chassis.moveToPoint(-12, -54, 1250, {}, false);
chassis.turnToPoint(-60, -24, 700, {.forwards = false}, false);
Intake.move(-127);
chassis.moveToPoint(-60, -26, 600, {.forwards = false, .minSpeed = 127}, false);
chassis.moveToPoint(-60, -26, 1800, {.forwards = false, .maxSpeed = 60}, false);
Mogo.set_value(true);
pros::delay(100);
//Push into corner
chassis.turnToPoint(-68, -48, 700, {.forwards = false}, false);
Mogo.set_value(false);
Intake.move(127);
chassis.moveToPoint(-63, -54, 1000, {.forwards = false}, false);
//Get ring & Get empty goal
pros::delay(100);
chassis.turnToPoint(-48, -50, 800);
chassis.moveToPoint(-48, -50, 1250);
Hook.move(0);
chassis.moveToPoint(-64, -54, 1000, {.forwards=false});
chassis.turnToPoint(-24, -24, 700);
Hook.move_relative(-500, 127);
chassis.moveToPoint(-24, -24, 1500);
chassis.turnToPoint(-45, 0, 700, {.forwards = false}, false);
chassis.moveToPoint(-46 , 0, 2000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
chassis.turnToPoint(-24, 24, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(-24, 24, 1000, {}, false);
chassis.turnToPoint(-28, 48, 700);
chassis.moveToPoint(-28, 52, 1000);
chassis.turnToHeading(270, 700);
chassis.moveToPoint(-58, 52, 1000);
pros::delay(250);
chassis.turnToPoint(-32, 57, 700, {.forwards=false});
chassis.moveToPoint(-32, 60, 1000, {.forwards=false});
chassis.turnToPoint(-62, 69, 700);
chassis.moveToPoint(-62, 69, 1000);
chassis.turnToHeading(135, 1500, {.minSpeed=80}, false);
chassis.moveToPoint(-68, 70, 500,{.forwards=false}, false);
Mogo.set_value(false);
pros::delay(500);
chassis.moveToPoint(-27, 27, 1000, {}, false);
target=16100;
chassis.turnToPoint(0, 0, 700, {.forwards=false});
chassis.moveToPoint(0, 0, 9999, {.forwards=false});

}


void BlueMidRush1(){
//Set up for BLUEMIDRUSH (QUALS)
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
RedTeam = false;
chassis.setPose(49.643,-60.256, 288.13);
Intake.move(127);
Mogo.set_value(false);
Doinker.set_value(true);
//Get mid mogo
chassis.moveToPoint(21, -50.88974, 1000, {.minSpeed = 127}, false);
Doinker.set_value(false);
pros::delay(290);
chassis.moveToPoint(30 ,-50.175, 15000, {.forwards=false}, false);
Doinker.set_value(true);
pros::delay(50);
chassis.turnToPoint(22, -24, 700, {.forwards=false}, false);
chassis.moveToPoint(22, -24, 1000, {.forwards=false, .maxSpeed=60}, false);
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
Hook.move(0);
chassis.moveToPoint(50, -60, 700, {}, false);
chassis.moveToPoint(36, -60 , 1000, {.maxSpeed = 100});
Mogo.set_value(false);
pros::delay(50);
chassis.turnToPoint(24, -24, 700);
Hook.move_absolute(20000, -127);
chassis.moveToPoint(24, -24, 1000, {}, false);
chassis.turnToPoint(13, -46, 1000, {.forwards=false});
chassis.moveToPoint(10, -55, 3500, {.forwards = false, .maxSpeed = 60}, false);
Mogo.set_value(true);
chassis.moveToPose(36, -45, 90, 10000);
pros::delay(300);
Hook.move(-127);
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
chassis.moveToPoint(60, 24, 1000);
chassis.turnToHeading(0, 500, {lemlib::AngularDirection::CW_CLOCKWISE});
chassis.moveToPoint(60, 45 , 700);
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
    //REd Mid rush ladder touch
// set up
RedTeam = true;
BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-49.643,-36.256, 108.13);
Mogo.set_value(false);


Doinker.set_value(true);
Intake.move(127);
chassis.moveToPoint(-21, -45.06069, 1000, {.minSpeed=127}, false);
Doinker.set_value(false);
pros::delay(300);
chassis.moveToPoint(-30, -42.15599, 1000, {.forwards=false}, false);
Doinker.set_value(true);
pros::delay(20);
chassis.turnToHeading(90, 500, {}, false);
Doinker.set_value(false);
pros::delay(100);
chassis.moveToPoint(-22, -42.15599, 700);
chassis.turnToPoint(-22, -22, 700, {.forwards=false});
chassis.moveToPoint(-23, -22, 1000, {.forwards=false, .maxSpeed=60}, false);
Mogo.set_value(true);
pros::delay(100);
Hook.move(-127);
chassis.moveToPoint(-22, -56, 1000);
chassis.swingToHeading(270, lemlib::DriveSide::RIGHT, 700, {}, false);
Doinker.set_value(true);
chassis.moveToPoint(-53, -67, 1000, {}, false);
Hook.move(0);
chassis.turnToHeading(330, 1000, {.minSpeed=100}, false);
pros::delay(50);
Hook.move(-127);
Doinker.set_value(false);
chassis.moveToPoint(-58, -38, 1000);
chassis.swingToHeading(241, lemlib::DriveSide::RIGHT, 700, {}, false);
chassis.moveToPoint(-61, -59, 700, {}, false);
Hook.move(0);
Hook.move(0);

Hook.move(0);

Hook.move(0);


chassis.turnToPoint(-20, -22, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed=80});
pros::delay(200);
Mogo.set_value(false);
Intake.move(0);
chassis.moveToPoint(-24, -24, 1000, {}, false);
chassis.turnToPoint(-9, -40, 700, {.forwards=false});
chassis.moveToPoint(-9, -44, 1000, {.forwards=false, .maxSpeed = 80}, false);
Mogo.set_value(true);
pros::delay(100);
Hook.move(-127);
chassis.moveToPose(-30, -45, -90, 10000);

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
IntakePiston.set_value(true);
LB.move_relative(1200, 127);
chassis.moveToPose(-48, 6, -180, 3000, {.lead = .4, .minSpeed = 70}, false);
IntakePiston.set_value(false);
target=6000;

// touch ladder
chassis.moveToPose(-12, 8, -45, 4000, {.forwards = false, .lead = .4, .minSpeed=70}, false);

}

void RedSoloAWP(){
    //Red Solo AWP

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
chassis.turnToPoint(-22, 25, 700, { .forwards = false}, false);
chassis.moveToPoint(-22, 25, 500, { .forwards = false}, false);
chassis.moveToPoint(-22, 25, 2000, { .forwards = false, .maxSpeed = 50}, false);
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
chassis.moveToPoint(-20, -24.5, 2000, { .forwards = false, .maxSpeed = 50}, false);
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
