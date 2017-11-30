#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SDA_PIN 10
#define RST_PIN 9
#define LED_G 7 //define green LED
#define LED_R 6 //define red LED
const int BUZZER1 = 4;

MFRC522 mfrc522(SDA_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  
  myServo.attach(2); //servo pin 2
  myServo.write(0); //servo start position
  
  pinMode(LED_W, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER1, OUTPUT);
  noTone(BUZZER1);
}

void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  // Read the UID number of card
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();
  
  // Give access if authorized keys
  if (content.substring(1) == "65 C5 ED 8B" || content.substring(1) == "56 3F E3 29")  
    access();

 // Illegal attempt detected
  else
    alert();
}

/** Give an access */
void access(){
      // Blink green LED
    digitalWrite(LED_G, HIGH);
    noTone(BUZZER1);

    // Unlock the doorlock
    myServo.writeMicroseconds(2300);
    delay(10000);
    
    // Back to locked status
    myServo.write(0);
    digitalWrite(LED_G, LOW);
}

/** Turn on the alarming system */
void alert(){
    // Turn on the light and buzzer
    digitalWrite(LED_R, HIGH);
    tone(BUZZER1, 5000);

    // Turn off
    delay(5000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER1);
}

