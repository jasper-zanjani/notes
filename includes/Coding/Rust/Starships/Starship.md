```rs
struct Starship {
    name: String,
    registry: String,
    crew: i16
    captain: Officer
    // class: StarshipClass
}

fn main() {
    let enterprise = Starship {
        name: String::from("USS Enterprise"),
        registry: String::from("NCC-1701"),
        crew: 203
    };
    println!("{:20}{:20}{:10}", "Name", "Registry", "Crew");
    println!("{:20}{:20}{:10}", enterprise.name, enterprise.registry, enterprise.crew);
}
```