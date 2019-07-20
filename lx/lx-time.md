# Time in Linux

Connection to an NTP server is necessary for a variety of services.
Linux systems have two clocks:
  1. hardware clock/real-time clock (RTC)
  2. system clock

#### Manually synchronize hardware clock to system clock
Generally only required if __no NTP server is available__
```bash
hwclock --hctosys
```
