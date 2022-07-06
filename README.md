# Assure Secure - A Keyless Entry Security System
IEEE Quarterly Project Fall 2017 - FIRST PLACE WINNER

## Table of Contents
- [Team Members](https://github.com/eminguyen/home-security-system#team-members)
- [Purpose and Idea](https://github.com/eminguyen/home-security-system#purpose-and-idea)
- [Parts](https://github.com/eminguyen/home-security-system#parts)
- [Explanation](https://github.com/eminguyen/home-security-system#explanation)
- [Demonstration](https://github.com/eminguyen/home-security-system#demonstration)
- [Additional Credit](https://github.com/eminguyen/home-security-system#additional-credit)

## Team Members
- [Esther Soyoung Kang](https://github.com/esther-soyoung) - Code / Mechanical Design
- [Antony Nguyen](https://github.com/eminguyen) - Code / Mechanical Design
- [Jianing Zhang](https://github.com/johnnyzhang123) - Hardware / Mechanical Design

## Purpose and Idea
The theme for this quarter's IEEE project was to create a home automation device. 
<br />
<br />
Our group decided to pursue development of a home security system.
We wanted to develop something that was simple but useful and convenient.
We avoided fancy features like voice control, number pads, phone applications.
Instead, we simply made it so you can unlock the door with the tap of an NFC tag.
<br />
<br />
This idea behind this system is to automate the home by creating a keyless entry system.
You can unlock a door by scanning an NFC tag and it will automatically relock once the door is closed.
It creates an efficient form of entry.

## Parts
1. Arduino
2. Ultrasonic Sensor
3. Servo Motor
4. NFC Sensor
5. Buzzers + Lights

## Explanation
We have divided the code into three parts - servo code, Ultrasonic sensor code, and NFC code

### Servo
- The servo code is relatively simple.
- It sets the angle of the servo to the unlocked value when the NFC sensor is triggered.
- It sets the angle of the Ultrasonic sensor to the locked value when the Ultrasonic sensor is triggered

### Ultrasonic Sensor
- The Ultrasonic Sensor is used to read distance.
- It triggers when the user passes a certain distance through the door.
- The ultrasonic sensor emits a high frequency sound waves and times how long it takes for it to travel back.
- By combining this idea of sonar with the speed of sound, we can measure distance.
- One problem with the ultrasonic sensor is that the hardware can randomly trigger due to high frequency sound waves.
- We filtered this out by averaging the return value of 100ms to ensure that there was actually some one triggering the sensor.

### NFC
- The NFC Sensor is used to read NFC tags.
- NFC tag values can be added in a separate document
- If an improper NFC tag is used, a red light will flash and an alarm will siren.
- If the proper one is used, a green light will flash and the door will unlock.

## Demonstration
- [Basic Functionality](https://youtu.be/NeMNWZ8lvp8)
- [NFC Denied](https://youtu.be/ru8mSP7Ndqg)
- [Front View](https://youtu.be/aLkNH8MQNwY)

## Additional Credit / Special Thanks
- [IEEE UCSD for hosting the competition](https://www.facebook.com/ieeeucsd/)
- [UCSD ECE Department for sponsorship](http://www.ece.ucsd.edu/)
- [Miguel Balboa for his RFID Library](https://github.com/miguelbalboa/rfid)
