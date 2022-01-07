# Tasks

#### Boilerplate
:   
    Cursive apps are constructed procedurally using a succession of method calls, which require the main Cursive object (conventionally named "siv" in documentation) to be mutable.

    The **default()** function which sits at the root of the cursive module streamlines some of the boilerplate involved with calling **Cursive::new()** explicitly.

    === "default()"

        ```rs hl_lines="2"
        fn main() {
            let mut siv = cursive::default();
            siv.add_global_callback('q', |s| s.quit());

            // ...

            siv.run();
        }
        ```

    === "Cursive::new()"

        ```rs hl_lines="1 4"
        use cursive::{Cursive, CursiveExt}; // (1)

        fn main() {
            let mut app = Cursive::new();
            app.add_global_callback('q', |s| s.quit());
            
            // ...

            app.run();
        }
        ```

        1. CursiveExt must be imported in order to call the **run()** method.

## Hello, World!

#### TextView as layer
:   
    ```rs
    use cursive::views::TextView;

    fn main() {
        let mut app = cursive::default();
        app.add_global_callback('q', |s| s.quit());
        
        app.add_layer(TextView::new("Hello World!\nPress q to quit."));
        
        app.run();
    }
    ```

#### Dialog
:   
    ```rs
    use cursive::views::{DummyView, TextView, Dialog, LinearLayout};

    fn main() {
        let mut siv = cursive::default();
        siv.add_global_callback('q', |s| s.quit());

        siv.add_layer(Dialog::new()
            .title("Hello, world!")
            .content(
                LinearLayout::vertical()
                    .child(TextView::new("Hello, World!"))
                    .child(DummyView)
                    .child(TextView::new("Hello again!"))
            )
        );

        siv.run();
    }
    ```
