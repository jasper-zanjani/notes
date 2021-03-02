# nginx


```sh
nginx -s stop
nginx -s start
nginx restart
```

NGINX config files are composed of **simple directives** contained in **block directives**. A few top-level directives are referred to as **contexts** and group together directives according to traffic type.
- `events`
- `http`
- `mail`
- `stream`
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