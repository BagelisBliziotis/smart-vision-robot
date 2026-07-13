# Wiring — Arduino + L293D (Day 5)

## Arduino → L293D (half-size breadboard)
| Arduino | L293D pin | Function |
|---|---|---|
| D3 (PWM) | 1 (EN1) | Motor A speed |
| D4 | 2 (IN1) | Motor A direction |
| D5 | 7 (IN2) | Motor A direction |
| D6 (PWM) | 9 (EN2) | Motor B speed |
| D7 | 10 (IN3) | Motor B direction |
| D8 | 15 (IN4) | Motor B direction |
| 5V | 16 (VCC1) | Logic supply |
| GND | GND rail | Common ground |

## L293D → motors
| L293D pin | Goes to |
|---|---|
| 3 (OUT1) | Left motor terminal 1 |
| 6 (OUT2) | Left motor terminal 2 |
| 11 (OUT3) | Right motor terminal 1 |
| 14 (OUT4) | Right motor terminal 2 |
| 4, 5, 12, 13 | GND rail |

## Power
| Source | Goes to |
|---|---|
| 4×AA pack + | L293D pin 8 (VCC2, motor supply) |
| 4×AA pack − | GND rail (shared with Arduino GND) |
| USB power bank | Arduino (USB) |

## HC-SR04 ultrasonic

| HC-SR04 pin | Connects to          | Notes                                   |
|-------------|----------------------|-----------------------------------------|
| VCC         | 5V rail (Arduino 5V) | ~15 mA, fine from the Arduino           |
| TRIG        | Arduino D9           | 10µs HIGH pulse fires the ping          |
| ECHO        | Arduino D10          | Direct — safe on 5V Arduino. STM32 port needs a 10k/20k divider (3.3V pin). |
| GND         | Common GND rail      |                                         |

## STM32 Discovery — motor control 
EN1 (motor A speed) → PD12 (TIM4_CH1)
IN1                  → PE7
IN2                  → PE8
EN2 (motor B speed) → PD13 (TIM4_CH2)
IN3                  → PE9
IN4                  → PE10
L293D pin 16 (VCC1) → Discovery 5V
Ground               → Discovery GND, shared with battery negative
