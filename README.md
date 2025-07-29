# Smart-Home-System
This repository contains the code for my Smart Home System, which I designed to remotely control my front door lock and bedroom lights.

The system uses two ESP32 boards working together:

&nbsp;-ESP32 (Door Lock): Connects to Wi-Fi and communicates with the Blynk IoT app for remote control.

&nbsp;-ESP32 (Room Light): Linked to the first ESP32 via ESP-NOW for seamless local device-to-device communication.

Both ESP32 boards are connected to servo motors, which serve as the physical mechanisms to lock/unlock the door and switch the light on/off.

Through the Blynk IoT app, I can easily control both devices with simple button presses, providing a convenient, wireless smart home solution.
