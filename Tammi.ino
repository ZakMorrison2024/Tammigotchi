// Libraries
#include <U8g2lib.h>

// init LCD
U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, /*clock=*/ 13, /*data=*/ 11, /*CS=*/ 9, /*reset=*/ 8);

// Sprites (Byte):
// Squidy sprite frames
const uint8_t sprite_0[8] = {
  0b00111110, //    XXXXX
  0b01111111, //   XXXXXXX
  0b01001001, //   X  X  X
  0b01111111, //   XXXXXXX
  0b01111111, //   XXXXXXX
  0b01100011, //   XX   XX
  0b01100011, //   XX   XX
  0b01100011  //   XX   XX
};

const uint8_t sprite_1[8] = {
  0b00111110, //    XXXXX
  0b01111111, //   XXXXXXX
  0b01001001, //   X  X  X
  0b01111111, //   XXXXXXX
  0b01111111, //   XXXXXXX
  0b00110110, //    XX XX
  0b00110110, //    XX XX
  0b00110110  //    XX XX
};



// Declarations:
// Input pins
const int button1Pin = 2;  // Button 1 connected to digital pin 2
const int button2Pin = 3;  // Button 2 connected to digital pin 3

// Tammi variables:
int food = 100;
int happy = 100;


void setup() {

  // Initialize the display
  u8g2.begin();  
  
  // Set button pins as input with pull-up resistors
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {

  // Graphics:
  u8g2.clearBuffer();  // Clear the display buffer
  
  // Draw the Squidy sprite in the middle off the screen/ First Frame
  u8g2.drawBitmap(116, 76, 8, 8, sprite_0);  // x, y, width, height, sprite data
  
  u8g2.sendBuffer();  // Update the display
  
  delay(1000);  // Delay for 1 second before drawing again

  u8g2.clearBuffer();  // Clear the display buffer
  
  // Second Frame
  u8g2.drawBitmap(116, 76, 8, 8, sprite_1);  // x, y, width, height, sprite data
  
  u8g2.sendBuffer();  // Update the display

  delay(1000);  // Delay for 1 second before drawing again






  // Input: 
  // Read button states (LOW means pressed due to pull-up resistors)
  bool button1State = digitalRead(button1Pin) == LOW;
  bool button2State = digitalRead(button2Pin) == LOW;

  // Action for Button 1
  if (button1State) {
    Serial.println("Button 1 pressed!");
    // Next
    delay(200); // Debounce delay
  }

  // Action for Button 2
  if (button2State) {
    Serial.println("Button 2 pressed!");
    // Enter/Select
    delay(200); // Debounce delay
  }

    food -= 1;
    delay(5000);
    Serial.println(food);

    if (food < 50) {
    happy -= 1;
    delay(5000);
    Serial.println(happy);
    }



}
