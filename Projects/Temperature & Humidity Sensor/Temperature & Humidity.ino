#include <DHT.h>
#include <LiquidCrystal.h>

// SETTINGS
const int TEMP_LOW = 70;
const int TEMP_HIGH = 80;
const int HUMIDITY_LOW = 30;
const int HUMIDITY_HIGH = 40;

#define DHTPin A0
const int buzzer = 7;
const int greenLED = 2;
const int redLED = 4;
const int blueLED = 5;
const int rs = 12, en = 13, d4 = 11, d5 = 10, d6 = 9, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPin, DHT11);

int humidity;
int temperature;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  //SENSOR STUFF
  Serial.begin(9600);
  dht.begin();
  
  beep(200);
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(blueLED, HIGH);
  
  // SETUP LCD
  lcd.noDisplay();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("SmartyPlant v1.0");
  lcd.setCursor(0,1);
  lcd.print("Zachary Khan");
  lcd.noCursor();
  lcd.display();
 
  delay(5000);
  beep(100); 
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature(true);

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    return;
  }

  printToLCD();
  setLED();
  delay(10000);
}



void beep(int delayInSeconds) {
  digitalWrite(buzzer, HIGH);
  delay(delayInSeconds);
  digitalWrite(buzzer, LOW);
}

void setLED() {
  if (temperature >= TEMP_LOW && temperature <= TEMP_HIGH) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    
    beep(100);
    delay(50);
    beep(100);
  }

  if (humidity >= HUMIDITY_LOW && humidity <= HUMIDITY_HIGH) {
    digitalWrite(blueLED, LOW);
  } else {
    digitalWrite(blueLED, HIGH);
    beep(100);
    delay(50);
    beep(100);
    delay(50);
    beep(100);
  }
  
}

void printToLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("F");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
}
