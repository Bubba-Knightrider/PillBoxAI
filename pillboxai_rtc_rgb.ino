#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68

int RedPin = 8;
int GreenPin = 9;
int BluePin = 10;

byte decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

void setup() {
  Serial.begin(9600);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  Wire.begin();
}

void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year) {
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x0E);
  Wire.write(0b00011100);
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(dayOfWeek));
  Wire.write(decToBcd(dayOfMonth));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.endTransmission();
}

void readDS3231time(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year) {
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}

void loop() {
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);

  if (hour == 17) {
    digitalWrite(RedPin, HIGH);
    digitalWrite(BluePin, LOW);
    digitalWrite(GreenPin, LOW);
    delay(1000);
  }

  Serial.print(hour); Serial.print(":");
  if (minute < 10) Serial.print("0"); Serial.print(minute); Serial.print(":");
  if (second < 10) Serial.print("0"); Serial.print(second); Serial.print(" ");
  Serial.print(dayOfMonth); Serial.print("/"); Serial.print(month); Serial.print("/"); Serial.println(year);
  delay(1000);
}
