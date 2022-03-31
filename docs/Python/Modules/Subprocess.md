# subprocess

**subprocess** modules allows you to spawn new processes, interact with file descriptors, and obtain exit codes. The recommended approach is to use the `run()` function as default, which runs a CLI command with options as a list of strings and returns a `CompletedProcess` instance.\
Execute shell command
Unlike `os.system`, `subprocess.run()` takes a list of arguments. 
```py
subprocess.run(['ls','-l,'.'], 0)
```
Set `capture_output` to `True` to save output, stored as property `stdout` of the returned object. 
```py
data = subprocess.run(['ls,'-l','.'], 0, capture_output=True)
```
The data is stored as a **bytestring**, which can be decoded to a normal string.
```py
data.stdout.decode('utf-8')
```
This return a `CompletedProcess` instance with the command's output stored under the `stdout` property
```py
subprocess.run(['ls','-l','/dev/null'], capture_output=True)
```
This will raise a `CalledProcessError` exception because of the non-zero exit code
```py
subprocess.run('exit 1', shell=True, check=True)
```
