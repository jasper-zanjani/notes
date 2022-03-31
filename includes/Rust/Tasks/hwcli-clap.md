```rs
use clap::{App,Arg, crate_version, crate_authors};

fn main() {
    let args = App::new("Say hello")
        .version(crate_version!())
        .author(crate_authors!())
        .arg(Arg::new("name")
            .help("Name to greet")
            .takes_value(true)
            .required(true)
        )
        .get_matches();

    println!("Hello, {}!", args.value_of("name").unwrap());
}
```