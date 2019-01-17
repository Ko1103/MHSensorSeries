
int sensorPin = A0;
int sensorValue = 0;
int percent = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  percent = convertToPercent(sensorValue);
  printValuesToSerial();
  delay(1000);
}

int convertToPercent(int value) {
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  if (percentValue > 100) {
    percentValue = 100;
  }
  return percentValue;
}

void printValuesToSerial() {
  Serial.print("センサーの値：");
  Serial.println(sensorValue);
  Serial.print("パーセント：");
  Serial.println(percent);
}
