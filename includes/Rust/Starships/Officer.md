```rs
struct Officer {
    first_name: String,
    last_name: String,
    grade: char,
    // birth_date: NaiveDate
}

impl Officer {
    fn name(&self) -> String {
        return format!("{} {}", &self.first_name, &self.last_name);
    } 
}
```