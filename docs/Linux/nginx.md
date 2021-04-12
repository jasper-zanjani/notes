# nginx

**nginx**

The default config for nginx may be at various paths (**/etc/nginx/nginx.conf**), depending on installation method, or a config can be explicitly specified with `--conf-path`/`-c`.
Nginx can be interrogated for its default config with `-t`

Nginx config files resemble C# code files. 

- **Simple directives** like `listen *:80;` are made of a name, multiple optional parameters, and a closing semicolon. 
Parameters themselves can pass a value after an equal sign, i.e. `backlog=511`.
- **Context directives** or simply **contexts** like `events`, `http`, and `server` wrap a group of other directives in a pair of braces and can be nested.
Most simple directives can only be declared in specific contexts.
- There is also an implied **main context** which wraps all the contents of the file, and putting a simple directive into the main context means making it a top-level statemtn.


## Examples

A very simple representative config that creates an HTTP server listening on port 80 of every network interface, with no HTTP Host specified, from the specified root path:

=== "Default"

    ```nginx
     
       
      
    events {

    }

    http {
      server {



      }
    }
    ```

=== "Expanded with explicit values"

    ```nginx
    user nobody nogroup;
    worker_processes 1;

    events {
      worker_connections 512;
    }

    http {
      server {
        listen *:80;
        server_name "";
        root /usr/share/nginx/html;
      }
    }
    ```



```
http {
  server {
    listen 8080;
    root /www;
    
    location /images {
      root /;
    }
  }
}
events { }
```


```sh
nginx -s stop
nginx -s start
nginx restart
```


### Reverse proxy

Each Nginx virtual server should be described by a file in the **/etc/nginx/sites-available** directory. These are linked to by symlinks placed in **/etc/nginx/sites-enabled**.
Configuring a reverse proxy involves associating routes to proxied servers in these virtual server configs. [NGINX.org](https://docs.nginx.com/nginx/admin-guide/web-server/reverse-proxy/)
```ini
server {
  listen 80;
  location / {
    proxy_pass "http://127.0.0.1:8000";
  }
}
```

The configuration to serve static files placed in the local directory **/path/to/staticfiles** from the URL **/static** is:
```ini
location /static/ {
  root /path/to/staticfiles/
}
```

### Load balancer

A load balancer is similar to a reverse proxy, with the following differences.

- Load balancers perform reverse proxy across many backends, rather than a single one
- Load balancers operate at either Layer 7 or Layer 4, whereas a reverse proxy operates only at Level 7
- Load balancers are expected to handle much higher scale.

Load balancers themselves tend to be load balanced by DNS servers, which can serve multiple A records to clients which are supposed to choose one of the IP addresses at random.
Some DNS providers like [AWS Route 53](/Cloud#route-53) randomize the order of these records per query.

```nginx
http {
  upstream backend {
    server 192.0.2.10;
    server 192.0.2.11;
  }

  server {
    listen 80;

    location / {
      proxy_pass http://backend;
    }
  }
}
```

## 📘 Glossary

--8<-- "includes/nginx-definitions.md"
