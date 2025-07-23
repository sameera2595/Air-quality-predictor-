#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2       // DHT11 connected to pin 2
#define DHTTYPE DHT11

#define MQPIN A0       // MQ135 sensor analog output to A0
#define BUZZER_PIN 3   // Buzzer connected to pin 3

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 columns, 2 rows
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Air Quality Init");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensors
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  int mqValue = analogRead(MQPIN);  // 0-1023 value

  // Check sensor read errors
  if (isnan(temp) || isnan(humi)) {
    lcd.setCursor(0, 0);
    lcd.print("DHT error");
    digitalWrite(BUZZER_PIN, LOW);
    delay(2000);
    return;
  }

  // Convert MQ135 reading to "PPM-like" value (rough)
  float ppm = map(mqValue, 0, 1023, 0, 1000);  // scale to 0-1000 PPM

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp, 1);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(humi, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("AQI:");
  lcd.print(ppm, 0);
  lcd.print("ppm   ");

  // Print to serial
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("C  Hum: ");
  Serial.print(humi);
  Serial.print("%  AQI: ");
  Serial.print(ppm);
  Serial.println("ppm");

  // Buzzer alert for bad air quality
  if (ppm > 100) {  // adjust threshold if needed
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(3000);  // update every 3 seconds
}
