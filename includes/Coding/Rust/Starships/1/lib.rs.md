``` rs linenums="1"
#[derive(Debug)]
pub struct Officer {
    pub first_name: String,
    pub last_name: String,
    pub grade: char,
    // pub birth_date: NaiveDate
}

impl Officer {
    pub fn name(&self) -> String {
        return format!("{} {}", &self.first_name, &self.last_name);
    } 
}

#[derive(Debug)]
pub enum StarshipClass {
    Constitution,
    Galaxy
}


/// Embodies a starship, fictitious or otherwise.
/// 
/// # Examples
/// 
/// ```
/// use starships::{Starship, Officer, StarshipClass};
/// 
/// let kirk = Officer {
///     first_name: String::from("James"),
///     last_name: String::from("Kirk"),
///     grade: 'A',
/// };
/// let enterprise = Starship {
///     name: String::from("USS Enterprise"),
///     registry: String::from("NCC-1701"),
///     crew: 203,
///     class: StarshipClass::Constitution,
///     captain: kirk
/// };
/// assert_eq!(enterprise.captain.name(), "James Kirk");
/// ```
#[derive(Debug)]
pub struct Starship {
    pub name: String,
    pub registry: String,
    pub crew: i16,
    pub captain: Officer,
    pub class: StarshipClass,
}
```