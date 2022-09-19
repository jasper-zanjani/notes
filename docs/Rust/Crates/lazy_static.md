# lazy\_static

```rs
use lazy_static::lazy_static;
use std::collections::HashMap;

lazy_static! {
    static ref STARSHIPS: HashMap<&'static str, Starship> = {
        let mut map = HashMap::new();
        map.insert(
            "NCC-1701",
            Starship {
                name: String::from("USS Enterprise"),
                registry: String::from("NCC-1701"),
                crew: 203,
            },
        );
        map.insert(
            "NX-74205",
            Starship {
                name: String::from("USS Defiant"),
                registry: String::from("NX-74205"),
                crew: 50,
            },
        );
        map
    };
}
```