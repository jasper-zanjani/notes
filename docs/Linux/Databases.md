# Databases

- [Azure Data Studio](https://docs.microsoft.com/en-us/sql/azure-data-studio/download-azure-data-studio?view=sql-server-2017)
- [Cosmos DB emulator](https://docs.microsoft.com/en-us/azure/cosmos-db/local-emulator?tabs=ssl-netstd21)

### PostgreSQL

PostgreSQL configs **postgresql.conf** and **pg_hba.conf** are stored where the PostgreSQL database cluster was initialized with initdb.
This directory can be initialized anywhere, but the default in Red Hat systems is **/var/lib/pgsql/data**.

## Tasks

#### Setup PostgresQL
:   

    --8<-- "includes/Linux/Tasks/postgresql.md"

    ```sh
    systemctl start postgresql
    sudo -u postgres psql
    ```

    ```sql title="Role setup"
    CREATE ROLE username LOGIN INHERIT -- (1)
                         CREATEDB -- (5)
                         PASSWORD 'password'; -- (3)
    GRANT postgres TO username; -- (2)
    CREATE DATABASE username; -- (4)
    exit
    ```

    1. Create a new user or "role". Like SSH, psql by default will use the currently logged-in username, which does not exist on a fresh installation.
    2. Grant [group membership](https://www.postgresql.org/docs/9.5/role-membership.html) to the newly created user.
    3. Manually set a password for the newly created user. Single quotes are necessary here, as double quotes will cause an error.
    ```sql title="After role creation"
    ALTER USER username WITH PASSWORD 'password' ;
    ```
    4. The default database which is logged into is also named after the currently logged-in user. 
    Also the built-in command **createdb** can be used from the command-line.
    5. Database creation is a [restricted operation](https://www.postgresql.org/docs/9.5/role-attributes.html) granted by an attribute.
    ```sql title="After role creation"
    ALTER USER username WITH CREATEDB;
    ```

### SQL

#### Starships
:   

    ```sql
    CREATE TABLE starships (
        name text, registry text, crew integer
    );
    ```

    ```sql
    INSERT INTO starships (name, registry, crew) 
        VALUES ('USS Enterprise', 'NCC-1701', 400); -- (1)
    ```

    1. For some reason, a double-quote **"** produces an error, and only single-quotes are accepted.

#### Cosmos DB
:   
    ...


## Commands

--8<-- "includes/Linux/Commands/psql.md"

--8<-- "includes/Linux/Commands/sqlite3.md"