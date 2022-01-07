# API

#### Dialog
:   
    [**Dialog**](https://docs.rs/cursive/latest/cursive/views/struct.Dialog.html) can be constructed with **new()** or with the (barely) more concise **around()** helper method.

    === "around()"

        ```rs hl_lines="9-10"
        use cursive::{Cursive, CursiveExt};
        use cursive::views::{TextView, Dialog};

        fn main() {
            let mut siv = Cursive::new();
            siv.add_global_callback('q', |s| s.quit());

            siv.add_layer(
                Dialog::around(TextView::new("Hello, world!"))
                    .button("Ok", |s| s.quit())
            );

            siv.run();
        }
        ```

    === "new()"

        ```rs hl_lines="9-11"
        use cursive::{Cursive, CursiveExt};
        use cursive::views::{TextView, Dialog};

        fn main() {
            let mut siv = Cursive::new();
            siv.add_global_callback('q', |s| s.quit());

            siv.add_layer(
                Dialog::new()
                    .content(TextView::new("Hello, world!"))
                    .button("Ok", |s| s.quit())
            );

            siv.run();
        }
        ```

#### DummyView
:   
    A [**DummyView**](https://docs.rs/cursive/latest/cursive/views/struct.DummyView.html) is used as a spacer.

    ```rs
    use cursive::views::{DummyView, TextView, Dialog, LinearLayout};
    use cursive::{Cursive, CursiveExt};

    fn main() {
        let mut siv = Cursive::new();
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

#### LinearLayout
:   
    A [**LinearLayout**](https://docs.rs/cursive/latest/cursive/views/struct.LinearLayout.html) supports horizontal or vertical layout similar to a [StackPanel](/Misc/WinUI/API/#stackpanel) in WinUI.

    ```rs
    use cursive::views::{DummyView, TextView, Dialog, LinearLayout};
    use cursive::{Cursive, CursiveExt};

    fn main() {
        let mut siv = Cursive::new();
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

#### PaddedView
:   
    [**PaddedView**](https://docs.rs/cursive/latest/cursive/views/struct.PaddedView.html) wraps a single View and applies a margin specified in terminal cells.
    It can be instantiated with **new()** or the somewhat abbreviated **lrtb()** help method.

    === "lrtb()"

        ```rs hl_lines="9"
        use cursive::{Cursive, CursiveExt};
        use cursive::views::{TextView, PaddedView};

        fn main() {
            let mut siv = Cursive::new();
            siv.add_global_callback('q', |s| s.quit());

            siv.add_layer(
                PaddedView::lrtb(2, 2, 1, 1, TextView::new("Hello, World!"))
            );

            siv.run();
        }
        ```

    === "new()"

        ```rs hl_lines="3 10"
        use cursive::{Cursive, CursiveExt};
        use cursive::views::{TextView, PaddedView};
        use cursive::view::Margins;

        fn main() {
            let mut siv = Cursive::new();
            siv.add_global_callback('q', |s| s.quit());

            siv.add_layer(
                PaddedView::new(Margins::lrtb(2, 2, 1, 1), TextView::new("Hello, World!"))
            );

            siv.run();
        }
        ```



#### ResizedView
:   
    A **ResizedView** functions as a container around a single view, similar to a **Box** in GTK.
    ResizedView can be initiated with a variety of methods that define its appearance.

    - Helper methods like **[with\_fixed\_size()](https://docs.rs/cursive/latest/cursive/views/struct.ResizedView.html#method.with_fixed_size)** take a tuple of two integers defining the size of the view in columns and rows as well as an inner View.
    - Helper methods like **[with\_fixed\_height()](https://docs.rs/cursive/latest/cursive/views/struct.ResizedView.html#method.with_fixed_width)** take a single integer and an inner View.
    - Finally, methods like **[with\_full\_screen()](https://docs.rs/cursive/latest/cursive/views/struct.ResizedView.html#method.with_full_screen)** take only the contained View.

#### SelectView
:   
    [**SelectView**](https://docs.rs/cursive/latest/cursive/views/struct.SelectView.html) allows an item to be selected from a list and so is equivalent to widgets like [ListView](/Coding/WinUI/API/#listview) in WinUI.

    ```rs
    use cursive::traits::{Scrollable, Resizable};
    use cursive::views::{Dialog, SelectView, TextView};
    use cursive::Cursive;

    fn main() {
        let mut siv = cursive::default();
        
        let mut select = SelectView::new();

        select.add_all_str(vec!["USS Enterprise", "USS Voyager", "USS Reliant"]);
        select.set_on_submit(show_next_window);

        siv.add_layer(
            Dialog::around(
                select.scrollable()         // (1)
                    .fixed_size((20, 10))   // (2)
            ) .title("Where are you from?"),
        );
        siv.run();
    }

    fn show_next_window(siv: &mut Cursive, starship: &str) {
        siv.pop_layer();
        let starship = String::from(starship).replace("USS ", "");
        let text = format!("The {} is a fine ship!", starship);
        siv.add_layer(
            Dialog::around(TextView::new(text)).button("Quit", |s| s.quit()),
        );
    }
    ```

    1. [**scrollable()**](https://docs.rs/cursive/latest/cursive/traits/trait.Scrollable.html#method.scrollable) is included in [cursive::traits::Scrollable](https://docs.rs/cursive/latest/cursive/traits/trait.Scrollable.html).
    2. [**fixed_size()**](https://docs.rs/cursive/latest/cursive/traits/trait.Resizable.html#method.fixed_size) is included in [cursive::traits::Resizable](https://docs.rs/cursive/latest/cursive/traits/trait.Resizable.html)

    [autojump()](https://docs.rs/cursive/latest/cursive/views/struct.SelectView.html#method.autojump) will change the selection in response to keypresses. This will interfere with the global callback set for `q`.