/*This tab detects NFC cards/tags and reads them*/

/*Reads card values*/
void cardDetect(){
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
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if(cardAllowed(content.substring(1))){
    allowEntry();
  }
  else
  {
    illegalAttempt();
  }
}

boolean cardAllowed(String content){
  for(int i = 0; i < numKeys; i++)
  {
    if(nfcAllowed[i].equals(content))
    {
      return true;
    }
  }
  return false;
}

