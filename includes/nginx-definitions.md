**default server block**{: #default-server-block}
:   First server block defined in the config

**events**{: #events }
:   Context that governs connection processing configuration.
    Events can only be declared in the main context and there can only be a single events defined within the configuration.
    

**http**{: #http }
:   Context that allows configuration of HTTP servers and typically serves as a container for the [**server**](#server) context.
    Directives that are intended to apply to multiple server contexts are typically placed within the http context.

**listen**{: #listen }
:   Simple directive in the [server](#server) context that configures the network interfaces and ports to listen on for requests.
    ```nginx
    server {
        listen *:80;
        listen *:81;
    }
    ```

**location**{: location }
:   Context directive used when there is not a 1:1 mapping between path of the HTTP request and the filesystem.
    **Prefix location blocks**, the most basic implementation, allow various root directories to be specified depending on the request path.

    Various **modifiers** can be used to modify how the request path is matched.
    When resolving paths, the most specific match is used.
    
    Location blocks in order of precedence:

    - Exact match modifier (`=`) 
    - Order matters with regex blocks because the first match will be used.
        - Non-regex prefix (`^~`) overrides any regex match
        - Case-sensitive regex (`~`) 
        - Case-insensitive regex (`~*`)
    - Prefix (no modifier)

    ```nginx
    location /images/ {
        root /var/www/images;
    }

    location = /images/business_cat.gif {
        # ...
    }
    
    location ~ \.(gif|jpg)$ {
        # ...
    }

    location ~* \.(GIF|JPG)$ {
        # ...
    }

    location ^~ /foobar/images {
        root /var/www/foobar;
    }
    ```

    

**server**{: #server } (context directive)
:   [http-context](#http) context directive.

**server** (simple directive)
:   [upstream](#upstream)-context directive that specifies a backend node.
    Additional parameters can specify load-balancing behavior.

        - **weight** controls weighting of backend nodes (default value is 1)
        - **max_fails** controls the number of times that the server can be marked as unhealthy before it is removed from the pool
        - **fail_timeout** controls the time a server is removed from the pool when it is marked unhealthy, and for how long `max_fails` is good for

**server_name**{: #server_name}
:   Server context simple directive that enables virtual hosting.
    Values of this directive are matched to the HTTP GET request header's `Host`.
    If no matches are found, nginx uses the [default server block](#default-server-block).

**upstream**{: #upstream }
:   [http-context](#http) simple directive that can, using the `server` simple directive, specify a pool of backend server.
    ```nginx
    upstream backend {
        server 192.0.2.10:443 weight=3;
        server app1.example.com;
        server unix:/u/apps/my_app/current/tmp/unicorn.sock;
    }
    ```
    Each server directive can additionally 



**user**{: #user }
:   Main context simple directive that sets the Unix user and group that nginx worker processes will run as; by default `nobody` and the group is `nogroup`.

**worker process**{: #worker-process }
:   The non-root nginx process that serves incoming HTTP requests.
    Each worker process is single-threaded and runs a non-blocking event loop to process requests efficiently.

**worker_connections**{: #worker-connections}
:   Main context simple directive that sets the maximum number of simultaneous connections that can be opened by each [worker process](#worker-process).

**worker_processes**{: #worker-processes }
:   Main context simple directive that sets the number of [worker processes](#worker-process) to serve HTTP requests (1 by default).
