<!--  

Merely in order to follow along with the Rust Programming Recipes
section on Diesel, I need to have a better idea of how Rust crates
are structured, and especially how the syntax has changed in Rust 2018. 

Now that I know about the module structure, I see flaws in the methodology
and approach taken by the tutorial's author.

Stoodley basically copy-pastes the code of his example in the video. 

-->

# Overview

Learning Diesel is harder than other crates because of the amount of setup that is required.

- Reliant on a specific workflow dependent on the [Diesel CLI](#diesel-cli) utility
- A lot of boilerplate code
- Multiple APIs available for doing the same thing

Diesel supports procedural functions for CRUD functions as well as (mostly) equivalent methods on structs that implement Dsl traits.
The Dsl API is more fluent 

| CRUD verb | function                                                                       | method                                                                                  |
| --------- | ------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------- |
| Create    | [diesel::insert_into](https://docs.rs/diesel/1.4.8/diesel/fn.insert_into.html) | [diesel::dsl::insert_into](https://docs.rs/diesel/1.4.8/diesel/dsl/fn.insert_into.html) |
| Delete    | [diesel::delete](https://docs.rs/diesel/1.4.8/diesel/fn.delete.html)           | [diesel::dsl::delete](https://docs.rs/diesel/1.4.8/diesel/dsl/fn.delete.html)?          |


#### Prerequisites
:   
    Diesel has drivers for various DBMSes.
    Prerequisites for these have to be installed before attempting to install the corresponding features in [Diesel CLI](#diesel-cli) or compiling a Rust project using it.

    --8<-- "includes/Linux/Tasks/postgresql.md"

#### Diesel CLI
:   

    ```sh title="Install Diesel CLI"
    cargo install diesel_cli --no-default-features --features postgres sqlite # (1)
    ```

    1. Without installing dependencies, the installation will fail upon calling /usr/bin/ld because it is unable to find "-lpq" (in the case of PostgreSQL).

    ```sh title=".env"
    DATABASE_URL=database.db # (1)
    ```

    1. Because this is a relative path, Diesel will create the database in the working directory, wherever it may be. So absolute paths are recommended.


    ```sh title="Create migrations directory and database specified in .env"
    diesel setup
    ```



    ```toml title="diesel.toml"
    [print_schema]
    file = "src/schema.rs"
    ```

    ```rs title="schema.rs"
    table! {
        starships (registry) {
            registry -> Text,
            name -> Text,
            crew -> Integer,
        }
    }
    ```

    The schema can also be [printed](https://diesel.rs/guides/schema-in-depth.html) from the command-line
    ```sh
    diesel print-schema
    ```

#### Migrations
:   
    Diesel facilitates the creation of **migration** scripts, reversible changes to the database's schema. 
    Named **up.sql** and **down.sql**, they must be manually edited by the user.

    ```sh title="Migration commands"
    diesel migration generate setup_tables # (1)
    diesel migration list
    diesel migration run
    diesel migration revert # (2)
    diesel migration redo
    ```

    1. Example scripts:
    ```sql title="up.sql"
    CREATE TABLE starships (
        registry TEXT PRIMARY KEY NOT NULL,
        name TEXT NOT NULL,
        crew INTEGER NOT NULL
    );
    ```
    ```sql title="down.sql"
    DROP TABLE starships;
    ```
    2. Because the migrations are reversible (via the down.sql script), the migration can be rolled back.

    When a migration is performed, the Diesel CLI will generate a **schema.rs** file in a directory set by [**diesel.toml**](http://diesel.rs/guides/configuring-diesel-cli).