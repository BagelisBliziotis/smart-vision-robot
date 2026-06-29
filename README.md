# Smart Vision Robot 

**Work in progress** — an autonomous obstacle-avoiding robot built in two phases.

## Architecture (two brains)
- **STM32** — real-time control: motor PWM, ultrasonic ranging, IMU. C (HAL).
- **Raspberry Pi 5** — vision layer (OpenCV), sends commands over UART.

Phase 1: autonomous obstacle avoidance, first on Arduino, then rebuilt on STM32.

## Status
Build log starting now — updated as I go.