# Pygobject

## Tasks

#### Development environment
:   
    === ":material-redhat: Red Hat"
    
        ```sh
        dnf install python3-venv python3-wheel
        dnf install gcc zlib-devel bzip2 bzip2-devel readline-devel sqlite sqlite-devel openssl-devel tk-devel git python3-cairo-devel cairo-gobject-devel gobject-introspection-devel
        pip install pygobject
        ```

    === ":material-ubuntu: Ubuntu"

        ```sh
        apt install python3-gi python3-gi-cairo gir1.2-gtk-3.0 libgirepository1.0-dev
        pip install pygobject
        ```

#### Boilerplate
:   
    <figure markdown>![](/img/GTK/boilerplate.png)</figure>

    ```xml title="Interface"
    <?xml version="1.0" encoding="UTF-8"?>
    <interface>
        <requires lib="gtk+" version="3.40"/>
        <object class="GtkApplicationWindow" id="window">
            <property name="title">My GTK App</property>
            <property name="default-width">300</property>
            <property name="default-height">300</property>
        </object>
    </interface>
    ```

    ```py
    import gi
    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk  # (1)

    class ApplicationWindow(Gtk.ApplicationWindow): # (2)
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs) # (3)
            self.set_size_request(300,300)
            self.set_title("My GTK App")
            self.show_all()
            self.present()


    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.learning-gtk') # (4)

        def do_activate(self):
            self.window = ApplicationWindow(application=self)

    if __name__ == '__main__':
        app = Application() # (5)
        app.run()
        # (6)
    ```

    1. Note that the gi module's **`require_version()`** function must be called before importing Gtk.
    2. The recommended way of using the PyGTK API is to subclass and modify the [**Application**](/GTK/API#application) and [**ApplicationWindow**](/GTK/API#applicationwindow) classes. These were introduced in GTK+ versions 3.0 and 3.4 respectively and are meant to be used as base classes.
    PyGTK also offers an alternative [**Gtk.Window**](/GTK/API#window) class, which like ApplicationWindow is a subclass of Gtk.Container, and which still appears in many tutorials.
    3. The ApplicationWindow subclass calls the superclass's constructor. The UI is composed by adding widgets to this subclass by calling **`self.add()`**. Typically a single [**Box**](/GTK/API#box) container is added to the top-level container and controls are added to that container.
    4. The [Application](/GTK/API#application) subclass also calls its superclass's constructor and exposes a **`do_activate()`** method that instantiates the [ApplicationWindow](/GTK/API#applicationwindow) subclass and assigns that object to `self.window` before calling `self.window.present()`. The Application subclass essentially acts as a wrapper around ApplicationWindow.
    5. At the script's entrypoint, the Application subclass itself is instantiated and its **`run`** method is called.
    6. In online tutorials that use [Window](/GTK/API#window), typically the Application wrapper class does not appear. The `Gtk.main()` method must be called somewhere in the script in order for the UI to appear.

#### Dice roller
:   
    <figure markdown>![](/img/gui-dice.png)</figure>

    ```py
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import random
    from math import floor

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)

            scale_adj = Gtk.Adjustment.new(1, 0, 6, 1, 2, 0)
            self.scale = Gtk.Scale.new(Gtk.Orientation.HORIZONTAL, scale_adj)
            self.scale.set_digits(0)
            
            button = Gtk.Button.new_with_label("Throw")
            button.connect("clicked", self.on_button_clicked)
            self.label = Gtk.Label.new()


            box = Gtk.Box.new(Gtk.Orientation.VERTICAL,5)
            box.pack_start(self.scale, False, True, 0)
            box.pack_start(button, False, True, 0)
            box.pack_start(self.label, False, True, 0)

            self.add(box)
            self.set_size_request(200,200)

        def on_button_clicked(self, button):
            dice = floor(self.scale.get_value())
            results = [random.randrange(6) for i in range(dice)]
            self.label.set_text(str(results))


    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

#### MenuBar
:   
    <figure markdown>![](/img/GUI/gui-gtk-menubar.png)</figure>

    ```py
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk

    class AppWindow(Gtk.ApplicationWindow):

        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_size_request(250, -1)
            menubar = Gtk.MenuBar.new()
            self.add(menubar)

            file = Gtk.MenuItem.new_with_label("File")
            menubar.append(file)
            filemenu = Gtk.Menu.new()
            file.set_submenu(filemenu)
            new = Gtk.MenuItem.new_with_label("New")
            open = Gtk.MenuItem.new_with_label("Open")
            filemenu.append(new)
            filemenu.append(open)

            edit = Gtk.MenuItem.new_with_label("Edit")
            menubar.append(edit)
            editmenu = Gtk.Menu.new()
            edit.set_submenu(editmenu)
            cut = Gtk.MenuItem.new_with_label("Cut")
            copy = Gtk.MenuItem.new_with_label("Copy")
            paste = Gtk.MenuItem.new_with_label("Paste")
            editmenu.append(cut)
            editmenu.append(copy) 
            editmenu.append(paste)

            help = Gtk.MenuItem.new_with_label("Help")
            menubar.append(help)
            helpmenu = Gtk.Menu.new()
            help.set_submenu(helpmenu)
            contents = Gtk.MenuItem.new_with_label("Help")
            about = Gtk.MenuItem.new_with_label("About")
            helpmenu.append(contents)
            helpmenu.append(about)

    class Application(Gtk.Application):

        def __init__(self, *args, **kwargs):
            super().__init__(*args, application_id="org.example.myapp", **kwargs)
            self.window = None

        def do_activate(self):
            if not self.window:
                self.window = AppWindow(application=self, title="Menu Bars")
            self.window.show_all()
            self.window.present()

    if __name__ == "__main__":
        app = Application()
        app.run()
    ```

#### Login
:   
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


### Hello, World!

=== "Window title"

    <figure markdown>![](/img/GTK/Hello-World/frame.png)</figure>

    ```py
    import sys
    import gi
    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, name, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_default_size(300,300)
            self.set_title(f"Hello, {name}!")
            self.show_all()


    class Application(Gtk.Application):
        def __init__(self, name):
            super().__init__(application_id="com.example.learning-gtk")
            self.name = name
            
        def do_activate(self):
            self.window = ApplicationWindow(application=self, name=self.name)


    if __name__ == '__main__':
        if len(sys.argv) > 1:
            app = Application(sys.argv[-1])
        else:
            app = Application("World")
        app.run()
    ```


=== "Label"

    <figure markdown>![](/img/GTK/Hello-World/label-cli.png)</figure>

    ```py hl_lines="10"
    import sys
    import gi
    gi.require_version("Gtk","3.0")
    from gi.repository import Gtk

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, name, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_size_request(300, 300)
            self.add(Gtk.Label(label=f"Hello, {name}!"))

    class Application(Gtk.Application):
        def __init__(self, name = "World", *args, **kwargs):
            self.name = name
            super().__init__(*args, application_id="org.example.myapp", **kwargs)

        def do_activate(self):
            self.window = ApplicationWindow(application=self, name = self.name, title = "Hello, World!")
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        if len(sys.argv) > 1:
            app = Application(sys.argv[-1])
        else:
            app = Application("World")
        app.run() 
    ```


=== "Button reveal"

    <figure markdown>![](/img/GTK/Hello-World/button.gif)</figure>

    ```xml title="Interface"
    <?xml version="1.0" encoding="UTF-8"?>
    <interface>
        <requires lib="gtk+" version="3.40">
        <object class="GtkApplicationWindow" id="window">
        <property name="title">My GTK App</property>
        <property name="default-width">300</property>
        <property name="default-height">300</property>
            <child>
            <object class="GtkButton" id="button">
                <property name="label">Press me!</property>
                <property name="margin-top">12</property>
                <property name="margin-bottom">12</property>
                <property name="margin-start">12</property>
                <property name="margin-end">12</property>  
            </object>
            </child>
        </object>
    </interface>
    ```

    ```py
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk

    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            builder = Gtk.Builder.new_from_file('hw-button.ui')
            self.window = builder.get_object('window')
            self.button = builder.get_object('button')
            self.button.connect('clicked', self.on_button_clicked)
            self.window.connect('destroy', Gtk.main_quit)
            self.window.show_all()
            self.window.present()

        def on_button_clicked(self, button):
            self.button.set_label('Hello, World!')

        def run(self):
            super().run()
            Gtk.main()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

=== "Interactive"

    <figure markdown>![](/img/GTK/Hello-World/hwi-dialog.gif)</figure>

    ```py hl_lines="19 22-30"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
            self.add(box)

            question = Gtk.Label.new("What is your name?")
            box.add(question)

            self.entry = Gtk.Entry(text="World")
            box.add(self.entry)

            button = Gtk.Button.new_with_mnemonic("Greet")
            button.connect("clicked", self.on_button_clicked, self)
            box.add(button)

        def on_button_clicked(self, button, parent):
            dialog = Gtk.MessageDialog(
                message_type=Gtk.MessageType.INFO,
                text=f"Hello, {parent.entry.get_text()}",
                parent=parent,
            )
            dialog.add_button("OK", Gtk.ResponseType.OK)
            dialog.run()
            dialog.destroy()

    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

=== "HeaderBar"

    ```py hl_lines="11-15"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import sys

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_default_size(-1, -1)
            # headerbar = Gtk.HeaderBar(title=f"Hello, {name}!", subtitle="HeaderBar example", show_close_button=True)
            headerbar = Gtk.HeaderBar()
            headerbar.set_title(f"Hello, World!")
            headerbar.set_subtitle("HeaderBar example")
            headerbar.set_show_close_button(True)
            self.set_titlebar(headerbar)

            button = Gtk.Button(label="Greet")
            button.connect("clicked", self.on_button_clicked, self)
            headerbar.add(button)

            self.entry = Gtk.Entry(text="World", name="entry")
            headerbar.add(self.entry)

        def on_button_clicked(self, button, parent):
            dialog = Gtk.MessageDialog(
                message_type=Gtk.MessageType.INFO,
                text=f"Hello, {parent.entry.get_text()}!",
                parent=parent,
            )
            dialog.add_button("O_K", Gtk.ResponseType.OK)
            dialog.run()
            dialog.destroy()

    class HeaderBar(Gtk.Application):
        def __init__(self):
            super().__init__(application_id="org.example.headerbar")
        
        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = HeaderBar()
        app.run()
    ```

### Starships

<figure markdown>![](/img/GTK/Starships/dialog.gif)</figure>

=== "Hardcoded data"

    ```py
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)

            ships = ['USS Enterprise', 'USS Defiant', 'USS Voyager']

            self.treeview = Gtk.TreeView(model=Gtk.ListStore.new((str,)))
            
            column = Gtk.TreeViewColumn("Ship", Gtk.CellRendererText(), text=0)
            self.treeview.append_column(column)
            for s in ships:
                self.treeview.get_model().append((s,))

            self.add(self.treeview)
            self.set_size_request(-1,-1)

    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

=== "CSV import"


    ```py hl_lines="4 10-13 17-19 21-22"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import csv

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            
            with open('/home/jasper/dogfood/csv/starships.csv',mode='r') as f:
                reader = csv.reader(f)
                self.headers = [h.title() for h in next(reader)]
                self.data = [r for r in reader]

            self.treeview = Gtk.TreeView(model=Gtk.ListStore.new((str,str,str,str)))
            
            for h in self.headers:
                column = Gtk.TreeViewColumn(h, Gtk.CellRendererText(), text=self.headers.index(h))
                self.treeview.append_column(column)

            for r in self.data:
                self.treeview.get_model().append(r)

            self.treeview.connect('row-activated', self.on_row_activated)

            self.add(self.treeview)
            self.set_size_request(-1,-1)

    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

=== "Sortable columns"

    ```py hl_lines="19"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import csv


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            
            with open('/home/jasper/dogfood/csv/starships.csv',mode='r') as f:
                reader = csv.reader(f)
                self.headers = [h.title() for h in next(reader)]
                self.data = [r for r in reader]

            self.treeview = Gtk.TreeView(model=Gtk.ListStore.new((str,str,str,str)))
            for h in self.headers:
                column = Gtk.TreeViewColumn(h, Gtk.CellRendererText(), text=self.headers.index(h))
                column.set_sort_column_id(self.headers.index(h))
                self.treeview.append_column(column)

            for r in self.data:
                self.treeview.get_model().append(r)

            self.treeview.connect('row-activated', self.on_row_activated)

            self.add(self.treeview)
            self.set_size_request(-1,-1)


    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

=== "Event handler"


    ```py hl_lines="30-32"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import csv


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            
            with open('/home/jasper/dogfood/csv/starships.csv',mode='r') as f:
                reader = csv.reader(f)
                self.headers = [h.title() for h in next(reader)]
                self.data = [r for r in reader]

            self.treeview = Gtk.TreeView(model=Gtk.ListStore.new((str,str,str,str)))
            for h in self.headers:
                column = Gtk.TreeViewColumn(h, Gtk.CellRendererText(), text=self.headers.index(h))
                column.set_sort_column_id(self.headers.index(h))
                self.treeview.append_column(column)

            for r in self.data:
                self.treeview.get_model().append(r)

            self.treeview.connect('row-activated', self.on_row_activated)

            self.add(self.treeview)
            self.set_size_request(-1,-1)

        def on_row_activated(self, treeview, path, col):
            model = treeview.get_model()
            print(f'Using path object as index to model: {model[path][:]}')


    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```

=== "MessageDialog"

    ```py hl_lines="29-38"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk
    import csv

    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            
            with open('/home/jasper/dogfood/csv/starships.csv',mode='r') as f:
                reader = csv.reader(f)
                self.headers = [h.title() for h in next(reader)]
                self.data = [r for r in reader]

            self.treeview = Gtk.TreeView(model=Gtk.ListStore.new((str,str,str,str)))
            for h in self.headers:
                column = Gtk.TreeViewColumn(h, Gtk.CellRendererText(), text=self.headers.index(h))
                column.set_sort_column_id(self.headers.index(h))
                self.treeview.append_column(column)

            for r in self.data:
                self.treeview.get_model().append(r)

            self.treeview.connect('row-activated', self.on_row_activated)

            self.add(self.treeview)
            self.set_size_request(-1,-1)

        def on_row_activated(self, treeview, path, col):
            model = treeview.get_model()
            dialog = Gtk.MessageDialog(
                message_type=Gtk.MessageType.INFO,
                text=model[path][:],
                parent = self
            )
            dialog.add_button("OK", Gtk.ResponseType.OK)
            dialog.run()
            dialog.destroy()


    class Application(Gtk.Application):
        def __init__(self):
            super().__init__(application_id='org.example.myapp')

        def do_activate(self):
            self.window = ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```
