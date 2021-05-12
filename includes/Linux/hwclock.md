Connection to an NTP server is necessary for a variety of services.

Linux systems have two clocks:
1. hardware clock/real-time clock (RTC)
2. system clock

Manually synchronize hardware clock to system clock (generally only required if **no NTP server is available**)
```bash
hwclock --hctosys
```