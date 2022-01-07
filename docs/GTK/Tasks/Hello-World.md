# Hello, World!



#### Window frame

<figure markdown>
![](/img/GTK/GTK-hw-frame.png)
</figure>

=== ":material-language-rust: Rust"

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

=== ":material-language-python: Python"

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


#### Label

<figure markdown>
![](/img/GUI/gui-gtk-hwlabel.png)
</figure>

=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"

    ```py hl_lines="11"
    import gi
    gi.require_version("Gtk","3.0")
    from gi.repository import Gtk
    import sys


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, name, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_size_request(200, 200)
            self.add(Gtk.Label(label=f"Hello, {name}!"))

    class Application(Gtk.Application):
        def __init__(self, name = "World", *args, **kwargs):
            self.name = name
            super().__init__(*args, application_id="org.example.myapp", **kwargs)

        def do_activate(self):
            self.window = ApplicationWindow(application=self, name, title = f"Hello, {self.name}!")
            self.window.show_all()
            self.window.present()

    if __name__ == '__main__':
        app = Application()
        app.run()
    ```


#### Button reveal

<figure markdown>
![](/img/GTK/GTK-hw-button.gif)
</figure>

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

=== ":material-language-rust: Rust"

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

=== ":material-language-python: Python"

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



#### Interactive

<figure markdown>
![](/img/GUI/gui-gtk-messagedialog.png)
</figure>

=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"

    ```py hl_lines="22-30"
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



#### HeaderBar

<figure markdown>
![](/img/GUI/gui-gtk-messagedialog-headerbar.png)
</figure>

=== ":material-language-rust: Rust"

    ```rs
    ```

=== ":material-language-python: Python"

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
