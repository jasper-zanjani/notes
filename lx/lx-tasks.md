# Linux system administration tasks

#### Change hostname 
```bash
sudo hostnamectl set-hostname newhostname
```

#### Check kernel version
```bash
uname -srm
```

Output:
> ```
> Linux 4.15.0-54-generic x86_64
> ```

```bash
hostnamectl | grep "Kernel"
```
Output:
```
            Kernel: Linux 4.15.0-54-generic
```

```bash
cat /proc/version
```

Output:
```
Linux version 4.15.0-54-generic (buildd@lgw01-amd64-014) (gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)) #58-Ubuntu SMP Mon Jun 24 10:55:24 UTC 2019
```

## Sources
- "How to check the Kernel Version in Linux". [Linuxize](https://linuxize.com/post/how-to-check-the-kernel-version-in-linux/): 2019/07/08.