const int outputPin = 3;
const int temperaturePin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  
  
}

void loop() {
  float voltage, degreesC;
  boolean switcher;
  
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
  Serial.print("  deg C: ");
  Serial.println(degreesC);

  if (degreesC > 31){
    digitalWrite(outputPin, LOW);
  }
  if (degreesC < 29){
    digitalWrite(outputPin, HIGH);
  }
  
  delay(100);

}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
