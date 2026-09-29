// Wiring:
// Green LED  -> D13
// Yellow LED -> D12
// Red LED    -> D11
// HC-SR04 Sensor:
// TRIG -> D9
// ECHO -> D10
// VCC  -> 5V
// GND  -> GND

const int greenLED = 13;
const int yellowLED = 12;
const int redLED = 11;

const int trigPin = 9;
const int echoPin = 10;

// Sensor and Timing Values
const float carThresholdCm = 8.0;
const unsigned long countTime = 10000;

// Setup Function
void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  allLightsOff();

  Serial.println("Traffic Light Car Counter Started");
  Serial.println("Pass Hot Wheels cars under/in front of the sensor one at a time.");
}
// Main Loop
void loop() {
  int carCount = countCars();

  int greenTime;
  int yellowTime;
  int redTime;

  if (carCount == 0) {
    greenTime = 3;
    yellowTime = 1;
    redTime = 3;
  } 
  else if (carCount == 1 || carCount == 2) {
    greenTime = 5;
    yellowTime = 3;
    redTime = 5;
  } 
  else {
    greenTime = 8;
    yellowTime = 5;
    redTime = 8;
  }

  Serial.println("----------------------");
  Serial.print("Cars counted: ");
  Serial.println(carCount);

  Serial.print("Green time: ");
  Serial.print(greenTime);
  Serial.println(" seconds");

  Serial.print("Yellow time: ");
  Serial.print(yellowTime);
  Serial.println(" seconds");

  Serial.print("Red time: ");
  Serial.print(redTime);
  Serial.println(" seconds");
  Serial.println("----------------------");

  runTrafficLight(greenTime, yellowTime, redTime);
}
// Car Counting Function
int countCars() {
  int carCount = 0;
  bool carCurrentlyDetected = false;

  unsigned long startTime = millis();

  Serial.println();
  Serial.println("Counting cars for 10 seconds...");

  while (millis() - startTime < countTime) {
    float distance = getDistanceCm();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance < carThresholdCm) {
      if (carCurrentlyDetected == false) {
        carCount++;
        carCurrentlyDetected = true;

        Serial.print("Car counted! Total cars = ");
        Serial.println(carCount);
      }
    } 
    else {
      carCurrentlyDetected = false;
    }

    delay(150);
  }

  return carCount;
}
// Distance Sensor Function
float getDistanceCm() {
  long duration;
  float distanceCm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  distanceCm = duration * 0.0343 / 2.0;
  return distanceCm;
}
// Traffic Light Function
void runTrafficLight(int greenTime, int yellowTime, int redTime) {
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  Serial.println("GREEN light");
  delay(greenTime * 1000);

  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  Serial.println("YELLOW light");
  delay(yellowTime * 1000);

  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  Serial.println("RED light");
  delay(redTime * 1000);

  allLightsOff();

  Serial.println("Cycle complete. Restarting car count...");
}
// Turn Off All Lights
void allLightsOff() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
}