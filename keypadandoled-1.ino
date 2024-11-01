#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
#include <ESP32Servo.h>
const int rows=4;
const int cols=4;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
Servo myservo;
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
uint8_t colpins[cols] = {2, 0, 4, 16 };
uint8_t rowpins[cols] = {12, 14, 27, 26};

Keypad keypad = Keypad(makeKeymap(keys), rowpins, colpins, rows, cols);
const String password = "0000"; 
String input_password;
Servo servo_bin;
void setup(){
  servo_bin.attach(19);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,2);
  display.clearDisplay();
  display.setTextSize(2);
  Serial.begin(115200);
  input_password.reserve(32);
}

void loop(){
  char key = keypad.getKey();
  if (key) {
  Serial.println(key);
  display.print(key);
  display.display();
  
 if (key == '*') {
      input_password = ""; 
      display.clearDisplay();
      display.display();
      display.setCursor(0,2);} 
  else if (key == '#') {
      if ("1" == input_password) {
        Serial.println("Help Me");
        servo_bin.write(0);
        display.clearDisplay();
        display.setCursor(0,2);
        display.setTextSize(2);
        display.print("Sent");
        display.display();
        display.setCursor(0,22);
        display.print("Help Me");
        display.display();
        delay(3000);
        servo_bin.write(90);
        display.clearDisplay();
        display.display();
        display.setCursor(0,2);
      } else if("2" == input_password){
        Serial.println("Not feeling well");
        display.clearDisplay();
        display.setCursor(0,2);
        display.setTextSize(2);
        display.print("Sent");
        display.setCursor(0,20);
        display.setTextSize(2);
        display.print("Not feeling well");
        display.display();
        delay(3000);
        display.clearDisplay();
        display.display();
        display.setCursor(0,2);
      }else {
        Serial.println("No message typed");
        display.clearDisplay();
        display.setCursor(0,2);
        display.setTextSize(2);
        display.print("Not Sent");
        display.display();
        delay(3000);
        display.clearDisplay();
        display.display();
        display.setCursor(0,2);
      }
      input_password = ""; 
  } 
  else {
      input_password += key; 
    }
      delay(100);
  }
}



