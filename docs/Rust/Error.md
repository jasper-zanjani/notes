# Error handling

Error handling in Rust is closely tied to a specific type, the [**Result**](https://doc.rust-lang.org/std/result/){: #result } enum:
```rs
enum Result<T, E> {
    Ok(T),
    Err(E),
}
```
Plainly, Results encapsulate the success or failure of an operation, and the idiomatic "Rustic" way to return a value from a function is to wrap it in **Ok** (or an error wrapped in **Err**).

Results expose many methods to handle errors. 
Some like [**unwrap**](https://doc.rust-lang.org/std/result/enum.Result.html#method.unwrap) and [**expect**](https://doc.rust-lang.org/std/result/enum.Result.html#method.expect) are familiar to Rust learners, and they are commonly used at the beginning stages of development as crude forms of error handling.

Other methods include the family of [**combinators**](#combinators) which allow operations to be conducted on wrapped values, including errors, and for these operations to be chained together in a way that is fluent and intuitive.

Rust distinguishes between *recoverable* and *unrecoverable* errors.
Recoverable errors can be handled by program logic, whereas unrecoverable errors result in a crash (ref. [**panic**](/Rust/Glossary/#macro)).

### Question mark operator
:   
    The [**question mark operator**](https://doc.rust-lang.org/reference/expressions/operator-expr.html#the-question-mark-operator) (**?**) is used only within the body of functions that return Results and only at the end of function calls that also return results.
    It is similar to using a [**match**](/Rust/Glossary/#match) expression in that the value wrapped by Result is returned to the calling code. 
    

    ```rs
    fn main() {
        match outer() {
            Err(e) => eprintln!("inner() returned an error!"),
            _ => println!("No error!")
        };
    }

    fn outer() -> Result<T, E> {
        let value = inner()?; // (1)
    }

    fn inner() -> Result<T, E> {
        Err()
    }
    ```

    1. If **inner()** returns an Error (which it does), it is immediately returned as the return value of **outer()**


    If the error types are mismatched then the compiler will automatically attempt to convert them using **from**, so the From trait for the inner error type should be implemented for the outer error type.
    

    ```rs
    use std::io;
    use std::io::Read;
    use std::fs::File;

    fn read_username_from_file() -> Result<String, io::Error> {
        let mut s = String::new();
        File::open("hello.txt")? // (1)
            .read_to_string(&mut s)?; // (2)
        Ok(s)
    }
    ```

    1. Equivalent to:
    ```rs
    let mut f = match File::open("hello.txt") {
        Ok(file) => file,
        Err(e) => return Err(e),
    };
    ```
    2. Equivalent to:
    ```rs
    let mut s = String::new();
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
    ```

### Combinators

<!-- 
One of the things that is confusing about learning combinators is that they are methods on both Option and Result.
And most of the tutorials out there on combinators appear to focus on the Option methods, e.g. Rust By Example 
(https://doc.rust-lang.org/rust-by-example/error/option_unwrap/map.html)

But in practice the Result methods are actually used more for error handling and to structure business logic. 
-->

Combinators are a functional programming approach to error handling that use a variety of [Result](#result) methods to run operations on wrapped types, especially errors.

#### and\_then
:   
    The [**and\_then**](https://doc.rust-lang.org/std/result/enum.Result.html#method.and_then) combinator can be used to take a value wrapped in **Ok** and pass it to another function.
    An error short circuits this method and is returned immediately.

    Here, it is used trivially to display a greeting after receiving a string interactively.

    --8<-- "includes/Rust/Tasks/hwi.md"

    and\_then also figures prominently in Ken Youens-Clark's [Command-Line Rust](https://github.com/kyclark/command-line-rust), where he uses it to pass a Config object containing values parsed from the command-line using clap.

    ```rs title="Standard entrypoint in KYC's Rust CLI programs"
    fn main() {
        if let Err(e) = catr::get_args().and_then(catr::run) {
            eprintln!("{}", e);
            std::process::exit(1);
        }
    }
    ```

#### map
:   
    The [**map**](https://doc.rust-lang.org/std/result/enum.Result.html#method.map) combinator runs a function on the wrapped value, changing its type, or passes along the Error.

    === "Naive"

        ```rs
        struct Person {
            name: String,
            age: i32,
        }

        fn display(person: Option<Person>) {
            match person {
                Some(person) =>println!("{:?}",person),
                None => println!("No person")
            }
        }

        fn main() {
            let person = Some(Person {
                name: "Amita".to_string(),
                age: 16
            });
            
            display(person);
        }
        ```

    === "map()"

        ```rs hl_lines="7-9"
        struct Person {
            name: String,
            age: i32,
        }

        fn display(person: Option<Person>) {
            let result: Option<String> = person.map(|p| p.name)
                .filter(|x| x.contains("Ami"))
                .take();
            println!("{:?}", result.unwrap());
        }

        fn main() {
            let person: Option<Person> = Some(Person {
                name: "Amita".to_string(),
                age: 16,
            });

            display(person);
        }
        ```

        
