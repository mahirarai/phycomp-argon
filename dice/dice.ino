const int PIN_BUTTON = D2;
const int PIN_LED1 = A4;
const int PIN_LED2 = A3;
const int PIN_LED3 = A2; 
const int PIN_LED4 = D3; 
const int PIN_LED5 = D4; 
const int PIN_LED6 = D5; 
const int PIN_LED7 = D6; 
const int PIN_LED8 = D7; 
const int PIN_LED9 = D8; 

// arrays with six pin states 
const int rollOne[] = {0,0,0,0,1,0,0,0,0}; 
const int rollTwo[] = {1,0,0,0,0,0,0,0,1}; 
const int rollThree[] = {1,0,0,0,1,0,0,0,1}; 
const int rollFour[] = {1,0,1,0,0,0,1,0,1}; 
const int rollFive[] = {1,0,1,0,1,0,1,0,1}; 
const int rollSix[] = {1,0,1,1,0,1,1,0,1}; 

int randNumber = 0; 

int stateButtonLast = HIGH;
int stateButtonCurrent = HIGH; 

void setup() {
  pinMode(PIN_BUTTON, INPUT); 
  pinMode(PIN_LED1, OUTPUT); 
  pinMode(PIN_LED2, OUTPUT); 
  pinMode(PIN_LED3, OUTPUT); 
  pinMode(PIN_LED4, OUTPUT); 
  pinMode(PIN_LED5, OUTPUT); 
  pinMode(PIN_LED6, OUTPUT); 
  pinMode(PIN_LED7, OUTPUT);
  pinMode(PIN_LED8, OUTPUT);  
  pinMode(PIN_LED9, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // watch button for click 
  stateButtonCurrent = digitalRead(PIN_BUTTON);
  if(stateButtonCurrent == LOW && stateButtonLast == HIGH){ 
    // roll dice
    rollDice();      
  }
  stateButtonLast = stateButtonCurrent;

}

void rollDice(){
  // get random number from 1 to 6
  randNumber = random(1, 7);
  Serial.println("Rolled: " + String(randNumber)); 
  
  // show dice
  if(randNumber == 1){ showDice(rollOne); } 
  else if(randNumber == 2){ showDice(rollTwo); } 
  else if (randNumber == 3){ showDice(rollThree); }
  else if (randNumber == 4){ showDice(rollFour); }  
  else if (randNumber == 5){ showDice(rollFive); } 
  else if (randNumber == 6){ showDice(rollSix); }   
}

void showDice(const int arr[]){
  // go through array and 
  digitalWrite(PIN_LED1, arr[0]); 
  digitalWrite(PIN_LED2, arr[1]); 
  digitalWrite(PIN_LED3, arr[2]); 
  digitalWrite(PIN_LED4, arr[3]); 
  digitalWrite(PIN_LED5, arr[4]); 
  digitalWrite(PIN_LED6, arr[5]); 
  digitalWrite(PIN_LED7, arr[6]); 
  digitalWrite(PIN_LED8, arr[7]); 
  digitalWrite(PIN_LED9, arr[8]); 
}

