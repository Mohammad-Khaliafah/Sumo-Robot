# Sumo-Robot

Welcome to the Sumo Robot project repository! This project involves designing, building, and programming a competitive sumo robot. The robot is equipped with various sensors for obstacle detection and line tracking, and it is controlled using an Arduino.

## Table of Contents
- [Introduction](#introduction)
- [Hardware Components](#hardware-components)
- [Mechanical Design](#mechanical-design)
- [Electrical Design](#electrical-design)
- [Software Design](#software-design)
- [Code Algorithm](#code-algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Contributors](#contributors)

## Introduction
The Sumo Robot project aims to develop a robot that can compete in sumo wrestling matches. The robot is designed to detect opponents, avoid obstacles, and stay within the ring boundaries. This repository contains all the necessary files and instructions to replicate the project.

## Hardware Components
- **E18-D80NK Infrared Obstacle Avoidance Sensor**:

  ![59e3e0d4-52f0-4947-9d2a-fbaa54251bd5](https://github.com/user-attachments/assets/45e8d497-4570-4c35-9939-bd4708387ece)

  - Quantity: 5
  - Adjustable range: 3-80 cm
  - Used for detecting opponents and obstacles.
  - Normally closed output configuration.

- **Dual Micro Line Sensor ML2**:

  ![dual-line-sensor-ml2-2131-80-B](https://github.com/user-attachments/assets/3a8ab19a-96cf-45f0-84e6-5b37bf7c1d5e)

  - Quantity: 4
  - Used for line tracking to detect the edge of the sumo ring.

- **BTS7960 Motor Driver**:

  ![download](https://github.com/user-attachments/assets/de1259f5-b11d-40da-95ad-73a36a157b90)

  - Quantity: 2
  - High power motor driver for controlling the DC motors.
  - Provides high current capacity and protection features.

## Mechanical Design
- **Chassis**: 
  - Designed to be compact and sturdy to withstand collisions.
  - Equipped with a low center of gravity to prevent tipping over.

- **Wheels**: 
  - High traction wheels for better grip on the sumo ring surface.
  - Positioned to provide optimal maneuverability.

## Electrical Design
- **Power Supply**: 
  - LiPo battery to power the motors and electronics.
  - Voltage regulators to ensure a stable power supply.

- **Sensor Integration**: 
  - Infrared sensors and line sensors are strategically placed around the robot for optimal performance.
  - Connected to the Arduino for real-time data processing.

- **Motor Control**: 
  - BTS7960 motor drivers control the DC motors.
  - Provides smooth and responsive motor operation.

## Software Design
- **Arduino IDE**: 
  - Used for writing and uploading the control code to the Arduino.
  - Provides a user-friendly environment for programming the robot.

- **Control Algorithms**: 
  - Implemented PID control for precise motor speed and direction control.
  - Includes obstacle avoidance and line tracking algorithms.

- **State Machine**: 
  - Manages the robot's behavior during the match.
  - Switches between different states such as searching for the opponent, pushing the opponent, and avoiding the ring edge.

## Code Algorithm
The code contains a delay of five seconds, taking into account that the Arduino is delayed in operation. Then we move to the strategy of tracking the opponent using the IR sensors, with priority being given to the Line Follower, so that the robot remains inside the ring and pounces on the opponent if it is identified from the front.

- **Right Attack Strategy**: By making the right side of the robot face the opponent in order to circumvent him and then start the tracking process to take him out.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Mohammad-Khaliafah/sumo-robot.git
   cd sumo-robot
   ```
2. Install the Arduino IDE from the official website: [Arduino IDE](https://www.arduino.cc/en/software)
3. Open the Arduino IDE and load the provided code from the `sumo_robot.ino` file.

## Usage
1. Upload the code to the Arduino:
   - Connect your Arduino to your computer.
   - Open the `sumo_robot.ino` file in the Arduino IDE.
   - Select the appropriate board and port from the Tools menu.
   - Click the Upload button.
2. Power on the robot and place it in the sumo ring.
3. The robot will start in idle mode and begin searching for an opponent once it detects the edge of the ring.

## Contributors
- **Mohammad Khalifah** - [Mohammad-Khaliafah](https://github.com/Mohammad-Khaliafah)
