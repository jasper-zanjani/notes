<!-- 

The documentation for rocket uses some bizarre terminology which I haven't found properly explained, all of which is consistent
with the project's theme of rocketry: launch, ignite, fairing, etc.


This includes the concept of guards, which appear to refer to using Rust types for data validation.

- **Segment guards** must implement the FromSegments trait. For example, because PathBuf implements FromSegments, it is a segments guard which ensures that routes typed with PathBuf cannot lead to path traversal attacks.
- [**Query guards**](https://docs.rs/rocket/latest/rocket/request/trait.FromQuery.html#query-guards) operate on multiple items of a request's query string

Rocket's various guards appear to be a generalization and abstraction of the concept of 
**route guards**, which exist in various web application frameworks and serve to restrict 
unauthorized or unauthenticated access to parts of the web application.

- Angular [route guards](https://codeburst.io/understanding-angular-guards-347b452e1892) are interfaces which control the accessibility of a route.
- Vue Router has [Navigation Guards](https://router.vuejs.org/guide/advanced/navigation-guards.html)
- React Router is the preferred library for implementing routes in React, but it does not have guarded routes by default but they can be [defined](https://blog.netcetera.com/how-to-create-guarded-routes-for-your-react-app-d2fe7c7b6122) 

Notably "guard" is also used in concurrent programming as the return type of some lock access methods.

Other terms:
- [**Fairings**](https://rocket.rs/0.4/guide/fairings/) are Rocket's approach to structured middleware which hook into the request lifecycle and expose callbacks for events such as incoming requests and outgoing responses.. ("the future runs all ignite fairings in serial, attach order,")
- deorbited
- ignite ("Returns a Future that transitions this instance of Rocket into the ignite phase")

-->
# Rocket

??? bug "API changes"

    Major API changes are in store in the transition from 0.4.10 (current stable version as of the time of this writing) and 0.5.0-rc.1.
    The [guide](https://rocket.rs/0.4/guide/) is written for 0.4 and there is no 0.5 version published yet.

    These changes include a reorganization of some traits, such as FromForm from [request](https://docs.rs/rocket/0.4.10/rocket/request/index.html) to the new [form](https://docs.rs/rocket/0.5.0-rc.1/rocket/form/index.html) module.

Rocket is a web framework for Rust, along the lines of Flask for Python.


The lifecyle of a Rocket request is as follows: [Routing](#route) -> Validation -> Processing -> Response

The process of building a Rocket application has several stages:

- Mounting [routes](#route)
- Managing **state**
- Attach [**fairings**](#fairing)




## Tasks

#### Configuration
:   
    Rocket can be configured using a [Rocket.toml](https://rocket.rs/0.4/guide/configuration/#rockettoml) file placed at the crate root to specify host address, port, etc. 
    Some of these settings appear to be necessary for certain REST clients.
    ```toml title="Rocket.toml"
    [development]
    address = "127.0.0.1"
    port = 8000
    ```


### Hello, World!

#### Simple
:   

    ```rs
    #[macro_use]
    extern crate rocket;

    #[launch] // (1)
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index])
    }

    #[get("/")]
    fn index() -> &'static str {
        "Hello, World!"
    }
    ```

    1. The [**#[launch]**](https://api.rocket.rs/v0.5-rc/rocket/attr.launch.html) attribute actually generates an async runtime. 
    ```rs
    #[macro_use]
    extern crate rocket;

    #[rocket::main]
    async fn main() {
        rocket::build()
            .mount("/", routes![index])
            .launch().await;
    }

    #[get("/")]
    async fn index() -> &'static str {
        "Hello, World!"
    }
    ```

#### Parameterized
:   
    Parameterization is enabled by [dynamic routes](#route):

    ```rs hl_lines="10-13"
    #[macro_use]
    extern crate rocket;

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index])
    }

    #[get("/<name>")] // (1)
    fn index(name: String) -> String {
        format!["Hello, {}!", name]
    }
    ```

    1. Alternatively, using a query segment:
    ```rs hl_lines="1"
    #[get("/?<name>)"]
    ```
    In which case the handler would only to the path "`/?name=...`", i.e.
    ```sh
    curl localhost:8000/?name=Jasper
    ```

    ```rs hl_lines="11 14-17" title="State"
    use rocket::{get, routes, launch, State};

    struct MyConfig {
        msg: String
    }

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index,])
            .manage(MyConfig { msg: "Hello, World!".to_string() })
    }

    #[get("/")]
    fn index(state: &State<MyConfig>) -> String { // (1)
        String::from(&state.msg)
    }
    ```

    1. **State** generally appears only in the parameter list of route handlers as a reference which must be initialized in the rocket crate itself.

    ```rs title="File server"
    use rocket::launch; // (2)
    use rocket::fs::FileServer;

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", FileServer::from("site"))
    }
    ```

    ```rs hl_lines="2 12 21" title="Template"
    use rocket::{get, routes, launch, };
    use rocket_dyn_templates::Template; // (3)

    #[derive(serde::Serialize)] // (1)
    struct Message {
        msg: String
    }

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .attach(Template::fairing()) // (2)
            .mount("/", routes![index,])
    }

    #[get("/")]
    fn index() -> Template {
        let context = Message {
            msg: String::from("Hello, World!")
        };
        Template::render("index", &context) // (4)
    }
    ```

    1. The context struct used to insert information into the template must have the Serialize derive.
    2. [**Template::fairing()**](https://api.rocket.rs/master/rocket_dyn_templates/struct.Template.html#method.fairing) must be attached to the running Rocket instance.
    A [**fairing**](https://rocket.rs/v0.5-rc/guide/fairings/) in Rocket parlance refers to structured middleware which expose hooks that allow callbacks to be placed into the request lifecycle to rewrite incoming requests and outgoing responses.
    1. Prior to 0.5, the Template struct was in the [**rocket\_contrib**](https://api.rocket.rs/v0.4/rocket_contrib/) crate. 
    Since 0.5, the **rocket\_dyn\_templates** crate requires at least one of two features to be enabled to use Template.
    ```toml title="Cargo.toml"
    rocket_dyn_templates = {version = "0.1.0-rc.1", features = ["handlebars", "tera"]}
    ```
    1. Template names passed to Template::render() must correspond to files placed in the path set by the **template\_dir** configuration parameter.
    The process of Rocket finding these templates is called [**discovery**](https://api.rocket.rs/master/rocket_dyn_templates/index.html#discovery).
    ```html title="index.html.hbs"
    <!doctype html>
    <html>
        <head>
            <title>{{msg}}</title>
        </head>
        <body>
            <p>{{msg}}</p>
        </body>
    </html>
    ```

    ```rs title="Styled template"
    use rocket::{get, routes, launch, };
    use rocket_dyn_templates::Template; // (2)
    use rocket::fs::FileServer;

    #[derive(serde::Serialize)]
    struct Message {
        msg: String
    }

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .attach(Template::fairing())
            .mount("/", FileServer::from("static"))
            .mount("/", routes![index,])

    }

    #[get("/")]
    fn index() -> Template {
        let context = Message {
            msg: String::from("Hello, World!")
        };
        Template::render("index", &context) // (1)
    }
    ```

    1. This template is themed using the Bulma CSS framework, which is served as a static file above.
    ```pug title="index"
    head
      head
        link rel="stylesheet" href="bulma.css"
        title {{msg}}
      body
        section.hero.is-primary
          .hero-body
            .container
              h1.title {{msg}}
    ```
    1.  
    ```toml title="Cargo.toml"
    rocket_dyn_templates = { version = "0.1.0-rc.1", features = ["handlebars"], default-features = false }
    ```

### Starships

A naive list-details application can be implemented using the [**lazy\_static**](../lazy_static) module to create a trivial in-memory database.

```rs
#[macro_use]
extern crate rocket;

use lazy_static::lazy_static;
use std::collections::HashMap;

lazy_static! {
    static ref STARSHIPS: HashMap<&'static str, Starship> = {
        let mut map = HashMap::new();
        map.insert(
            "NCC-1701",
            Starship {
                name: String::from("USS Enterprise"),
                registry: String::from("NCC-1701"),
                crew: 203,
            },
        );
        map.insert(
            "NX-74205",
            Starship {
                name: String::from("USS Defiant"),
                registry: String::from("NX-74205"),
                crew: 50,
            }
        );
        map
    };
}

#[derive(Debug)]
struct Starship {
    name: String,
    registry: String,
    crew: usize,
}

#[launch]
fn rocket() -> _ {
    rocket::build().mount("/", routes![ship,])
}

#[get("/<registry>")]
fn ship(registry: &str) -> String {
    let starship = STARSHIPS.get(registry); // (1)
    match starship {
        Some(s) => format!["Found starship: {:?}", s],
        None => String::from("No starship found!"),
    }
}
```

1. TODO: This is a good opportunity to use simple string manipulation to make the query case-insensitive, but I can't seem to get it to work.
I have to figure out a way to incorporate case-insensitivity here.
Also potentially a place to implement regex..

#### Benchmarking
:   
    Web applications can be benchmarked using the **benchrs** tool
    ```sh
    cargo install benchrs
    benchrs -c 30 -n 3000 -k http://127.0.0.1:8000/
    ```

## Glossary

#### Catcher
:   
    A route handler returning an Option will trigger the 404 error handler or [**catcher**](https://api.rocket.rs/v0.5-rc/rocket/struct.Catcher.html) when the None variant is returned.
    ```rs
    #[catch(404)]
    fn not_found(req: &Request) -> String {
        format!("{} not found", req.uri())
    }
    ```

    Analogous to the **mount** method and **routes!** macro for routes, catchers are associated with a Rocket application using the **register** method and **catchers!** macro.
    ```rs hl_lines="5"
    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index,])
            .register("/", catchers![not_found,])
    }
    ```

#### Fairing
:   
    [**Fairings**](https://rocket.rs/0.4/guide/fairings/) are Rocket's approach to structured middleware which hook into the request lifecycle and expose callbacks for events such as incoming requests and outgoing responses.
    The default builtin fairing is **Shield**, which injects HTTP security and privacy headers to all responses by default.

    Fairings (callbacks) are **attached** (registered) to the application's Rocket instance with the `attach()` method.
    Some structs like **Template** expose a **fairing()** method.

    ```rs hl_lines="4"
    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .attach(Template::fairing())
    }
    ```
    
    Fairings can be created from a function or closure using the [**AdHoc** struct](https://docs.rs/rocket/latest/rocket/fairing/struct.AdHoc.html).



#### Forms
:   
    **Forms** refers to data submitted by users, referring to the information provided by users on e.g. a subscription page.
    In rocket these are processed into structs which are decorated with the [**FreeForm**](https://api.rocket.rs/0.5-rc/rocket/form/trait.FromForm.html) derivable trait, making them **form guards**.
    FreeForm is used for collections, that is when more than one form field is available for parsing.
    Types with a single form field should implement [**FromFormField**](https://api.rocket.rs/0.5-rc/rocket/form/trait.FromFormField.html) instead.


#### Guards
:   
    [**Request guards**](https://rocket.rs/0.4/guide/requests/#request-guards) are used to arbitrarily validate requests, particularly API keys. 
    Types that implement the [**FromRequest**](https://api.rocket.rs/0.4/rocket/request/trait.FromRequest.html) trait (and specifically the **from\_request** method, returning an **Outcome** enum) are request guards.
    Builtin request guards include [CookieJar](https://api.rocket.rs/master/rocket/http/struct.CookieJar.html).
    They appear as additional parameters in the signature of a route handler.
    ```rs
    #[get("/<param>")]
    fn index(param: isize, a: A, b: B, c: C)  { /* .. */ } // (1)
    ```

    1. Here, **a**, **b**, and **c** are request guards.

    The term **data guard** refers to types that implement [**FromData**](https://api.rocket.rs/0.4/rocket/data/trait.FromData.html) (i.e. [rocket::serde::json::Json](https://docs.rs/rocket/0.5.0-rc.1/rocket/serde/json/struct.Json.html) which is also a form guard).

    ```rs
    use rocket::serde::json::Json;
    use serde::Deserialize;

    #[derive(Deserialize)]
    struct User {
        /* ... */
    }

    #[post("/user", format = "json", data = "<user>")]
    fn new_user(user: Json<User>) {
        /* ... */
    }
    ```

#### Databases
:   
    Integration with database libraries is done through [feature flags](https://rocket.rs/v0.5-rc/guide/state/#databases) on the **rocket\_sync\_db\_pools** crate.
    ```toml title="Diesel Postgres database pool"
    rocket_sync_db_pools = {version = "0.1.0-rc.1", default-features = false, features = ["diesel_postgres_pool",]}
    ```

#### Launch
:   
    A Rocket instance represents a web server and its state, and occupies one of three [**phases**](https://api.rocket.rs/v0.5-rc/rocket/struct.Rocket.html#phases) during its lifecycle, each of which is identifiable with a trait:

    - **Build** enables setting configuration, mounting and registering routes, managing state, and attaching [fairings](#fairing).
    - **Ignite** represents finalized configuration.
    - **Orbit** represents a running server.
    
    The boilerplate for a Rocket instance in fact returns the application in the Build phase

    ```rs hl_lines="7"
    #[macro_use]
    extern crate rocket;

    use rocket::{Rocket, Build};

    #[launch]
    fn rocket() -> Rocket<Build> {
        rocket::build()
    }
    ```


    Rocket instance in either Build or Ignite phases can be [launched](#launch) by running **Rocket::launch()**


#### Response
:   



#### Route
:   
    **Routes** are associated with handler functions and are typically composed of an HTTP method (GET, POST, etc) and a URI which is further composed of a **path** and a **query**. 
    
    ```rs
    #[get("/")]
    fn index() -> &'static str {
        "Hello, World!"
    }
    ```

    Both paths and queries can be decomposed into segments, delimited by slashes in the path and ampersands in the query.
    Any segment can be **static** or **dynamic**.
    
    Dynamic segments correspond with an eponymous variable that is passed to the route handler. The data type must implement [**FromParam**](https://api.rocket.rs/v0.5-rc/rocket/request/trait.FromParam.html).
    Many common primitives, including numbers and Strings, already implement this trait by default.

    === "Path segment"

        ```rs
        #[get("/<name>")]
        fn index(name: String) -> String {
            format!["Hello, {}!", name]
        }
        ```

    === "Query segment"

        ```rs
        #[get("/?<name>")]
        fn index(name: String) -> String {
            format!["Hello, {}!", name]
        }
        ```

    Another dynamic form exists with trailing **`..`** called **multiple segments**, i.e. `#[get("/<name..>)"]`.
    Such types must implement [**FromSegments**](https://api.rocket.rs/v0.5-rc/rocket/request/trait.FromSegments.html).
    The existing FromSegments implementation for **PathBuf** already prevents insecure traversal paths using `..`.

    Finally the **ignored segment** **`<_>`** or **`<_..>`** is a special case which will not appear in the argument list.
    ```rs
    #[get("/<_>")]
    ```

    Multiple handlers can also be defined for the same route, in which case each must have a **rank**.

    Routes can also define a **format**, which is useful in POST, PUT, and DELETE requests where there is a payload.
    These formats are IANA media types (lowercase), as well as some aliases, such as "html" for "text/html; charset=utf-8" etc.

#### State
:   
    A Rocket instance can manage any type that implements Send and Sync with the [**manage**](https://api.rocket.rs/v0.5-rc/rocket/struct.Rocket.html#method.manage) method.
    A managed state is typically used to handle a persistent database connection.
    ```rs
    use std::sync::atomic::AtomicU64;

    struct VisitorCounter { 
        visitor: AtomicU64,
    }

    fn rocket() -> _ {
        let counter = VisitorCounter {
            visitor: AtomicU64::new(0),
        };
        rocket::build()
            .manage(counter)
            .mount("/", <!-- ... -->)
    }
    ```
    This state is exposed as the State request guard:
    ```rs
    #[get("/")]
    fn route(counter: &State<VisitorCounter>,) {
        counter.visitor.fetch_add(1, Ordering::Relaxed);
        println!("The number of visitors is: {}", counter.visitor.load(Ordering::Relaxed));
    }
    ```
