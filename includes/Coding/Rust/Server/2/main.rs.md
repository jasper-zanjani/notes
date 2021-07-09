``` rs linenums="1" hl_lines="20-24 26-36"
fn main() {
    let server = Server::new("127.0.0.1:8080");
    server.run();
}

struct Server {
    addr: String,
}

impl Server {
    fn new(addr:String) -> Self {
        Self {
            addr
        }
    }

    fn run(self) {}
}

struct Request {
    path: String,
    query_string: String,
    method: Method,
}

enum Method {
    GET,
    DELETE,
    POST,
    PUT,
    HEAD,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH,
}
```