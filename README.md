# 🌫 Air Quality Predictor using Arduino UNO

A simple and effective embedded system to *predict air quality levels* using *Arduino UNO, **MQ135 Gas Sensor, and **DHT11 Temperature & Humidity Sensor*. The system displays real-time air quality and weather data on an LCD screen.

---

## 📸 Project Preview

![Circuit Diagram](![w1](https://github.com/user-attachments/assets/b15650c6-768e-45b9-adc3-b4a0af8cd31d))
![Project Models](![w3](https://github.com/user-attachments/assets/f01eb530-96f1-44c6-ade9-e7b811ef6b08))
![w4](https://github.com/user-attachments/assets/87575cb0-fa7d-4cde-9911-f9e5413710b4)


---

## 🔧 Components Used

- Arduino UNO
- MQ135 Gas Sensor (Air Quality)
- DHT11 Sensor (Temperature & Humidity)
- 16x2 LCD Display with I2C Module
- Breadboard and Jumper Wires
- USB Cable for Arduino

---

## ⚙ Working Principle

- *MQ135* detects hazardous gases and VOCs (e.g., CO2, NH3).
- *DHT11* measures ambient temperature and humidity.
- *Arduino UNO* reads the sensor data, calculates AQI (basic estimation), and displays it on the LCD.
- LCD shows:
  - Temperature (°C)
  - Humidity (%)
  - Air Quality (Good / Moderate / Poor)

---

## 🖥 How to Use

1. Connect the components as shown in the circuit diagram.
2. Upload the Arduino code using the Arduino IDE.
3. Power the Arduino board.
4. Observe live temperature, humidity, and air quality levels on the LCD screen.

---

## 🧠 Learning Outcomes

- Hands-on experience with sensors (MQ135 & DHT11)
- Understanding analog and digital I/O with Arduino
- Interfacing LCD using I2C
- Data interpretation for real-world environment monitoring
- Beginner-level embedded system integration

---

## 💡 Project Inspiration

This project was inspired by the growing need for *environmental awareness* and air quality tracking in urban and rural areas. It is especially useful for:
- Science fairs / Engineering expos
- Learning embedded electronics
- Building awareness of environmental issues

---


## 🧑‍🔬 Future Improvements

- Add *WiFi module (ESP8266)* to upload data to the cloud
- Build a *web dashboard* for remote AQI monitoring
- Use *BME680* or *SDS011* for more accurate AQI readings
- Send alerts via email/SMS when pollution levels exceed safe limits

---

## 📢 Author

Project by Sameera Suthapalli  
💬 Feel free to raise an issue or connect!

---
