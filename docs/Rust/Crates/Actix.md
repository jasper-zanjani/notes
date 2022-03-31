# actix

## Tasks

#### Hello, World!
:   

    ```rs
    use actix_web::{App, HttpServer};
    use actix_web::{web, HttpResponse, Responder};

    #[actix_web::main]
    async fn main() -> std::io::Result<()> {
        HttpServer::new(|| {
            App::new()
                .route("/", web::get().to(hello))
        })
        .bind(("127.0.0.1", 8000))? // (1)
        .run()
        .await
    }

    async fn hello() -> impl Responder {
        HttpResponse::Ok().body("Hello, World!")
    }
    ```

    1. Note the address and port can be defined as a tuple or as a string
    ```rs
    .bind("127.0.0.1:8000")?
    ```

#### Static file server
:   

    ```rs hl_lines="8"
    use actix_web::{App, HttpServer};
    use actix_files::Files;

    #[actix_web::main]
    async fn main() -> std::io::Result<()> {
        HttpServer::new(|| {
            App::new()
                .service(Files::new("/", "./static/").index_file("index.html"))
                .wrap(actix_web::middleware::Logger::default())
        })
        .bind(("127.0.0.1", 8000))? 
        .run()
        .await
    }
    ```
