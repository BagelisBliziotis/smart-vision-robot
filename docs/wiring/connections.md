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

