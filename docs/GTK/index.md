# :material-gnome: GTK

<figure><img src="/img/Logos/GTK_logo.svg" width="200px"></figure>

??? info "Resources"
    - [PyGObject API reference](https://lazka.github.io/pgi-docs/)
    - [PyGObject docs](https://pygobject.readthedocs.io/en/latest/index.html)
    
    Documentation for Rust GTK bindings

    - [GTK3](https://gtk-rs.org/gtk3-rs/stable/latest/docs/gtk/)
    - [GTK4](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/index.html)

Because GTK+ class properties are implemented as Python properties, with few exceptions they can usually be set either at instantiation or using dedicated setter methods.

```py
window = Gtk.Window(title="Hello World")    # kwarg
window.set_title(f"Hello, {name}!")         # setter
window.props.title=f"Hello, {name}"         # property
```

## gtk-rs

In the **gtk-rs** library for Rust, the API for building some structs uses the **`builder()`** factory method.
This API supports procedural construction of the object using a chain of method calls, ending in **`build()`**.

=== "Application"

    ```rs
    let app = Application::builder()
        .application_id("org.gtk-rs.example")
        .build();
    ```

=== "ApplicationWindow"

    ```rs
    let window = ApplicationWindow::builder()
        .application(app)
        .title("My GTK App")
        .child(&container)
        .build();
    ```

=== "Button"

    ```rs
    let button = Button::builder()
        .label("Press me!")
        .margin_top(12)
        .margin_bottom(12)
        .margin_start(12)
        .margin_end(12)
        .build();
    ```

Other objects, like **Box**, do not expose this API.

```rs
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
Alternatively, a [closure](../Rust#closure) can be used for simple windows.
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

Widgets are added by instantiating objects using the `builder()` factory method, then assigning them as children of ApplicationWindow.
This can be done using one of two ways:

- `child()` on instantiatiation, passing an immutable reference to the widget.
- `set_child()` method after instantiation, but this time passing a [`Some()`](../Rust#result) result containing the immutable reference to the widget.

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

[**`glib::clone`**](https://docs.rs/glib/0.9.0/glib/macro.clone.html) was [introduced](https://gtk-rs.org/blog/2019/12/15/new-release.html) to simplify the process of passing cloned references to objects by removing the need to manually declare new local variables that are then passed into the closure.
