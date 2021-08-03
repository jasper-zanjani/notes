```rs
use clap::{App,Arg};

fn main() {
    let args = App::new("Say hello")
        .arg(Arg::with_name("name")
            .help("Name to greet")
            .takes_value(true)
            .default_value("World"))
        .get_matches();

    println!("Hello, {}!", args.value_of("name").unwrap());
}
```