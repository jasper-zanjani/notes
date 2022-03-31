# Winrm

**Winrm** allows you to connect Linux and Windows hosts over WinRM. <sup>[adamtheautomator.com](https://adamtheautomator.com/winrm-linux-remoting/ "Step-by-step guide on how to set up WinRM on a Linux client") </sup>
Begin a WinRM session. If no errors are thrown, the session has been successfully established
```py
session = winrm.Session(ipaddress, auth = (username, password) )
```