# Npyscreen

Widget library and application framework built on top of [`ncurses`](#ncurses). <sup>[Documentation](https://npyscreen.readthedocs.io/)]

Three main types of object compose `npyscreen` applications:
- **Application objects** manage forms and other classes
- **Form objects** form the canvas upon which widgets are arrayed
  - `Form` general-purpose
  - [`FormMutt`](#npyscreenFormMutt)
- **Widget objects** are individual controls
  - `TitleText` text entry
  - `TitleSelectOne` equivalent to radio buttons
  - `TitleDateCombo` allows picking of date on a small calendar

`npyscreen.wrapper_basic` is the main entry point
```py
import npyscreen

def myFunction(*args):
  pass

if __name__ == '__main__':
  npyscreen.wrapper_basic(myFunction)
  print "Blink and you missed it!"
```
`npyscreen.Form` is equivalent to the `Tk()` object, which is typically instantiated as `win` in GUI frameworks.
```py
F = npyscreen.Form(name='My Test Application')
```
Several important methods are key:
- `create()` The standard constructor calls this method, which does nothing by default and is meant to be overriden in subclasses. Widgets are defined here.

[**`npyscreen.FormMutt`**](https://npyscreen.readthedocs.io/form-objects.html#mutt-like-forms) imitates a UI layout popularized by applications like [`mutt`](https://github.com/jasper-zanjani/notes/tree/master/lx), `irssi`, and `vim`, with a title bar at the top, a command line at the bottom, and a status line directly above the command line.

`ACTION_CONTROLLER` can be defined in the `FormMutt` subclass as the name of a subclass of `ActionControllerSimple`.
Commands for the application can be defined as callbacks in the `create()` method.
```py
self.add_action(ident,call_back, True)
```
Callbacks are called with the following arguments:
```py
call_back(command_line, control_widget_proxy, live=True)
```
```py
class ActionControllerSearch(npyscreen.ActionControllerSimple):
    def create(self):
        self.add_action('^/.*', self.set_search, True)
    
    def set_search(self, command_line, widget_proxy, live):
        self.parent.value.set_filter(command_line[1:])
        self.parent.wMain.values = self.parent.value.get()
        self.parent.wMain.display()

class FmSearchActive(npyscreen.FormMuttActiveTraditional):
    ACTION_CONTROLLER = ActionControllerSearch
```

**`npyscreen.NPSAppManaged`** is the preferred superclass to support object-oriented implementation.
```py
class MyApplication(npyscreen.NPSAppManaged):
  pass
```
Calling `run()` method of application object as main entry point.
`run()` activates the default form, which should be given an id of `MAIN`
```py
if __name__ == '__main__':
  TestApp = MyApplication().run()
  print "All objects, baby."
```
Using a `try`/`except` block to allow for well-mannered exit in case of `KeyboardInterrupt` (Ctrl+C)<sup>[GitHub](https://github.com/c1ko/nh/blob/master/nh.py)</sup>
```py
try:
  App().run()
except KeyboardInterrupt:
  sys.exit(0)
```
There are three methods for registering a `Form` object with a `NPSAppManaged` instance;
- `addForm()` creates a new form and returns a `weakref.proxy` to it
- `addFormClass()` register a class of `Form` rather than an instance
- `registerForm()`

It continually displays the Form named by its `NEXT_ACTIVE_FORM` attribute.
Use the `afterEditing` method to allow exiting.
```py
class myEmployeeForm(npyscreen.Form):
  def afterEditing(self):
    self.parentApp.setNextForm(None)
```