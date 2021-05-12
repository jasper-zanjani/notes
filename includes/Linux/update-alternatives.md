#### update-alternatives

A command-line program that can be used to set default commands on Debian distros.
update-alternatives manages various **link groups** that correspond to general application types, i.e. **www-browser** for a web browser.
These link groups can be enumerated with **--get-selections**

```sh
update-alternatives --get-selections
```

=== "Create"

    ```sh
    update-alternatives --install /usr/bin/new-link-group new-link-group /dev/null 1
    ```

=== "Read"

    ```sh
    update-alternatives --list www-browser
    ```

=== "Update"

    ```sh
    update-alternatives --set www-browser /usr/bin/wslview
    ```

=== "Delete"

    ```sh
    update-alternatives --remove www-browser /usr/bin/lynx
    ```
