# R3-SoftwareTraining-AnthonyPersaud

## General Info
This project is a simple 2-motor driver controlled by an Arduino, where different motor configurations are toggled by a dip switch, and the speed of the motors are controlled by a potentiometer. The circuit is powered by a 9V battery voltage source and the 5V Arduino voltage.

## Technologies
This project is created with Autodesk Tinkercad 2020

## Setup
![Image of Schematic](https://ibb.co/m8D2Nnq)

## Progress
The circuit shown was built using Tinkercad, connecting together an Arduino, a dip switch, 2 hobby gear motors, a potentiometer, an L293D IC, and a 9V battery. The 4 inputs of the L293D and 4 inputs on the dip switch were all connected to a digital pin on the Arduino UNO. The potentiometer was connected to an analog pin A0, and its potential value was mapped to digital pin 2, which connects to the enable pin on the L293D. This allows for the voltage of the motors to be adjusted from the potentiometer. There are 2 output wires for each motor, each of which are coded to be HIGH, which allows the motor to move clockwise, and LOW for counter-clockwise. 4 unique combinations of these states are coded to allow the motors to move forward, backward, turn left, and turn right. Each of these 4 combinations is also coded to 1 of 4 switches on the dip switch, and the motors won't move when all switches are off.
