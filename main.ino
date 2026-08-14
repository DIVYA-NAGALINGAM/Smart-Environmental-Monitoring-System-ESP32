#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// DHT22 settings
#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// LED pin
#define LED_PIN 2

void setup() {

  // Start Serial Monitor
  Serial.begin(115200);

  // Start DHT22 sensor
  dht.begin();

  // Set LED as output
  pinMode(LED_PIN, OUTPUT);

  // Start OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.println("Environmental");
  display.println("Monitoring System");

  display.display();

  delay(2000);
}

void loop() {

  // Read humidity
  float humidity = dht.readHumidity();

  // Read temperature
  float temperature = dht.readTemperature();

  // Check if sensor reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read DHT22!");
    return;
  }

  // Print values in Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Display values on OLED
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Environmental Monitor");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("T:");
  display.print(temperature);
  display.println("C");

  display.setCursor(0, 45);
  display.print("H:");
  display.print(humidity);
  display.println("%");

  display.display();

  // Temperature alert
  if (temperature > 30) {
    digitalWrite(LED_PIN, HIGH);
  } 
  else {
    digitalWrite(LED_PIN, LOW);
  }

  // Wait before next reading
  delay(2000);
}
