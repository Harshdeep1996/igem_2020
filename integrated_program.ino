#include <Wire.h>
#include "SFE_ISL29125.h"
#include <SPI.h>
#include <SD.h>

bool OD_MESUREMENT = false;
bool verbose = true;


/*
 * Relative to the TSL235r
 */
int tsl_input_pin = 2;
volatile unsigned long cnt = 0;
unsigned long oldcnt = 0;
unsigned long t = 0;
unsigned long last;
void irq1()
{
  cnt++;
}

// Welcome attentive viewer, who paused the video to see what the code looks like! 
//Great job...

/* 
 *  Relative to the white LED
 */
int white_light_pin = 3;
/*
 * Relative to the RGB light sensor
 */
 SFE_ISL29125 RGB_sensor;

int red_low = 480;
int red_high = 3860;
int green_low = 770;
int green_high = 5950;
int blue_low = 575;
int blue_high = 4400;

/*
 * Relative to the yellow LED
 */
int yellow_light_pin = 4;
 
/*
 * Main
 */

int switch_cnt = 0;
int THRESHOLD = 10;


// for the temperature sensor
unsigned long previousMillis = 0;
const int outputPin_tmp = 5;
const int temperaturePin = A0;

void switch_mode(){
  switch_cnt = 0;
  OD_MESUREMENT = !OD_MESUREMENT;

  if (verbose){
    Serial.println("SWITCH!");
  }
  if (OD_MESUREMENT){
    if(verbose){
      Serial.println("Start OD mesurement");
    }
    tsl_input_pin = 2;
    cnt = 0;
    oldcnt = 0;
    t = 0;
    last = millis();
    digitalWrite(yellow_light_pin, LOW);
    digitalWrite(white_light_pin, HIGH);
  } else {
    if(verbose){
      Serial.print("Start fluorescence mesurement ");
      Serial.println("(using yellow led approx 580 nm)");
    }
    digitalWrite(yellow_light_pin, HIGH);
    digitalWrite(white_light_pin, LOW);
  }
}

void setup() {
  Serial.begin(9600);

  //TSL235r setup
  Serial.println("START");
  pinMode(tsl_input_pin, INPUT);
  digitalWrite(tsl_input_pin, HIGH);
  attachInterrupt(0, irq1, RISING);

  //Yellow LED setup
  pinMode(yellow_light_pin, OUTPUT);

  //White LED setup
  pinMode(white_light_pin, OUTPUT);

  pinMode(outputPin_tmp, OUTPUT);
  
  //RGB light sensor setup
  if (RGB_sensor.init()){
    Serial.println("Sensor Initialization Successful\n\r");
  }
  switch_mode();
}

void od_mesurements(){
    if (millis() - last >= 1000){      
      switch_cnt += 1;
      last = millis();
      t = cnt;
      unsigned long hz = t - oldcnt;
      
      Serial.print("FREQ: "); 
      Serial.print(hz);
      Serial.print("\t = "); 
      Serial.print((hz+50)/100);  // +50 == rounding last digit
      Serial.println(" mW/m2");
      oldcnt = t;
    }
}

void fluo_mesurements(){      
  switch_cnt += 1;

  unsigned int red = RGB_sensor.readRed();
  unsigned int green = RGB_sensor.readGreen();
  unsigned int blue = RGB_sensor.readBlue();

  int redV = map(red, red_low, red_high, 0, 255);
  int redVal = constrain(redV, 0, 255);

  int greenV = map(green, green_low, green_high, 0, 255);
  int greenVal = constrain(greenV, 0, 255);

  int blueV = map(blue, blue_low, blue_high, 0, 255);
  int blueVal = constrain(blueV, 0, 255);
  
  Serial.print("Red: "); Serial.print(redVal);
  Serial.print(", ");
  Serial.print("Green: "); Serial.print(greenVal);
  Serial.print(", ");
  Serial.print("Blue: "); Serial.print(blueVal);
  Serial.println();
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}

const int total_interval = 25000;

void loop() {

  float voltage, degreesC;
  boolean switcher;
  
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
//  Serial.print("  deg C: ");
//  Serial.println(degreesC);

  // unsigned long currentMillis = millis();


  if(previousMillis >= total_interval) {
    previousMillis = 0;
  }

  if (degreesC > 31){
    digitalWrite(outputPin_tmp, LOW);
    delay(8000);
    previousMillis += 8000;
  }
  if (degreesC < 29){
    if (degreesC < 20) {
      digitalWrite(outputPin_tmp, LOW);
      delay(8000);
      previousMillis += 8000;
   } else {
       digitalWrite(outputPin_tmp, HIGH);
       delay(3000);
       previousMillis += 3000;
   }
  }

  if((previousMillis + 3000 >= total_interval) && (previousMillis + 8000 >= total_interval) && (previousMillis > total_interval)) {
    //if(switch_cnt == THRESHOLD){
    //  switch_mode();
    //}
    // put your main code here, to run repeatedly:
    //if (OD_MESUREMENT){
     od_mesurements();
    //} else {
    //fluo_mesurements();
    //}
  }
  // delay(2000);
}
