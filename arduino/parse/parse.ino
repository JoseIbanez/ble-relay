#include <stdio.h>
#include <string.h>

#include <SoftwareSerial.h>
SoftwareSerial bleSerial(2, 3); // RX, TX

// Main vars
int curTime = 0;
String relayStatus = "0000";
char sample[] = "0100;0000";


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // BLE configure
  bleSerial.begin(9600);
  
  // send an intro:
  Serial.println("Count down:");
}

void loop() {
  // Get a command
  if (Serial.available()) {
    inputParse(Serial.readString());
    updateGPIO(relayStatus);
  }

  if (bleSerial.available()) {
    inputParse(bleSerial.readString());
    updateGPIO(relayStatus);
  }


  if (curTime > 0) {
    delay(1000);
    curTime--;
    if (! curTime > 0) {
      relayStatus = "0000";
      updateGPIO(relayStatus);
    }    
    Serial.println(String(curTime) + ";" + relayStatus);
  }


}


int inputParse(String input) {

  Serial.println(input);

  char delimiter[] = ";";
  char* ptr;
  char buf[sizeof(sample)];

  input.toCharArray(buf, sizeof(buf));

  // Get TimeOut
  ptr = strtok(buf, delimiter);
  if (ptr != NULL) {
    curTime = String(ptr).toInt();
    Serial.println("Uptime: " + String(curTime));
  }

  // Get Gpio Status
  ptr = strtok (NULL, delimiter);
  if (ptr != NULL) {
    relayStatus = String(ptr);
    Serial.println("Relay status: " + relayStatus);
  }

}


int updateGPIO(String status) {

  bleSerial.print(status);

  for (int index=0 ; index < status.length() ; index++ )

    if (status.charAt(index) == '1' ){
      Serial.println("Pos "+String(index)+ ": ON ");
    } else {
      Serial.println("Pos "+String(index)+ ": OFF ");
   }

}

