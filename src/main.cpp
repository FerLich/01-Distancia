#include <Arduino.h>

/*********
  Taken from a project by Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-hc-sr04-ultrasonic-arduino/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

//Velocidad del sonido cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(TRIG, OUTPUT); // Sets the TRIG as an Output
  pinMode(ECHO, INPUT); // Sets the ECHO as an Input
}

void loop() {
  // Clears the TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  // Sets the TRIG on HIGH state for 10 micro seconds
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // Reads the ECHO, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distancia (cm): ");
  Serial.println(distanceCm);
  
  delay(1000);
}
