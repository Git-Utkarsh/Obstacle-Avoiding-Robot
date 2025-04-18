# Award Winning Obstacle Avoidance Robot
<img width="540" alt="github" src="https://github.com/Git-Utkarsh/Obstacle-Avoiding-Robot/assets/84007458/7aeda056-1576-4711-8bd8-979557bbe6c9">

## Description

This Arduino code implements an object avoidance mechanism using an ultrasonic sensor and a four-wheeled robot with individual motors. When an object is detected within 15 cm, the robot performs a predefined sequence: it moves backward, turns right, turns left, and then moves forward. Motor control is facilitated through the AFMotor library, while the distance calculation relies on the pulse duration from the ultrasonic sensor.

## Components Used

- Ultrasonic Sensor
- AFMotor Library
- Motor Shield
- Four DC Motors (M1, M2, M3, M4)
- Arduino Board

## Circuit Setup

![circuit](https://github.com/Git-Utkarsh/Obstacle-Avoiding-Robot/assets/84007458/781412bb-f07f-4280-b765-7d485bdd2650)
<img width="596" alt="image" src="https://github.com/Git-Utkarsh/Obstacle-Avoiding-Robot/assets/84007458/b0042fcc-5bce-4545-8022-7ba2c903a563">

1. Connect the ultrasonic sensor's trigPin to A2 and echoPin to A3 on the Arduino.
2. Connect the four DC motors to the motor controller, assigning each to motorM1, motorM2, motorM3, and motorM4.
3. Ensure the AFMotor library is installed in your Arduino IDE.

## How It Works

The Arduino continuously measures the distance using the ultrasonic sensor. When an object is detected within 15 cm, it triggers a sequence of movements to avoid the obstacle: move backward, turn right, turn left, and then move forward. Motor speed and direction are controlled through the AFMotor library.

## Usage

1. Upload the provided code to your Arduino board.
2. Ensure the hardware setup is correct.
3. Power up the robot.
4. Observe the robot's behavior in response to obstacles within its detection range.

Note: Adjustments to motor speeds and delay times can be made in the code to optimize performance for your specific robot.

Feel free to contribute by forking the repository and submitting pull requests.



## License

This project is licensed under the [MIT License](LICENSE).
