# Overview

[**Cursive**](https://github.com/gyscos/cursive) is a TUI framework.

- Cursive widgets are called **Views** (i.e. TextView).
- Each screen's view tree has a **StackView** as root. Children are **layers** that can be pushed and popped.
- Callbacks are typically [closures](Glossary#closure).


Key presses are represented by [**Event**](https://docs.rs/cursive/latest/cursive/event/enum.Event.html) enums.

- Alphanumeric keypresses are represented by the char itself.
- Single and multiple modifier key presses are represented by `Ctrl(Key)`, `Alt(Key)`, `CtrlAlt(Key)`, etc.

Global keybindings are applied by calling [`Cursive::add_global_callback()`](https://docs.rs/cursive/latest/cursive/struct.Cursive.html#method.add_global_callback) on the application object.

Keybindings that are effective only on particular Views are created by wrapping the View in [**OnEventView**](/Rust/API/#oneventview).
