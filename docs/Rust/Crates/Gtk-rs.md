# gtk-rs

## Tasks

#### Development environment
:   
    ```sh title="Red Hat"
    dnf install gtk4-devel gcc
    ```

    ```sh title="Ubuntu"
    apt install libgtk-4-dev build-essential
    ```

#### Boilerplate
:   
    <figure markdown>![](/img/GTK/GTK-boilerplate.png)</figure>

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

    ```rs
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

#### Clicker
:   

    This appears to be a common demonstration of data binding in various GUI frameworks, the code below is taken from [here](https://gtk-rs.org/gtk4-rs/git/book/gobject_memory_management.html).

    ```rs
    use gtk4::prelude::*;
    use gtk4::{glib, Application, ApplicationWindow, Box, Button, Orientation};
    use std::{cell::Cell, rc::Rc};

    fn main() {
        // Create a new application
        let app = Application::builder()
            .application_id("org.gtk-rs.example")
            .build();

        // Connect to "activate" signal of `app`
        app.connect_activate(build_ui);

        // Run the application
        app.run();
    }

    fn build_ui(app: &Application) {
        // Create two buttons
        let button_increase = Button::builder()
            .label("Increase")
            .margin_top(12)
            .margin_bottom(12)
            .margin_start(12)
            .margin_end(12)
            .build();
        let button_decrease = Button::builder()
            .label("Decrease")
            .margin_top(12)
            .margin_bottom(12)
            .margin_start(12)
            .margin_end(12)
            .build();

        // Reference-counted object with inner mutability
        let number = Rc::new(Cell::new(0)); // (1)

        // Connect callbacks
        // When a button is clicked, `number` and label of the other button will be changed
        button_increase.connect_clicked(glib::clone!(@weak number, @weak button_decrease => // (2)
            move |_| {
                number.set(number.get() + 1);
                button_decrease.set_label(&number.get().to_string());
        }));
        button_decrease.connect_clicked(glib::clone!(@weak button_increase => // (3)
            move |_| {
                number.set(number.get() - 1);
                button_increase.set_label(&number.get().to_string());
        }));

        // Add buttons to `gtk_box`
        let gtk_box = Box::builder().orientation(Orientation::Vertical).build();
        gtk_box.append(&button_increase);
        gtk_box.append(&button_decrease);

        // Create a window
        let window = ApplicationWindow::builder()
            .application(app)
            .title("My GTK App")
            .child(&gtk_box)
            .build();

        // Present the window
        window.present();
    }
    ```

    1. It appears **number** must be an Rc&lt;Cell&gt;. Changing it to a raw i8 causes compilation errors within [glib::clone](#glibclone).
    2. Removing the weak reference to **number** causes a compilation error.
    3. Adding a weak reference to **number** here also causes a compilation error.

### Hello, World!

#### Window frame
:   
    <figure markdown>![](/img/GTK/GTK-hw-frame.png)</figure>

    !!! warn "TODO"
    
        At the moment, this example is broken because I don't know how to pass the string into the **Application** struct for string interpolation.

    ```rs
    use gtk4::prelude::*;
    use gtk4::{Application, ApplicationWindow};

    fn main() {
        let name = String::new();
        if let Some(s) = 42std::env::args().nth(1) {
            name = s;
        } else {
            name = String::from("World");
        };

        let app = Application::builder()
            .application_id("com.example.learning-gtk")
            .build();
        app.connect_activate(build_ui);
        println!("{}", app.name);
        app.run();
    }

    fn build_ui(app: &Application) {
        let window = ApplicationWindow::builder()
            .application(app)
            .title("Hello, World!")
            .default_height(300)
            .default_width(300)
            .build();
        window.present();
    }
    ```

#### Button reveal
:   
    <figure markdown>![](/img/GTK/Hello-World/button.gif)</figure>

    ??? info "Interface"

        ```xml
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

    ```rs
    use gtk::prelude::*;
    use gtk::{Application, ApplicationWindow, Button};

    fn main() {
        let app = Application::builder()
            .application_id("org.gtk-rs.example")
            .build();

        app.connect_activate(build_ui);
        app.run();
    }

    fn build_ui(app: &Application) {
        let builder = gtk::Builder::from_string(include_str!("window.ui"));
        let window: ApplicationWindow = builder
            .object("window")
            .expect("Could not get object `window` from builder.");
        let button: Button = builder
            .object("button")
            .expect("Could not get object `button` from builder.");

        window.set_application(Some(app));

        button.connect_clicked(move |button| { // (1)
            button.set_label("Hello World!");
        });

        window.set_child(Some(&button));
        window.show_all();
        window.present();
    }
    ```

    1. This `move` keyword appears to be unnecessary.

## API

#### glib::clone
:   
    [**glib::clone!**](http://gtk-rs.org/gtk-rs-core/stable/latest/docs/glib/macro.clone.html) is used to create closures using strong or weak references.

    === "Strong"

        ```rs hl_lines="6"
        use glib;
        use glib_macros::clone;
        use std::rc::Rc;

        let v = Rc::new(1);
        let closure = clone!(@strong v => move |x| {
            println!("v: {}, x: {}", v, x);
        });

        closure(2);
        ```

    === "Weak"

        ```rs hl_lines="6"
        use glib;
        use glib_macros::clone;
        use std::rc::Rc;

        let u = Rc::new(2);
        let closure = clone!(@weak u => move |x| {
            println!("u: {}, x: {}", u, x);
        });

        closure(3);
        ```

#### glib::wrapper
:   
    [**glib::wrapper**](https://gtk-rs.org/gtk-rs-core/stable/latest/docs/glib/macro.wrapper.html) is used to wrap GObjects and figures prominently in the [To-Do App](#).
    Parent classes must be provided after **@extends** and any interfaces implemented must be provided after **@implements**

    ```rs
    wrapper! {
        pub struct $name($kind<$foreign>); // (2)

        match fn {
            $fn_name => /* (1) */,
            ...
        }
    }
    ```

    1. Closure-like expressions in the **match fn** block allow copying, freeing, referencing, and dereferencing the value that is being wrapped.
    2. There are three possible values for **$kind**: **Boxed** (heap allocated types), **Shared** (records with reference-counted, shared ownership), or **Object** (classes)
    
    ```rs
    wrapper! {
        pub struct Button(Object<ffi::GtkButton>)
            @extends Bin, Container, Widget,
            @implements Buildable, Actionable;

        match fn {
            type_ => || ffi::gtk_button_get_type(), // (1)
        }
    }
    ```


--8<-- "includes/GTK/API.md"

