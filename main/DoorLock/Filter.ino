/*This tab is used to control the ultrasonic sensor filter*/

/** Filters out random bursts of sound
 *  Checks if servo should be rotated 
 */
void filterCheck(){ 
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
    servoLock();
    resetFilter();
  }
  else
  {
    resetFilter();
    //Starts filtering on first reading when distance < 100
    if(distance < 100)
    {
      motorTime = millis();
    }
  }
}

/** Resets the filter to default values*/
void resetFilter(){
  filterTotal = 0;
  filterNumElements = 0;
  filterAverage = 101;
  motorTime = 0;
}
