const int EN1 = 3;   
const int IN1 = 4; 
const int IN2 = 5;   
const int EN2 = 6;   
const int IN3 = 7;   
const int IN4 = 8;   

const int TRIG = 9;
const int ECHO = 10;


const int SPEED_A = 250;     
const int SPEED_B = 250;
int  TURN_90_MS   = 670;     
const int STOP_CM    = 20;   
const int REVERSE_MS = 350;  
const int PAUSE_MS   = 150;  

void setup() {
  pinMode(EN1, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(TRIG, OUTPUT); pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  Serial.begin(9600);        
  stopMotors();
  delay(3000);            


long readDistanceCm() {
  digitalWrite(TRIG, LOW);  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  long us = pulseIn(ECHO, HIGH, 30000);  
  if (us == 0) return 999;               
  return us / 58;                        
}

void loop() {
  long d = readDistanceCm();
  Serial.println(d);

  if (d > STOP_CM) {
    forward();
  } else {
    stopMotors();  delay(PAUSE_MS);
    reverse();     delay(REVERSE_MS);
    stopMotors();  delay(PAUSE_MS);
    turnRight();   delay(TURN_90_MS);
    stopMotors();  delay(PAUSE_MS);
  }
  delay(60);   
}


void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(EN1, SPEED_A); analogWrite(EN2, SPEED_B);
}

void reverse() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  analogWrite(EN1, SPEED_A); analogWrite(EN2, SPEED_B);
}

void turnLeft() {  
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(EN1, SPEED_A); analogWrite(EN2, SPEED_B);
}

void turnRight() {   
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
  analogWrite(EN1, SPEED_A); analogWrite(EN2, SPEED_B);
}

void stopMotors() {
  analogWrite(EN1, 0); analogWrite(EN2, 0);
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
