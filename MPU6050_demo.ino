// Basic demo for accelerometer readings from Adafruit MPU6050

// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  /*
    Other range options: (+-n G,G = G-force)(normal people can sustain up to 4-6G before passing out!)
    MPU6050_RANGE_2_G (+-2G)
    MPU6050_RANGE_4_G (+-4G)
    MPU6050_RANGE_16_G (+-16G)
  */
  imuSensor.setAccelerometerRange(MPU6050_RANGE_8_G);

  /*
    Other range options: (+-n deg/s)
    MPU6050_RANGE_250_DEG 
    MPU6050_RANGE_1000_DEG
    MPU6050_RANGE_2000_DEG 
  */
  imuSensor.setGyroRange(MPU6050_RANGE_500_DEG);

  /*
    Other filter options: (+-n Hz)(lower = smoother/less fluctuation)
    MPU6050_BAND_260_HZ
    MPU6050_BAND_184_HZ
    MPU6050_BAND_94_HZ
    MPU6050_BAND_44_HZ
    MPU6050_BAND_21_HZ
    MPU6050_BAND_10_HZ
    MPU6050_BAND_5_HZ
  */
  imuSensor.setFilterBandwidth(MPU6050_BAND_5_HZ);
  delay(100);
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");

  Serial.println("");
  delay(500);
}