#### httpd
:   
    The Apache web server daemon is named **httpd** in RHEL and other RPM-based distributions.
    HTML content is served from **/var/www/html** by default, but this can be changed by modifying the **DocumentRoot** directive in the Apache config located at **/etc/httpd/conf/httpd.conf**.
    
    ```ini title="/etc/httpd/conf/httpd.conf"
    DocumentRoot "/web"
    # ...
    <Directory "/web">
    ```

    Containers must mount content to **/usr/local/apache2/htdocs**.

    Users can also serve files from their home directories, by default from a directory named **public\_html**.
