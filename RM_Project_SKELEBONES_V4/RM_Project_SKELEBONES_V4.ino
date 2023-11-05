//this is version 4 that tests out the emg system

int EMGPin = A0;
int EMGVal = 0;

void setup() {
Serial.begin(9600);

}

void loop() {
EMGVal = analogRead(EMGPin);
Serial.println(EMGVal);
delay(100);

}
