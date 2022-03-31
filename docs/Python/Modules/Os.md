# os

Execute shell command given by string.  The value returned is actually the exit code, **not** the output of the command to STDOUT.
```py
os.system('ls -la')
``` 
Store output in a variable
```py
os.popen('ls -la').read()
``` 
Navigate filesystem
```py
os.getcwd()
os.chdir(path)
```
Test for existence of a file
```py
os.path.isfile(file)
``` 