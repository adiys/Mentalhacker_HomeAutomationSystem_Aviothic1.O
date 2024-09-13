# Home Automation System Using ESP8266 and Blynk

## Overview

This project is a **Home Automation System** built using the **ESP8266 NodeMCU** module and **Blynk IoT** platform. The system integrates multiple sensors, including a **gas sensor (MQ2)**, a **temperature and humidity sensor (DHT11)**, a **PIR motion sensor**, and an **ultrasonic sensor**. Additionally, it provides control over two relays and a buzzer for various automation and alert functions. The project also features an **LCD display (I2C)** to show real-time sensor readings.

## Features

- **Gas Leak Detection**: Monitors air quality with the MQ2 sensor and triggers an alarm if gas leakage is detected.
- **Temperature & Humidity Monitoring**: Uses the DHT11 sensor to provide temperature and humidity data, displayed on both the Blynk app and the LCD.
- **Motion Detection**: Uses a PIR sensor to detect motion and send alerts.
- **Distance Measurement**: Uses an ultrasonic sensor to detect distance or water level, displayed in the app and on the LCD.
- **Relay Control**: Provides control over two electrical appliances via relays through the Blynk app.
- **Buzzer Alerts**: Activates the buzzer when necessary (e.g., gas leak or motion detected).
- **LCD Display**: Real-time display of gas levels, temperature, humidity, and distance data.

## Hardware Components

- **ESP8266 NodeMCU** module
- **DHT11** (Temperature and Humidity Sensor)
- **MQ2** (Gas Sensor)
- **PIR** (Motion Sensor)
- **Ultrasonic Sensor** (HC-SR04)
- **2-channel Relay Module**
- **16x2 LCD (I2C)**
- **Buzzer**
- Connecting wires and a breadboard

## Software Requirements

- **Arduino IDE** with ESP8266 Board Manager installed.
- **Blynk Library**.
- **LiquidCrystal I2C Library**.
- **DHT Sensor Library**.

## Circuit Connections

1. **Buzzer**: Pin D0
2. **MQ2 Gas Sensor**: Analog pin A0
3. **Ultrasonic Sensor**:
   - Trigger Pin: D4
   - Echo Pin: D5
4. **PIR Sensor**: Pin D6
5. **Relay 1**: Pin D7
6. **Relay 2**: Pin D8
7. **DHT11 Sensor**: Pin D3
8. **LCD (I2C)**: Connected to I2C pins (SDA and SCL)

## Blynk App Configuration

- **Virtual Pin V0**: PIR sensor activation (1/0).
- **Virtual Pin V1**: Gas sensor value.
- **Virtual Pin V2**: Temperature value.
- **Virtual Pin V3**: Humidity value.
- **Virtual Pin V4**: Ultrasonic sensor value.
- **Virtual Pin V5**: Relay 1 control.
- **Virtual Pin V6**: Relay 2 control.

## Installation

1. Clone the repository and open the project in the **Arduino IDE**.
2. Install the required libraries:
   - **Blynk**: `Arduino IDE > Sketch > Include Library > Manage Libraries > Search Blynk`
   - **LiquidCrystal I2C**: `Arduino IDE > Sketch > Include Library > Manage Libraries > Search LiquidCrystal I2C`
   - **DHT Sensor Library**: `Arduino IDE > Sketch > Include Library > Manage Libraries > Search DHT`
3. Connect the hardware components as per the circuit diagram.
4. Replace the following placeholders in the code:
   - **`auth[]`**: Your Blynk authentication token.
   - **`ssid[]`**: Your WiFi network name (SSID).
   - **`pass[]`**: Your WiFi password.
5. Upload the code to the **ESP8266 NodeMCU**.
6. Configure the Blynk app according to the specified virtual pins.

## How It Works

1. **Gas Sensor (MQ2)**: Continuously monitors the air for harmful gases. If the gas level exceeds a set threshold, an alert is sent to the Blynk app, and the buzzer is triggered.
2. **Temperature & Humidity Sensor (DHT11)**: Reads and displays temperature and humidity values on the LCD and sends the data to the Blynk app.
3. **PIR Motion Sensor**: Detects movement when activated through the app and triggers the buzzer in case of motion.
4. **Ultrasonic Sensor**: Measures the distance or water level and displays it on the LCD and app.
5. **Relay Control**: Allows control over two appliances via the Blynk app.

## Usage

- The system automatically starts reading from the connected sensors and displaying the values on the LCD and Blynk app.
- Use the Blynk app to monitor sensor values and control the relays for home automation.
- The buzzer will be activated automatically when a gas leak or motion is detected.
- You can turn on/off the relays using virtual pins in the Blynk app.

## Contributions

Feel free to open an issue or submit a pull request if you'd like to contribute to improving the system.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

