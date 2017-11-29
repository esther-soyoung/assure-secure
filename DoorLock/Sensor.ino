/*This tab is utilized for the sonar detection*/

/* Pulses the ultrasonic sensor to measure distance
 */
void sonarDetect(){
  //Repeatedly pulses the trigger pin high and low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Reads the echo pin and converts the duration into distance
  duration = pulseIn(echoPin, HIGH);
  distance = convertToDistance(duration);
}

/* Uses speed of sound formula to convert sound to distance
 *  @param timeToConvert - time in milliseconds
 */
int convertToDistance(long timeToConvert){
  return timeToConvert*0.034/2;
}
