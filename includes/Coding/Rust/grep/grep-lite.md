This example begins with hard-coded strings and quickly develops the core logic of searching for a string.
First regex (2), then a CLI framework is implemented (3).

We take a slight digression to illustrate how file reading is done in Rust.
First we produce a naive implementation (4) using a [loop](#loop).
A more expressive choice (5) is a `for in` loop iterating over the iterator returned by the BufReader's **lines** method.

Finally, file opening is incorporated into the business logic of the application (6). 
The search logic itself is abstracted into a function. 
If the `-` argument is received from the command-line, STDIN is treated just as a file.

Files are modeled with structs (7).
`read()` models reading a file by cloning the File struct's data Vector,  then `reserve`ing that clone's length and appending its values to a buffer struct.
`open` and `close` functions are inert stubs (8).

Refactoring `read()` into a method on `File` and implementing the `new` method using an `impl` blocks is more idiomatic and readable (9).

`open()`, `close()`, and `read()` are refactored to use Results. 
Also a [rand](#rand) function is used to model error generation on a random basis (10).

Define a FileState enum (11). Implementing the Display [trait](#trait) allows us to use a standard template in a `println!` statement (12).

=== "1"

    ```rs
    // RIA 68
    fn main() {
        let search_term = "picture";
        let quote ="Once upon a midnight dreary\nWhile I pondered weak and weary\nOver many a quaint and curious volume of forgotten lore";

        for line in quote.lines() {
            if line.contains(search_term) {
                println!("{}", line);
            }
        }
    }
    ```

=== "2"

    ```rs hl_lines="2 5 8-11"
    // RIA 69
    use regex::Regex;

    fn main() {
        let re = Regex::new("picture").unwrap();
        let quote ="Once upon a midnight dreary\nWhile I pondered weak and weary\nOver many a quaint and curious volume of forgotten lore";
        for line in quote.lines() {
            let contains_substring = re.find(line);
            match contains_substring {
                Some(_) => println("{}", line),
                None => (),
            }
        }
    }
    ```

=== "3"

    ```rs hl_lines="3 6-13 15"
    // RIA 71-72
    use regex::Regex;
    use clap::{App,Arg};
    
    fn main() {
        let args = App::new("grep-lite")
            .version("0.1")
            .about("searches for patterns")
            .arg(Arg::with_name("pattern")
                .help("The pattern to search for")
                .takes_value(true)
                .required(true))
            .get_matches();

        let pattern = args.value_of("pattern").unwrap();
        let re = Regex::new("picture").unwrap();
        let quote ="Once upon a midnight dreary\nWhile I pondered weak and weary\nOver many a quaint and curious volume of forgotten lore";
        for line in quote.lines() {
            let contains_substring = re.find(line);
            match contains_substring {
                Some(_) => println("{}", line),
                None => (),
            }
        }
    }
    ```

=== "4"

    ```rs
    // RIA 73
    use std::fs::File;
    use std::io::BufReader;
    use std::io::prelude::*;

    fn main() {
        let f = File::open("readme.md").unwrap();
        let mut reader = Bufreader::new(f);

        let mut line = String::new();

        loop {
            let len = reader.read_line(&mut line)
                .unwrap();

            if len == 0 {
                break
            }

            println!("{} ({} bytes long)", line, len);

            line.truncate(0);
        }
    }
    ```

=== "5"

    ```rs
    // RIA 73
    use std::fs::File;
    use std::io::BufReader;
    use std::io::prelude::*;

    fn main() {
        let f = File::open("readme.md").unwrap();
        let reader = BufReader::new(f);

        for line_ in reader.lines() {
            let line = line_.unwrap();
            println!("{} ({} bytes long)", line, line.len());
        }
    }
    ```

=== "6"

    ```rs hl_lines="2-5 27-30 39-40"
    // RIA 74-75
    use std::fs::File;
    use std::io;
    use std::io::BufReader;
    use std::io::prelude::*;
    use regex::Regex;
    use clap::{App,Arg};

    fn process_lines<T: BufRead + Sized>(reader: T, re: Regex) {
        for line_ in reader.lines() {
            let line = line_.unwrap();
            match re.find(&line) {
                Some(_) => println!("{}", line),
                None => (),)
            }
        }
    }

    fn main() {
        let args = App::new("grep-lite")
            .version("0.1")
            .about("searches for patterns")
            .arg(Arg::with_name("pattern")
                .help("The pattern to search for")
                .takes_value(true)
                .required(true))
            .arg(Arg::with_name("input")
                .help("File to search")
                .takes_value(true)
                .required(false))
            .get_matches();

        let pattern = args.value_of("pattern").unwrap();
        let re = Regex::new("picture").unwrap();

        let input = args.value_of("input").unwrap_or("-");

        if input == "-" {
            let stdin = io::stdin();
            let reader = stdin.lock();
            process_lines(reader, re);
        } else {
            let f = File::open(input).unwrap();
            let reader = BufReader::new(f);
            process_lines(reader, re);
        }
    }
    ```

=== "7"

    ```rs
    // RIA 80
    #[derive(Debug)]
    struct File {
        name: String,
        data: Vec<u8>,
    }

    fn main() {
        let f1 = File {
            name: String::from("f1.txt"),
            data: Vec:new(),
        };

        let f1_name = &f1.name;
        let f1_length = &f1.data.len();

        println!("{:?}", f1);
        println!("{} is {} byes long", f1_name, f1_length);
    }
    ```

=== "8"

    ```rs hl_lines="10-19 34"
    // RIA 82-83
    #![allow(unused_variables)]

    #[derive(Debug)]
    struct File {
        name: String,
        data: Vec<u8>,
    }

    fn read(
        f: &File,
        save_to: &mut Vec<u8>,
    ) -> usize {
        let mut tmp = f.data.clone();
        let read_length = tmp.len();
        save_to.reserve(read_length);
        save_to.append(&mut tmp);
        read_length
    }

    fn open(f: &mut File) -> bool { true }

    fn close(f: &mut File) -> bool { true }

    fn main() {
        let mut f = File {
            name: String::from("2.txt"),
            data: vec![1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29],
        };

        let mut buffer: Vec<u8> = vec![];

        open(&mut f);
        let f_length = read(&f2, &mut buffer);
        close (&mut f);

        let text = String::from_utf8_lossy(&buffer);
        
        println!("{:?}", f);
        println!("{} is {} bytes long", &f.name, f_length);
        println!("{}", text);
    }
    ```

=== "9"

    ```rs hl_lines="10-36 44"
    // RIA 86
    #![allow(unused_variables)]

    #[derive(Debug)]
    struct File {
        name: String,
        data: Vec<u8>,
    }

    impl File {
        fn new(name: &str) -> File {
            File {
                name: String::from(name),
                data: Vec::new(),
            }
        }

        fn new_with_data(
            name: &str,
            data: &Vec<u8>,
        ) -> File {
            let mut f = File::new(name);
            f.data = data.clone();
            f
        }
        fn read(
            self: &File, 
            save_to: &mut Vec<u8>,
        ) -> usize {
            let mut tmp = self.data.clone();
            let read_length = tmp.len();
            save_to.reserve(read_length);
            save_to.append(&mut tmp);
            read_length
        }
    }

    fn open(f: &mut File) -> bool { true }

    fn close(f: &mut File) -> bool { true }

    fn main() {
        let f_data: Vec<u8> = vec![1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
        let mut f = File::new_with_data("2.txt", &f_data);

        let mut buffer: Vec<u8> = vec![];

        open(&mut f);
        let f_length = f.read(&mut buffer);
        close(&mut f);

        let text = String::from_utf8_lossy(&buffer);

        println!("{:?}", f);
        println!("{} is {} bytes long", &f.name, f_length);
        println!("{}", text);
    }
    ```

=== "10"

    ``` rs hl_lines="36 45 53 62-64"
    // RIA 93-94
    use rand::prelude::*;

    fn one_in(denominator: u32) -> bool {
        thread_rng().gen_ratio(1, denominator)
    }

    #[derive(Debug)]
    struct File {
        name: String,
        data: Vec<u8>,
    }

    impl File {
        fn new(name: &str) -> File {
            File {
                name: String::from(name),
                data: Vec::new(),
            }
        }

        fn new_with_data(name: &str ,data: Vec<u8>) -> File {
            let mut f = File::new(name);
            f.data = data.clone();
            f
        }

        fn read(
            self: &File,
            save_to: &mut Vec<u8>,
        ) -> Result<usize, String> {
            let mut tmp = self.data.clone();
            let read_length = tmp.len();
            save_to.reserve(read_length);
            save_to.append(&mut tmp);
            Ok(read_length)
        }
    }

    fn open(f: File) -> Result<File, String> {
        if one_in(10_000) {
            let err_mag = String::from("Permission denied");
            return Err(err_msg);
        }
        Ok(f)
    }

    fn close(f: File) -> Result<File, String> {
        if one_in(100_000) {
            let err_mag = String::from("Interrupted by signal!");
            return Err(err_msg);
        }
        Ok(f)
    }

    fn main() {
        let f_data: Vec<u8> = vec![1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
        let mut f = File::new_with_data("4.txt", &f_data);

        let mut buffer: Vec<u8> = vec![];

        f = open(f).unwrap();
        let f_length = f.read(&mut buffer).unwrap();
        f = close(f).unwrap();

        let text = String::from_utf8_lossy(&buffer);

        println!("{:?}", f);
        println!("{} is {} bytes long", &f.name, f_length);
        println!("{}", text);
    }
    ```

=== "11"

    ```rs hl_lines="2-6 12 20 37 42 48"
    // RIA 97-98
    #[derive(Debug,PartialEq)]
    enum FileState {
        Open,
        Closed,
    }

    #[derive(Debug)]
    struct File {
        name: String,
        data: Vec<u8>,
        state: FileState,
    }

    impl File {
        fn new(name: &str) -> File {
            File {
                name: String::from(name),
                data: Vec::new(),
                state: FileState::Closed,
            }
        }

        fn read(
            self: &File,
            save_to: &mut Vec<u8>,
        ) -> Result<usize, String> {
            let mut tmp = self.data.clone();
            let read_length = tmp.len();
            save_to.reserve(read_length);
            save_to.append(&mut tmp);
            Ok(read_length)
        }
    }

    fn open(mut f: File) -> Result<File, String> {
        f.state = FileState::Open;
        Ok(f)
    }

    fn close(mut f: File) -> Result<File, String> {
        f.state = FileState::Closed;
        Ok(f)
    }

    fn main() {
        let f_data: Vec<u8> = vec![1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
        let mut f = File::new("4.txt");

        let mut buffer: Vec<u8> = vec![];

        f = open(f).unwrap();
        let f_length = f.read(&mut buffer).unwrap();
        f = close(f).unwrap();

        let text = String::from_utf8_lossy(&buffer);

        println!("{:?}", f);
        println!("{} is {} bytes long", &f.name, f_length);
        println!("{}", text);
    }
    ```

=== "12"

    ```rs
    // RIA 101-102
    #![allow(dead_code)]

    use std::fmt;
    use std::fmt::{Display};

    #[derive(Debug,PartialEq)]
    enum FileState {
        Open,
        Closed,
    }

    impl Display for FileState {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            match *self {
                FileState::Open => write!(f, "OPEN"),
                FileState::Closed => write!(f, "CLOSED"),
            }
        }
    }

    impl Display for File {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "<{} ({})>", self.name, self.state)
        }
    }

    // --snip--

    fn main() {
        println!("{:?}", f);
        println!("{}", f);
    }
    ```

