#include <SoftwareSerial.h>
SoftwareSerial bleSerial(2, 3); // RX, TX
void setup() {
  //initialize serial port for logs
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println("Hello!");

  bleSerial.begin(9600);
}
void loop() {
  if (bleSerial.available()) {
     Serial.write(bleSerial.read());
  }
  
  if (Serial.available()) {
    bleSerial.write(Serial.read());
  }
}
