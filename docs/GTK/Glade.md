# Glade

Glade files are XML **interfaces** that can be defined by strings inline or (more usually) in XML files, which are then loaded in the constructor for [Gtk.Builder](#builder).

- The root node in these files is the **interface** element itself.
- The first direct child of an interface is the **requires** element, with a version number that specifies the required version of GTK. It contains no children so it is self-closing.
- Signals and callbacks are specified in the markup on the **signal** element, which is the direct child to the object emitting the signal and also self-closing. Callback method names are specified in the **handler** attribute
- [Container](#container) widgets like [Gtk.Box](#box) wrap every child in a **child** element. Note that the interface element does not need a but is immediate parent to the outermost container of the UI.
- Each property of an object is a **property** element with the name of the property provided in a **name** attribute and the value provided as the element's value.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<interface>
  <requires lib="gtk+" version="3.20"/>
  <object class="GtkWindow" id="main_window">
    <signal name="destroy" handler="on_main_window_destroy"/>
    <child>
      <object class="GtkBox">
        <property name="orientation">vertical</property>
        <child>
          <object class="GtkEntry"/>
        </child>
      </object>
    </child>
  </object>
</interface>
```

#### Hello, World!

Here, a simple text message is displayed to to the user.
The UI specified by the markup, which can be either [Gtk.Window](#window) or [Gtk.ApplicationWindow](#applicationwindow), is assigned to the window property of the Application object.
Note that the required version must be greater than 3.4 when using ApplicationWindow because that is the version in which it was introduced.

=== "Window"

    ```xml hl_lines="3 4"
    <?xml version="1.0" encoding="UTF-8"?>
    <interface>
      <requires lib="gtk+" version="3.00"/>
      <object class="GtkWindow" id="window">
        <property name="height-request">300</property>
        <property name="width-request">300</property>
        <child>
          <object class="GtkLabel" id="label">
            <property name="label">Hello, World!</property>
          </object>
        </child>
      </object>
    </interface>
    ```

=== "ApplicationWindow"

    ```xml hl_lines="3 4"
    <?xml version="1.0" encoding="UTF-8"?>
    <interface>
      <requires lib="gtk+" version="3.40"/>
      <object class="GtkApplicationWindow" id="window">
        <property name="height-request">300</property>
        <property name="width-request">300</property>
        <child>
          <object class="GtkLabel" id="label">
            <property name="label">Hello, World!</property>
          </object>
        </child>
      </object>
    </interface>
    ```

The application will not close correctly without explicitly binding the destroy signal.
This is because signal handlers specified in the markup must be mapped to actual methods in the code. 
This is done with the `connect_signals()` method, which can be used in two different ways depending on the object passed:

- **Class** that implements the named methods exactly
- **Dictionary** that maps handler values from markup to function names

=== "Handler object"

    ```py
    class Handlers():
        def on_window_destroy(self):
            Gtk.main_quit()
    
    builder.connect_signals(Handlers())
    ```

=== "Dictionary"

    ```py
    handlers = {
        "on_window_destroy": Gtk.main_quit
    }

    builder.connect_signals(handlers)
    ```


`Gtk.main()` must be explicitly called somewhere. Here it is called in `Application.run()`, but it can also be placed in the script's entrypoint.

```py
import gi
gi.require_version("Gtk","3.0")
from gi.repository import Gtk
import sys


class Application(Gtk.Application):
    def __init__(self, *args, name = "World", **kwargs):
        self.name = name
        super().__init__(*args, application_id="org.example.myapp", **kwargs)

    def do_activate(self):
        builder = Gtk.Builder.new_from_file('hwp.glade')
        self.window = builder.get_object('window')
        self.window.connect("destroy",Gtk.main_quit)
        self.window.set_title(f'Hello, {self.name}!')
        label = builder.get_object('label')
        label.set_text(f'Hello, {self.name}!')
        self.window.show_all()
        self.window.present()

    def run(self):
        super().run()
        Gtk.main()

if __name__ == '__main__':
    app = Application(name=sys.argv[-1])
    app.run()
```


#### Hello, World! (interactive)

All of the examples in this task extend the following application markup and differ exclusively in the implementation of the `on_button_clicked()` signal handler.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!-- Generated with glade 3.38.2 -->
<interface>
  <requires lib="gtk+" version="3.4"/>
  <object class="GtkApplicationWindow" id="window">
    <property name="width-request">200</property>
    <property name="height-request">200</property>
    <property name="can-focus">False</property>
    <signal name="destroy" handler="on_window_destroy" swapped="no"/>
    <child>
      <object class="GtkBox">
        <property name="can-focus">False</property>
        <property name="orientation">vertical</property>
        <child>
          <object class="GtkEntry" id="entry">
            <property name="can-focus">True</property>
            <property name="show-emoji-icon">True</property>
          </object>
          <packing>
            <property name="expand">False</property>
            <property name="fill">True</property>
            <property name="position">0</property>
          </packing>
        </child>
        <child>
          <object class="GtkButton" id="button">
            <property name="label">Greet</property>
            <property name="can-focus">True</property>
            <property name="receives-default">False</property>
            <signal name="clicked" handler="on_button_clicked" swapped="no"/>
          </object>
          <packing>
            <property name="expand">False</property>
            <property name="fill">True</property>
            <property name="position">1</property>
          </packing>
        </child>
        <child>
          <object class="GtkLabel" id="label">
            <property name="can-focus">False</property>
          </object>
          <packing>
            <property name="expand">True</property>
            <property name="fill">True</property>
            <property name="position">2</property>
          </packing>
        </child>
      </object>
    </child>
  </object>
</interface>
```

=== "`Label`"

    <figure><img src="/img/GUI/gui-gtk-hwi-label.gif"/></figure>

    ```py hl_lines="26-28"
    import gi
    gi.require_version("Gtk","3.0")
    from gi.repository import Gtk
    import sys


    class Application(Gtk.Application):
        def __init__(self, name = "World", *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.name = name

        def do_activate(self):
            self.builder = Gtk.Builder.new_from_file('hwi.glade')
            self.window = self.builder.get_object('window')
            self.window.set_title(f"Hello, {self.name}!")
            self.builder.connect_signals(self)

            self.entry = self.builder.get_object('entry')
            self.entry.set_text(self.name)

            self.label = self.builder.get_object('label')

            self.window.show_all()
            self.window.present()

        def on_button_clicked(self, button):
            self.label.set_text(f'Hello, {self.entry.get_text()}!')
            self.window.set_title(f'Hello, {self.entry.get_text()}!')

        def on_window_destroy(self, arg):
            Gtk.main_quit()

        def run(self):
            super().run()
            Gtk.main()

    if __name__ == '__main__':
        try:
            app = Application(sys.argv[1])
        except IndexError:
            app = Application()
        app.run()
    ```


=== "`MessageDialog`"

    <figure><img src="/img/GUI/gui-gtk-hwi-dialog.gif"/></figure>

    ```py hl_lines="26-34"
    import gi
    gi.require_version("Gtk","3.0")
    from gi.repository import Gtk
    import sys


    class Application(Gtk.Application):
        def __init__(self, name = "World", *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.name = name

        def do_activate(self):
            self.builder = Gtk.Builder.new_from_file('hwi.glade')
            self.window = self.builder.get_object('window')
            self.window.set_title(f"Hello, {self.name}!")
            self.builder.connect_signals(self)

            self.entry = self.builder.get_object('entry')
            self.entry.set_text(self.name)

            self.label = self.builder.get_object('label')

            self.window.show_all()
            self.window.present()

        def on_button_clicked(self, button):
            dialog = Gtk.MessageDialog(
                message_type=Gtk.MessageType.INFO,
                text=f"Hello, {self.entry.get_text()}",
                parent=self.window,
            )
            dialog.add_button("O_K", Gtk.ResponseType.OK)
            dialog.run()
            dialog.destroy()

        def on_window_destroy(self, arg):
            Gtk.main_quit()

        def run(self):
            super().run()
            Gtk.main()

    if __name__ == '__main__':
        try:
            app = Application(sys.argv[1])
        except IndexError:
            app = Application()
        app.run()
    ```

#### Menu

GTK objects are declared using either special predefined elements (e.g. **menu**) or an **object** element with the class name itself specified in the **class** attribute.
These syntaxes do not appear to be entirely interchangeable.

=== "Predefined element"

    ```xml
    <menu id="app-menu">
    ```

=== "`object` element"

    ```xml
    <object class="GtkMenu" id="app-menu">
    ```

Here, each  menu item is described by one of three attribute, identifiable in the **attribute** XML tags:

- **`action`** which names an action and class to handle the signal
- **`target`** specifies the string that displays in the menu item
- **`label`** whether or not the target attribute string should be translated


```xml hl_lines="9-12 14-16"
<?xml version="1.0" encoding="UTF-8"?>
<interface>
  <menu id="app-menu">
    <section>
      <attribute name="label" translatable="yes">
        Change label
      </attribute>
      <item>
        <attribute name="action">win.change_label</attribute>
        <attribute name="target">String 1</attribute>
        <attribute name="label" translatable="yes">String 1</attribute>
      </item>
      <item>
        <attribute name="action">win.change_label</attribute>
        <attribute name="target">String 2</attribute>
        <attribute name="label" translatable="yes">String 2</attribute>
      </item>
    </section>
  </menu>
</interface>
```


#### Examples

=== "Hello, World!"

    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <!-- Generated with glade 3.38.2 -->
    <interface>
      <requires lib="gtk+" version="3.24"/>
      <object class="GtkApplicationWindow">
        <property name="can-focus">False</property>
        <child>
          <object class="GtkLabel">
            <property name="visible">True</property>
            <property name="can-focus">False</property>
            <property name="label" translatable="yes">Hello, World!</property>
          </object>
        </child>
      </object>
    </interface>
    ```

=== "Basic example"

    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <interface>
    <menu id="app-menu">
      <section>
      <attribute name="label" translatable="yes">Change label</attribute>
      <item>
        <attribute name="action">win.change_label</attribute>
        <attribute name="target">String 1</attribute>
        <attribute name="label" translatable="yes">String 1</attribute>
      </item>
      <item>
        <attribute name="action">win.change_label</attribute>
        <attribute name="target">String 2</attribute>
        <attribute name="label" translatable="yes">String 2</attribute>
      </item>
      <item>
        <attribute name="action">win.change_label</attribute>
        <attribute name="target">String 3</attribute>
        <attribute name="label" translatable="yes">String 3</attribute>
      </item>
      </section>
      <section>
      <item>
        <attribute name="action">win.maximize</attribute>
        <attribute name="label" translatable="yes">Maximize</attribute>
      </item>
      </section>
      <section>
      <item>
        <attribute name="action">app.about</attribute>
        <attribute name="label" translatable="yes">_About</attribute>
      </item>
      <item>
        <attribute name="action">app.quit</attribute>
        <attribute name="label" translatable="yes">_Quit</attribute>
        <attribute name="accel">&lt;Primary&gt;q</attribute>
      </item>
      </section>
    </menu>
    </interface>
    ```