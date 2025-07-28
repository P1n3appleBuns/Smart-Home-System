/*Hello! My name is Shao Lin Lan.
  This is my project to make a Smart Light switch with a servo and ESP32 that automatically turns off my room light.

  I integrated 2 ESP32 devices to create a Smart system at home. One for my front door lock and another for my room light.
  The one ESP32 board is connects through my WIFI to my phone using Blynk IoT. The second ESP32 board is connected to the 
  first through ESP now. Both of the boards are controlled remotely with button presses on the Blynk IoT app.

*/

#define BLYNK_TEMPLATE_ID "TMPL2rOUV5sMB"
#define BLYNK_TEMPLATE_NAME "ESP32 Smart Light"
#define BLYNK_AUTH_TOKEN "lrEwpBqLPC_J2dXS3RdNqtV6FpHUbSMp"

#include <WiFi.h>
#include <WifiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char ssid[] = "Lanhome";
char pass[] = "lanjiahome123";

Servo myServo;
int servoPin = 18;
void setup() {

  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  myServo.attach(servoPin); // Change pin to Pin 18
  myServo.write(90); 

}

BLYNK_WRITE(V0) {
    int value = param.asInt(); // 1 or 0
    if (value == 1) {

      // Rotate CW
      myServo.write(0);  //full speed CW
      delay(2076.75);    // rotate ~90 degrees on gear CW
      myServo.write(90); // Stop
      delay(1000);       // Pause

    } else if (value == 0) {

      // Rotate CCW
      myServo.write(180); //full speed CCW
      delay(2220.75);     // rotate ~90 degrees on gear CCW
      myServo.write(90);  // Stop
      delay(1000);        // Pause

    } else {

      Serial.println("Womp womp"); //No understand command

    }
}

void loop() {
  Blynk.run();
}