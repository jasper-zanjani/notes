# Starships

This task implements the [list/details pattern](https://docs.microsoft.com/en-us/windows/apps/design/controls/list-details).


<figure markdown>
![](/img/GUI/gui-gtk-starships-messagedialog.gif)
</figure>

#### Hardcoded data


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"

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

#### CSV import


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"


    ```py hl_lines="4 11-14 18-20 22-23"
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

#### Sortable columns


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"


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

#### Event handler


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"


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

#### MessageDialog


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"


    ```py hl_lines="30-39"
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


#### Dice roller

<figure markdown>
![](/img/gui-dice.png)
</figure>

=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"

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

<figure markdown>
![](/img/GUI/gui-gtk-menubar.png)
</figure>


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"


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