from machine import Pin, PWM
import time

# --- Configuration ---
PWM_FREQ = 1000
speed = 800 

# 1. Initialize PWM pins for all 4 motors
# Front Left Motor
fl_fwd = PWM(Pin(12), freq=PWM_FREQ)
fl_bwd = PWM(Pin(13), freq=PWM_FREQ)

# Front Right Motor
fr_fwd = PWM(Pin(14), freq=PWM_FREQ)
fr_bwd = PWM(Pin(27), freq=PWM_FREQ)

# Back Left Motor (Assuming these new pins, change if different)
bl_fwd = PWM(Pin(26), freq=PWM_FREQ)
bl_bwd = PWM(Pin(25), freq=PWM_FREQ)

# Back Right Motor (Assuming these new pins, change if different)
br_fwd = PWM(Pin(33), freq=PWM_FREQ)
br_bwd = PWM(Pin(32), freq=PWM_FREQ)

def stop():
    for pwm in [fl_fwd, fl_bwd, fr_fwd, fr_bwd, bl_fwd, bl_bwd, br_fwd, br_bwd]:
        pwm.duty(0)

def move_forward():
    # All wheels rotate forward
    fl_fwd.duty(speed); fl_bwd.duty(0)
    fr_fwd.duty(speed); fr_bwd.duty(0)
    bl_fwd.duty(speed); bl_bwd.duty(0)
    br_fwd.duty(speed); br_bwd.duty(0)

def move_backward():
    # All wheels rotate backward
    fl_fwd.duty(0); fl_bwd.duty(speed)
    fr_fwd.duty(0); fr_bwd.duty(speed)
    bl_fwd.duty(0); bl_bwd.duty(speed)
    br_fwd.duty(0); br_bwd.duty(speed)

def strafe_left():
    # FL & BR backward, FR & BL forward
    fl_fwd.duty(0); fl_bwd.duty(speed)
    fr_fwd.duty(speed); fr_bwd.duty(0)
    bl_fwd.duty(speed); bl_bwd.duty(0)
    br_fwd.duty(0); br_bwd.duty(speed)

def strafe_right():
    # FL & BR forward, FR & BL backward
    fl_fwd.duty(speed); fl_bwd.duty(0)
    fr_fwd.duty(0); fr_bwd.duty(speed)
    bl_fwd.duty(0); bl_bwd.duty(speed)
    br_fwd.duty(speed); br_bwd.duty(0)

def rotate_clockwise():
    # Left side forward, Right side backward
    fl_fwd.duty(speed); fl_bwd.duty(0)
    fr_fwd.duty(0); fr_bwd.duty(speed)
    bl_fwd.duty(speed); bl_bwd.duty(0)
    br_fwd.duty(0); br_bwd.duty(speed)

def rotate_anticlockwise():
    # Left side backward, Right side forward
    fl_fwd.duty(0); fl_bwd.duty(speed)
    fr_fwd.duty(speed); fr_bwd.duty(0)
    bl_fwd.duty(0); bl_bwd.duty(speed)
    br_fwd.duty(speed); br_bwd.duty(0)