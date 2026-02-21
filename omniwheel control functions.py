from machine import Pin, PWM
import time

# 1. Initialize PWM pins at a frequency of 1000Hz
# Left Motors
L_IN1 = PWM(Pin(12), freq=1000)
L_IN2 = PWM(Pin(13), freq=1000)

# Right Motors
R_IN3 = PWM(Pin(14), freq=1000)
R_IN4 = PWM(Pin(27), freq=1000)

# Global speed variable (0 to 1023)
speed = 800 

def stop():
    L_IN1.duty(0)
    L_IN2.duty(0)
    R_IN3.duty(0)
    R_IN4.duty(0)

def move_forward():
    L_IN1.duty(speed)
    L_IN2.duty(0)
    R_IN3.duty(speed)
    R_IN4.duty(0)

def move_backward():
    L_IN1.duty(0)
    L_IN2.duty(speed)
    R_IN3.duty(0)
    R_IN4.duty(speed)

def turn_left():
    L_IN1.duty(0)
    L_IN2.duty(0)
    R_IN3.duty(speed)
    R_IN4.duty(0)

def turn_right():
    L_IN1.duty(speed)
    L_IN2.duty(0)
    R_IN3.duty(0)
    R_IN4.duty(0)

def rotate_clockwise():
    L_IN1.duty(speed)
    L_IN2.duty(0)
    R_IN3.duty(0)
    R_IN4.duty(speed)

def rotate_anticlockwise():
    L_IN1.duty(0)
    L_IN2.duty(speed)
    R_IN3.duty(speed)
    R_IN4.duty(0)