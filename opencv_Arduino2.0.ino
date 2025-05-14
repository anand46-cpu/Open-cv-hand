#include <Servo.h>

Servo servothumb;
Servo servoindex;
Servo servomiddle;
Servo servoring;
Servo servopinky;

int servoPinky, servoMiddle, servoIndex, servoThumb, servoRing;

void setup() {
  Serial.begin(9600);
  servoindex.attach(2);
  servomiddle.attach(3);
  servoring.attach(7);
  servopinky.attach(5);
  servothumb.attach(6);
}

void loop() {
  receiveData();

  if (servoPinky == 1) {
    servopinky.write(90); // Change from 180 to 90
  } else {
    servopinky.write(0);
  }
  if (servoIndex == 1) {
    servoindex.write(90); // Change from 180 to 90
  } else {
    servoindex.write(0);
  }
  if (servoMiddle == 1) {
    servomiddle.write(90); // Change from 180 to 90
  } else {
    servomiddle.write(0);
  }
  if (servoThumb == 1) {
    servothumb.write(90); // Change from 180 to 90
  } else {
    servothumb.write(0);
  }
  if (servoRing == 1) {
    servoring.write(90); // Change from 180 to 90
  } else {
    servoring.write(0);
  }
}

void receiveData() {
  if (Serial.available() ) {
    String inputString = Serial.readStringUntil('\n'); // Read until newline character
    
    // Split the received string into individual elements using comma as delimiter
    String dataElement;
    int dataArray[6]; // Adjust the size based on the number of expected elements
    int dataIndex = 0;
    
    for (int i = 0; i < inputString.length(); i++) {
      char c = inputString.charAt(i);
      if (c == ',') {
        dataArray[dataIndex] = dataElement.toInt();
        dataIndex++;
        dataElement = "";
      } else {
        dataElement += c;
      }
    }
    /*for (int i = 0; i < dataIndex; i++) {
      Serial.print("Data at index ");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(dataArray[i]);
    }*/
    
//    Serial.println(dataArray[]);
    servoThumb = dataArray[0];
    Serial.println(servoThumb);
    servoIndex = dataArray[1];
    Serial.println(servoIndex);
    servoMiddle = dataArray[2];
    Serial.println(servoMiddle);
    servoRing = dataArray[3];
    Serial.println(servoRing);
    servoPinky = dataArray[4];
    Serial.println(servoPinky);
  }
}

  // Read until newline character
  
