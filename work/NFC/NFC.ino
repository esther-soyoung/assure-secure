#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <pitches.h>

#define SDA_PIN 10
#define RST_PIN 9
#define LED_W 5 //define white LED pin
#define LED_R 4 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SDA_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_W, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

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
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();ss
  Serial.print("Message : ");
  content.toUpperCase();
  
  // Give access if blue key or white card
  if (content.substring(1) == "65 C5 ED 8B" || content.substring(1) == "56 3F E3 29") 
  {
    Serial.println("Door Unlocked");
    Serial.println();
    delay(500);
    // Blink white LED
    digitalWrite(LED_W, HIGH);
    noTone(BUZZER);
    // Unlock the doorlock
    myServo.write(180);
    delay(5000);
    // Lock the door again
    myServo.write(0);
    digitalWrite(LED_W, LOW);
  }

 // Illegal attempt detected
 else   {
    Serial.println("Illegal Attempt");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 500);
//    // Turn off the alert
//    if (){
//      noTone(BUZZER);
//      digitalWrite(LED_R, LOW);    
//    }
  }
}
