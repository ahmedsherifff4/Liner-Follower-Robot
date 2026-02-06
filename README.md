# Line Following Robot

A simple Arduino project: a robot that follows a black line using 3 sensors and 2 DC motors.

## Features
- Follows a line using 3 sensors (Left, Middle, Right)
- Moves forward, turns left/right, stops if the line is lost
- Adjustable motor speed

## Components / Hardware
- Arduino Uno / compatible board
- 2 DC Motors
- L298N Motor Driver
- 3 IR Sensors (Left, Middle, Right)
- Jumper wires, battery, and chassis

## Wiring
| Sensor/Motor | Arduino Pin |
|--------------|-------------|
| Left Sensor  | A1          |
| Middle Sensor| A2          |
| Right Sensor | A0          |
| Motor A IN1  | 2           |
| Motor A IN2  | 4           |
| Motor B IN3  | 9           |
| Motor B IN4  | 10          |
| Motor A ENA  | 3           |
| Motor B ENB  | 5           |

## Code
[`main.cpp`](https://github.com/ahmedsherifff4/Liner-Follower-Robot/blob/main/src/main.cpp) → Main robot logic
- Sensors are read every loop, and motors are controlled accordingly

## How to Run
1. Open `main.cpp` in Arduino IDE
2. Connect your robot hardware
3. Upload the code to the Arduino board
4. Place the robot on a black line and power it on

## Image
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/20c4693a-4c40-4e29-b528-2e2a00bff30e" />













