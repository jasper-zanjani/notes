# To-Do

#### Vector assembly
:   
    ```rs
    use std::rc::Rc;
    use std::cell::RefCell;

    fn main() {
        let mut v: Vec<String> = Vec::new();
        loop {
            let mut input: String = String::new();
            println!("Enter to-do list item ('q' to quit): ");
            std::io::stdin().read_line(&mut input).unwrap();
            match input.trim() {
                "q" => break,
                s => v.push(s.to_string()),
            }
        }

        for i in v {
            println!("{}", i);
        }
    }
    ```
