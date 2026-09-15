# Time-Stamped Sensor Data Logger

## 📌 Project Overview

The **Time-Stamped Sensor Data Logger** is an embedded system developed using the **LPC2148 ARM7 microcontroller**. It measures temperature using an **LM35 temperature sensor** and records the sensor data along with the current date and time obtained from an **RTC (Real-Time Clock)**.

The measured data is displayed on an **LCD** and transmitted to a PC through **UART communication**. A keypad is provided to configure the RTC and temperature threshold. The system also generates an alert when the temperature exceeds the predefined limit.

## 🔧 Hardware Used

* LPC2148 ARM7 Microcontroller
* LM35 Temperature Sensor
* RTC
* 16x2 LCD
* 4x4 Keypad
* UART Interface
* Buzzer/Alert
* Power Supply

## 💻 Software Used

* Embedded C
* Keil uVision
* Flash Magic
* Proteus (for simulation)

## ⚙️ Key Features

* Real-time temperature monitoring
* Date and time stamping using RTC
* LCD display for sensor data
* UART communication with PC
* Keypad-based RTC configuration
* User-defined temperature threshold
* High-temperature alert
* Embedded C based firmware

## 🔄 Working Principle

```text
       LM35 Sensor
            ↓
       LPC2148 ARM7
       ↙     ↓      ↘
     RTC    LCD     UART
      ↓              ↓
 Date & Time        PC
            ↓
      Temperature
       Threshold
            ↓
      High Temp Alert
```

The **LM35** provides an analog temperature signal to the LPC2148. The microcontroller converts the analog signal using its **ADC**, obtains the current date and time from the **RTC**, and displays the information on the LCD. The data can also be sent to a PC through UART. If the temperature exceeds the configured threshold, an alert is generated.

## 🎯 Applications

* Temperature monitoring systems
* Industrial data logging
* Environmental monitoring
* Embedded monitoring applications
* Laboratory measurement systems

## 👨‍💻 Technologies

**Microcontroller:** LPC2148 ARM7
**Programming Language:** Embedded C
**Communication:** UART
**Sensor:** LM35
**Timekeeping:** RTC
**Display:** LCD
**Input:** Keypad

## 📂 Project Structure

```text
Time-Stamped-Sensor-Data-Logger/
│
├── Source/
│   └── *.c
│
├── Header/
│   └── *.h
│
├── Proteus/
│   └── Simulation files
│
├── Documentation/
│   └── Project documentation
│
└── README.md
```

## 🚀 Future Improvements

* Store sensor readings in external EEPROM/SD card
* Add multiple sensors
* Add wireless data transmission
* Develop a PC-based graphical monitoring application
* Add long-term data analysis and visualization

## 📄 License

This project is developed for **educational and embedded systems learning purposes**.
