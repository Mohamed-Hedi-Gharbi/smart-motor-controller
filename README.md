# Arduino Motor Control Project

## Description
This project provides an Arduino-based motor control system that enables precise control of two DC motors using serial communication. Commands can be sent via Bluetooth or a serial monitor to execute actions like moving forward, backward, turning left or right, and pausing. Ideal for robotics applications, this setup ensures reliable and responsive motor control.

---

## Features 🚀
- **Dual Motor Control:** Manage two DC motors (Motor A and Motor B) independently.
- **Command Support:**
  - **A**: Move forward ⬆️
  - **R**: Move backward ⬇️
  - **D**: Turn right ➡️
  - **G**: Turn left ⬅️
  - **P**: Pause (stop motors) ⏸️
- **PWM-Based Speed Control:** Enables smooth and efficient motor operation.
- **Real-Time Interaction:** Control motors through serial communication.
- **Safety Measures:** Motors halt automatically on invalid commands.

---

## Hardware Requirements 🛠️
- **Arduino Board:** Compatible with Uno, Mega, or Nano.
- **Motor Driver Module:** L298N.
- **DC Motors:** Two units.
- **Bluetooth Module:** Optional, for wireless control.
- **Power Supply:** Suitable for both the motors and Arduino board.

---

## Software Requirements 💻
- **Arduino IDE:** Version 1.8.0 or higher.
- **Serial Communication Interface:** Such as the Serial Monitor in Arduino IDE or a Bluetooth terminal app.

---

## Circuit Diagram ⚙️
### Connections for Motor A:
- **ENA (PWM pin):** Pin 10
- **IN1:** Pin 9
- **IN2:** Pin 8

### Connections for Motor B:
- **ENB (PWM pin):** Pin 5
- **IN3:** Pin 7
- **IN4:** Pin 6

### Power and Ground:
- Connect the power supply to the motor driver and Arduino.
- Ground all components to a common GND pin.

---

## Installation and Usage 📋

### 1. Upload the Code
1. Open the Arduino IDE.
2. Paste the provided code into the IDE.
3. Select the correct **Board** and **Port** from the "Tools" menu.
4. Click **Upload** to flash the code onto the Arduino.

### 2. Connect the Hardware
1. Assemble the circuit following the provided diagram.
2. Power on the Arduino and motor driver module.

### 3. Test the System
1. Open the Serial Monitor or a Bluetooth terminal app.
2. Set the baud rate to **9600**.
3. Use the following commands to control the motors:
   - `A` for forward ⬆️
   - `R` for backward ⬇️
   - `D` for turning right ➡️
   - `G` for turning left ⬅️
   - `P` to stop ⏸️

---

## Code Overview 🧑‍💻

### Setup
The setup initializes motor pins and configures serial communication:
```cpp
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}
```

### Main Loop
The main loop listens for serial input and processes commands:
```cpp
void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
      case 'A': Avancer(); break;
      case 'R': Reculer(); break;
      case 'D': Droite(); break;
      case 'G': Gauche(); break;
      case 'P': Pause(); break;
      default: Pause(); Serial.println("Invalid Command"); break;
    }
  }
}
```

---

## Safety Considerations ⚠️
- **Proper Grounding:** Ensure all components share a common ground to avoid electrical issues.
- **Power Supply:** Use a power source suitable for your motors to prevent overloading.
- **Command Handling:** Avoid sending conflicting commands rapidly to maintain smooth motor operation.

---

## Future Improvements 🌟
- **Obstacle Detection:** Integrate sensors like Ultrasonic or IR for enhanced functionality.
- **Wireless Control:** Extend capabilities with Bluetooth or Wi-Fi modules.
- **Speed Control Adjustments:** Allow speed modifications via serial commands.

---

## License 📜
This project is licensed under the MIT License. Refer to the LICENSE file for details.

---

## Author 👨‍💻
**Mohamed Hedi GHARBI**

For inquiries or suggestions, feel free to contact via GitHub or email.

