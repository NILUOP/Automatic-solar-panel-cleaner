#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int sensorPin = A3;                 // sensor pin
int servoPin = 9;                         // select the pin for the servo motor
int sensorValue = 0;                      // variable to store the value from the sensor
float vIn;                                // measured voltage (3.3V = max. 16.5V, 5V = max 25V)
float vOut;
float voltageSensorVal;                   // value on pin A3 (0 - 1023)
const float factor = 6.667;               // reduction factor of the Voltage Sensor shield
const float vCC = 5.00;                   // Arduino input voltage (measurable by voltmeter)

void setup() {
  myservo.attach(servoPin);               // attaches the servo on pin 9 to the servo object
  myservo.write(0);                      // set initial position to 90 degrees
  Serial.begin(9600);
}

void loop() {

  voltageSensorVal = analogRead(sensorPin);    // read the current sensor value (0 - 1023) 
  vOut = (voltageSensorVal / 1024) * vCC;      // convert the value to the real voltage on the analog pin
  vIn =  vOut * factor;                        // convert the voltage on the source by multiplying with the factor

  Serial. println(vIn);
  
  sensorValue = analogRead(sensorPin);         // read the value from the sensor
  if (vIn < 3.5){

    Serial. println("cleaning...");
    myservo.write(0);                          // move servo to 0 degrees (90 degrees counterclockwise)
    delay(1000);        
    myservo.write(100);                         // move servo to 90 degrees (90 degrees clockwise)
    delay(1000);        
  }

  delay(1000);
}
