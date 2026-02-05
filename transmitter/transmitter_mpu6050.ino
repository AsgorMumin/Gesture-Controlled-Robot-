#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Motor pins (D2–D5)
#define IN1 2   // Left motor forward
#define IN2 3   // Left motor backward
#define IN3 4   // Right motor backward
#define IN4 5   // Right motor forward

// Calibration margins (less sensitive)
const int AX_MARGIN = 2500;
const int AY_MARGIN = 2500;

// Neutral values
int ax_neutral = 0;
int ay_neutral = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  if (!mpu.testConnection()) {
    Serial.println("❌ MPU6050 NOT connected!");
    while (1);
  }

  Serial.println("✅ MPU6050 connected");
  calibrateMPU();
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  String gesture = "STOP";
  int D2v = 0, D3v = 0, D4v = 0, D5v = 0;

  // FORWARD → 1001
  if (ax < ax_neutral - AX_MARGIN) {
    gesture = "FORWARD";
    D5v = 1; D4v = 0; D3v = 0; D2v = 1;
  }

  // BACKWARD → 0110
  else if (ax > ax_neutral + AX_MARGIN) {
    gesture = "BACKWARD";
    D5v = 0; D4v = 1; D3v = 1; D2v = 0;
  }

  // LEFT → 0100
  else if (ay > ay_neutral + AY_MARGIN) {
    gesture = "LEFT";
    D5v = 0; D4v = 1; D3v = 0; D2v = 0;
  }

  // RIGHT → 0010
  else if (ay < ay_neutral - AY_MARGIN) {
    gesture = "RIGHT";
    D5v = 0; D4v = 0; D3v = 1; D2v = 0;
  }

  else {
    stopMotors();
    Serial.println("Gesture: STOP | Binary: 0000");
    delay(200);
    return;
  }

  // Apply motor signals
  digitalWrite(IN1, D2v);
  digitalWrite(IN2, D3v);
  digitalWrite(IN3, D4v);
  digitalWrite(IN4, D5v);

  // Serial Monitor Output
  Serial.print("Gesture: ");
  Serial.print(gesture);
  Serial.print(" | Binary: ");
  Serial.print(D5v);
  Serial.print(D4v);
  Serial.print(D3v);
  Serial.println(D2v);

  delay(200);
}

// ---------- FUNCTIONS ----------

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void calibrateMPU() {
  Serial.println("🔄 Calibrating... Keep hand steady");

  long sumX = 0, sumY = 0;

  for (int i = 0; i < 100; i++) {
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    sumX += ax;
    sumY += ay;
    delay(20);
  }

  ax_neutral = sumX / 100;
  ay_neutral = sumY / 100;

  Serial.print("Neutral AX: ");
  Serial.println(ax_neutral);
  Serial.print("Neutral AY: ");
  Serial.println(ay_neutral);
  Serial.println("✅ Calibration complete");
}
