/*
    ARDUINO RGB LED Sample Code for Arduino UNO R3
    @ Kehiio - Github
*/
 
/* Global Variables for where each cathode is connected to the board. 
   Change depending on where each cathode is connected.
   Ensure you are using PMW pins: 3, 5, 6, 9, 10, or 11 for UNO */
const int PIN_RED   = 9; //Red LED cathode on pin 9
const int PIN_GREEN = 10; //Green LED cathode on pin 10
const int PIN_BLUE  = 11; //Blue LED cathode on Pin 11
 
/* Sets the color of the LED depending on input values between 0 and 255 for R, G, B */
void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}
 
void setup() {
  //set all three pins to output mode, allows to be writeable
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
 
}

/* HUESHIFT - Slowly goes through color spectrum like a color wheel 
   R   G   B   Color 
   255 0   0   Red
   255 255 0   Yellow
   0   255 0   Green
   0   255 255 Cyan
   0   0   255 Blue
   255 0   255 Magenta
*/
void hueShift(){

  /* RED->YELLOW LOOP - gradient from Red to Yellow by increasing green value*/
  for (int g = 0; g <= 255; g++){
    setColor(255, g, 0);
    delay(5);
  }

  /* YELLOW->GREEN LOOP - gradient from Yellow to Green by decreasing red value*/
  for (int r = 255; r >= 0; r--){
    setColor(r, 255, 0);
    delay(5);
  }

  /* GREEN->CYAN LOOP - gradient from Green to Cyan by increasing blue value*/
  for (int b = 0; b <= 255; b++){
    setColor(0, 255, b);
    delay(5);
  }

  /* CYAN->BLUE LOOP - gradient from Cyan to Blue by reducing green value*/
  for (int g = 255; g >= 0; g--){
    setColor(0, g, 255);
    delay(5);
  }

  /* BLUE->MAGENTA LOOP - gradient from Blue to Magenta by increasing red value*/
  for (int r = 0; r <= 255; r++){
    setColor(r, 0, 255);
    delay(5);
  }

  /* MAGENTA->RED LOOP - gradient from Magenta to Red by reducing blue value*/
  for (int b = 255; b >= 0; b--){
    setColor(255, 0, b);
    delay(5);
  }

}
 
void loop() {

  hueShift();

  setColor(0,0,0); // turn off LED
  
  exit(0); // exit loop
}
