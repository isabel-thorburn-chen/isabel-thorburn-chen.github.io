#include <Arduino.h>
#include <AccelStepper.h>

const uint8_t RED_PIN = 12;
const uint8_t GREEN_PIN = 11;
const uint8_t BLUE_PIN = 10;

const uint8_t DIR_PIN = 8;
const uint8_t STEP_PIN = 9;
const uint8_t START_PIN = 7;
const uint8_t BACK_PIN = 6;
const uint8_t FORWARD_PIN = 5;
const uint8_t STOP_PIN = 13;

const float WIDTH_10ML = 0.59; //cm/mL conversion factor, or mm/0.1mL
const float WIDTH_20ML = 0.35; //cm/mL conversion factor, or mm/0.1mL

uint16_t FLOW_RATE = 50; //units of 0.1 mL/min or 100 uL/min
uint8_t SYRINGE_DIA = 2; //either 1 for 10mL or 2 for 20mL
uint16_t MICRO_STEP = 32; //microstepping setting on the stepper driver
uint16_t STEP_RATE;

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void ledColor(char color);
bool runStepper(uint16_t step_rate);
float getStepRate(uint16_t flow_rate, uint8_t syringe_dia);
void readPins(); //Print function for debugging

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(START_PIN, INPUT_PULLUP);
  pinMode(STOP_PIN, INPUT_PULLUP);
  pinMode(FORWARD_PIN, INPUT_PULLUP);
  pinMode(BACK_PIN, INPUT_PULLUP);
  stepper.setMaxSpeed(1000);

  Serial.begin(9600);
  Serial.println("Setup Complete");
  STEP_RATE = getStepRate(FLOW_RATE, SYRINGE_DIA);
}

void loop()
{
  //Serial.println("-----");
  //readPins();
  while(digitalRead(START_PIN) == LOW)
  {
    runStepper(0);
    ledColor('Y');
    if(digitalRead(FORWARD_PIN) == LOW)
    {
      digitalWrite(DIR_PIN, HIGH); // Set direction to forward
      runStepper(800);
    }
    if(digitalRead(BACK_PIN) == LOW)
    {
      digitalWrite(DIR_PIN, LOW); // Set direction to forward
      runStepper(800);
    }

    digitalWrite(DIR_PIN, HIGH); // Set direction to forward
  }
  while(digitalRead(STOP_PIN) == HIGH && digitalRead(START_PIN) == HIGH)
  {
    ledColor('R');
    // Stop the stepper motor
    runStepper(0);
    delay(100);
  }
  ledColor('G');
  runStepper(STEP_RATE);
}

void ledColor(char color) {
  switch (color) {
    case 'G':
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
      break;
    case 'Y':
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
      break;
    case 'R':
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      break;
    case 'O':
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      break;
    default:
      // Turn off all LEDs if an invalid color is provided
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
  }
}

bool runStepper(uint16_t step_rate) {
  stepper.setSpeed(step_rate);
  stepper.runSpeed();
  return true;
}

float getStepRate(uint16_t flow_rate, uint8_t syringe_dia) {
  float step_rate = 0.0;
  if (syringe_dia == 1) {
    step_rate = (flow_rate * (1/60) * 0.125 * WIDTH_10ML * MICRO_STEP * 100); // Convert to steps/s
  } else if (syringe_dia == 2) {
    step_rate = (flow_rate * (1/60) * 0.125 * WIDTH_20ML * MICRO_STEP * 100); // Convert to steps/s
  }
  Serial.println("Calculated Step Rate: " + String(step_rate) + " steps/s");
  return step_rate;
}

void readPins() {
  int startVal = digitalRead(START_PIN);
  int stopVal = digitalRead(STOP_PIN);
  int forwardVal = digitalRead(FORWARD_PIN);
  int backVal = digitalRead(BACK_PIN);
  Serial.println("");
  Serial.println("Start Pin: " + startVal);
  Serial.println("Stop Pin: " + stopVal);
  Serial.println("Forward Pin: " + forwardVal);
  Serial.println("Back Pin: " + backVal);
  Serial.println("-----");
}
