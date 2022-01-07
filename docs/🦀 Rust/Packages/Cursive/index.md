# Cursive

[**Cursive**](https://docs.rs/cursive/) is a TUI framework.

- Cursive widgets are called **Views** (i.e. TextView).
- Each screen's view tree has a **StackView** as root. Children are **layers** that can be pushed and popped.
- Callbacks are typically [closures](Glossary#closure).
