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

/* cycle() : Activates each segment then deactivates each segment for testing purposes.*/
void cycle(){
  digitalWrite(TOP_MID, HIGH);
  delay(500);
  digitalWrite(TOP_RIGHT, HIGH);
  delay(500);
  digitalWrite(BOT_RIGHT, HIGH);
  delay(500);
  digitalWrite(BOT_MID, HIGH);
  delay(500);
  digitalWrite(BOT_LEFT, HIGH);
  delay(500);
  digitalWrite(TOP_LEFT, HIGH);
  delay(500);
  digitalWrite(CENTER, HIGH);
  delay(500);
  digitalWrite(DP, HIGH);
  delay(500);

  digitalWrite(TOP_MID, LOW);
  delay(500);
  digitalWrite(TOP_RIGHT, LOW);
  delay(500);
  digitalWrite(BOT_RIGHT, LOW);
  delay(500);
  digitalWrite(BOT_MID, LOW);
  delay(500);
  digitalWrite(BOT_LEFT, LOW);
  delay(500);
  digitalWrite(TOP_LEFT, LOW);
  delay(500);
  digitalWrite(CENTER, LOW);
  delay(500);
  digitalWrite(DP, LOW);
  delay(500);

}

/* clockwise_loading_sequence(): Shows a clockwise rotation with two adjacent segments turning on at a time.
   mimics the loading animation for webpages. 
   VARIABLES:
    IN - int LOADING_DELAY - delay between segments turning on and off (in milliseconds) */
void clockwise_loading_sequence(const int LOADING_DELAY){
  digitalWrite(TOP_MID, LOW);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(BOT_RIGHT, HIGH);

 delay(LOADING_DELAY);
  digitalWrite(BOT_MID, HIGH);
  digitalWrite(TOP_RIGHT, LOW);

  delay(LOADING_DELAY);
  digitalWrite(BOT_RIGHT, LOW);
  digitalWrite(BOT_LEFT, HIGH);

  delay(LOADING_DELAY);
  digitalWrite(BOT_MID, LOW);
  digitalWrite(TOP_LEFT, HIGH);

  delay(LOADING_DELAY);
  digitalWrite(BOT_LEFT, LOW);
  digitalWrite(TOP_MID, HIGH);

  delay(LOADING_DELAY);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(TOP_LEFT, LOW);

  delay(LOADING_DELAY);
  digitalWrite(TOP_MID, LOW);
  digitalWrite(TOP_RIGHT, LOW);

}

/* diagonal_wave(): Shows a 3 frame "wave" going fom top left to bottom right of display. 
   VARIABLES:
    IN - int WAVE_DELAY - delay between segments turning on and off (in milliseconds) */
void diagonal_wave(const int WAVE_DELAY){
  
  // Frame 1 - Top left segments
  digitalWrite(TOP_MID, HIGH);
  digitalWrite(TOP_LEFT, HIGH);

  // Frame 2 - Middle segment
  delay(WAVE_DELAY);
  digitalWrite(TOP_MID, LOW);
  digitalWrite(TOP_LEFT, LOW);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(CENTER, HIGH);
  digitalWrite(BOT_LEFT, HIGH);

  // Frame 3 - Bottom right segments
  delay(WAVE_DELAY);
  digitalWrite(TOP_RIGHT, LOW);
  digitalWrite(CENTER, LOW);
  digitalWrite(BOT_LEFT, LOW);
  digitalWrite(BOT_MID, HIGH);
  digitalWrite(BOT_RIGHT, HIGH);

  // Turn off remaining segments of display, adds extra delay for loop
  delay(WAVE_DELAY);
  digitalWrite(BOT_MID, LOW);
  digitalWrite(BOT_RIGHT, LOW);
  delay(WAVE_DELAY);
}

void setup() {
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
  clockwise_loading_sequence(150);
  clockwise_loading_sequence(150);
  clockwise_loading_sequence(150);

  diagonal_wave(150);
  diagonal_wave(150);
  diagonal_wave(150);
  diagonal_wave(150);

  exit(0);
}
