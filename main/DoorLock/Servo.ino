/*This tab is used to control the servo*/

/*Locks the door*/
void servoLock(){
  Serial.println("Locking door");
  doorLock.write(lockAngle);
}

/*Unlocks the door*/
void servoUnlock(){
  Serial.println("Unlocking door");
  doorLock.write(unlockAngle);
}

