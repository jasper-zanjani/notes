# 🖥&#xFE0F; GUI frameworks comparison

[tkcalendar]: https://pypi.org/project/tkcalendar/ "Requires tkcalendar package"

Although XAML widgets can declare their own headers, in Tkinter this is implemented as separate **`LabelFrame`** widgets, meant to contain controls. 
Tkinter widgets must be slaved in a manner which ultimately leads to the root object initialized by `Tk()`, conceptually similar to the **`Window`** root node in XAML.

To refer to UI elements, XAML prefers the term **control** whereas tkinter and other frameworks prefer **widget**. Elements that can contain other elements and are used to visually organize the application are known as **layout panels**.

| WinUI control | tkinter widget          |
| ------------- | ----------------------- |
| Button        | Button                  |
| Checkbox      | Checkbutton             |
| DatePicker    | [DateEntry][tkcalendar] |
| TextBox       | Entry                   |
| ListView      |


## Widgets

### Date picker

=== "XAML"
    ```xml
    <Window
        x:Class="EmployeeManager.WinUI.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="using:EmployeeManager.WinUI"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        mc:Ignorable="d">
        
        <DatePicker Header="Entry date"/>
    </Window>
    ```
=== "tkinter"

    ```python
    import tkinter as tk
    from tkinter.ttk import LabelFrame
    from tkcalendar import DateEntry

    window = tk.Tk()
    frame=LabelFrame(window, text="Entry date: ")
    frame.pack()
    DateEntry(frame).pack()
    tk.mainloop()
    ```

## Examples

### Hello, World!

=== "gtk"
    ```py
    import gi

    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk

    win = Gtk.Window()
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    Gtk.main()
    ```

=== "wx"
    ```py
    import wx
    
    app = wx.App()
    frame = wx.Frame(parent=None, title='Hello World')
    frame.Show()
    app.MainLoop()
    ```

### Empty window

=== "Python"
    ```sh
    pip install PyGObject
    ```
    ```py
    import gi
    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk

    window = Gtk.Window(title="Hello, world!")
    window.connect("destroy", Gtk.main_quit)
    window.show_all()
    Gtk.main()
    ```

=== "Vala"
    [src](https://www.youtube.com/watch?v=0R8gzwiR9sI)
    ```csharp
    int main(string[] args)
    {
        Gtk.init (ref args);
        var window = new Gtk.Window();
        window.title = "Hello, world!";
        window.border_width=10;
        window.window_position = Gtk.WindowPosition.CENTER;
        window.set_default_size (200, 200);
        window.destroy.connect(Gtk.main_quit);
        window.show_all()
        Gtk.main();
        return 0;
    }
    ```

### Empty window (OOP)

=== "Python"
```py
import gi

gi.require_version("Gtk", "3.0")

from gi.repository import Gtk

class HelloWorld(Gtk.Window):
    def __init__(self):
        super().__init__(self, title="Hello, world!")

window = HelloWorld();
```

=== "Vala"

    There are two constructors in Vala, one named after the class and the second named with the keyword `construct`.
    The class constructor is only invoked upon the first instantiation.
    The `construct` constructor is invoked with every new object instantiation.
    ```csharp
    public class HelloWorld : Gtk.Application
    {
        public HelloWorld () 
        {
            Object (
                application_id: "com.github.alecaddd.test",
                flags: GLib.ApplicationFlags.FLAGS_NONE
            )
        }

        protected override activate () 
        {
            var window = new Gtk.ApplicationWindow(this);
            window.title = "Hello, world!";
            window.border_width = 10;
            window.window_position = Gtk.WindowPosition.CENTER;
            window.set_default_size (200, 200);

            window.show_all();
        }

        public static int main (string[] args)
        {
            var app = new HelloWorld();
            return app.run(args);
        }
    }
    ```


## tkinter

![](/img/GUI-WBC-01-tk.gif)

<details>
<summary>
main.py</summary>

```python
import tkinter as tk
from tkinter.ttk import Button
from tkinter.ttk import Labelframe
from tkinter.ttk import Label
from tkinter.ttk import Entry
from tkinter.ttk import Checkbutton
# from tkinter.ttk import 
import tkcalendar

LabelFrame = Labelframe

window = tk.Tk()
window.title("Wired Brain Coffee")

main = Labelframe(window)
main.pack()

headline = Label(main, text="Wired Brain Coffee")
headline.grid(row=0, column=0, columnspan=2)

sidebar = LabelFrame(main)
sidebar.grid(row=1, column=0)

refresh = Button(sidebar, text="Refresh")
refresh.pack()

mainarea = LabelFrame(main)
mainarea.grid(row=1, column=1)

firstname_frame = Labelframe(mainarea, text="First name")
firstname_frame.pack()
firstname_textbox = Entry(firstname_frame).pack()
# firstname_textbox.pack(expand='yes', fill='both')

dateentry_frame = Labelframe(mainarea, text="Entry date")
dateentry_frame.pack()
dateentry_picker = tkcalendar.DateEntry(dateentry_frame)
dateentry_picker.pack()

jobrole_frame = Labelframe(mainarea, text="Job Role")
jobrole_frame.pack()
jobrole_textbox = Entry(jobrole_frame).pack()
# jobrole_textbox.pack(expand='yes', fill='both')

iscoffeedrinker = Checkbutton(mainarea, text="Is coffee drinker?").pack()
# iscoffeedrinker.pack()

window.resizable=(True,True)
window.mainloop()
```
</details>
