# Traffic Light Optimization Simulator

**Course:** EGG 104-1003  
**University:** University of Nevada, Las Vegas  
**Project Type:** Team Engineering Project  
**Date:** May 2026  

## Overview

This project is a small-scale traffic light optimization simulator designed to respond to simulated traffic demand instead of using only fixed timing.

The prototype uses an **Arduino Uno**, an **HC-SR04 ultrasonic sensor**, and red, yellow, and green LEDs. Hot Wheels cars are passed through the sensor area to simulate traffic. The Arduino counts the detected cars during a 10-second window and selects different traffic-light timings based on the traffic level.

## How It Works

1. A car passes through the ultrasonic sensor's detection area.
2. The HC-SR04 measures the object's distance.
3. The Arduino counts each valid vehicle detection.
4. After the 10-second counting period, the program selects one of three traffic levels.
5. The red, yellow, and green LEDs run using the selected timing.

### Traffic Levels

| Cars Detected | Traffic Level | Green | Yellow | Red |
|---|---|---:|---:|---:|
| 0 | No traffic | 3 sec | 1 sec | 3 sec |
| 1-2 | Medium traffic | 5 sec | 3 sec | 5 sec |
| 3+ | High traffic | 8 sec | 5 sec | 8 sec |

## Hardware

- ELEGOO / Arduino Uno R3
- HC-SR04 ultrasonic sensor
- Breadboard
- Red LED
- Yellow LED
- Green LED
- Resistors
- Jumper wires
- Hot Wheels cars for traffic simulation

## Software

- Arduino IDE
- MATLAB
- Simulink was considered during the original project plan

The team tested both MATLAB and Arduino IDE. Arduino IDE was used for the final demonstration because it counted fast-moving cars more reliably and communicated directly with the Arduino board.

## Testing

The final prototype was tested with:

- 0 cars
- 1 car
- 2 cars
- 3 or more cars

The system successfully changed the signal timing based on the number of detected vehicles.

## Challenges and Improvements

One challenge was communication between MATLAB and the Arduino. MATLAB introduced small delays when reading the sensor through the computer, which made fast vehicle detection less reliable.

Possible future improvements include:

- Camera-based traffic detection
- Multiple traffic lanes
- Multiple intersections
- A larger physical road model
- More advanced traffic-control logic

## My Contributions

This was a team project. My documented contributions included:

- Introduction
- Plan of Action vs. Actual Outcome
- Software Logic
- Project planning documentation
- Project pictures and documentation

## Skills Demonstrated

- Arduino programming
- Sensor integration
- Breadboard circuit building
- LED and resistor wiring
- Hardware/software troubleshooting
- MATLAB testing
- Engineering documentation
- Team communication
- Prototype testing

## Project Files

This repository includes the project report and final presentation.

- `Final Report - Traffic Light Optimization Simulator.pdf`
- `Final Presentation - Traffic Light Optimization Simulator.pdf`

If the original Arduino source file is available later, it can be added to a `code/` folder.

## Team

- Zihan Chen
- Calvin Le Zheng
- Evan Macke
- Nathaniel Lubas
