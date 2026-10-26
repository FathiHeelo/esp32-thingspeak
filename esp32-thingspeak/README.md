# ESP32 → ThingSpeak: Live Temperature & Humidity Monitoring

## Project Description
This project reads temperature and humidity from a DHT22 sensor connected to an ESP32 and sends the readings to ThingSpeak every 20 seconds over Wi-Fi. The data is displayed publicly using ThingSpeak's built-in charts.

## Student Information
- **Full Name:** Fathi Heelo
- **University ID:** 12323885

## Links
- **ThingSpeak Public URL:** https://thingspeak.com/channels/3551681
- **Wokwi Project:** [paste Wokwi link here]

## Hardware / Simulation
- ESP32 Dev Board (simulated in Wokwi)
- DHT22 temperature and humidity sensor

## Wiring
| DHT22 Pin  | ESP32 Pin |
|------------|-----------|
| VCC        | 3V3       |
| SDA (DATA) | GPIO 15   |
| GND        | GND       |

The NC pin of the DHT22 is not connected.

## ThingSpeak Channel Setup
- **Channel name:** Fathi_Heelo_12323885
- **Channel ID:** 3551681
- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)
- **Access:** Public

## How It Works
1. The ESP32 connects to Wi-Fi (Wokwi-GUEST network in the simulator).
2. Every 20 seconds, it reads temperature and humidity from the DHT22 on GPIO 15.
3. It sends both values to ThingSpeak with an HTTP GET request.
4. The University ID is printed to the Serial Monitor with each reading.

## Screenshots
- ThingSpeak channel page: `screenshots/channel_page.png`
- Live temperature graph: `screenshots/temperature_graph.png`
- Live humidity graph: `screenshots/humidity_graph.png`
- Wokwi simulation: `screenshots/wokwi_setup.png`

## Repository Contents
- `sketch.ino`: ESP32 source code
- `diagram.json`: Wokwi circuit diagram
- `screenshots/`: Proof of working system
- `README.md`: Project documentation

## Setup Notes
Replace `YOUR_WRITE_API_KEY` in `sketch.ino` with your own ThingSpeak Write API Key before running.
