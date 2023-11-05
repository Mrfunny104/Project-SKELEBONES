//this is version 3 that moves the arm motor with IR and buttons

#include <IRremote.h>

#define Extend_button 36975  // code received from Down arrow button
#define Retract_button 57375 // code received from Up arrow button

int receiver_pin = A1;      //output pin of IR receiver to pin A1 of arduino
IRrecv receiver(receiver_pin); //Arduino will take output of IR receiver from pin 2
decode_results output;


// constants won't change
const int ENA_PIN = 9;   // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6;   // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5;   // the Arduino pin connected to the IN2 pin L298N
const int BTN1_PIN = 2;  // the Arduino pin connected to the first button
const int BTN2_PIN = 3;  // the Arduino pin connected to the second button

// variables will change
int btn1_state = 0;  // the state of the first button
int btn2_state = 0;  // the state of the second button

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  // initialize digital pins as inputs with pull-up resistors.
  pinMode(BTN1_PIN, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);

  digitalWrite(ENA_PIN, HIGH);

  receiver.enableIRIn(); // Start to take the output from IR receiver

}

// the loop function runs over and over again forever
void loop() {
  // read the state of the buttons
  btn1_state = digitalRead(BTN1_PIN);
  btn2_state = digitalRead(BTN2_PIN);

  // if both buttons are pressed, stop the motor
  if (btn1_state == LOW && btn2_state == LOW) {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
  }

  // if only the first button is pressed, extend the actuator
  else if (btn1_state == LOW && btn2_state == HIGH) {
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
  }

  // if only the second button is pressed, retract the actuator
  else if (btn1_state == HIGH && btn2_state == LOW) {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
  }

  // if neither button is pressed, do nothing
  else {
    // do nothing
  }
  /*****************************
  *             IR             *
  *****************************/
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    switch(value) {
      case Extend_button:
        digitalWrite(IN1_PIN, HIGH);
        digitalWrite(IN2_PIN, LOW);
        delay(2000);
        break;
      
      case Retract_button:
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, HIGH);
        delay(2000);
        break;
    }
    receiver.resume();
    }
}