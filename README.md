# can_frame_generator_c

## Overview

This is a trivial example on how to generate CAN-friendly frames for consumption by [CANBridge](https://github.com/xba1k/CANBridge)

## Installation

This code is intended for Ubuntu and similar Linux distributions. Run make to build.

## Run

Run with two arguments - IP address of the CANBridge, and port the CANBridge is listening on, such as 1080

```
./can_frame_generator 192.168.1.3 1080
Starting generator...
1647584626
1647584636
^C
```

```
tcpdump -e -n -A -vvv port 1080
tcpdump: listening on enp0s25, link-type EN10MB (Ethernet), capture size 262144 bytes
23:23:46.968038 18:03:73:e8:66:35 > 74:4d:28:a6:01:7d, ethertype IPv4 (0x0800), length 52: (tos 0x0, ttl 64, id 48677, offset 0, flags [DF], proto UDP (17), length 38)
    192.168.1.69.36969 > 192.168.1.3.1080: [bad udp cksum 0x83bc -> 0x338a!] UDP, length 10
E..&.%@.@......E.....i.8....V.....d...
23:23:46.968051 18:03:73:e8:66:35 > 74:4d:28:a6:01:7d, ethertype IPv4 (0x0800), length 54: (tos 0x0, ttl 64, id 48678, offset 0, flags [DF], proto UDP (17), length 40)
    192.168.1.69.36969 > 192.168.1.3.1080: [bad udp cksum 0x83be -> 0x28e2!] UDP, length 12
E..(.&@.@......E.....i.8....^...PacketGe
23:23:56.968166 18:03:73:e8:66:35 > 74:4d:28:a6:01:7d, ethertype IPv4 (0x0800), length 52: (tos 0x0, ttl 64, id 49266, offset 0, flags [DF], proto UDP (17), length 38)
    192.168.1.69.36969 > 192.168.1.3.1080: [bad udp cksum 0x83bc -> 0x338a!] UDP, length 10
E..&.r@.@......E.....i.8....V.....d...
23:23:56.968178 18:03:73:e8:66:35 > 74:4d:28:a6:01:7d, ethertype IPv4 (0x0800), length 54: (tos 0x0, ttl 64, id 49267, offset 0, flags [DF], proto UDP (17), length 40)
    192.168.1.69.36969 > 192.168.1.3.1080: [bad udp cksum 0x83be -> 0x28e2!] UDP, length 12
E..(.s@.@......E.....i.8....^...PacketGe
```

Note that the checksum message is normal when sniffing outgoing traffic on an interface with the hw acceleration.
