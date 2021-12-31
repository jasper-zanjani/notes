# 📘 Glossary

**Action**{: #action }
:   
    Actions have prefixes that determine where they are sent for processing:
    
    - Window-specific actions are specified with **`win.`** (i.e. `win.change_label`), which specifies that ApplicationWindow processes the signal.
    - Application-wide actions are prefixed with **`app.`**

    Create new actions with `Gio.SimpleAction`

    ```py
    import gi
    gi.require_version('Gtk', '3.0')
    from gi.repository import Gio

    # --snip--

    quit_action = Gio.SimpleAction.new("quit", None)
    quit_action.connect("activate", self.on_quit)
    ```

    - **activate**
    - **open**


**Callback**{: #callback }
:   
    Event handler for GTK [signals](#signal)

**Container**{: #container}
:   
    - **Decorator containers** derive from **Gtk.Bin** and can hold only a single child, like [ApplicationWindow](#applicationwindow), and are so called because they add functionality to the child widget.
    - **Layout containers** derive directly from **Gtk.Container** and are used to arrange multiple child widgets.

**Pop-up menu**
:   
    Context menu

**Signal**{: #signal }
:   
    A **signal** is a notification to the application that the user has performed an action.
    
    A signal must be connected to a [callback](#callback) method so that when the signal is emitted the method is executed.
    It is possible to connect signals at any point in applications, but it is considered good form to initialize callbacks before calling `gtk_main()` or `present()`.
    

    Signals in GTK are similar to events in other GUI frameworks, although the term "**events**{: #events }" is also used in GTK to refer to special signals emitted by the X Windows System.
    GTK event handlers are methods that begin with **`do_`**, i.e. `do_startup`.

    - **`handle-local-options`**


