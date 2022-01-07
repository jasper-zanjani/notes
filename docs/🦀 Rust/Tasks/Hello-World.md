# Hello, World!

#### Parameterized

--8<-- "includes/Rust/hwp.md"

Here the [**if let**](/Rust/Glossary#if-let) syntax is used to provide a default value for the value passed in from the command-line.

#### Interactive

--8<-- "includes/Rust/hwi.md"

#### CLI frameworks

Here the same simple Hello, World! CLI application is provided using both the standard **App** struct as well as the **`clap_app`** macro.
Simple **clap** applications can be made using short-hand syntaxes available with the `clap_app!` macro (which is actually deprecated now).

Boolean values can be set to true with `+` and false with `!`:
```rs
+required // Arg::required(true)
!required // Arg::required(false)
```

Note that the `crate_version!` and `crate_authors!` macros will retrieve values from the corresponding fields in the crate's Cargo.toml.

=== "`App`"

    --8<-- "includes/Rust/hwcli-clap.md"

=== "`clap_app!`"

    --8<-- "includes/Rust/hwcli-clap-clap_app.md"

Using **structopt**

--8<-- "includes/Rust/hwcli-structopt.md"
