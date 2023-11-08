#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

float initialPitch = 0.0;  // Initial pitch angle
float initialRoll = 0.0;   // Initial roll angle
float initialYaw = 0.0; //Initial yaw angle

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // Read and store the initial orientation
  initialPitch = mpu6050.getAngleX();
  initialRoll = mpu6050.getAngleY();
  initialYaw = mpu6050.getAngleZ();
}

void loop() {
  // Read MPU6050 data
  int16_t ax, ay, az, gx, gy, gz;
  mpu6050.update();
  ax = mpu6050.getAccX();
  ay = mpu6050.getAccY();
  az = mpu6050.getAccZ();
  gx = mpu6050.getGyroX();
  gy = mpu6050.getGyroY();
  gz = mpu6050.getGyroZ();

  // Calculate pitch and roll angles
  float pitch = mpu6050.getAngleX() - initialPitch;
  float roll = mpu6050.getAngleY() - initialRoll;
  float yaw = mpu6050.getAngleZ() - initialYaw;

  // Print pitch and roll angles as degrees of deviation
  Serial.print("Pitch (deviation from initial): ");
  Serial.print(pitch);
  Serial.print(" degrees | Roll (deviation from initial): ");
  Serial.print(roll);
  Serial.print(" degrees | Roll (deviation from initial): ");
  Serial.print(yaw);
  Serial.print(" degrees");



  Serial.println();
}
