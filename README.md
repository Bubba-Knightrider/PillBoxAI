# PillBox AI – Smart Medication Assistant

PillBox AI is a real-time, intelligent medication management system that combines embedded hardware, wireless communication, and cloud-enabled interfaces. It assists users in maintaining medication schedules with reminders, logs, and alerts—accessible via both a web interface and mobile application. The system is built using ESP32 and supports Bluetooth and Wi-Fi connectivity.

##Project Features

- Timely reminders and notifications
- Smart pill dispensing system (motorized or sensor-logged)
- ESP32-based embedded firmware
- BLE connectivity to mobile devices
- Wi-Fi support for cloud sync
- Web dashboard for caregivers or user tracking
- Secure data logging and history

## Highlights

- Microcontroller: ESP32 Dual Core
- Communication: BLE, Wi-Fi (MQTT or RESTful API)
- Local Control: Web server via ESP32 captive portal
- Web Dashboard: Real-time pill schedule and logs
- App Sync: BLE connection for logs and command
- Intelligent Reminders: Based on usage trend and missed doses
- Expandable: Support for multiple pill slots and users

## Technologies Used
Embedded System:
  - ESP32 (Arduino framework)
  - IR/Hall sensors for compartment access
  - Servo/motor control
  - DHT sensor (optional)

Wireless Communication:
  - Bluetooth Low Energy (BLE)
  - Wi-Fi (MQTT or HTTP)

Web Interface:
  - HTML, CSS, JavaScript (React)
  - ESP32-hosted local server or external web app

Mobile App:
  - Flutter
  - BLE communication, local sync

Cloud Services:
  - Firebase / Node.js backend
  - Google Sheets or SQLite for logs

## System Architecture

[PillBox Unit] → [ESP32 MCU] → BLE/Wi-Fi → [Mobile App or Web Dashboard] → [Logs / Alerts / Cloud Services]

## Future Advancements

  - AI-based dose prediction (delays, patterns)
  - Offline logging with local mobile fallback
  - Caregiver alerts with role-based access
  - OTA firmware upgrades
  - Pill ID using camera or RFID integration

## Contributions

# Fork this repository
# Create your feature branch
# Commit your changes
# Submit a Pull Request
