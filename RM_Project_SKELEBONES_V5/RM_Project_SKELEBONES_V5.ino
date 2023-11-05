//this is version 5 that integrates the arm motor with the emg movement

int EMGPin = A0;
int EMGVal = 0;

// constants won't change
const int ENA_PIN = 9;   // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6;   // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5;   // the Arduino pin connected to the IN2 pin L298N
const int BTN1_PIN = 2;  // the Arduino pin connected to the first button
const int BTN2_PIN = 3;  // the Arduino pin connected to the second button

void setup() {
Serial.begin(9600);
/*pinMode(LED_BUILTIN, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(12, OUTPUT);
pinMode(12, OUTPUT);

digitalWrite(LED_BUILTIN,LOW);
digitalWrite(12,LOW);
*/
// initialize digital pins as outputs.
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  digitalWrite(ENA_PIN, HIGH);
}

void loop() {
EMGVal = analogRead(EMGPin);
Serial.println(EMGVal);
delay(50);

if (EMGVal < 1000 && EMGVal > 100) {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  }

else if (EMGVal > 1000){
  /*digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);*/
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  delay(1000);
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  }

else if (EMGVal < 100){
  /*digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);*/
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  delay(1000);
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  }
}
