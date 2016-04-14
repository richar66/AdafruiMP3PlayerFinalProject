/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
const int buttonPin2 = 3;     // the number of the pushbutton pin
const int ledPin2 =  12; 
const int buttonPin3 = 4;     // the number of the pushbutton pin
const int ledPin3 =  11; 
const int buttonPin4 = 5;     // the number of the pushbutton pin
const int ledPin4 =  10; 

// variables will change:
int buttonReading1;
int buttonReading2;
int buttonReading3;
int buttonReading4;// variable for reading the pushbutton status

int state1 = HIGH;
int state2 = HIGH;
int state3 = HIGH;
int state4 = HIGH;

int previous1 = LOW;
int previous2 = LOW;
int previous3 = LOW;
int previous4 = LOW;

const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT);
    pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin3, INPUT);
  pinMode(ledPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin4, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonReading1 = digitalRead(buttonPin1);
   buttonReading4 = digitalRead(buttonPin4);
 buttonReading2 = digitalRead(buttonPin2);
  buttonReading3 = digitalRead(buttonPin3);
  
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (buttonReading1 == HIGH && previous1 == LOW) {
    if (state1 == HIGH)
      state1 = LOW;
    else
      state1 = HIGH;    
  }

  digitalWrite(ledPin1, state1);

  previous1 = buttonReading1;

   if (buttonReading2 == HIGH && previous2 == LOW) {
    if (state2 == HIGH)
      state2 = LOW;
    else
      state2 = HIGH;    
  }

  digitalWrite(ledPin2, state2);

  previous2 = buttonReading2;
  
 
  if (buttonReading3 == HIGH && previous3 == LOW) {
    if (state3 == HIGH)
      state3 = LOW;
    else
      state3 = HIGH;    
  }

  digitalWrite(ledPin3, state3);

  previous3 = buttonReading3;

   if (buttonReading4 == HIGH && previous4 == LOW) {
    if (state4 == HIGH)
      state4 = LOW;
    else
      state4 = HIGH;    
  }

  digitalWrite(ledPin4, state4);

  previous4 = buttonReading4;
  

   // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
