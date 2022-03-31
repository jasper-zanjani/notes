# serde

The [**serde\_json**](https://docs.rs/serde_json/latest/serde_json/) crate 
provides a rich API for interacting with JSON files.

The [json macro](https://docs.rs/serde_json/latest/serde_json/macro.json.html) can be used to serialize any struct decorated with Serialize.
```rs hl_lines="18"
use serde_json::{json, Value};
use serde::{Deserialize, Serialize}; // (1)

#[derive(Debug, Serialize, Deserialize)]
struct Starship {
    name: String,
    registry: String,
    crew: u64
}

fn main() {
    let starship: Starship = Starship{
        name: "USS Enterprise".to_string(), 
        registry: "NCC-1701".to_string(), 
        crew: 400 
    };

    println!("{}", json!("Enterprise": {starship}));
}
```

1. The derive attributes **Serialize** and **Deserialize** are included from  serde directly but only after enabling the **derive** feature (and not the serde\_derive crate).
```toml
[dependencies]
serde = {version = "^1.0", features = ["derive"]}
```


Although a simpler and more naive implementation is possible, the recommended use of the API is to define a struct that reflects the model of the JSON document and to type the destination variable accordingly.

!!! warning "?"

    There appears to be some bizarre error in the example using &str below.

=== "String"

    ```rs
    #[derive(Debug, serde_derive::Deserialize)]
    enum Series {
        TOS,
        DS9,
        VOY,
    }

    #[derive(Debug, serde_derive::Deserialize)]
    struct Starship {
        name: String,
        registry: String,
        series: Series,
    }

    fn main() {
        let ships: Vec<Starship> = gen_ships("starships.json");
        println!("{:?}", ships);
    }

    fn gen_ships(fname: &str) -> Vec<Starship> {
        let file = std::fs::read_to_string(&fname).unwrap();
        let ships : Vec<Starship> = serde_json::from_str(&file).unwrap();
        ships
    }
    ```


=== "&str"

    ```rs hl_lines="9-11"
    #[derive(Debug, serde_derive::Deserialize)]
    enum Series {
        TOS,
        DS9,
        VOY,
    }

    #[derive(Debug, serde_derive::Deserialize)]
    struct Starship<'a> {
        name: &'a str,
        registry: &'a str,
        series: Series,
    }

    fn main() {
        let ships: Vec<Starship> = gen_ships("starships.json");
        println!("{:?}", ships);
    }

    fn gen_ships(fname: &str) -> Vec<Starship> {
        let file = std::fs::read_to_string(&fname).unwrap();
        let ships : Vec<Starship> = serde_json::from_str(&file).unwrap(); // (1)
        ships
    }
    ```

    1. For some reason, the compiler produces an error here, saying that **&file** is borrowed. Furthermore the compiler will not allow **ships** to be returned from the function because it "returns a value referencing data owned by the current function".