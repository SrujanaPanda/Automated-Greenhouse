#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;
const int ledPin = 13;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);

  lcd.print("Greenhouse");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C ");

  if (temperature > 30) {
    digitalWrite(ledPin, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Cooling ON ");
  } 
  else {
    digitalWrite(ledPin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Normal Temp ");
  }

  delay(1000);
}
