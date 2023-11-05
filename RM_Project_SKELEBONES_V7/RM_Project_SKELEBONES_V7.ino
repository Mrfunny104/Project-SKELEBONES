//this is version 7 that moves both back and arm motors with one movement with emg

int EMGPin = A0;
int EMGVal = 0;

// constants won't change
const int ENA_PIN = 3; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5; // the Arduino pin connected to the IN2 pin L298N
const int ENB_PIN = 9; // the Arduino pin connected to the EN1 pin L298N
const int IN3_PIN = 11; // the Arduino pin connected to the IN1 pin L298N
const int IN4_PIN = 10; // the Arduino pin connected to the IN2 pin L298N

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // initialize digital pins as outputs.
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);

  digitalWrite(ENA_PIN, HIGH);
  digitalWrite(ENB_PIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
EMGVal = analogRead(EMGPin);
Serial.println(EMGVal);
delay(50);

if (EMGVal < 1000 && EMGVal > 100) {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);
  }

  // extend the actuator
else if (EMGVal > 1000){
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);
  delay(1000); // actuator will stop extending automatically when reaching the limit
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);
  }

  // retracts the actuator
else if (EMGVal < 100){
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH);
  delay(1000); // actuator will stop retracting automatically when reaching the limit
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);
  }
}
