# Hello, World!

#### Parameterized
:   
    --8<-- "includes/Rust/Tasks/hwp.md"

#### Interactive
:   

    The interactive implementation of Hello, World! allows us to apply the **and\_then()** combinator to great effect.

    --8<-- "includes/Rust/Tasks/hwi.md"

#### Modules
:   

    ```rs hl_lines="1-2 9 19"
    use input::get_name;
    use output::display_name;

    fn main() -> Result<(), std::io::Error> {
        get_name().and_then(display_name)?;
        Ok(())
    }

    pub mod input {

        pub fn get_name() -> Result<String, std::io::Error> {
            let mut name = String::new();
            println!("What is your name? ");
            std::io::stdin().read_line(&mut name)?;
            Ok(name.trim().to_string())
        }
    }

    pub mod output {

        pub fn display_name(name: String) -> Result<(), std::io::Error> {
            println!("Hello, {}!", name);
            Ok(())
        }
    }
    ```

#### Separate files
:   
    Note that the filename of the module must match the name provided after **mod**.
    Folders can also be used, in which case the folder name must match.

    ```rs title="main.rs" hl_lines="1-2 4-5"
    mod input;
    mod output;

    pub use input::get_name;
    pub use output::display_name;

    fn main() -> Result<(), std::io::Error> {
        get_name().and_then(display_name)?;
        Ok(())
    }
    ```

    ```rs title="input.rs"
    pub fn get_name() -> Result<String, std::io::Error> {
        let mut name = String::new();
        println!("What is your name? ");
        std::io::stdin().read_line(&mut name)?;
        Ok(name.trim().to_string())
    }
    ```

    ```rs title="output.rs"
    pub fn display_name(name: String) -> Result<(), std::io::Error> {
        println!("Hello, {}!", name);
        Ok(())
    }
    ```