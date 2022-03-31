# Scratchpad


#### Errors
:   

    ```rs
    fn main() {
        do_error().expect("Error!");
    }

    fn do_error() -> Result<String, String> {
        Err("This error is on purpose!".to_string())
    }
    ```