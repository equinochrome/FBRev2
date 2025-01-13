#include "devices.h"
#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep
#include "robodash/views/console.hpp" //IWYU pragma: keep
#include <cstdio>

const int numStates = 3;
//make sure these are in centidegrees (1 degree = 100 centidegrees)
int states[numStates] = {50, 3700, 16100};
int currState = 0;
int target = 0;


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

void focus();



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
target = 16100;
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(24, 23, 700, { .forwards = false}, false);
chassis.moveToPoint(24, 28, 99999, { .forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(200);
// score 2 rings from middle 4 ring stacks
chassis.turnToHeading(325, 700);
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
chassis.moveToPose(14, 12, 45, 4000, {.forwards = false, .lead = .4, .minSpeed=70}, false);

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
target = 16100;
chassis.swingToHeading(138, lemlib::DriveSide::LEFT, 700, {}, false);
target=0;
//grab mogo
chassis.turnToPoint(24, 24, 700, { .forwards = false}, false);
chassis.moveToPoint(24, 24, 2000, { .forwards = false, .maxSpeed = 70}, false);
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
chassis.moveToPoint(20, -22.5, 2000, { .forwards = false, .maxSpeed = 80}, false);
Mogo.set_value(true);
pros::delay(50);
Hook.move(-127);
Intake.move(127);
//chassis.turnToPoint(24, -48, 700);
target=6000;
chassis.moveToPose(24, -50, 180, 2000, {.lead = .4, .minSpeed = 80}, false);
chassis.moveToPoint(8, -12, 3000, {.forwards = false}, false);

// print coordinates to console

}

void skills(){

// 9123C SKILLS ROUTINE

// set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
BlueTeam = false;
chassis.setPose(62.75,0, 270);
target = 300;

// score preload on alliance stake
Hook.move(-127);
pros::delay(300);
// grab mobile goal
chassis.moveToPoint(48, 0, 1000, {} , false);
Hook.move(0);
chassis.turnToHeading(180, 700);
chassis.moveToPoint(50, 24, 1000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
// score first ring
chassis.turnToHeading(270, 700, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(30, 25, 1000);
// place ring in wall stake mechanism
chassis.turnToPoint(-24, 48, 700, {}, false);
target=3700;
chassis.moveToPoint(-24, 48, 1250);
// score wall stake and intake second ring to mobile goal
chassis.turnToPoint(-1, 44, 700, {.forwards = false}, false);
chassis.moveToPoint(-1, 44, 1000, {.forwards = false}, false);
chassis.turnToHeading(0, 700, {}, false);
chassis.moveToPoint(-1, 66, 800, {}, false);
Hook.move_relative(50, 127);
target=16100;
pros::delay(500);
// score third through fifth rings
chassis.moveToPoint(-1, 51, 1000, {.forwards = false}, false);
chassis.turnToPoint(58, 51, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(36, 51, 750);
chassis.moveToPoint(60, 51, 3000, {.maxSpeed=70});
pros::delay(200);
// score sixth ring
chassis.turnToPoint(48, 60, 700);
chassis.moveToPoint(48, 60, 1000);
pros::delay(200);
// drop mobile goal into corner
chassis.turnToPoint(59, 61, 700, {.forwards = false});
chassis.moveToPoint(58.5, 61, 1000, {. forwards=false}, false);
Mogo.set_value(false);
pros::delay(50);
Hook.move(127);
target=100;
// grab second mobile goal
chassis.moveToPoint(51, 60, 1000);
chassis.turnToHeading(0, 700, {}, false);
chassis.moveToPoint(51, 0, 1000, {.forwards = false}, false);
Hook.move(0);
chassis.moveToPoint(51, -26, 1500, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(100);
// score first ring
chassis.turnToHeading(270, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(28, -26, 1000);
// primie wall stake and load with ring
chassis.turnToPoint(-24, -52, 700, {}, false);
target=3700;
chassis.moveToPoint(-24, -52, 1250);
// score ring on neutral wall stake and score second ring on mobile goal
chassis.turnToPoint(1, -44, 700, {.forwards = false}, false);
chassis.moveToPoint(1, -44, 1000, {.forwards = false}, false);
chassis.turnToHeading(180, 700);
chassis.moveToPoint(1, -66, 700, {}, false);
Hook.move_relative(75, 127);
target=16100;
pros::delay(500);
// score third through fifth rings
chassis.moveToPoint(1, -50, 1000, {.forwards = false}, false);
chassis.turnToPoint(58, -50, 700, {}, false);
Hook.move(-127);
chassis.moveToPoint(36, -50, 750);
chassis.moveToPoint(60, -50, 3000, {.maxSpeed=70});

}


void BlueMidRush1(){
//Set up for BLUEMIDRUSH (QUALS)
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(51.25,-37, 270);
//Get mid mogo
chassis.moveToPoint(16, -36, 1500, {.minSpeed = 127}, false);
pros::delay(50);
Doinker.set_value(true);
chassis.moveToPose(14.5, -36, 225, 80, {.minSpeed= 90, .earlyExitRange= 1});
chassis.turnToHeading(170, 750);
pros::delay(200);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(30, -24.5, 700, {.forwards = false, .minSpeed = 80});
chassis.moveToPoint(30, -24.5, 1000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(50);
///Stack
chassis.turnToPoint(60, 0, 900, {}, false);
Hook.move(-127);
chassis.moveToPoint(60, 0, 1000);
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
chassis.turnToPoint(26.5, -32.5, 700, {});
chassis.moveToPoint(26.5, -32.5, 1200, {});
chassis.turnToPoint(14, -52.25, 700, {.forwards=false}); 
chassis.moveToPoint(14, -63, 1500, {.forwards=false, .maxSpeed = 60}, false   );
Mogo.set_value(true); 
pros::delay(50);
//Stack
Hook.move(-127);
chassis.turnToHeading(75, 700);
chassis.moveToPoint(24, -48, 1000, {}, false);
chassis.moveToPoint(24, -14, 1000);
// 4 ring stacks disrupt
Doinker.set_value(true);
chassis.turnToHeading(55, 700, {.maxSpeed = 70});





}


void BlueMidRushExtropy(){
//Set up for BLUEMIDRUSH (EXTROPY ELIMS ROUTE
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(51.25,-37, 270);
//Get mid mogo
chassis.moveToPoint(16, -36, 1500, {.minSpeed = 127}, false);
pros::delay(50);
Doinker.set_value(true);
chassis.moveToPose(14.5, -36, 225, 80, {.minSpeed= 90, .earlyExitRange= 1});
chassis.turnToHeading(170, 750);
pros::delay(200);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(30, -24.5, 700, {.forwards = false, .minSpeed = 80});
chassis.moveToPoint(30, -24.5, 1000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(50);
///Stack
chassis.turnToPoint(60, 0, 900, {}, false);
Hook.move(-127);
chassis.moveToPoint(60, 0, 1000);
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
chassis.turnToPoint(26.5, -32.5, 700, {});
chassis.moveToPoint(26.5, -32.5, 1200, {});
chassis.turnToPoint(14, -52.25, 700, {.forwards=false}); 
chassis.moveToPoint(14, -63, 1500, {.forwards=false, .maxSpeed = 60}, false   );
Mogo.set_value(true); 
pros::delay(50);
//Stack
Hook.move(-127);
chassis.turnToHeading(75, 700);
chassis.moveToPoint(24, -48, 1000, {}, false);
chassis.moveToPoint(15, -55, 1000, {.forwards = false});

}

void BlueMidRushPOSCORNER(){
 //Set up for BLUEMIDRUSH (CORNER RUSH)
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(51.25,-37, 270);
//Get mid mogo
chassis.moveToPoint(16, -36, 1500, {.minSpeed = 127}, false);
pros::delay(50);
Doinker.set_value(true);
chassis.moveToPose(14.5, -36, 225, 80, {.minSpeed= 90, .earlyExitRange= 1});
chassis.turnToHeading(170, 750);
pros::delay(200);
Doinker.set_value(false);
//Get 2nd mogo
chassis.turnToPoint(30, -24.5, 700, {.forwards = false, .minSpeed = 80});
chassis.moveToPoint(30, -24.5, 1000, {.forwards = false, .maxSpeed = 50}, false);
Mogo.set_value(true);
pros::delay(50);
///Stack
chassis.turnToPoint(60, 0, 900, {}, false);
Hook.move(-127);
chassis.moveToPoint(60, 0, 1000);
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
chassis.turnToPoint(26.5, -32.5, 700, {});
chassis.moveToPoint(26.5, -32.5, 1200, {});
chassis.turnToPoint(14, -52.25, 700, {.forwards=false}); 
chassis.moveToPoint(14, -63, 1500, {.forwards=false, .maxSpeed = 60}, false   );
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
chassis.turnToHeading(0, 700, {lemlib::AngularDirection::CW_CLOCKWISE});
chassis.moveToPoint(60, 45 , 700);
Intake.move(80);
chassis.moveToPoint(55, 16, 1000, {.forwards = false}, false);
target = 16100;
//Turn to goal
chassis.turnToPoint(22, 27, 800, { .forwards = false});
chassis.moveToPoint(22, 27, 2000, { .forwards = false, .maxSpeed = 50}, false);
//Grab and turn to ring
Mogo.set_value(true);
pros::delay(100);
chassis.turnToPoint(16, 55, 1000, {}, false);
Hook.move(-127);
Intake.move(127);
chassis.moveToPoint(16, 55, 1000, {}, false);
pros::delay(500);
chassis.turnToPoint(44, 10, 700, {}, false);
IntakePiston.set_value(true);
chassis.moveToPoint(44, 10, 1500, {}, false);
IntakePiston.set_value(false);
chassis.moveToPoint(16, 24, 4000, {.forwards=false, .minSpeed=70});
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
chassis.setPose(-51.25,-37, 90);
//Grab mid mogo
chassis.moveToPoint(-20.3, -36, 1500, {.minSpeed = 127});
pros::delay(700);
chassis.turnToHeading(-140 , 750);
pros::delay(130);
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
//Ladder
Intake.move(-127);
chassis.moveToPoint(-20, -13,1000, {}, false);
Doinker.set_value(true);
chassis.turnToHeading(65, 1000, {.maxSpeed = 70});
}

void RedMidRushExtropy(){
    //RED MID RUSH EXTROPY
// set up
RedTeam = true;
BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-51.25,-37, 90);
//Grab mid mogo
chassis.moveToPoint(-20.3, -36, 1500, {.minSpeed = 127});
pros::delay(700);
chassis.turnToHeading(-140 , 750);
pros::delay(140);
Doinker.set_value(true);
pros::delay(500);
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
chassis.moveToPoint(-10, -60, 1000, {.forwards = false});


}
void RedMidRushPOSCORNER(){
//Red Mid Rush Pos Corner
 // set up
RedTeam = true;
BlueTeam=false;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
LB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
chassis.setPose(-51.25,-37, 90);
//Grab mid mogo
chassis.moveToPoint(-20.3, -36, 1500, {.minSpeed = 127});
pros::delay(700);
chassis.turnToHeading(-140 , 750);
pros::delay(135);
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
}

void RedSoloAWP(){
    //Red Solo AWP
}
void RedSoloAWPPush(){
 //RedSoloAWAPPush
}

