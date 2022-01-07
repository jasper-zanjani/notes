```rs
extern crate structopt;

use structopt::StructOpt;

#[derive(StructOpt)]
struct Options {
    #[structopt(default_value = "World")]
    /// Name to greet
    name: String
}

fn main() {
    let options = Options::from_args();
    let name = options.name;
    println!("Hello, {}!", name);
}

```