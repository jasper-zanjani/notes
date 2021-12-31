# Cargo

Cargo is Rust's package manager.

New [crates](Glossary#crate) can be created with the **`cargo`** command-line utility.
```sh
cargo new hello_cargo
cargo new hello_cargo --vcs none # Prevent creation of a Git repo
```

The **`add`** subcommand can be enabled:
```sh
cargo install cargo-edit
```

Now dependencies can be added thus:
``` sh
cargo add gtk4
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