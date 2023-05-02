#define IR_SENSOR_ONE 2
#define IR_SENSOR_TWO 3
#define IR_SENSOR_THREE 4
#define REED_SENSOR_ONE 5
#define REED_SENSOR_TWO 6
#define CONVER_MOTOR 9  //<----------------PID PIN
#define CONVER_MOTOR_PWM 10
#define BRACK_CYLINDER_SOLENOID 7
#define PUSHER_CYLINDER_SOLENOID 8
#define FUSHER_BORD_WRITE 12
#define STEPPER_BORD_READ 11
#define GREEN_LIGHT A0
#define RED_LIGHT A1
#define ALARM A2

const int TIME_ONE = 200;  //<---------------EPPEOM CHANGE VALUE
int STETUS = 0;
int STETUS_S = 0;
int PUSHER_PULES = 0;

int IR_SENSOR_ONE_VALUE = 0;
int IR_SENSOR_TWO_VALUE = 0;
int IR_SENSOR_THREE_VALUE = 0;
int REED_SENSOR_ONE_VALUE = 0;
int REED_SENSOR_TWO_VALUE = 0;
int STEPPER_BORD_READ_VALUE = 0;

void setup() {

  Serial.begin(9600);
  pinMode(IR_SENSOR_ONE, INPUT);
  pinMode(IR_SENSOR_TWO, INPUT);
  pinMode(IR_SENSOR_THREE, INPUT);
  pinMode(REED_SENSOR_ONE, INPUT);
  pinMode(REED_SENSOR_TWO, INPUT);
  pinMode(CONVER_MOTOR, OUTPUT);
  pinMode(CONVER_MOTOR_PWM, OUTPUT);
  pinMode(BRACK_CYLINDER_SOLENOID, OUTPUT);
  pinMode(PUSHER_CYLINDER_SOLENOID, OUTPUT);
  pinMode(FUSHER_BORD_WRITE, OUTPUT);
  pinMode(STEPPER_BORD_READ, INPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(ALARM, OUTPUT);
}

void loop() {
  IR_SENSOR_ONE_VALUE = digitalRead(IR_SENSOR_ONE);
  IR_SENSOR_TWO_VALUE = digitalRead(IR_SENSOR_TWO);
  IR_SENSOR_THREE_VALUE = digitalRead(IR_SENSOR_THREE);
  REED_SENSOR_ONE_VALUE = digitalRead(REED_SENSOR_ONE);
  REED_SENSOR_TWO_VALUE = digitalRead(REED_SENSOR_TWO);
  STEPPER_BORD_READ_VALUE = digitalRead(STEPPER_BORD_READ);

  /*Serial.print("IR_SENSOR_ONE_VALUE :-");
    Serial.print(IR_SENSOR_ONE_VALUE);
    Serial.print("\t");
    Serial.print("IR_SENSOR_TWO_VALUE :-");
    Serial.print(IR_SENSOR_TWO_VALUE);
    Serial.print("\t");
    Serial.print("IR_SENSOR_THREE_VALUE :-");
    Serial.print(IR_SENSOR_THREE_VALUE);
    Serial.print("\t");
    Serial.print("REED_SENSOR_ONE_VALUE :-");
    Serial.print(REED_SENSOR_ONE_VALUE);
    Serial.print("\t");
    Serial.print("REED_SENSOR_TWO_VALUE :-");
    Serial.println(REED_SENSOR_TWO_VALUE);*/


  if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 0 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
    //analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 101;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 0 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 101;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 101 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 1);
    //analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 1;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 1 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 1 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 2;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 1 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 2;
  }
  //////////////////////////////////////////////////REEOR/////////////////////////////
  else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 2 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
    //analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 1023);
    analogWrite(ALARM, 1023);
    delay(500);
    STETUS_S = 44;
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
    //analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(500);
    STETUS_S = 44;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS_S == 44 && STEPPER_BORD_READ_VALUE == 0) {
    delay(TIME_ONE);
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    STETUS = 5;
  }
  ///////////////////////////////////////////////////////////////////////////////////
  else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 1 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 2 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 3;
  }
  //////////////////////////////////////////////////REEOR/////////////////////////////
  else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 1 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 3 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 1023);
    analogWrite(ALARM, 1023);
    delay(500);
    STETUS_S = 45;
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(500);
    STETUS_S = 45;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS_S == 45 && STEPPER_BORD_READ_VALUE == 0) {
    delay(TIME_ONE);
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    STETUS = 5;
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 1 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 2 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 3;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 1 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 3 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 4;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 3 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 4;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 3 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS_S = 47;
  }
  //////////////////////////////////////////////////REEOR/////////////////////////////
  else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS_S == 47 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 1023);
    analogWrite(ALARM, 1023);
    delay(500);
    STETUS_S = 48;
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(500);
    STETUS_S = 48;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS_S == 47 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 1023);
    analogWrite(ALARM, 1023);
    delay(500);
    STETUS_S = 48;
    digitalWrite(BRACK_CYLINDER_SOLENOID, 0);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 0);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(500);
    STETUS_S = 48;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS_S == 48 && STEPPER_BORD_READ_VALUE == 0) {
    delay(TIME_ONE);
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    STETUS = 5;
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 4 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 1);
   // analogWrite(CONVER_MOTOR_PWM, 191);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(TIME_ONE);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 5;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 4 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 1);
  //  analogWrite(CONVER_MOTOR_PWM, 191);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(TIME_ONE);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 5;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 5 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 6;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 1 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 5 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 6;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 6 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
 //   analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 7;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 6 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 7;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 1 && STETUS == 7 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
   // analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 8;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 1 && STETUS == 7 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 8;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 8 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 9;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 0 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 8 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
  //  analogWrite(CONVER_MOTOR_PWM, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 9;
  } else if (IR_SENSOR_ONE_VALUE == 0 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 9 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    digitalWrite(FUSHER_BORD_WRITE, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(1000);
    digitalWrite(FUSHER_BORD_WRITE, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 0;
  } else if (IR_SENSOR_ONE_VALUE == 1 && IR_SENSOR_TWO_VALUE == 0 && IR_SENSOR_THREE_VALUE == 0 && REED_SENSOR_ONE_VALUE == 1 && REED_SENSOR_TWO_VALUE == 0 && STETUS == 9 && STEPPER_BORD_READ_VALUE == 0) {
    digitalWrite(BRACK_CYLINDER_SOLENOID, 1);
    digitalWrite(CONVER_MOTOR, 0);
    digitalWrite(PUSHER_CYLINDER_SOLENOID, 0);
    digitalWrite(FUSHER_BORD_WRITE, 1);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    delay(1000);
    digitalWrite(FUSHER_BORD_WRITE, 0);
    analogWrite(GREEN_LIGHT, 1023);
    analogWrite(RED_LIGHT, 0);
    analogWrite(ALARM, 0);
    STETUS = 0;
  }
}
