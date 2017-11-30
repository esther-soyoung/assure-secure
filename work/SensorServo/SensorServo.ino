#include <Servo.h>

//Declare servo
Servo doorLock;

//Declare UltraSonic Sensor pins
const int trigPin = 2;
const int echoPin = 3;

//Declare filter variables
unsigned long motorTime;
unsigned long filterTotal;
int filterNumElements;
int filterAverage;
unsigned long filterTime = 100;

//Declare sound measurement variables
long duration;
int distance;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Declare servo pin
  doorLock.attach(4);
  doorLock.write(0);

  Serial.begin(9600);
  resetFilter();
}

void loop() {

  //Repeatedly pulses the trigger pin high and low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Reads the echo pin and converts the duration into distance
  duration = pulseIn(echoPin, HIGH);
  distance = convertToDistance(duration);

  //Filters out the readings to ignore random sound waves

  //If filter is currently reading, repeatedly add the value to the filter
  if((motorTime > 1) && (motorTime > (millis()-filterTime)))
  {
    filterTotal += distance;
    filterNumElements++;
    filterAverage = filterTotal / filterNumElements;
  }
  //Upon filter ending, 
  else if(filterAverage < 100)
  {
    Serial.println("Door lock rotating");
    doorLock.write(100);
    resetFilter();
    delay(5000);
    doorTester();
  }
  else
  {
    resetFilter();
    //Starts filtering on first reading when distance < 100
    if(distance < 100)
    {
      Serial.println("Begin filtering");
      motorTime = millis();
    }
  }
}

/* Uses speed of sound formula to convert sound to distance
 *  @param timeToConvert - time in milliseconds
 */
int convertToDistance(long timeToConvert)
{
  return timeToConvert*0.034/2;
}

/** Resets the filter to default values*/
void resetFilter()
{
  filterTotal = 0;
  filterNumElements = 0;
  filterAverage = 101;
  motorTime = 0;
}

/** Tester to reset the door lock to 0 after being set to 100*/
void doorTester()
{
    Serial.println("Door lock resetting");
    doorLock.write(0);
}

