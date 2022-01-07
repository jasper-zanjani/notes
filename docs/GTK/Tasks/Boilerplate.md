# Boilerplate

<figure markdown>
![](/img/GTK/GTK-boilerplate.png)
</figure>

??? info "Interface"

    ```xml
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

=== ":material-language-rust: Rust"

    ```rs title="gtk-rs"
    use gtk4::prelude::*;
    use gtk4::{Application, ApplicationWindow};

    fn main() {
        let app = Application::builder()
            .application_id("com.example.learning-gtk")
            .build();

        app.connect_activate(build_ui);
        app.run();
    }

    fn build_ui(app: &Application) {
        let window = ApplicationWindow::builder()
            .application(app)
            .default_width(300)
            .default_height(300)
            .title("My GTK App")
            .build();
        
        window.present();
    }
    ```

=== ":material-language-python: Python"

    ```py title="PyGTK"
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
