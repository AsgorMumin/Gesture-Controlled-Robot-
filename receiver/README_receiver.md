# Receiver Section (Hardware Only)

The receiver section of this project does not use a microcontroller.

## Working Principle
1. RF receiver module receives encoded data
2. HT12D decoder converts RF data into 4-bit parallel output
3. Output pins are connected directly to the L293D motor driver
4. L293D drives the gear motors according to the received binary code

## Components Used
- RF Receiver (433 MHz)
- HT12D Decoder
- L293D Motor Driver
- DC Gear Motors
- 7805 Voltage Regulator
- External Motor Power Supply

## Advantage
- Reduced system complexity
- Faster response time
- Lower cost and power consumption
