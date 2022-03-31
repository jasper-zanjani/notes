# Cargo

Cargo is Rust's package manager.

New [crates](Glossary#crate) can be created with the **`cargo`** command-line utility.
```sh
cargo new hello_cargo
cargo new hello_cargo --vcs none # Prevent creation of a Git repo
```

Extensions to Cargo are available, which add subcommands like [**add**](https://crates.io/crates/cargo-edit) and [**watch**](https://crates.io/crates/cargo-watch)
```sh
cargo install cargo-edit
cargo install cargo-watch
```

During development, a crate can be compiled and run
```sh
cargo run
```

If behind a corporate firewall, where SSL certificates are substituted, a [special flag](https://github.com/rust-lang/cargo/issues/8688) must be set in **~/.cargo/config.toml** to allow package downloads.
```ini
[http]
check-revoke = false
```

Generate [documentation](#documentation) from doc comments using a built-in static site generator, and then open it.
```sh
cargo doc --open
```

Other commands:

- `cargo fmt` format code
- `cargo test` run [doctests](#tdd)

#### Features
:   
    Every crate has features that can be enabled in the Cargo.toml.
    Crate features are declared in the Cargo.toml
    ```toml
    rocket = {version = "0.5.0-rc.1", default-features = false, features = ["json"]}
    ```

    These can also be added from the command-line
    ```sh
    cargo add rocket --features json --no-default-features
    ```


    These are distinct from the "feature flag" [inner attributes](/Rust/attribute) referring to features of [unstable Rust](https://doc.rust-lang.org/unstable-book/index.html).
