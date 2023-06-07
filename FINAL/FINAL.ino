#include <ESP32Encoder.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define CLK 22 // CLK ENCODER
#define DT 23 // DT ENCODER

ESP32Encoder encoder;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");


    encoder.attachHalfQuad(DT, CLK);
  encoder.setCount(0);
  Serial.begin ( 115200 );
}

void loop() {
  long newPosition = encoder.getCount();
  lcd.print(newPosition);
  delay(25);
  
}
