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

#### HexView
:   
    Hexview is available from the [**cursive\_hexview**](https://github.com/hellow554/cursive_hexview) crate.

    ```rs
    use cursive::view::{Scrollable,Resizable};
    use cursive_hexview::{DisplayState, HexView,HexViewConfig};
    use std::env;
    use std::fs::File;
    use std::io::{self, Read};
    use std::path::Path;

    fn read_file(path: &Path) -> Result<Vec<u8>, io::Error> {
        let mut file = File::open(path)?;
        let mut buf = Vec::new();
        file.read_to_end(&mut buf)?;
        Ok(buf)
    }

    fn main() {
        let arg = env::args()
            .nth(1)
            .expect("Provide a valid filename");
        let path = Path::new(&arg);

        let mut cur = cursive::default();
        let view = HexView::new_from_iter(read_file(path).expect("Cannot read file")).display_state(DisplayState::Enabled)
            .config(HexViewConfig {
                bytes_per_line: 48,
                bytes_per_group: 8,
                ..Default::default()
            })
            .scrollable().full_screen();

        cur.add_layer(view);
        cur.run();
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

#### OnEventView
:   
    [**OnEventView**](https://docs.rs/cursive/latest/cursive/views/struct.OnEventView.html) allows keybindings to take effect on wrapped Views.

    ```rs hl_lines="10 14 18 22"
    use cursive::views::{OnEventView, TextView};
    use cursive::event::{Key, Event, EventTrigger};
    use cursive::Cursive;

    fn main() {
        let mut siv = cursive::default();
        siv.add_layer(
            OnEventView::new(TextView::new("Hello, World!\n(Q to quit)"))
                .on_event('q', Cursive::quit )  // (1)
                .on_event(Event::Key(Key::Enter), |s| { // (2)
                    s.pop_layer();
                    s.add_layer(TextView::new("Enter key pressed!"));
                })
                .on_event(Event::CtrlChar('a'), |s| { // (3)
                    s.pop_layer();
                    s.add_layer(TextView::new("Ctrl+A pressed!"))
                })
                .on_event(EventTrigger::mouse(), |s| { // (4)
                    s.pop_layer();
                    s.add_layer(TextView::new("Mouse clicked!"));
                })
        );
        siv.run();
    }
    ```

    1. Alphanumeric keypresses are represented by the char itself.
    2. Non-alphanumeric keypresses are represented by [**Event::Key**](https://docs.rs/cursive/latest/cursive/event/enum.Event.html) wrapping a [**Key**](https://docs.rs/cursive/latest/cursive/event/enum.Key.html) variant (`Enter`, `Esc`, etc.).
    3. Single and multiple modifier key presses are represented by particular [**Event**](https://docs.rs/cursive/latest/cursive/event/enum.Event.html) variants that wrap [**Key**](https://docs.rs/cursive/latest/cursive/event/enum.Key.html) variants for nonalphanumeric keypresses, i.e. `Event::Ctrl(Key)`, `Event::Alt(Key)`, `Event::CtrlAlt(Key)`. Separate Event variants are used for alphanumeric characters (i.e. `Event::CtrlChar(char)`, `Event::Alt(char)`, `Event::CtrlAltChar(char)`, etc) which wrap the char value of the keypress.
    4. **EventTrigger::mouse()** will respond to any mouse click. More specific mouse events may be specified by a [MouseEvent](https://docs.rs/cursive/latest/cursive/event/enum.MouseEvent.html) variant containing a [MouseButton](https://docs.rs/cursive/latest/cursive/event/enum.MouseButton.html) variant (TODO).

    In fact there are a variety of methods available that affect how Events are routed.

    - [**on\_event()**](https://docs.rs/cursive/latest/cursive/views/struct.OnEventView.html#method.on_event) and [**on\_event\_inner()**](https://docs.rs/cursive/latest/cursive/views/struct.OnEventView.html#method.on_event_inner) register callbacks that are **ignored** by the wrapped View (?).
    - [**on\_pre\_event()**](https://docs.rs/cursive/latest/cursive/views/struct.OnEventView.html#method.on_pre_event) and [**on\_pre\_event\_inner()**](https://docs.rs/cursive/latest/cursive/views/struct.OnEventView.html#method.on_pre_event_inner) register callbacks that need preprocessing and control whether the wrapped View should be given the Event.

    In this example, it appears not to matter which of the methods is used to register callbacks, possibly because the wrapped View ultimately receives the Event in either case.

    === "on\_event\_inner()"

        ```rs hl_lines="19-26"
        use cursive::traits::{Scrollable, Resizable};
        use cursive::views::{Dialog, SelectView, TextView,OnEventView};
        use cursive::event::EventResult;

        fn main() {
            let mut siv = cursive::default();
            list_ships(&mut siv);
            siv.run();
        }

        fn list_ships(siv: &mut cursive::Cursive) {
            siv.pop_layer();

            let mut select = SelectView::new();
            select.add_all_str(vec!["USS Enterprise", "USS Voyager", "USS Reliant"]);
            select.set_on_submit(show_ship);
            
            let select = OnEventView::new(select)
                .on_event_inner('k', |s, _| {
                    let cb = s.select_up(1);
                    Some(EventResult::Consumed(Some(cb)))
                })
                .on_event_inner('j', |s, _| {
                    let cb = s.select_down(1);
                    Some(EventResult::Consumed(Some(cb)))
                });

            siv.add_layer(
                Dialog::around(
                    select.scrollable()         // 
                        .fixed_size((20, 10))   // 
                ).title("Choose a ship"),
            );
        }

        fn show_ship(siv: &mut cursive::Cursive, starship: &str) {
            siv.pop_layer();
            let starship = String::from(starship).replace("USS ", "");
            let text = format!("The {} is a fine ship!", starship);
            siv.add_layer(
                Dialog::around(
                    TextView::new(text))
                        .button("OK", |s| list_ships(s))
                        .button("Quit", cursive::Cursive::quit),
            );
        }
        ```

    === "on\_pre\_event\_inner()"

        ```rs hl_lines="19-26"
        use cursive::traits::{Scrollable, Resizable};
        use cursive::views::{Dialog, SelectView, TextView,OnEventView};
        use cursive::event::EventResult;

        fn main() {
            let mut siv = cursive::default();
            list_ships(&mut siv);
            siv.run();
        }

        fn list_ships(siv: &mut cursive::Cursive) {
            siv.pop_layer();

            let mut select = SelectView::new();
            select.add_all_str(vec!["USS Enterprise", "USS Voyager", "USS Reliant"]);
            select.set_on_submit(show_ship);
            
            let select = OnEventView::new(select)
                .on_pre_event_inner('k', |s, _| {
                    let cb = s.select_up(1);
                    Some(EventResult::Consumed(Some(cb)))
                })
                .on_pre_event_inner('j', |s, _| {
                    let cb = s.select_down(1);
                    Some(EventResult::Consumed(Some(cb)))
                });

            siv.add_layer(
                Dialog::around(
                    select.scrollable()         // 
                        .fixed_size((20, 10))   // 
                ).title("Choose a ship"),
            );
        }

        fn show_ship(siv: &mut cursive::Cursive, starship: &str) {
            siv.pop_layer();
            let starship = String::from(starship).replace("USS ", "");
            let text = format!("The {} is a fine ship!", starship);
            siv.add_layer(
                Dialog::around(
                    TextView::new(text))
                        .button("OK", |s| list_ships(s))
                        .button("Quit", cursive::Cursive::quit),
            );
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



#### RadioGroup
:   
    [**RadioGroup&lt;T&gt;**](https://docs.rs/cursive/latest/cursive/views/struct.RadioGroup.html) is used to coordinate multiple radio buttons.
    
    Because RadioGroup is a View which does not implement Nameable, a closure will always be used to retrieve the user's choice with [**selection()**](https://docs.rs/cursive/latest/cursive/views/struct.RadioGroup.html#method.selection).
    It is possible to abstract some of the logic of creating a new View using the user's selection, with some bizarre syntax.

    === "Closure"

        ```rs
        use cursive::views::{Dialog,LinearLayout,RadioGroup,TextView};

        fn main() {
            let mut siv = cursive::default();
            let mut options : RadioGroup<String> = RadioGroup::new(); // (1)
            siv.add_layer(
                Dialog::around(
                    LinearLayout::vertical()
                        .child(options.button_str("Plato"))
                        .child(options.button_str("Aristotle")) // (2)
                        .child(options.button_str("Socrates")),
                ).button("Ok", move |s| { // (3)
                    s.pop_layer();
                    s.add_layer(
                        Dialog::around(
                            TextView::new(format!("You chose {}!", options.selection()))
                        ).button("Ok", |s| s.quit())
                    );
                })
            );
            siv.run();
        }
        ```

        1. **RadioGroup** is a generic and must be typed (according to its values?)
        2. The **button\_str()** method adds a button where the value equals its label. A **button()** method is also available which takes an additional argument, the value to be passed back upon selection.
        3. The **move** keyword must be used because the closure may outlive the current function but it captures **options** from the [environment](/Rust/Glossary/#closure) of the current function's scope.

    === "Closure and function"

        ```rs hl_lines="13 20"
        use cursive::views::{Dialog,LinearLayout,RadioGroup,TextView};

        fn main() {
            let mut siv = cursive::default();
            let mut options : RadioGroup<String> = RadioGroup::new();
            siv.add_layer(
                Dialog::around(
                    LinearLayout::vertical()
                        .child(options.button_str("Plato"))
                        .child(options.button_str("Aristotle"))
                        .child(options.button_str("Socrates")),
                ).button("Ok", move |s| {
                    let selection = &*options.selection(); // (1)
                    display_selection(s, selection);
                })
            );
            siv.run();
        }

        fn display_selection(siv: &mut cursive::Cursive, selection: &String) {
            siv.pop_layer();
            siv.add_layer(
                Dialog::around(
                    TextView::new(format!("You chose {}!", selection))
                ).button("Ok", |s| s.quit())
            );
        }
        ```

        1. This is apparently needed to dereference the [**Rc**](/Rust/API/#rc) returned by [**selection()**](https://docs.rs/cursive/latest/cursive/views/struct.RadioGroup.html#method.selection)

    === ":material-image:"

        <figure markdown>![](/img/Cursive/cursive-RadioGroup.png)</figure>

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
        select.set_on_submit(show_next_window); // (1)

        let select = OnEventView::new(select)
            .on_pre_event_inner('k', |s, _| {
                let cb = s.select_up(1);
                Some(EventResult::Consumed(Some(cb)))
            })

        siv.add_layer(
            Dialog::around(
                select.scrollable()         // (2)
                    .fixed_size((20, 10))   // (3)
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

    1. Sets the callback for when ++Enter++ is pressed.
    2. [**scrollable()**](https://docs.rs/cursive/latest/cursive/traits/trait.Scrollable.html#method.scrollable) is included in [cursive::traits::Scrollable](https://docs.rs/cursive/latest/cursive/traits/trait.Scrollable.html).
    3. [**fixed_size()**](https://docs.rs/cursive/latest/cursive/traits/trait.Resizable.html#method.fixed_size) is included in [cursive::traits::Resizable](https://docs.rs/cursive/latest/cursive/traits/trait.Resizable.html)

    [autojump()](https://docs.rs/cursive/latest/cursive/views/struct.SelectView.html#method.autojump) will change the selection in response to keypresses. This will interfere with the global callback set for `q`.

#### TabPanel
:   
    [**TabPanel**](https://docs.rs/cursive-tabs/latest/cursive_tabs/struct.TabPanel.html) is an ease-of-use wrapper around [TabView](#tabview) from the [cursive-tabs](https://docs.rs/cursive-tabs/latest/cursive_tabs/) crate.
    