# Smart Vision Robot

A two-brain autonomous robot built from scratch as a summer embedded-systems project.

**Status:**  Work in progress — building the drive base on Arduino (Phase 1).

## What it will do
An obstacle-avoiding rover that follows a colored object. A Raspberry Pi 5 runs
computer vision (OpenCV) and sends high-level commands over UART to an STM32,
which handles all real-time motor and sensor control.

## Architecture
- **STM32** — real-time reflexes: PWM motor control, ultrasonic ranging, IMU (C/HAL)
- **Raspberry Pi 5** — the thinking: OpenCV vision, decides where to go
- **UART link** — Pi sends Forward / Left / Right / Stop; STM32 executes

## Hardware
- STM32 Nucleo + Arduino (Phase 1 prototyping)
- L293D motor driver, TT gear motors, HC-SR04 ultrasonic, MPU-6050 IMU
- PETG chassis printed on a Bambu Lab P1S
- Raspberry Pi 5 + Camera Module 3 (vision phase)

## Progress
- [x] Chassis designed and printed
- [x] Motors mounted, drive base assembled
- [ ] Arduino motor control
- [ ] Obstacle avoidance (Arduino)
- [ ] Port to STM32 (hardware timers, input capture)
- [ ] IMU integration
- [ ] Raspberry Pi vision
