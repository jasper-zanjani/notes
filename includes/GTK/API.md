#### Action
:   

    **Gio.Action** is a way to expose any single task an application or widget does by a name.
    Classes like Gio.MenuItem and Gtk.ModelButton support properties to set an action name.
    These actions can be collected into a **Gio.ActionGroup**{: #actiongroup }.

    - **Gio.ActionMap** are interfaces implemented by [Gtk.ApplicationWindow](#applicationwindow)

#### ActionGroup
:   

#### Adjustment
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |


    **Gtk.Adjustment** is not a widget per se but is used in many widgets, including spin buttons, view ports, and children of **Gtk.Range**.

    - **page increment** and **page size** refer to actions taken when the user presses <kbd>PgUp</kbd> or <kbd>PgDn</kbd>
    ```py
    Gtk.Adjustment.new(initial_value, lower_range, upper_range, step_increment, page_increment, page_size)
    ```


#### Alignment
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.Alignment** controls the alignment and size of its child widget.


#### Application
:   
    | :material-language-python: PyGobject                                                                  | :material-language-rust: gtk-rs                                                                 | :material-language-c: gtk                                          |
    | ----------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
    | [Gtk.Application](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Application.html#Gtk.Application) | [gtk4::Application](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Application.html) | [GtkApplication](https://docs.gtk.org/gtk4/class.Application.html) |

    Subclasses of **Gtk.Application** encapsulate application behavior, including application startup and CLI processing.
    In practice it is simply a wrapper for the [ApplicationWindow](#applicationwindow) class which is instantiated in the `do_activate()` hook.
    Notably, the Application subclass provides the value for the **`application_id`** kwarg passed to the Gtk.Application constructor.
    This value is validated, and any simple string is not silently accepted.

    Application must expose several important methods:

    - **`do_activate()`**
    ```py
    def do_activate(self):
    self.window = ApplicationWindow(application=self, title="Hello, World!")
    self.window.show_all()
    self.window.present()
    ```
    - **`do_startup()`**


#### ApplicationWindow
:   
    | :material-language-python: PyGobject                                                                                    | :material-language-rust: gtk-rs                                                                             | :material-language-c: gtk                                                      |
    | ----------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
    | [Gtk.ApplicationWindow](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/ApplicationWindow.html#Gtk.ApplicationWindow) | [gtk4::ApplicationWindow](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.ApplicationWindow.html) | [GtkApplicationWindow](https://docs.gtk.org/gtk3/class.ApplicationWindow.html) |

    The **Gtk.ApplicationWindow** class is the main visible window for the application, and the only window for "single-instance" applications (which is the default).
    The ApplicationWindow class was introduced in GTK 3.4.

    When an [action](#actions) has the prefix `win.` it specifies that the ApplicationWindow subclass will process the signal.


#### Assistant
:   
    | :material-language-python: PyGobject                                                            | :material-language-rust: gtk-rs                                                             | :material-language-c: gtk                                      |
    | ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
    | [Gtk.Assistant](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Assistant.html#Gtk.Assistant) | [gtk4::Assistant](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Assistant.html) | [GtkAssistant](https://docs.gtk.org/gtk4/class.Assistant.html) |
    
    **Gtk.Assistant** widgets are used to implement the **wizard** pattern.

#### Box
:   
    | :material-language-python: PyGobject                                          | :material-language-rust: gtk-rs                                                 | :material-language-c: gtk                          |
    | ----------------------------------------------------------------------------- | ------------------------------------------------------------------------------- | -------------------------------------------------- |
    | [Gtk.Box](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Box.html#Gtk.Box) | [gtk4::Box](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Box.html) | [GtkBox](https://docs.gtk.org/gtk4/class.Box.html) |

#### Builder
:   
    | :material-language-python: PyGobject                                                      | :material-language-rust: gtk-rs                                                         | :material-language-c: gtk                                  |
    | ----------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
    | [Gtk.Builder](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Builder.html#Gtk.Builder) | [gtk4::Builder](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Builder.html) | [GtkBuilder](https://docs.gtk.org/gtk4/class.Builder.html) |

    **Gtk.Builder** allows the use of [interfaces](/GTK/#interfaces) to define widget layouts.
    Individual UI elements can be bound if they have an **id** attribute assigned.

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
                Gtk.main()
        ```

#### CheckButton
:   
    | :material-language-python: PyGobject                                                                  | :material-language-rust: gtk-rs                                                                 | :material-language-c: gtk                                          |
    | ----------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
    | [Gtk.CheckButton](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/CheckButton.html#Gtk.CheckButton) | [gtk4::CheckButton](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.CheckButton.html) | [GtkCheckButton](https://docs.gtk.org/gtk4/class.CheckButton.html) |

    **Gtk.CheckButton**s include checkboxes and (when placed into groups) radio buttons.

#### Container
:   
    | :material-language-python: PyGobject                                                            | :material-language-rust: gtk-rs                                                           | :material-language-c: gtk                                            |
    | ----------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- | -------------------------------------------------------------------- |
    | [Gtk.Container](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Container.html#Gtk.Container) | [gtk::Container](https://gtk-rs.org/gtk3-rs/stable/latest/docs/gtk/struct.Container.html) | [GtkContainer (3.0)](https://docs.gtk.org/gtk3/class.Container.html) |

    Both [Gtk.ApplicationWindow](#applicationwindow) and [Gtk.Window](#window) classes indirectly derive from the abstract class **Gtk.Container**.
    The main purpose of a container subclass is to allow a parent widget to contain one or more child widgets, and there are two types:

#### Dialog
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |



    <figure><img src="/img/GUI/gui-gtk-messagedialog.png"/></figure>

    **Gtk.Dialog** [:material-file-document:](https://docs.gtk.org/gtk3/class.Dialog.html) provides a convenient way to prompt the user for a small amount of input.
    It is a widget that can be instantiated and customized in its own right as well as a parent to various subclasses. 
    ```py
    dialog = Gtk.Dialog(title="Hello, World!", parent=parent)
    ```

    Dialogs are split into two parts:

    - **Content area** containing interactive widgets
    - **Action area** containing buttons

    These areas are both combined in a vertical [Box](#box) that is assigned to the **`vbox`** field.
    The action area is packed to the end of this vbox, so the `pack_start()` method is used to add widgets to the content area.

    Dialog boxes can be **modal**, meaning they prevent interaction with the main window while open, or **nonmodal**.

    === "Modal"
        ```py
        dialog = Gtk.Dialog(title="Hello, World!", parent=parent, modal=True)
        ```
    === "Nonmodal"
        ```py
        dialog = Gtk.Dialog(title="Hello, World!", parent=parent, modal=False)
        ```

    **Gtk.MessageDialog**{: #messagedialog } is a subtype of Dialog meant to simplify the process of creating simple dialogs.

    Buttons are added procedurally using `add_button()`, passing a display string (with support for mnemonics using `_`) and a ResponseType enum
    (they once could be added on instantiation by passing a tuple to the **`buttons`** keyword argument).
    
    ```py
    dialog.add_button("_OK", Gtk.ResponseType.OK)
    ```

    Methods:

    - **add_button()** [:material-file-document:](https://docs.gtk.org/gtk3/method.Dialog.add_button.html)


#### Entry
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    Unlike other widgets, **Gtk.Entry** can be instantiated without using a specific constructor.
    ```py
    entry = Gtk.Entry()
    ```

    Default text can be provided by passing a string to the **text** keyword argument or with the `set_text()` setter method:

    === "kwarg"

        ```py
        entry = Gtk.Entry(text="Hello, World!")
        ```

    === "setter"

        ```py
        entry.set_text("Hello, World!")
        ```

    A password field can be made by concealing text by passing False to  **visibility** or with the `set_visibility()` setter:

    === "kwarg"

        ```py
        password = Gtk.Entry(visibility=False)
        ```
    
    === "setter"
    
        ```py
        password.set_visibility(False)
        ```

    - **`get_text()`** [:material-file-document:](https://docs.gtk.org/gtk3/method.Entry.get_text.html) retrieve contents (string)
    - **`set_visibility(bool)`** [:material-file-document:](https://docs.gtk.org/gtk3/method.Entry.set_visibility.html) conceal text

#### EventBox
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.EventBox** is a container widget that allows event handling for widgets like [Gtk.Label](#label) that do not have an associated GDK window.
    The event box can be positioned above or below the windows of its child with `set_above_child()` (False by default.)
    An EventBox must also have a **Gtk.EventMask** enum set to specify the type of events the widget may receive. This enum is passed as a value to `set_events()`.
    

    In the following example, an event handler is connected to the EventBox to handle `button_press_event`. 
    This event handler changes the text of the Label after a double-click.

    ```py hl_lines="11-18"
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gtk, Gdk


    class AppWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_border_width(10)
            self.set_size_request(200, 50)
            eventbox = Gtk.EventBox.new()
            label = Gtk.Label.new("Double-Click Me!")
            eventbox.set_above_child(False)
            eventbox.connect("button_press_event", self.on_button_pressed, label)
            eventbox.add(label)
            self.add(eventbox)
            eventbox.set_events(Gdk.EventMask.BUTTON_PRESS_MASK)
            eventbox.realize()

        def on_button_pressed(self, eventbox, event, label):
            if event.type == Gdk.EventType._2BUTTON_PRESS:
                text = label.get_text()
                if text[0] == 'D':
                    label.set_text("I Was Double-Clicked!")
                else:
                    label.set_text("Double-Click Me Again!")
            return False

    class Application(Gtk.Application):

        def __init__(self, *args, **kwargs):
            super().__init__(*args, application_id="org.example.myapp", **kwargs)
            self.window = None

        def do_activate(self):
            if not self.window:
                self.window = AppWindow(application=self, title="Hello World!")
            self.window.show_all()
            self.window.present()

    if __name__ == "__main__":
        app = Application()
        app.run()
    ```

#### FileChooserDialog
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.FileChooserDialog** is one of the important subtypes of [Gtk.Dialog](#dialog).
    Like other dialogs, it is provided a title and parent window on instantiation.
    Additionally a FileChooserAction enum must be specified.

    **FileChooserAction**s include:

    - **Gtk.FileChooserAction.SAVE**
    - **Gtk.FileChooserAction.OPEN**
    - **Gtk.FileChooserAction.SELECT_FOLDER**
    - **Gtk.FileChooserAction.CREATE_FOLDER**

    ```py
    dialog = Gtk.FileChooserDialog(
        title="Save file as ...",
        parent=parent,
        action=FileChooserAction.SAVE
    )
    ```

    Selected files are then retrieved using
    ```py
    dialog.get_filenames()
    ```

    | Setter                                                                                                                            | Property          | Description                                                                           |
    | --------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
    | [`set_current_folder`](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/FileChooser.html#Gtk.FileChooser.set_current_folder_uri) |                   | Specify directory in filesystem where FileChooser will start                          |
    | [`set_current_name`](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/FileChooser.html#Gtk.FileChooser.set_current_name)         |                   | For FileChooserAction.SAVE, suggest a filename                                        |
    | [`set_select_multiple`](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/FileChooser.html#Gtk.FileChooser.set_select_multiple)   | `select_multiple` | For FileChooserAction.OPEN or SELECT_FOLDER, allow multiple file or folder selections |

#### Grid
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.Grid** allows children to be packed in a two-dimensional grid.
    Grids are instantiated with `new()` and widgets are laid out by calling `attach()` (see [Login](#login) for an example).

    - **`attach()`** lay out a widget providing column and row numbers followed by column and row spans
    ```py
    grid.attach(label, 0, 0, 1, 1)
    ```

#### HeaderBar
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.HeaderBar** allows the titlebar to be customized.
    Like other widgets, it can be configured on instantiation by providing values to keyword arguments or by using setters.

    !!! info "Adding to a window"
        HeaderBars are added with **`set_titlebar()`**.
        This is unlike other widgets which are assigned to an [ApplicationWindow](#applicationwindow) or [Window](#window) using `pack_start()`, `pack_end()`, or `add()`, 

    === "kwarg"

        ```py hl_lines="4-7"
        class ApplicationWindow(Gtk.ApplicationWindow):
            def __init__(self, *args, **kwargs):
                super().__init__(*args, **kwargs)
                headerbar = Gtk.HeaderBar(title=f"Hello, World!", 
                                        subtitle="HeaderBar example", 
                                        show_close_button=True)
                self.set_titlebar(headerbar)
        ```

    === "setter"

        ```py hl_lines="4-8"
        class ApplicationWindow(Gtk.ApplicationWindow):
            def __init__(self, *args, **kwargs):
                super().__init__(*args, **kwargs)
                headerbar = Gtk.HeaderBar()
                headerbar.set_title(f"Hello, World!")
                headerbar.set_subtitle("HeaderBar example")
                headerbar.set_show_close_button(True)
                self.set_titlebar(headerbar)
        ```


#### Label
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    Note that **Gtk.Label** sets its text with "label" and not "text" as you may expect from the corresponding setter.

    === "kwarg"

        ```py
        label = Gtk.Label(label="Hello, World!")
        ```

    === "setter"

        ```py
        label.set_text("Hello, World!")
        ```

#### ListBox
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    [**Gtk.ListBox**](https://lazka.github.io/pgi-docs/Gtk-3.0/classes/ListBox.html) is a vertical container of **Gtk.ListBoxRow** children used as an alternative to [TreeView](#treeview) when the children need to be interactive, as in a list of settings.
    ListBox 

#### ListStore
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.ListStore** is one of the two major classes that serves as combination schema and database backing [Gtk.TreeView](#treeview), the other being [Gtk.TreeStore](#treestore).
    
    It is instantiated with a sequence of data types, similar to a database schema. 
    These can be standard Python types or GObjects (which are mapped to the Python types anyway):
    
    === "Python types"

        ```py
        import gi
        gi.require_version("Gtk", "3.0")
        from gi.repository import Gtk

        liststore = Gtk.ListStore((str, int, str))
        ```
    
    === "GObject types"

        ```py hl_lines="3 5"
        import gi
        gi.require_version("Gtk", "3.0")
        from gi.repository import Gtk, GObject

        liststore = Gtk.ListStore((GObject.TYPE_STRING, GOBject).TYPE_INT, GObject.TYPE_STRING))
        ```


    This object then exposes an **`append`** method which is used to add records:
    ```py
    liststore.append(["Socrates", 350, "Athens"])
    ```

    The store is then associated with the treeview with `set_model`
    ```py
    treeview.set_model(liststore)
    ```


#### MenuBar
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |


    **Gtk.MenuBar** is populated with **Gtk.MenuItems**{: #menuitem }, corresponding to the expandable menu items (i.e. "File", "Edit", and "Help").
    **Gtk.Menu**{: #menu } is actually used for the submenu, which like MenuBar is also populared with MenuItems. 
    A Menu is attached to the MenuItem of a MenuBar by using the `set_submenu()` method on the Menu object.
    This setter does not have a corresponding kwarg, so all menus have to be constructed procedurally.

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


#### Notebook
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.Notebook** is a [layout container](#container) that organizes content into tabbed pages.
    It is instantiated with the **`new()`** method and pages are appended with the **`append_page()`** method, passing content and label widgets as arguments.
    
    The tab bar can be placed using **`set_tab_pos()`**, passing a **Gtk.PositionType**{: #positiontype } enum

    === "Top"

        ```py
        notebook = Gtk.Notebook.new()
        # notebook.set_tab_pos(Gtk.PositionType.TOP)
        ```

        <figure><img src="/img/gtk-notebook-top.png"/></figure>

    === "Right"

        ```py
        notebook = Gtk.Notebook.new()
        notebook.set_tab_pos(Gtk.PositionType.RIGHT)
        ```

        <figure><img src="/img/gtk-notebook-right.png"/></figure>

    === "Bottom"

        ```py
        notebook = Gtk.Notebook.new()
        notebook.set_tab_pos(Gtk.PositionType.BOTTOM)
        ```

        <figure><img src="/img/gtk-notebook-bottom.png"/></figure>

    === "Left"

        ```py
        notebook = Gtk.Notebook.new()
        notebook.set_tab_pos(Gtk.PositionType.LEFT)
        ```

        <figure><img src="/img/gtk-notebook-left.png"/></figure>

    ```py
    notebook = Gtk.Notebook.new()
    label = Gtk.Label.new("Tab title")
    child = Gtk.Label.new("Tab content")
    notebook.append_page(child, label)
    ```

    The label widget is commonly [Gtk.Label](#label) but can also be a [Gtk.Box](#box).



    The tab bar can be made scrollable using **`set_scrollable()`**, passing a bool.



#### Scale
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.Scale** widgets are sliders, and they can be instantiated in one of two ways:

    - **`new()`** passing an [Adjustment](#adjustment) object
    - **`new_with_range(min, max, step)`** passing values for minimum, maximum, and step

    Scale values are stored as doubles, so integers have to be simulated by reducing the number of digits to 0 using **`set_digits()`**.
    By default, the number of digits is set to that of the step value.


#### ScrolledWindow
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |


    **Gtk.ScrolledWindow** is a [decorator container](#container) that accepts a single child widget.
    Widgets that implement the Gtk.Scrollable [interface](#interface) have native scrolling suppport, like [Gtk.TreeView](#treeview), Gtk.TextView, and Gtk.Layout.
    Other widgets have to use Gtk.Viewport as an adaptor, and must be added to a Viewport which is then added to the ScrolledWindow.

    It is instantiated with the `new()` method, optionally passing two [Adjustment](#adjustment) objects that affect horizontal and vertical scrolling behavior when stepping or paging.
    ```py
    scrolled_win = Gtk.ScrolledWindow.new(None,None)
    ```

#### Statusbar
:   
    | :material-language-python: PyGobject                                                            | :material-language-rust: gtk-rs                                                             | :material-language-c: gtk                                            |
    | ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- | -------------------------------------------------------------------- |
    | [Gtk.Statusbar](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Statusbar.html#Gtk.Statusbar) | [gtk4::Statusbar](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Statusbar.html) | [GtkStatusbar (4.0)](https://docs.gtk.org/gtk4/class.Statusbar.html) |

    **Gtk.Statusbar** (note the lowercase *b* ) stores a stack of messages, the topmost of which is displayed.
    Before adding messages, a **context identifier**, a unique unsigned integer associated with a context description string, must be retrieved from the newly created Statusbar by passing a string value to `get_context_id()`. 
    This allows messages to be categorized and pushed to separate stacks.
    ```py
    statusbar.push(context_id, message)
    ```

#### Switch
:   
    | :material-language-python: PyGobject                                                   | :material-language-rust: gtk-rs                                                       | :material-language-c: gtk                                      |
    | -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
    | [Gtk.Switch](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Switch.html#Gtk.Switch) | [gtk4::Switch](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Switch.html) | [GtkSwitch (4.0)](https://docs.gtk.org/gtk4/class.Switch.html) |

    **Gtk.Switch** allows a user to toggle a boolean value.
    Switch exposes getters and setters for both **state** (which is represented by the trough color) and **active** (switch position) properties. State is the backend to activ, and they are kept in sync.

    ```py
    import gi

    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk


    class ApplicationWindow(Gtk.ApplicationWindow):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.set_border_width(10)

            box_outer = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
            listbox = Gtk.ListBox(selection_mode=Gtk.SelectionMode.NONE)
            row = Gtk.ListBoxRow()
            hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=50)
            label1 = Gtk.Label(label="Automatic Date & Time", xalign=0)
            
            hbox.add(label1)
            self.switch = Gtk.Switch(valign=Gtk.Align.CENTER, state=False)
            hbox.add(self.switch)
            row.add(hbox)
            listbox.add(row)
            box_outer.add(listbox)
            self.add(box_outer)
            button = Gtk.Button(label="Click")
            button.connect("clicked", self.on_button_clicked)
            box_outer.add(button)

        def on_button_clicked(self, button):
            print(f"Value of get_active(): {self.switch.get_active()}")
            print(f"Value of get_state(): {self.switch.get_state()}")
            

    class Application(Gtk.Application):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.window = None
        
        def do_activate(self):
            if not self.window:
                self.window=ApplicationWindow(application=self)
            self.window.show_all()
            self.window.present()

    if __name__ == "__main__":
        app = Application()
        app.run()
    ```

#### TreeView
:   
    | :material-language-python: PyGobject                                                         | :material-language-rust: gtk-rs                                                           | :material-language-c: gtk                                                                                                                 |
    | -------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
    | [Gtk.TreeView](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/TreeView.html#Gtk.TreeView) | [gtk4::TreeView](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.TreeView.html) | [GtkTreeView (4.0)](https://docs.gtk.org/gtk4/class.TreeView.html)&#13;[GtkTreeView (3.0)](https://docs.gtk.org/gtk3/class.TreeView.html) |

    In order to create a tree or list in GTK, the **Gtk.TreeView** widget is paired with a **Gtk.TreeModel** interface, the most typical implementation of which is [Gtk.ListStore](#liststore) or **Gtk.TreeStore**{ #treestore}.
    TreeView is a complicated widget that must be constructed procedurally:

    1. **Gtk.TreeView** is instantiated. A [ListStore](#liststore) is specified as data model and passed in as the value of the **model** kwarg.
    The ListStore specifies the schema of the data as a collection of types.
    ```py
    treeview = Gtk.TreeView(model=Gtk.ListStore.new((str)))
    ```
    Alternatively, the ListStore can be specified after instantiation.
    ```py
    treeview = Gtk.TreeView.new()
    treeview.set_model(Gtk.ListStore.new([str]))
    ```
    2. A **Gtk.TreeViewColumn**{: #treeviewcolumn } is created for every column in the model. These require a **Gtk.CellRenderer** to be defined. The TreeViewColumn is added to the treeview by calling the `append_column()` method on the treeview.
    The **text** kwarg appears to refer to the column of the data store to use for the column's values.
    ```py
    treeview.append_column(Gtk.TreeViewColumn("Greeks", Gtk.CellRendererText.new(), text=0))
    ```
    3. Items are added to the ListStore procedurally using the `append()` method. Note that the method takes only a single argument, so collections like lists or tuples must be used.
    ```py
    liststore.append(("Socrates",))
    liststore.append(("Plato",))
    liststore.append(("Aristotle",))
    ```

    Changing the number of columns affects the types used to define the ListStore, the appended records, as well as the number of columns added to the TreeView itself.

    === "1 column"

        ```py
        import gi
        gi.require_version('Gtk', '3.0')
        from gi.repository import Gtk


        class ApplicationWindow(Gtk.ApplicationWindow):
            def __init__(self, *args, **kwargs):
                super().__init__(*args, **kwargs)
                
                self.gen_treeview()

                scrolled_win = Gtk.ScrolledWindow.new(None,None)
                scrolled_win.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC)
                scrolled_win.add(self.treeview)

                self.add(scrolled_win)
                self.set_size_request(200,200)

            def get_liststore(self):
                store = Gtk.ListStore.new((str,))
                store.append(("Socrates",))
                store.append(("Plato",))
                store.append(("Aristotle",))
                return store

            def gen_treeview(self):
                self.treeview = Gtk.TreeView.new()
                self.treeview.set_model(self.get_liststore())
                self.treeview.append_column(Gtk.TreeViewColumn("Greeks", Gtk.CellRendererText.new(), text=0))



        class Application(Gtk.Application):
            def __init__(self):
                super().__init__(application_id='org.example.myapp')

            def do_activate(self):
                self.window = ApplicationWindow(application=self, title="Greeks")
                self.window.show_all()
                self.window.present()


        if __name__ == '__main__':
            app = Application()
            app.run()
        ```

    === "2 columns"

        ```py hl_lines="20-23 30"
        import gi
        gi.require_version('Gtk', '3.0')
        from gi.repository import Gtk


        class ApplicationWindow(Gtk.ApplicationWindow):
            def __init__(self, *args, **kwargs):
                super().__init__(*args, **kwargs)
                
                self.gen_treeview()

                scrolled_win = Gtk.ScrolledWindow.new(None,None)
                scrolled_win.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC)
                scrolled_win.add(self.treeview)

                self.add(scrolled_win)
                self.set_size_request(200,200)

            def get_liststore(self):
                store = Gtk.ListStore.new((str, str))
                store.append(["Socrates", "Athens"])
                store.append(["Plato", "Athens"])
                store.append(["Aristotle", "Athens"])
                return store

            def gen_treeview(self):
                self.treeview = Gtk.TreeView.new()
                self.treeview.set_model(self.get_liststore())
                self.treeview.append_column(Gtk.TreeViewColumn("Greeks", Gtk.CellRendererText.new(), text=0))
                self.treeview.append_column(Gtk.TreeViewColumn("Place of birth", Gtk.CellRendererText.new(), text=1))


        class Application(Gtk.Application):
            def __init__(self):
                super().__init__(application_id='org.example.myapp')

            def do_activate(self):
                self.window = ApplicationWindow(application=self, title="Greeks")
                self.window.show_all()
                self.window.present()


        if __name__ == '__main__':
            app = Application()
            app.run()
        ```

    The model backing a TreeView (usually a [ListStore](#liststore)), can be retrieved with the `get_model()` method.
    ```py
    treeview.get_model().append(('foo','bar'))
    ```

    TreeView emits several signals:

    - **`row_activated`** when a row is double-clicked, with the following implicit argument
        - **`widget`** refering to the emitting TreeView widget itself
        - **`path`** is a [TreePath](#treepath). 
        - **`column `** is of type [TreeViewcolumn](#treeviewcolumn)
    ```py
    treeview.connect("row_activated", self.on_row_activated, widget, path, column)
    ```
    ```py
    def on_row_activated(self, widget, path, column):
        row = path.get_indices()[0]
        print(f"row={path.get_indices()[0]},col={column.props.title}")
        print(widget.get_model()[row][:])
    ```

#### TreePath
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |
    

    **Gtk.TreePath** is a type used to implement the rows of a [TreeView](#treeview).
    Although it prints to an integer with the print statement, it cannot be treated as one.

    A path object can be passed as the index to a TreeModel like [ListStore](#liststore), as can an integer.
    The row number of a TreePath from a normal list-style TreeView can be retrieved with the `get_indices()` method.

    ```py
    row = path.get_indices()[0]

    # Using TreePath object as index to model
    model[path][:]

    # Using row integer as index to model
    model[row][:]
    ```

    Another method on TreePath, `get_depth()` always returns 1 for list-style TreeViews, but may be more useful for tree-style TreeViews.

#### TreeSelection
:   
    | :material-language-python: PyGobject | :material-language-rust: gtk-rs | :material-language-c: gtk |
    | ------------------------------------ | ------------------------------- | ------------------------- |

    **Gtk.TreeSelection** objects represent selection information for each tree view.

#### TreeViewColumn
:   
    | :material-language-python: PyGobject                                                                            | :material-language-rust: gtk-rs                                                                       | :material-language-c: gtk                                                                                                                                         |
    | --------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    | [Gtk.TreekViewColumn](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/TreeViewColumn.html#Gtk.TreeViewColumn) | [gtk4::TreeViewColumn](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.TreeViewColumn.html) | [GtkTreeViewColumn (4.0)](https://docs.gtk.org/gtk4/class.TreeViewColumn.html)&#13;[GtkTreeViewColumn (3.0)](https://docs.gtk.org/gtk3/class.TreeViewColumn.html) |

    **Gtk.TreeViewColumn** represents a visible column in a [Treeview](#treeview).
    Its **props** property exposes many associated values, including title.
    ```py
    print(column.props.title)
    ```
    A column is made [sortable](https://python-gtk-3-tutorial.readthedocs.io/en/latest/treeview.html#sorting) by calling `set_sort_column_id()`, passing the column of the model to sort by.
    ```py
    column.set_sort_column_id(0)
    ```

#### Window
:   
    | :material-language-python: PyGobject                                                   | :material-language-rust: gtk-rs                                                       | :material-language-c: gtk                                                                                                         |
    | -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
    | [Gtk.Window](https://lazka.github.io/pgi-docs/#Gtk-3.0/classes/Window.html#Gtk.Window) | [gtk4::Window](https://gtk-rs.org/gtk4-rs/stable/latest/docs/gtk4/struct.Window.html) | [GtkWindow (4.0)](https://docs.gtk.org/gtk4/class.Window.html)&#13;[GtkWindow (3.0)](https://docs.gtk.org/gtk3/class.Window.html) |
