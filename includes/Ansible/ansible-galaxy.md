#### ansible-galaxy
:   
    Search for roles
    ```sh
    ansible-galaxy search $ROLE
    ```

    Install `$ROLE` made  available in **Ansible Galaxy** by `$USER` into the [ system-wide ](#configuration) roles folder <sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]</sup>
    ```sh
    sudo ansible-galaxy install $USER.$ROLE
    ```

    Create a skeleton structure in which you can define a new role
    ```sh
    ansible-galaxy init roles/$ROLE
    ```

    [Log in][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
    ```sh
    ansible-galaxy login
    ```

    [Upload a role][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
    ```sh
    ansible-galaxy import $USERNAME $REPONAME
    ansible-galaxy import --no-wait $USERNAME $REPONAME # send job to background
    ```
