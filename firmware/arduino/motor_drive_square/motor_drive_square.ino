const int EN1 = 3;  
const int IN1 = 4;   
const int IN2 = 5;  
const int EN2 = 6;   
const int IN3 = 7;   
const int IN4 = 8;  


const int SPEED_A = 250;  
const int SPEED_B = 250;   
int  TURN_90_MS   = 660;
const int LEG_MS  = 1000;

void setup() {
  pinMode(EN1, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  stopMotors();
  delay(3000);             
}

void loop() {
  for (int i = 0; i < 4; i++) {
    forward();     delay(LEG_MS);
    stopMotors();  delay(250);        
    turnRight();   delay(TURN_90_MS);
    stopMotors();  delay(250);
  }
  stopMotors();
  while (true) {}           
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
