
const int PIN_BUTTON_RED1 = D2;
const int PIN_BUTTON_BLUE1 = D3;
const int PIN_RED = D4;
const int PIN_GREEN = D5;
const int PIN_BLUE = D6;
const int PIN_BUTTON_RED2 = D7;
const int PIN_BUTTON_BLUE2 = D8;

int stateButtonRed1_last = HIGH; 
int stateButtonRed1_current = HIGH; 
int stateButtonBlue1_last = HIGH; 
int stateButtonBlue1_current = HIGH; 
int stateButtonRed2_last = HIGH; 
int stateButtonRed2_current = HIGH; 
int stateButtonBlue2_last = HIGH; 
int stateButtonBlue2_current = HIGH; 

bool playing = false; 
int show = 2;
bool answered = false;

int player1Score = 0; 
int player2Score = 0;

void setup() {
  pinMode(PIN_BUTTON_RED1, INPUT); 
  pinMode(PIN_BUTTON_BLUE1, INPUT); 
  pinMode(PIN_RED, OUTPUT); 
  pinMode(PIN_GREEN, OUTPUT); 
  pinMode(PIN_BLUE, OUTPUT); 
  pinMode(PIN_BUTTON_RED2, INPUT); 
  pinMode(PIN_BUTTON_BLUE2, INPUT); 

  Serial.begin(9600); 
}

void loop() {

  if(!playing){ // if not playing, then play
    // blink light from white, red, green, blue
    delay(200); 
    analogWrite(PIN_RED, 255);
    analogWrite(PIN_GREEN, 255); 
    analogWrite(PIN_BLUE, 255); 
    delay(200); 
    analogWrite(PIN_RED, 0);
    analogWrite(PIN_GREEN, 0); 
    analogWrite(PIN_BLUE, 0); 
    delay(200); 
    analogWrite(PIN_RED, 255);
    analogWrite(PIN_GREEN, 255); 
    analogWrite(PIN_BLUE, 255); 
    delay(200); 
    analogWrite(PIN_RED, 0);
    analogWrite(PIN_GREEN, 0); 
    analogWrite(PIN_BLUE, 0); 
    delay(200); 
    analogWrite(PIN_RED, 255);
    analogWrite(PIN_GREEN, 255); 
    analogWrite(PIN_BLUE, 255);
    delay(200); 
    analogWrite(PIN_RED, 0);
    analogWrite(PIN_GREEN, 0); 
    analogWrite(PIN_BLUE, 0);  

    show = random(0,2); 

    if(show == 0){ // RED
      Serial.println("RED");
      analogWrite(PIN_RED, 255);
      analogWrite(PIN_GREEN, 0); 
      analogWrite(PIN_BLUE, 0); 
    }
    else if(show == 1){ // BLUE
      Serial.println("BLUE");
      analogWrite(PIN_RED, 0);
      analogWrite(PIN_GREEN, 0); 
      analogWrite(PIN_BLUE, 255); 
    }

    answered = false; 
    playing = true; 
  }

  int stateButtonRed1_current = digitalRead(PIN_BUTTON_RED1);
  int stateButtonBlue1_current = digitalRead(PIN_BUTTON_BLUE1);
  int stateButtonRed2_current = digitalRead(PIN_BUTTON_RED2);
  int stateButtonBlue2_current = digitalRead(PIN_BUTTON_BLUE2);

  if(stateButtonRed1_current == LOW && stateButtonRed1_last == HIGH){ // rising edge 
    if(show == 0 && !answered){
      player1Score++; 
      Serial.println("Player 1: " + String(player1Score));
      Serial.println("Player 2: " + String(player2Score));  
      answered = true;
      playing = false;  
    }
  }
  stateButtonRed1_last = stateButtonRed1_current;

  if(stateButtonBlue1_current == LOW && stateButtonBlue1_last == HIGH){ // rising edge 
    if(show == 1 && !answered){
      player1Score++; 
      Serial.println("Player 1: " + String(player1Score));
      Serial.println("Player 2: " + String(player2Score));   
      answered = true;
      playing = false;   
    }
  }
  stateButtonBlue1_last = stateButtonBlue1_current;

  if(stateButtonRed2_current == LOW && stateButtonRed2_last == HIGH){ // rising edge 
    if(show == 0 && !answered){
      player2Score++; 
      Serial.println("Player 1: " + String(player1Score));
      Serial.println("Player 2: " + String(player2Score));  
      answered = true;
      playing = false;   
    }
  }
  stateButtonRed2_last = stateButtonRed2_current;

  if(stateButtonBlue2_current == LOW && stateButtonBlue2_last == HIGH){ // rising edge 
    if(show == 1 && !answered){
      player2Score++; 
      Serial.println("Player 1: " + String(player1Score));
      Serial.println("Player 2: " + String(player2Score));   
      answered = true; 
      playing = false;  
    }
  }
  stateButtonBlue2_last = stateButtonBlue2_current;


}