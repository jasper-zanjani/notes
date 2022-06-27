#### setfacl
:   
    The effect of ACLs can be illustrated with a web server.
    This command removes read access from a file which would otherwise be served by the Apache/httpd web server daemon.
    ```sh
    setfacl -m u:apache:- /var/www/html/index.html
    ```

    This can be resolved by granting read to the apache service account (or removing the entry altogether)
    ```sh
    setfacl -m u:apache:r /var/www/html/index.html
    setfacl -x u:apache /var/www/html/index.html
    setfacl -b /var/www/html/index.html
    ```