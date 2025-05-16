# ESP32 + Raspberry Pi Wi-Fi Recon Tool

A simple but powerful wireless reconnaissance tool using an ESP32 microcontroller and a Raspberry Pi.

## 🔍 What It Does

- ESP32 scans for nearby Wi-Fi access points
- Sends scan results to a Flask server on a Raspberry Pi over HTTP
- Raspberry Pi saves the data to a text file (`wifi_scans.txt`)

This project can be used for passive reconnaissance, wireless footprinting, or as the foundation for real-time alerting or visualisations.

## 🛠️ Hardware

- ESP32 Dev Board (ESP-WROOM-32)
- Raspberry Pi 5 running Raspberry Pi OS
- Micro-USB cable
- Wi-Fi network

## 🧠 How It Works

1. ESP32 connects to your Wi-Fi
2. Scans all visible SSIDs and MACs
3. Sends results via HTTP POST to a Flask app running on the Pi
4. Flask receives and logs them to disk

## 🚀 Setup Instructions

### ESP32 Setup

1. Flash `esp32_scanner.ino` using Arduino IDE
2. Update `ssid`, `password`, and `serverUrl` with your Wi-Fi and Pi's IP address

### Flask Server Setup (on Pi)

```bash
sudo apt update
sudo apt install python3-flask
python3 wifi_receiver.py
