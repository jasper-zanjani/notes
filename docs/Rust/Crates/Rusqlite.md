# rusqlite

**rusqlite** is a wrapper for using SQLite from Rust.
Similar to the [**sqlite3**](/Python/Modules/Sqlite3.md) module in the Python standard library, procedural SQL commands are passed as strings to the **execute** method of a **Connection** object.


## Tasks

#### Boilerplate
:   

    ```rs
    fn main() -> Result<()> {
        let conn = rusqlite::Connection::open("database.db")?;
        conn.execute("SELECT * FROM TABLE", [])?;
        Ok(())
    }
    ```

#### Create table
:   

    ```rs
    use rusqlite::{Connection, Result};

    fn main() -> Result<()> {
        let conn = Connection::open("starships.db")?; // (1)

        conn.execute(
            "CREATE TABLE IF NOT EXISTS starships (
                registry TEXT PRIMARY KEY,
                name TEXT NOT NULL,
                crew INTEGER
            )",[]
        )?;

        Ok(())
    }
    ```

    1. This will create the database file if it does not exist.

#### Populate table
:   

    ```rs
    use rusqlite::{Connection, Result};

    struct Starship {
        name: String,
        registry: String,
        crew: u32
    }

    fn main() -> Result<()> {
        let conn = Connection::open("starships.db")?;

        let enterprise = Starship {
            name: "USS Enterprise".to_string(),
            registry: "NCC-1701".to_string(),
            crew: 401
        };

        conn.execute(
            "INSERT INTO starships (name, registry, crew) values (?1, ?2, ?3)", // (1)
            [enterprise.name, enterprise.registry, enterprise.crew.to_string()] // (2)
        )?;

        Ok(())
    }
    ```

    1. Note the unusual template syntax.
    2. All passed values must be passed as String structs.