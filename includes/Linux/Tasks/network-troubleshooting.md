
#### Diagnosing network problems

Test from the inside out, starting with the loopback

1. ping looback address, testing the TCP/IP stack
2. ping the hardware interface
3. ping another host on the network
4. ping the gateway
5. ping an IP address on the Internet
6. ping a hostname on the Internet

Display contents of a random file
```sh
ls | sort -R | sed 1q | xargs cat
```
Find out which commands you use most often
```sh
history | awk '{print $2' | sort | uniq -c | sort -rn | head
```
Count the number of occurrences of a string
```sh
| uniq -c | sort -
```
Change hostname 
```bash
sudo hostnamectl set-hostname newhostname
```

Check kernel version [linuxize.com](https://linuxize.com/post/how-to-check-the-kernel-version-in-linux/ "linuxize.com: \"How to check the Kernel version in Linux\"")
```bash
uname -srm
```

```bash
hostnamectl | grep "Kernel"
```

```bash
cat /proc/version
```