# 🤖 Spybotix with Automation

A hands-on robotics project developed during the **Two-Day Bootcamp on “Spybotix with Automation”**, focusing on the integration of sensors, motor control, embedded programming and wireless communication.

The project involved designing and implementing a compact **differential-drive robotic vehicle** capable of controlled movement and obstacle detection using an Arduino-based control system.

---

## 📌 About the Project

The Spybot is a small mobile robotic platform designed to demonstrate the basic principles of **robotics and automation**.

The robot uses:

- Arduino as the main controller
- L293D H-Bridge motor driver for DC motor control
- DC motors for locomotion
- IR sensors for obstacle detection
- HC-05/HC-06 Bluetooth module for wireless communication
- Relay interfacing for switching/control applications

The project demonstrates the complete flow:

**Sensing → Processing → Decision Making → Actuation**

---

## ⚙️ Key Features

- 🚗 Differential-drive locomotion
- 🔍 IR-based obstacle detection
- 🤖 Automated movement based on sensor inputs
- ⚡ Dual DC motor control using L293D
- 📡 Bluetooth-based wireless communication
- 🔗 UART/Serial communication between controller and Bluetooth module
- 🔌 Relay interfacing for electrical switching
- 🧩 Modular hardware architecture

---

## 🛠️ Hardware Components

| Component | Purpose |
|-----------|---------|
| Arduino | Main microcontroller |
| L293D Motor Driver | Controls direction and speed of DC motors |
| DC Motors | Provides robotic movement |
| IR Sensors | Detects obstacles |
| HC-05 / HC-06 | Bluetooth communication |
| Relay Module | Electrical switching/control |
| Battery/Power Supply | Powers the system |
| Robot Chassis | Mechanical structure |
| Wheels | Provides locomotion |

---

## 💻 Software & Technologies

- **Arduino IDE**
- **Embedded C/C++**
- **UART / Serial Communication**
- **Bluetooth Communication**
- **Digital I/O Interfacing**

---

## 🔌 System Architecture

```text
                 ┌─────────────────┐
                 │   IR Sensors    │
                 │ Obstacle Input  │
                 └────────┬────────┘
                          │
                          ▼
                  ┌───────────────┐
                  │    Arduino    │
                  │  Controller   │
                  └───────┬───────┘
                          │
              ┌───────────┴───────────┐
              │                       │
              ▼                       ▼
       ┌─────────────┐        ┌─────────────┐
       │ L293D Driver│        │ HC-05/HC-06 │
       │             │        │  Bluetooth  │
       └──────┬──────┘        └─────────────┘
              │
       ┌──────┴──────┐
       │             │
       ▼             ▼
    Motor 1       Motor 2
    (Left)        (Right)
