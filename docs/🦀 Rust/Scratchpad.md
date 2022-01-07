# Scratchpad

[GUI app](https://gtk-rs.org/gtk4-rs/stable/latest/book/gobject_memory_management.html) with two buttons that increment or decrement an integer.

??? info "Full working code"

    ```rs
    use gtk4::prelude::*;
    use gtk4::{Application, ApplicationWindow, Button, Orientation, glib::clone};
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
        let number = Rc::new(Cell::new(0));

        // Connect callbacks
        // When a button is clicked, `number` and label of the other button will be changed
        button_increase.connect_clicked(clone!(@weak number, @weak button_decrease => // (1)
            move |_| {
                number.set(number.get() + 1);
                button_decrease.set_label(&number.get().to_string());
        }));
        button_decrease.connect_clicked(clone!(@weak button_increase =>
            move |_| {
                number.set(number.get() - 1);
                button_increase.set_label(&number.get().to_string());
        }));

        // Add buttons to `gtk_box`
        let gtk_box = gtk4::Box::builder()
            .orientation(Orientation::Vertical)
            .build();
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

=== "1"

    ```rs linenums="36"
    let mut number = 0;

    button_increase.connect_clicked(|_| number += 1); // (1)
    button_decrease.connect_clicked(|_| number -= 1); // (2)
    ```

    1. Compiler will produce errors here because the closure mutably borrows the number variable twice in the same scope. 
    ```
    error[E0499]: cannot borrow `number` as mutable more than once at a time
      --> main.rs:27:37
       |
    26 |     button_increase.connect_clicked(|_| number += 1);
       |     ------------------------------------------------
       |     |                               |   |
       |     |                               |   first borrow occurs due to use of `number` in closure
       |     |                               first mutable borrow occurs here
       |     argument requires that `number` is borrowed for `'static`
    27 |     button_decrease.connect_clicked(|_| number -= 1);
       |                                     ^^^ ------ second borrow occurs due to use of `number` in closure
       |                                     |
       |                                     second mutable borrow occurs here
    ```
    2. There is also an additional error about lifetimes
    ```
    error[E0373]: closure may outlive the current function, but it borrows `number`, which is owned by the current function
      --> main.rs:26:37
       |
    26 |     button_increase.connect_clicked(|_| number += 1);
       |                                     ^^^ ------ `number` is borrowed here
       |                                     |
       |                                     may outlive borrowed value `number`
       |
    note: function requires argument type to outlive `'static`
      --> main.rs:26:5
       |
    26 |     button_increase.connect_clicked(|_| number += 1);
       |     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    help: to force the closure to take ownership of `number` (and any other referenced variables), use the `move` keyword
       |
    26 |     button_increase.connect_clicked(move |_| number += 1);
       |                                     ^^^^^^^^
    ```

=== "2"

    ```rs linenums="36"
    let number = Rc::new(Cell::new(0)); // (1)

    // Connect callbacks, when a button is clicked `number` will be changed
    let number_copy = number.clone();   // (2)
    button_increase.connect_clicked(move |_| number_copy.set(number_copy.get() + 1));
    button_decrease.connect_clicked(move |_| number.set(number.get() - 1));
    ```

    1. Wrapping the number value into a Rc&lt;Cell&lt;T&gt;&gt; helps implement multiple owners.
    2. But temporary variables like **number\_copy** are an anti-pattern.

=== "3"

    ```rs linenums="36"
    let number = Rc::new(Cell::new(0));

    // Connect callbacks
    // When a button is clicked, `number` and label of the other button will be changed
    button_increase.connect_clicked(clone!(@weak number, @strong button_decrease => // (1)
        move |_| {
            number.set(number.get() + 1);
            button_decrease.set_label(&number.get().to_string());
    }));
    button_decrease.connect_clicked(clone!(@strong button_increase =>
        move |_| {
            number.set(number.get() - 1);
            button_increase.set_label(&number.get().to_string());
    }));
    ```

    1. The [**glib::clone** macro](/GTK/API#clone "glib::clone") allows strong or weak references to be passed to closures. A strong reference keeps the value from being deallocated, in this case leading to a **reference cycle**.
    In point of fact, closing the window actually resolves the cycle.

=== "4"

    ```rs linenums="36"
    let number = Rc::new(Cell::new(0));

    // Connect callbacks
    // When a button is clicked, `number` and label of the other button will be changed
    button_increase.connect_clicked(clone!(@weak number, @weak button_decrease => // (1)
        move |_| {
            number.set(number.get() + 1);
            button_decrease.set_label(&number.get().to_string());
    }));
    button_decrease.connect_clicked(clone!(@weak button_increase =>
        move |_| {
            number.set(number.get() - 1);
            button_increase.set_label(&number.get().to_string());
    }));
    ```

    1. Changing to a weak reference resolves the reference cycle.
