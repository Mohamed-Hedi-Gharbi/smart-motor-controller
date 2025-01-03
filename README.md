# Arduino Motor Control Project

## Description
This project provides an Arduino-based motor control system that allows the user to control two DC motors using serial communication. Commands are sent via Bluetooth or a serial monitor to perform actions like moving forward, backward, turning left or right, and pausing. This setup is ideal for robotics applications where precise motor control is required.

---

## Features 🚀
- **Control two DC motors** (Motor A and Motor B) independently.
- Support for the following commands:
  - **A**: Move forward ⬆️
  - **R**: Move backward ⬇️
  - **D**: Turn right ➡️
  - **G**: Turn left ⬅️
  - **P**: Pause (stop motors) ⏸️
- **PWM-based speed control** for smooth and efficient motor operation.
- **Serial communication** for real-time interaction.
- **Safety measures** to halt the motors on invalid commands.

---

## Hardware Requirements 🛠️
- Arduino board (e.g., Uno, Mega, Nano).
- L298N motor driver module.
- Two DC motors.
- Bluetooth module (optional, for wireless control).
- Power supply suitable for motors and Arduino.

---

## Software Requirements 💻
- Arduino IDE version 1.8.0 or higher.
- Serial communication interface (e.g., Serial Monitor in Arduino IDE or a Bluetooth terminal app).

---

## Circuit Diagram ⚙️
The circuit connections are as follows:
- **Motor A**
  - ENA (PWM pin): Pin 10
  - IN1: Pin 9
  - IN2: Pin 8
- **Motor B**
  - ENB (PWM pin): Pin 5
  - IN3: Pin 7
  - IN4: Pin 6

Ensure to connect the power supply to the motor driver and Arduino. Ground all components to a common GND pin.

---

## Installation and Usage 📋

### 1. Upload the Code
1. Open the Arduino IDE.
2. Copy the provided code into the IDE.
3. Select the correct **Board** and **Port** under the "Tools" menu.
4. Click **Upload** to flash the code onto the Arduino.

### 2. Connect the Hardware
1. Assemble the circuit as per the circuit diagram.
2. Power up the Arduino and motor driver module.

### 3. Test the System
1. Open the Serial Monitor in the Arduino IDE or a Bluetooth terminal app.
2. Set the baud rate to **9600**.
3. Send the following commands to control the motors:
   - `A` for forward ⬆️.
   - `R` for backward ⬇️.
   - `D` for right turn ➡️.
   - `G` for left turn ⬅️.
   - `P` to stop ⏸️.

---

## Code Overview 🧑‍💻
The program uses the following key components:

### Setup
Initializes the motor pins and configures serial communication:
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
Waits for serial input and processes commands:
```cpp
void loop() {
  if (Serial.available()) {
    command = Serial.read();
    switch (command) {
      case 'A': Avancer(); break;
      case 'R': Reculer(); break;
      case 'D': Droite(); break;
      case 'G': Gauche(); break;
      case 'P': Pause(); break;
      default: Pause(); Serial.println("Commande invalide"); break;
    }
  }
}
```

---

## Safety Considerations ⚠️
- Always ensure proper grounding to avoid electrical hazards.
- Use a suitable power supply for the motors to prevent overloading.
- Avoid sending multiple conflicting commands rapidly to maintain smooth operation.

---

## Future Improvements 🌟
- Add obstacle detection using sensors like Ultrasonic or IR.
- Implement a wireless control system with Bluetooth or Wi-Fi.
- Include speed control adjustments via serial commands.

---

## License 📜
This project is licensed under the MIT License. See the LICENSE file for more details.

---

## Author 👨‍💻
**Mohamed-Hedi Gharbi**

For any queries or suggestions, feel free to contact via GitHub or email.

