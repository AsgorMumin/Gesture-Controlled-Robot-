# Gesture-Controlled Robot Using MPU6050 and RF Communication

This project presents the design and implementation of a **gesture-controlled robotic car** using an **MPU6050 accelerometer**, **ATmega328P microcontroller**, and **RF communication**.

Hand gestures are captured on the transmitter side, processed into a 4-bit binary command, and transmitted wirelessly.  
The receiver side decodes the signal and **directly drives the motors using hardware only**, without any microcontroller.

---

## Project Overview

### Transmitter Side
- MPU6050 detects hand tilt and orientation
- ATmega328P processes gesture data
- Gestures are mapped to 4-bit binary codes
- HT12E encoder encodes the data
- RF transmitter sends the signal wirelessly

### Receiver Side
- RF receiver receives the transmitted signal
- HT12D decoder converts it to 4-bit parallel output
- L293D motor driver drives DC gear motors directly
- **No microcontroller is used on the receiver side**

---

## Gesture to Binary Mapping

| Gesture   | Binary Code (D5 D4 D3 D2) |
|----------|----------------------------|
| Forward  | 1001 |
| Backward | 0110 |
| Left     | 0100 |
| Right    | 0010 |
| Stop     | 0000 |

---

## Motor Driver Input Mapping

| Arduino / HT12D Output | Motor Function |
|------------------------|----------------|
| D2 | Left motor forward |
| D3 | Left motor backward |
| D4 | Right motor backward |
| D5 | Right motor forward |

---

## Repository Structure

gesture-controlled-robot-mpu6050-rf/
├─ transmitter/
│ └─ transmitter_mpu6050.ino
│
├─ receiver/
│ └─ README_receiver.md
│
├─ circuit-diagrams/
│ ├─ transmitter_circuit.png
│ └─ receiver_circuit.png
│
├─ docs/
│ └─ poster_presentation.pdf
│
└─ README.md


---

## Poster Presentation

The complete **academic poster presentation** for this project is available in PDF format.

📄 **Location:** `docs/poster_presentation.pdf`

The poster includes:
- System block diagram
- Transmitter and receiver circuit diagrams
- Gesture-to-binary mapping
- Methodology, results, and conclusion

---

## Key Features

- Intuitive hand gesture control
- Wireless communication using RF modules
- Hardware-only receiver (low latency, low cost)
- Real-time motor response
- Academic and modular project structure

---

## Applications

- Gesture-controlled robotics
- Assistive devices
- Educational embedded systems projects
- Human–machine interaction research

---

