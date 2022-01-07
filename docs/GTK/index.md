# Overview

<figure><img src="/img/Logos/GTK_logo.svg" width="200px"></figure>

??? info "Resources"
    - [PyGObject API reference](https://lazka.github.io/pgi-docs/)
    - [PyGObject docs](https://pygobject.readthedocs.io/en/latest/index.html)
    
    Documentation for Rust GTK bindings

    - [GTK3](https://gtk-rs.org/gtk3-rs/stable/latest/docs/gtk/)
    - [GTK4](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/index.html)

GTK is an open-source cross-platform widget toolkit developed by The GNOME Project for creating GUI applications.
Major desktop environments including GNOME and Xfce are based on GTK.

GTK was originally designed for use in GIMP as a replacement for the previous Motif toolkit which was unsatisfactory.
Since GTK 2.8 (2005), GTK uses the **Cairo** library to render vector graphics.

Building GTK application UIs can be done procedurally by defining UI elements in code or [declaratively](#interfaces) in XML interfaces.

#### Interfaces


XML **interfaces** can be defined in XML files or less commonly as string literals which are then loaded in the constructor for [Gtk.Builder](/GTK/API/#builder).
Interfaces are also known as "Glade files" after the popular Glade UI design application.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<interface> # (1)
  <requires lib="gtk+" version="3.40"/> <!-- (2) -->
  <object class="GtkApplicationWindow" id="window">
    <signal name="destroy" handler="on_main_window_destroy"/> <!-- (3) -->
    <child> <!-- (4) -->
      <object class="GtkBox">
        <property name="orientation">vertical</property> <!-- (5) -->
        <object class="GtkLabel" id="label">
          <property name="label">Hello, World!</property>
        </object>
      </object>
    </child>
  </object>
</interface>
```

1. The root node in these files is the **interface** element itself.
2. The first direct child of an interface is the **requires** element, with a version number that specifies the required version of GTK. If this interface used [Gtk.ApplicationWindow](/GTK/API/#applicationwindow) instead of [Gtk.Window](/GTK/API/#window), this number would have to be 3.40 because that is the version this class was introduced.
3. Signals and callbacks can be specified in the markup on the **signal** element, which is the direct child to the object emitting the signal and also self-closing. Callback method names are specified in the **handler** attribute
4. [Container](/GTK/API/#container) widgets like [Gtk.Box](/GTK/API/#box) wrap every child in a **child** element. Note that the interface element does not need a but is immediate parent to the outermost container of the UI.
5. Each property of an object is a **property** element with the name of the property provided in a **name** attribute and the value provided as the element's value.

The UI is then loaded into the application using [Gtk.Builder](/GTK/API/#builder). Individual UI elements can be bound if they have an **id** attribute assigned.

=== ":material-language-rust: Rust"

    ```rs hl_lines="11-13 15"
    fn main() {
        let app = gtk::Application::builder()
            .application_id("org.example.gtk-app")
            .build();

        app.connect_activate(build_ui);
        app.run();
    }

    fn build_ui(app: &Application):{
        let builder = gtk::Builder::from_string(include_str!("window.ui"));
        let window: ApplicationWindow = builder.object("window")
            .expect("Error loading ApplicationWindow!");

        window.set_application(Some(app));
        window.show_all();
        window.present();
    }
    ```

=== ":material-language-python: Python"

    ```py hl_lines="6 7"
    class Application(Gtk.Application):
        def __init__(self, *args, **kwargs):
            super().__init__(application_id = "org.example.gtk-app")
        
        def do_activate(self):
            builder = Gtk.Builder.new_from_file("window.ui")
            self.window = builder.get_object("window")
            self.window.show_all()
            self.window.present()

        def run(self):
            super().run()
            Gtk.main() # (1)
    ```
    
    1. For some reason, one of the differences between a PyGTK script that specifies its UI procedurally in code4 and one that takes it from an interface file is that **`Gtk.main()`** must be explicitly called somewhere.
    The [Application](/GTK/API/#application) object's **run()** method can be overridden to call it, or it can be placed in the script's entrypoint.


#### Builder pattern

A typical ways of building UIs procedurally in gtk-rs is the [Builder design pattern](https://rust-unofficial.github.io/patterns/patterns/creational/builder.html). 
This pattern supports procedural construction of the object using a chain of method calls, ending in **`build()`**.
Note, this is not to be confused with the [Gtk.Builder](/GTK/API/#builder) API that is actually used for declarative UI specification in [interfaces](#interfaces).

```rs hl_lines="6-8 11-16" title="gtk-rs"
use gtk4 as gtk;
use gtk::prelude::*;
use gtk::{Application, ApplicationWindow};

fn main() {
    let app = Application::builder()
        .application_id("org.example.HelloWorld")
        .build();

    app.connect_activate(|app| {
        let window = ApplicationWindow::builder()
            .application(app)
            .default_width(320)
            .default_height(200)
            .title("Hello, World!")
            .build();

        window.show();
    });

    app.run();
}
```

Other objects, like **Box**, do not expose this API.

#### connect\_activate

This simple (nonfunctional) example produces an error that demands a handler be implemented for the **`activate`** signal.
```rs
use gtk::prelude::*;
use gtk::Application;

fn main() {
    let app = Application::builder()
        .application_id("org.gtk-rs.example")
        .build();

    app.run();
}
```

Here the `activate` signal is bound to the `build_ui()` function.
Alternatively, a [closure](../Rust/Glossary#closure) can be used for simple windows.
ApplicationWindow's `present()` and `show()` methods appear to be interchangeable.

=== "Function"

    ```rs
    fn main() {
        // ...
        app.connect_activate(build_ui);
        app.run();
    }

    fn build_ui(app: &Application) {
        let window = ApplicationWindow::builder()
            .application(app)
            .title("My GTK App")
            .build();
        window.present();
    }
    ```

=== "Closure"

    ```rs
    fn main() {
        // ...
        app.connect_activate(|app| {
            let window = ApplicationWindow::builder()
                .application(app)
                .title("Hello, World!")
                .build();
            window.show();
        });
        app.run();
    }
    ```

Widgets are added as children of containers like [ApplicationWindow](/GTK/API/#applicationwindow) or [Box](/GTK/API/#box).
This can be done using one of two ways:

- **child()** builder helper method, passing an immutable reference to the widget.
- **set_child()** method after instantiation, but this time passing a [`Some()`](../Rust#result) result containing the immutable reference to the widget.

=== "child()"

    ```rs hl_lines="4"
    let window = ApplicationWindow::builder()
        .application(app)
        .title("Hello, World!")
        .child(&button)
        .build();
    ```

=== "set_child()"

    ```rs hl_lines="6"
    let window = ApplicationWindow::builder()
        .application(app)
        .title("Hello, World!")
        .build();

    window.set_child(Some(&button));
    ```
<!-- 

I don't know what I was talking about here or why it was important...

[**`glib::clone`**](https://docs.rs/glib/0.9.0/glib/macro.clone.html) was [introduced](https://gtk-rs.org/blog/2019/12/15/new-release.html) to simplify the process of passing cloned references to objects by removing the need to manually declare new local variables that are then passed into the closure. 

-->
