/*
    ARDUINO 7-Segment Display Sample Code for Arduino UNO R3
    @ Kehiio - Github
*/
 
 /* Global variables - where each segment (denoted by letters) is connected
    to the board. NOTE: comment shows the letter name of each pin according to
    the pinout image provided.
 */
const int CENTER    = 11; // g
const int TOP_LEFT  = 10; // f
const int TOP_MID   = 9;  // a
const int TOP_RIGHT = 8;  // b
const int BOT_LEFT  = 7;  // e
const int BOT_MID   = 6;  // d
const int BOT_RIGHT = 5;  // c
const int DP        = 4;  // dp

/* clearDisplay() : Turns off all segments of display. */
void clearDisplay(){
  digitalWrite(TOP_LEFT, LOW);
  digitalWrite(TOP_MID, LOW);
  digitalWrite(TOP_RIGHT, LOW);
  digitalWrite(CENTER, LOW);
  digitalWrite(BOT_LEFT, LOW);
  digitalWrite(BOT_MID, LOW);
  digitalWrite(BOT_RIGHT, LOW);
  digitalWrite(DP, LOW);
}

/*  displayDigit(int n): Displays the input digit "n" on the 7-segment display and prints the digit in the terminal. 
    int n - Digit to display. Can only be 0-9. Any other numbers will not display and will print error message in the terminal.
    */
void displayDigit(int n){

  // clears display
  clearDisplay();

  // displays number depending on input variable n
  switch(n){
    case 0:
      digitalWrite(TOP_LEFT, HIGH);
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(BOT_LEFT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      break;

    case 1:
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      break;

    case 2:
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_LEFT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      break;

    case 3:
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      break;

    case 4:
      digitalWrite(TOP_LEFT, HIGH);
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      break;

    case 5:
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_LEFT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      break;

    case 6:
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_LEFT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_LEFT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      break;

    case 7:
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      break;

    case 8:
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_LEFT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_LEFT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      break;

    case 9:
      digitalWrite(TOP_RIGHT, HIGH);
      digitalWrite(TOP_MID, HIGH);
      digitalWrite(TOP_LEFT, HIGH);
      digitalWrite(CENTER, HIGH);
      digitalWrite(BOT_RIGHT, HIGH);
      digitalWrite(BOT_MID, HIGH);
      break;


    default:
    // print error
    Serial.print("Invalid number error: ");
    Serial.println(n);

  }



}


void setup() {
  // setup serial communication
  Serial.begin(9600);

  // set all pins to output mode
  pinMode(CENTER, OUTPUT);
  pinMode(TOP_LEFT, OUTPUT);
  pinMode(TOP_MID, OUTPUT);
  pinMode(TOP_RIGHT, OUTPUT);
  pinMode(BOT_LEFT, OUTPUT);
  pinMode(BOT_MID, OUTPUT);
  pinMode(BOT_RIGHT, OUTPUT);
  pinMode(DP, OUTPUT);

}

void loop() {
  // Loop through numbers 0-10 with 1 second delay, printing an error to the serial monitor panel at 10.
  for (int i = 0; i <= 10; i++){
    displayDigit(i);
    delay(1000);

  }
  clearDisplay();
  exit(0);

}
