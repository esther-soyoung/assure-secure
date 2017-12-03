//Include libraries
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

//Creates array to store allowed tag values
int numKeys = 3; //How many keys are allowed to use the security system
String nfcAllowed[] = {"65 C5 ED 8B", "56 3F E3 29", "08 6F A0 D0"};

//Define pins
#define RST_PIN 9
#define SDA_PIN 10
#define buzzer 2//define buzzer pin
#define ledRed 5//Define red LED pin
#define ledGreen 4//Define green LED pin
#define trigPin 6//Define trigger pin
#define echoPin 7//Define echo pin
#define servoPin 8//Define servoPin

//Define servo
const int unlockAngle = 80;//Servo unlock position
const int lockAngle = 0;//Servo lock position
Servo doorLock; //Declare servo

//Declare filter variables
unsigned long motorTime;
unsigned long filterTotal;
int filterNumElements;
int filterAverage;
unsigned long filterTime = 100; // Define filter delay time

//Declare sound measurement variables
long duration;
int distance;

// Create MFRC522 instance
MFRC522 mfrc522(SDA_PIN, RST_PIN);
  
void setup() {
  Serial.begin(9600); //Initiate a serial communication
  SPI.begin();  //Initiate SPI bus
  pinMode(buzzer, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  doorLock.attach(servoPin); //Attach the servo pin
  doorLock.write(lockAngle); //Servo start position
  mfrc522.PCD_Init(); //Initiate MFRC522
  noTone(buzzer); //Shush the buzzer
  resetFilter(); //Set the sound filter to default values

  //Initialization message
  Serial.println("System activated");
  Serial.println();
}

void loop() {
  
  //Pulses the ultrasonic sensor to measure distance
  sonarDetect();
  
  //Filters out the distance reading; decides whether to lock door
  filterCheck();

  //Checks the NFC Sensor to see if door should be unlocked
  cardDetect();
}

