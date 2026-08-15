# Smart Environmental Monitoring System using ESP32

## Project Overview

This project is an ESP32-based environmental monitoring system that measures temperature and humidity using a DHT22 sensor. The measured values are displayed on an SSD1306 OLED display. An LED alert is activated when the temperature exceeds a predefined limit.

## Features

* Measures temperature using DHT22 sensor
* Measures humidity using DHT22 sensor
* Displays temperature and humidity on OLED display
* Shows sensor readings in the Serial Monitor
* Turns ON an LED when temperature exceeds 30°C
* Updates sensor readings every 2 seconds

## Components Used

* ESP32 Development Board
* DHT22 Temperature and Humidity Sensor
* SSD1306 OLED Display
* LED

## Pin Connections

| Component   | ESP32 Pin |
| ----------- | --------- |
| DHT22 VCC   | 3V3       |
| DHT22 DATA  | GPIO 15   |
| DHT22 GND   | GND       |
| LED Anode   | GPIO 2    |
| LED Cathode | GND       |
| OLED VCC    | 3V3       |
| OLED GND    | GND       |
| OLED SDA    | GPIO 21   |
| OLED SCL    | GPIO 22   |

## Working

1. The DHT22 sensor measures the temperature and humidity.
2. ESP32 reads the sensor data.
3. The temperature and humidity values are displayed on the OLED screen.
4. The values are also displayed in the Serial Monitor.
5. If the temperature exceeds 30°C, the LED turns ON as an alert.
6. The system updates the readings every 2 seconds.

## Software Used

* Wokwi Simulator
* Arduino IDE
* GitHub

## Project Files

* `main.ino` - ESP32 source code
* `README.md` - Project documentation

## Future Improvements

* Send sensor data to the cloud using Wi-Fi
* Integrate ThingSpeak for IoT monitoring
* Add a buzzer for alerts
* ## Circuit Diagram

![Smart Environmental Monitoring System](smart%20environment%20monitor.png)
* Add a mobile or web dashboard
* Store historical temperature and humidity data
