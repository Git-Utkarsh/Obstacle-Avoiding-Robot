#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
float initialYaw = 0.0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.setGyroOffsets(-3.01, 0.42, -0.35);
  initialYaw = mpu6050.getAngleZ();
}

void loop() {
  int16_t az, gz;
  mpu6050.update();
  az = mpu6050.getAccZ();
  gz = mpu6050.getGyroZ();
  float yaw = mpu6050.getAngleZ() - initialYaw;

  if (yaw > 90.0) {
    Serial.println("Extreme Right");
  } else if (yaw < -90.0) {
    Serial.println("Extreme Left");
  } else {
    Serial.print("Yaw: ");
    Serial.print(yaw);
    Serial.print(" degrees");
    Serial.println();
  }
}
