# Development environment

=== ":material-language-rust: Rust"
    ```sh title="Red Hat"
    dnf install gtk4-devel gcc
    ```

    ```sh title="Ubuntu"
    apt install libgtk-4-dev build-essential
    ```

=== ":material-language-python: Python"
   
    ```sh title="Red Hat"
    dnf install python3-venv python3-wheel
    dnf install gcc zlib-devel bzip2 bzip2-devel readline-devel sqlite sqlite-devel openssl-devel tk-devel git python3-cairo-devel cairo-gobject-devel gobject-introspection-devel
    pip install pygobject
    ```

    ```sh title="Ubuntu"
    apt install python3-gi python3-gi-cairo gir1.2-gtk-3.0 libgirepository1.0-dev
    pip install pygobject
    ```

