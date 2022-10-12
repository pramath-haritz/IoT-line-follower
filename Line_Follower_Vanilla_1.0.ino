
#define in1 18 //Left_Motor IN1 

#define in2 19 //Left_Motor IN2 

#define in3 16 //Right_Motor IN3 
 
#define in4 17 //Right_Motor IN4

#define ena 26
#define enb 25

#define R_S 2 //Right_IR_Snsor

#define L_S 4 //Left_IR_Sensor

const int frequency = 500;
const int pwm_channel1 = 0;
const int pwm_channel2 = 0;
const int resolution = 8;;

void setup(){ 

Serial.begin(9600);

pinMode(R_S, INPUT); 

pinMode(L_S, INPUT); 

pinMode(in1, OUTPUT); 

pinMode(in2, OUTPUT); 

pinMode(in3, OUTPUT); 

pinMode(in4, OUTPUT); 

pinMode(ena, OUTPUT); 

pinMode(enb, OUTPUT);

ledcSetup(pwm_channel1, frequency, resolution);

ledcSetup(pwm_channel2, frequency, resolution);

ledcAttachPin(ena, pwm_channel1);
ledcAttachPin(enb, pwm_channel2);

ledcWrite(pwm_channel1, 70 );
ledcWrite(pwm_channel2, 70 );

delay(3000);

}

void loop(){  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function

}

 void forward(){  //forword

digitalWrite(in2, HIGH); //Right Motor forword Pin 

digitalWrite(in1, LOW);  //Right Motor backword Pin 

digitalWrite(in4, HIGH);  //Left Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor forword Pin 

}

void turnLeft(){ //turnRight

digitalWrite(in1, HIGH);  //Right Motor forword Pin 

digitalWrite(in2, LOW); //Right Motor backword Pin  

digitalWrite(in3, LOW);  //Left Motor backword Pin 

 digitalWrite(in4, HIGH); //Left Motor forword Pin 


}

void turnRight(){ //turnLeft

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, HIGH);  //Right Motor backword Pin 

digitalWrite(in3, HIGH); //Left Motor backword Pin 

digitalWrite(in4, LOW);  //Left Motor forword Pin 


}

void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, LOW); //Right Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor backword Pin 

digitalWrite(in4, LOW); //Left Motor forword Pin 



}