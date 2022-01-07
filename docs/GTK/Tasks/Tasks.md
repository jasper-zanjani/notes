# Tasks

#### Login


=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"

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
