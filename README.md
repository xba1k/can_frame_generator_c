# can_frame_generator_c

## Overview

This is a trivial example on how to generate CAN-friendly frames for consumption by [CANBridge](https://github.com/xba1k/CANBridge)

## Installation

This code is intended for Ubuntu and similar Linux distributions. Run make to build.

## Run

Run with two arguments - IP address of the CANBridge, and port the CANBridge is listening on, such as 1080

```
./can_frame_generator 192.168.1.123 1080
Starting generator...
1647584302
1647584312
^C
```