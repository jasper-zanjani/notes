```rs
use clap::{clap_app, crate_version, crate_authors};

fn main() {
    let app = clap_app!( _a => 
            (version: crate_version!())
            (author: crate_authors!())
            (about: "Say hello")
            (@arg input: +required  "Sets the input file")
        )       
        .get_matches();

    let name = app.value_of("input").unwrap();
    println!("Hello, {}!", &name.replace("\"",""));
}
```