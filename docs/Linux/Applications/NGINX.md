# Nginx

**Nginx** ("engine-x") is described as an *event-based reverse proxy server*.
This refers to the fact that it has an asynchronous architecture, unlike its competitors Apache and IIS which create a new blocking thread per connection.
Nginx is much newer than Apache which started in 1995, although it has seen widespread adoption since 2008, growing mostly at Apache's expense.
A typical and favored deployment is to place Nginx in the front-end and Apache in the back-end to combine the advantages of both platforms.

Nginx follows the convention of even version numbers being stable and odd numbers being mainline or development.


=== ":material-redhat: Red Hat"

    ```sh
    # /etc/yum.repos.d/nginx.repo

    [nginx]
    name=nginx repo
    baseurl=http://nginx.org/packages/centos/7/$basearch/
    gpgcheck=0
    enabled=1
    ```
    ```sh
    dnf install nginx
    ```

=== ":material-ubuntu: Ubuntu"

    ```sh
    # /etc/apt/sources.list

    deb http://nginx.org/packages/ubuntu/ trusty nginx
    deb-src http://nginx.org/packages/ubuntu/ trusty nginx
    ```
    ```sh
    curl -fsSL http://nginx.org/keys/nginx_signing.key
    apt-key add nginx_signing.key
    apt install nginx

    ```

Depending on installation method and distribution, configurations can exist in various directories.
A config can be explicitly specified at runtime with `--conf-path`/`-c`.

This option also appears in the output of `ps` for the Nginx master process, which is one way of interrogating which config is being used for the current Nginx instance.
Nginx can also be interrogated for its default config with `-t`

Nginx config files contain **directives**: 

- **Simple directives** like `listen *:80;` contain a name, multiple optional parameters, and a closing semicolon. 
Parameters themselves can pass a value after an equal sign, i.e. `backlog=511`.
- **Context directives** (or simply "contexts", also "block directives") like `events`, `http`, and `server` wrap a group of other directives in a pair of braces and can be nested.
Most simple directives can only be declared in specific contexts.
- There is also an implied **main context** which wraps all the contents of the file, and putting a simple directive into the main context means making it a top-level statemtn.
- Comments can be written using `#`

## Examples

A very simple representative config that creates an HTTP server listening on port 80 of every network interface, with no HTTP Host specified, from the specified root path:

  ``` nginx title="Default"
  events {
  }

  http {
    server {
    }
  }
  ```

  ```nginx title="Expanded with explicit values"
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



``` nginx
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

Each Nginx virtual server should be described by a file in the **/etc/nginx/sites-available** directory. 
These are linked to by symlinks placed in **/etc/nginx/sites-enabled**.
[Configuring a reverse proxy](https://docs.nginx.com/nginx/admin-guide/web-server/reverse-proxy/) involves associating routes to proxied servers in these virtual server configs. 

``` nginx
server {
  listen 80;
  location / {
    proxy_pass "http://127.0.0.1:8000";
  }
}
```

The configuration to serve static files placed in the local directory **/path/to/staticfiles** from the URL **/static** is:
``` nginx
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
Some DNS providers like [AWS Route 53](/Cloud/#route-53) randomize the order of these records per query.

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
