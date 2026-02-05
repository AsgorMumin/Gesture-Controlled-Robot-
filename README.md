# Gesture-Controlled Robot Using MPU6050 and RF Communication

This project implements a gesture-controlled robotic car where hand gestures are used to control the motion of the robot wirelessly.

The transmitter section processes gesture data using an MPU6050 sensor and sends encoded signals via RF modules.  
The receiver section decodes the received signals and directly drives the motors using an L293D motor driver IC, without any microcontroller on the receiver side.

---

## System Overview

**Transmitter Side**
- MPU6050 detects hand orientation
- ATmega328P processes sensor data
- Gesture mapped into 4-bit binary code
- HT12E encodes and RF module transmits data

**Receiver Side**
- RF receiver receives signal
- HT12D decodes 4-bit data
- L293D motor driver drives gear motors directly

---

## Gesture to Binary Mapping

| Gesture   | Binary (D5 D4 D3 D2) |
|----------|----------------------|
| Forward  | 1001 |
| Backward | 0110 |
| Left     | 0100 |
| Right    | 0010 |
| Stop     | 0000 |

---

## Pin Mapping (Motor Driver Input)

| Binary Bit | Function |
|-----------|----------|
| D5 | Right motor forward |
| D4 | Right motor backward |
| D3 | Left motor backward |
| D2 | Left motor forward |

---

## Folder Structure

- `transmitter/` → Arduino code (MPU6050 + gesture processing)
- `receiver/` → Hardware explanation (no code)
- `circuit-diagrams/` → Transmitter and receiver schematics
- `docs/` → Block diagram for poster/presentation

---

## Applications
- Assistive robotics
- Intuitive human-machine interfaces
- Educational embedded systems projects

---

## License
MIT License
