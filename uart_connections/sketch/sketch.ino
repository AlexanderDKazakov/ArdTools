/*
 * Alexander Kazakov <alexander.d.kazakov@gmail.com>
 *
 * Code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
*/

#include <JC_Button.h>          // https://github.com/JChristensen/JC_Button
#include <SoftwareSerial.h>     // Serial communication

// pin assignments
const byte
    BUTTON_INC_PIN(7),              // connect a button switch from this pin to ground
    BUTTON_DEC_PIN(8),              // connect a button switch from this pin to ground
    LED_PIN(9),                     // the standard Arduino "pin 13" LED
    Rx(2),
    Tx(4);

// variables
uint8_t brightness = 0;  // 0 - 255

SoftwareSerial deviceSerial(Rx, Tx); // Rx, Tx
Button incBtn(BUTTON_INC_PIN);       // define the button
Button decBtn(BUTTON_DEC_PIN);       // define the button

void setup() {
  deviceSerial.begin(9600);  // Device
  
  Serial.begin(9600);        // Loger  // 9600 bits per second
  
  // buttons
  incBtn.begin();
  decBtn.begin();

  pinMode(LED_PIN, OUTPUT);   // led
}

void loop() {

  incBtn.read();
  decBtn.read();

  if (incBtn.wasReleased()) {brightness += 1;};
  if (decBtn.wasReleased()) {brightness -= 1;};
  
  analogWrite(LED_PIN, brightness);

  Serial.println(brightness);
  deviceSerial.write(brightness);
  
  delay(500);

}
