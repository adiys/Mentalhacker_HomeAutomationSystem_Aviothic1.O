
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = "TYhbgTVpvGzadqa7RW_XoftUUXUIXvWa";
char ssid[] = "Abhay";
char pass[] = "abhay10818";

DHT dht(D3, DHT11); //(sensor pin,sensor type)
BlynkTimer timer;
bool pirbutton = 0;

// Define component pins
#define Buzzer D1
#define MQ2 D2
#define trig D3
#define echo D4
#define PIR D5
#define relay1 D6
#define relay2 D7

//Get buttons values
BLYNK_WRITE(V0) {
  
  pirbutton = param.asInt();
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(Buzzer, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Home Automation");
  lcd.setCursor(4, 1);
  lcd.print("System");
  delay(4000);
  lcd.clear();

//Call the functions
  timer.setInterval(100L, gassensor);
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(100L, pirsensor);
  timer.setInterval(100L, ultrasonic);
}

//Get the MQ2 sensor values
void gassensor() {
  int value = analogRead(MQ2);
  Serial.println(value);
  value = map(value, 0, 1024, 0, 100);
  if (value <= 55) {
    digitalWrite(Buzzer, LOW);
  } else if (value > 55) {
    Blynk.logEvent("gas","Warning! Gas leak detected");
    digitalWrite(Buzzer, HIGH);
  }
  Blynk.virtualWrite(V1, value);
  lcd.setCursor(0, 0);
  lcd.print("G:");
  lcd.print(" ");
  lcd.print(value);

}

//Get the DHT11 sensor values
void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);

  lcd.setCursor(8, 0);
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(h);

}

//Get the PIR sensor values
void pirsensor() {
  bool value = digitalRead(PIR);
  if (pirbutton == 1) {
    if (value == 0) {
      digitalWrite(Buzzer, LOW);
    } else if (value == 1) {
     Blynk.logEvent("pir","Warning! Please check your security system");
      digitalWrite(Buzzer, HIGH);
    }
  }
}

//Get the ultrasonic sensor values
void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Blynk.virtualWrite(V4, cm);

  lcd.setCursor(8, 1);
  lcd.print("W:");
  lcd.print(cm);
  lcd.print("  ");
}

//Get buttons values
BLYNK_WRITE(V5) {
 bool RelayOne = param.asInt();
  if (RelayOne == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}

//Get buttons values
BLYNK_WRITE(V6) {
 bool RelayTwo = param.asInt();
  if (RelayTwo == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

//Get buttons values
BLYNK_WRITE(V7) {
 bool RelayThree = param.asInt();
  if (RelayThree == 1) {
    digitalWrite(relay3, LOW);
  } else {
    digitalWrite(relay3, HIGH);
  }
}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}