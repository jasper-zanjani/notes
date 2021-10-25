# 🖥&#xFE0F; GUI frameworks comparison

[tkcalendar]: https://pypi.org/project/tkcalendar/ "Requires tkcalendar package"

Although XAML widgets can declare their own headers, in Tkinter this is implemented as separate **`LabelFrame`** widgets, meant to contain controls. 
Tkinter widgets must be slaved in a manner which ultimately leads to the root object initialized by `Tk()`, conceptually similar to the **`Window`** root node in XAML.

To refer to UI elements, XAML prefers the term **control** whereas tkinter and other frameworks prefer **widget**. Elements that can contain other elements and are used to visually organize the application are known as **layout panels**.

| WinUI control              | GTK         | tkinter                 |
| -------------------------- | ----------- | ----------------------- |
| Button                     | Button      | Button                  |
| Checkbox                   | CheckButton | Checkbutton             |
| TextBox                    | Entry       | Entry                   |
| ListView                   | TreeView    |
| StackPanel                 | Box         |                         |
| [DatePicker](#date-picker) | Calendar    | [DateEntry][tkcalendar] |



## Widgets


#### Label

In both GTK and Tkinter frameworks, a window size must be set or else it will collapse to the boundaries of the contained label.

=== "PyGTK"
    
    <figure>
        <img src="/img/hw-label-gtk.png">
    </figure>

    ```py hl_lines="12"
    import gi
    gi.require_version("Gtk","3.0")
    from gi.repository import Gtk
    import sys


    class AppWindow(Gtk.ApplicationWindow):

        def __init__(self, *args, name = "world", **kwargs):
            super().__init__(*args, **kwargs)

            label = Gtk.Label.new(f"Hello {name}")
            self.add(label)
            self.set_size_request(200, 200)

    class Application(Gtk.Application):
        def __init__(self, name, *args, **kwargs):
            self.name = name
            super().__init__(*args, application_id="org.example.myapp", **kwargs)
            self.window = None

        def do_activate(self):
            if not self.window:
                self.window = AppWindow(application=self, 
                                        name = self.name, 
                                        title = f"Hello, {self.name}!")
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application(sys.argv[-1])
        app.run()
    ```

=== "tkinter"

    <figure><img src="/img/hw-label-tk.png"></figure>

    ```py hl_lines="11"
    import tkinter
    from tkinter import ttk
    import sys


    class Window(tkinter.Tk):
        def __init__(self, name="World"):
            super().__init__()
            self.title(f"Hello, {name}!")
            self.geometry("200x200")
            self.resizable(False, False)
            ttk.Label(self, text=f"Hello, {name}!").grid(column=0, row=0)


    if __name__ == '__main__':
        try:
            win = Window(name=sys.argv[1])
        except IndexError:
            win = Window()
        win.mainloop()
    ```


#### Date picker

=== "XAML"

    ```xml hl_lines="10"
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

    ```python hl_lines="10"
    import tkinter as tk
    from tkinter.ttk import LabelFrame
    from tkcalendar import DateEntry


    window = tk.Tk()
    frame=LabelFrame(window, text="Entry date: ")
    frame.pack()

    DateEntry(frame).pack()
    tk.mainloop()
    ```


#### Textbox

=== "PyGTK"

    ```py hl_lines="15-16"
    import os, sys

    import gi
    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk


    class AppWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_border_width(10)
            prompt_str = "What is the password for " + os.getlogin() + "?"
            question = Gtk.Label(label=prompt_str)
            label = Gtk.Label(label="Password:")
            passwd = Gtk.Entry()
            passwd.set_visibility(False)
            # passwd.set_invisible_char("*")
            hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=0)
            hbox.pack_start(label, False, False, 5)
            hbox.pack_start(passwd, False, False, 5)
            vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=0)
            vbox.pack_start(question, False, False, 0)
            vbox.pack_start(hbox, False, False, 0)
            self.add(vbox)


    class Application(Gtk.Application):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, application_id="org.example.myapp", **kwargs)
            self.window = None

        def do_activate(self):
            if not self.window:
                self.window = AppWindow(application=self, title="Password")
            self.window.show_all()
            self.window.present()


    if __name__ == "__main__":
        app = Application()
        app.run(sys.argv)
    ```


#### ListView

=== "PyGTK"

    ```py
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            
            self.gen_treeview()

            scrolled_win = Gtk.ScrolledWindow.new(None,None)
            scrolled_win.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC)
            scrolled_win.add(self.treeview)

            self.add(scrolled_win)
            self.set_size_request(200,200)

        def get_liststore(self):
            store = Gtk.ListStore.new((str,))
            store.append(["Socrates"])
            store.append(["Plato"])
            store.append(["Aristotle"])
            return store

        def gen_treeview(self):
            self.treeview = Gtk.TreeView.new()
            self.treeview.set_model(self.get_liststore())
            self.treeview.append_column(Gtk.TreeViewColumn("Greeks", Gtk.CellRendererText.new(), text=0))



    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self, title="Greeks")
            self.window.show_all()
            self.window.present()


    if __name__ == '__main__':
        app = Application()
        app.run()
    ```


#### Toggle Button

```py hl_lines="14-15"
#!/usr/bin/python3

