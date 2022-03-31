# Pyinstaller

[pyinstaller --name]: # "Change the name of the executable artifact"
[pyinstaller --onefile]: # "Package the entire application intoa  single executable file"
[pyinstaller --hidden-import]: # "Explicitly specify imports that may not have been detected by PyInstaller."

Source: [RealPython tutorial](https://realpython.com/pyinstaller-python/)

Installing **PyInstaller**, even in a virtual environment, will install the pyinstaller executable to $HOME/.local/bin.
On Windows, it is installed to another directory within 
[`LOCALAPPDATA`](# "$Env:LOCALAPPDATA\Packages\PythonSoftwareFoundation.Python.3.x....\LocalCache\local-packages\Python3x\Scripts").
```sh
pip install pyinstaller
```
PyInstaller creates primarily 3 items:
- .spec file, named after the CLI script
- build/ folder, which can be ignored
- dist/ folder, containing the final artifact at dist/cli/cli or dist/cli/cli.exe

Several options are available
[`hidden-import`][pyinstaller --hidden-import]
[`name`][pyinstaller --name]
[`onefile`][pyinstaller --onefile]
```sh
pyinstaller script.py --onefile
```
On Windows, if PyInstaller is run from a virtual environment without necessary modules installed, they may not be available for compilation into the artifact. This does not appear to be an issue with Linux.

This problem appears to be specific to certain modules, like [**emoji**](https://github.com/carpedm20/emoji/).
