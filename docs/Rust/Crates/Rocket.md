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
# rocket

```rs title="Boilerplate"
use rocket::launch;

#[launch]
fn rocket() -> _ {
    rocket::build()
}
```

Rocket is a web framework for Rust, along the lines of Flask for Python.

!!! bug "API changes"

    Major API changes are in store in the transition from 0.4.10 (current stable version as of the time of this writing) and 0.5.0-rc.1.
    The [guide](https://rocket.rs/0.4/guide/) is written for 0.4 and there is no 0.5 version published yet.

    These changes include a reorganization of some traits, such as FromForm from [request](https://docs.rs/rocket/0.4.10/rocket/request/index.html) to the new [form](https://docs.rs/rocket/0.5.0-rc.1/rocket/form/index.html) module.


#### Fairing
:   
    [**Fairings**](https://rocket.rs/0.4/guide/fairings/) are Rocket's approach to structured middleware which hook into the request lifecycle and expose callbacks for events such as incoming requests and outgoing responses.

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


#### Pathing
:   
    **Dynamic paths** are possible by implementing the [**FromParam**](https://api.rocket.rs/0.4/rocket/request/trait.FromParam.html) trait on any type.


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


#### Hello, World!
:   


    ```rs title="Index route"
    use rocket::{get, routes, launch}; // (3)

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index,]) // (2)
    }

    #[get("/")] // (1)
    fn index() -> String {
        String::from("Hello, World!")
    }
    ```

    1. Create an index route by placing the [**get** attribute](https://docs.rs/rocket/latest/rocket/attr.get.html) on a route handler.
    There are various attributes corresponding to HTTP methods: GET, PUT, POST, DELETE, etc.
    An alternative syntax is also available:
    ```rs hl_lines="1"
    #[route(GET, path = "/")]
    fn index() -> String {
        String::from("Hello, World)
    }
    ```
    2. [**mount**](https://docs.rs/rocket/latest/rocket/struct.Rocket.html#method.mount) takes a base path and the [**routes**](https://docs.rs/rocket/latest/rocket/macro.routes.html) macro containing a list of routes.
    3. Note the use of "feature flag" inner attribute that allows use of two features from [unstable Rust](https://doc.rust-lang.org/unstable-book/index.html). 
    ```rs title="0.4"
    #![feature(proc_macro_hygiene, decl_macro)] // (1)

    use rocket::{get, routes};

    fn main() {
        rocket::ignite()
            .mount("/", routes![index])
            .launch();
    }

    #[get("/")]
    fn index() -> String {
        String::from("Hello, World!")
    }
    ```

    ```rs hl_lines="14-17" title="Dynamic route"
    use rocket::{get, routes, launch};

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index, greeting])
    }

    #[get("/")]
    fn index() -> String {
        String::from("Hello, World!")
    }

    #[get("/<name>")] // (1)
    fn greeting(name: String) -> String {
        format!("Hello, {}!", name)
    }
    ```

    1. The word in angle brackets is known as a **dynamic parameter** and becomes the identifier of a variable that must appear as an argument in the function.


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
            .mount("/", FileServer::from("site")) // (1)
    }
    ```

    1. Since rocket 0.5, [**FileServer**](https://docs.rs/rocket/0.5.0-rc.1/rocket/fs/struct.FileServer.html) is recommended for building static file servers, although the API of 0.4 can be aped more directly with the following code:
    ```rs hl_lines="4-7"
    use rocket::{get, routes, launch};
    use rocket::fs::NamedFile;

    #[get("/")]
    pub async fn index() -> Option<NamedFile> {
        NamedFile::open("/site/index.html").await.ok()
    }

    #[launch]
    fn rocket() -> _ {
        rocket::build()
            .mount("/", routes![index])
    }
    ```
    2. 
    ```rs title="0.4"
    #![feature(proc_macro_hygiene, decl_macro)]

    use rocket::{get, routes};
    use rocket::response::{Responder, NamedFile};

    #[get("/")]
    fn index() -> Result<impl Responder<'static>, std::io::Error> {
        NamedFile::open("/site/index.html")
    }

    fn main() {
        rocket::ignite()
            .mount("/", routes![index])
            .launch();
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
    3. Prior to 0.5, the Template struct was in the [**rocket\_contrib**](https://api.rocket.rs/v0.4/rocket_contrib/) crate. 
    Since 0.5, the **rocket\_dyn\_templates** crate requires at least one of two features to be enabled to use Template.
    ```toml title="Cargo.toml"
    rocket_dyn_templates = {version = "0.1.0-rc.1", features = ["handlebars", "tera"]}
    ```
    4. Template names passed to Template::render() must correspond to files placed in the path set by the **template\_dir** configuration parameter.
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
    ```html title="index.html.hbs"
    <!doctype html>
    <html>
      <head>
        <link rel="stylesheet" href="bulma.css"/>
        <title>{{msg}}</title>
      </head>
      <body>
        <section class="hero is-primary">
          <div class="hero-body">
            <div class="container">
              <h1 class="title">{{msg}}</h1>
            </div>
          </div>
        </section>
      </body>
    </html>
    ```
    2.  
    ```toml title="Cargo.toml"
    rocket_dyn_templates = { version = "0.1.0-rc.1", features = ["handlebars"], default-features = false }
    ```