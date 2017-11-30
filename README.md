# Arduino Home Security System
IEEE Quarterly Project Fall 2017 - Home Automation

- A home security device developed for IEEE UCSD's Fall 2017 Quarterly Project.
- WORK IN PROGRESS

## Table of Contents
- [Team Members](https://github.com/eminguyen/home-security-system#team-members)
- [Purpose and Idea](https://github.com/eminguyen/home-security-system#purpose-and-idea)
- [Parts](https://github.com/eminguyen/home-security-system#parts)
- [Explanation](https://github.com/eminguyen/home-security-system#explanation)
- [Demonstration](https://github.com/eminguyen/home-security-system#demonstration)
- [Additional Credit](https://github.com/eminguyen/home-security-system#additional-credit)

## Team Members
- [Esther Soyoung Kang](https://github.com/esther-soyoung)
- [Antony Nguyen](https://github.com/eminguyen)
- [Jianing Zhang](https://github.com/johnnyzhang123)

## Purpose and Idea
The theme for this quarter's IEEE project was to create a home automation device. 
<br />
<br />
Our group decided to pursue development of a home security system.
We wanted to develop something that was simple but useful and convenient.
We avoided fancy features like voice control, number pads, phone applications.
Instead, we simply made it so you can unlock the door with the tap of your phone.
<br />
<br />
This idea behind this system is to automate the home by locking the door upon the user
exiting the house. The user can then use his/her phone or an NFC card to unlock the
door.

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
Video will be added once project is complete

## Additional Credit
- [Miguel Balboa for his RFID Library](https://github.com/miguelbalboa/rfid)
- IEEE & UCSD for sponsorship