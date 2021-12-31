# Cursive

[**Cursive**](https://docs.rs/cursive/) is a TUI framework.

- Cursive widgets are called **Views** (i.e. TextView).
- Each screen's view tree has a **StackView** as root. Children are **layers** that can be pushed and popped.
- Callbacks are typically [closures](Glossary#closure).

```rs
use cursive::views::TextView;
use cursive::{Cursive, CursiveExt};

fn main() {
    let mut app = Cursive::new();
    app.add_layer(TextView::new("Hello World!\nPress q to quit."));
    app.add_global_callback('q', |s| s.quit());
    app.run();
}
```
