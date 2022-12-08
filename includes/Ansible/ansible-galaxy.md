#### ansible-galaxy
:   

    ```sh
    # Log in
    ansible-galaxy login
    
    # Search for roles
    ansible-galaxy search $ROLE

    # Install a role made publicly available by a user
    sudo ansible-galaxy install $USER.$ROLE

    # Initiate the skeleton structure of a role
    ansible-galaxy init $ROLENAME

    # Upload a role
    ansible-galaxy import $USERNAME $REPONAME
    ansible-galaxy import --no-wait $USERNAME $REPONAME # send job to background
    ```