import sys
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

class AppWindow(Gtk.ApplicationWindow):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.set_border_width(10)
        vbox = Gtk.Box.new(orientation=Gtk.Orientation.VERTICAL, spacing=0)
        toggle1 = Gtk.ToggleButton.new_with_mnemonic("_Deactivate the other one!")
        toggle2 = Gtk.ToggleButton.new_with_mnemonic("_No! Deactivate that one!")
        toggle1.connect("toggled", self.on_button_toggled, toggle2)
        toggle2.connect("toggled", self.on_button_toggled, toggle1)
        vbox.pack_start(toggle1, True, True, 1)
        vbox.pack_start(toggle2, True, True, 1)
        self.add(vbox)

    def on_button_toggled(self, toggle, other_toggle):
        if (Gtk.ToggleButton.get_active(toggle)):
            other_toggle.set_sensitive(False)
        else:
            other_toggle.set_sensitive(True)

class Application(Gtk.Application):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, application_id="org.example.myapp",
                         **kwargs)
        self.window = None

    def do_activate(self):
        if not self.window:
            self.window = AppWindow(application=self, title="Toggle Buttons")
        self.window.show_all()
        self.window.present()

if __name__ == "__main__":
    app = Application()
    app.run(sys.argv)

```



## Tasks


#### Wired Brain Coffee

=== "tkinter"

    <figure>
        <img src="/img/GUI-WBC-01-tk.gif">
    </figure>

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


#### Raven lines

=== "PyGTK"

    ```py hl_lines="22"
    import sys
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import itertools

    class AppWindow(Gtk.ApplicationWindow):

        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_border_width(25)
            button = Gtk.Button.new_with_mnemonic("_Raven")
            button.connect("clicked", self.on_button_clicked)
            button.set_relief(Gtk.ReliefStyle.NORMAL)
            self.add(button)
            self.set_size_request(200, 100)

            with open("/home/jasper/notes/docs/Coding/Dogfood/raven.txt") as f:
                self.raven = itertools.cycle([l.strip() for l in f.readlines()])

        def on_button_clicked(self, button):
            print(next(self.raven))

    class Application(Gtk.Application):

        def __init__(self, argv , *args, **kwargs):
            super().__init__(*args, application_id="org.example.myapp",
                            **kwargs)
            self.name=argv[-1]
            self.window = None

        def do_activate(self):
            if not self.window:
                self.window = AppWindow(application=self, 
                                        title=f"Hello {self.name}!")
            self.window.show_all()
            self.window.present()

    if __name__ == "__main__":
        app = Application(sys.argv)
        app.run(sys.argv)
    ```


#### Login dialog box

<figure><img src="/img/gui-login.png"/></figure>

=== "PyGTK"

    ```py
    import gi
    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_size_request(300,300)
            grid = Gtk.Grid.new()
            image = Gtk.Image.new_from_icon_name("dialog-password", Gtk.IconSize.DIALOG)
            grid.attach(image, 0, 0, 1, 1)
            grid.attach(Gtk.Label(label="Enter your credentials."), 0, 1, 2, 1)
            grid.attach(Gtk.Label(label="User name:"), 0, 2, 1, 1)
            grid.attach(Gtk.Entry(), 1, 2, 1, 1)
            grid.attach(Gtk.Label(label="Password:"), 0, 3, 1, 1)
            grid.attach(Gtk.Entry(visibility=False), 1, 3, 1, 1)


    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id="org.example.myapp")

        def do_activate(self):
            self.window = ApplicationWindow(application=self, title="Hello, World!")
            self.window.show_all()
            self.window.present()


    if __name__ == "__main__":
        app = Application()
        app.run()
    ```


#### Timeshift clone

=== "Type"

    <figure><img src="/img/gui-timeshift-1.png"/></figure>

=== "Location"

    <figure><img src="/img/gui-timeshift-2.png"/></figure>

=== "Schedule"

    <figure><img src="/img/gui-timeshift-3.png"/></figure>

=== "Users"

    <figure><img src="/img/gui-timeshift-4.png"/></figure>

