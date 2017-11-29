/*This tab provides feedback such as LED lights and buzzer sounds*/

/*Unlocks door and lights up NFC if there is a valid NFC*/
void allowEntry(){
  Serial.println("Door Unlocked");
  Serial.println();
  digitalWrite(ledWhite, HIGH);
  doorLock.write(unlockAngle);
  delay(5000);
  //Lock the door again
  doorLock.write(lockAngle);
  digitalWrite(ledWhite, LOW);
}

/*Sounds off buzzer and turns on red light if there is an invalid NFC tag*/
void illegalAttempt(){
  Serial.println("Illegal Attempt");
  digitalWrite(ledRed, HIGH);
  tone(buzzer, 500);
  delay(5000);
  noTone(buzzer);
  digitalWrite(ledRed, LOW);
}

