/*
 * Project A2 Light Sculpture
 * Description: Singing flowers
 * Author: Mahira Raihan
 * Date: Feb 1 2020
 */

// initializing pins
const int PIN_LED1 = D6; 
const int PIN_LED2 = D5; 
const int PIN_LED3 = D4; 
const int PIN_LED4 = D3;
const int PIN_LED5 = D2;  

void setup() {
  // setting pinMode for pins
  pinMode(PIN_LED1, OUTPUT); 
  pinMode(PIN_LED2, OUTPUT); 
  pinMode(PIN_LED3, OUTPUT); 
  pinMode(PIN_LED4, OUTPUT); 
  pinMode(PIN_LED5, OUTPUT); 
}

void loop() {
  // turning lights on and off
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED3, HIGH); 
  digitalWrite(PIN_LED5, HIGH);
  delay(500);  
  digitalWrite(PIN_LED2, HIGH); 
  digitalWrite(PIN_LED4, HIGH); 
  delay(500);  
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED5, LOW);
  delay(500); 
  digitalWrite(PIN_LED2, LOW); 
  digitalWrite(PIN_LED4, LOW);
  delay(500); 
  digitalWrite(PIN_LED3, LOW);
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED5, HIGH);
  delay(500); 
  digitalWrite(PIN_LED2, HIGH); 
  digitalWrite(PIN_LED4, HIGH);
  delay(500);
  digitalWrite(PIN_LED3, HIGH);
  delay(500);
  digitalWrite(PIN_LED3, LOW);
  delay(500);
  digitalWrite(PIN_LED2, LOW); 
  digitalWrite(PIN_LED4, LOW);
  delay(500);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED5, LOW);
  delay(500);

}