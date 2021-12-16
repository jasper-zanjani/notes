``` rs
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
```