#### pass
:   
    The [standard unix password manager](https://www.passwordstore.org/), backed by GPG, is a command-line password manager and MFA program.

    The first step in using pass is generating a new key pair. 
    
    --8<-- "includes/Linux/Tasks/gpg.md"

    ```sh title="Display public keys"
    gpg -k # --list-keys
    ```

    Unwanted keys can be deleted by specifying the public key:
    ```sh
    gpg --delete-secret-and-public-keys ▒▒▓░░▒▓░▓░▓░▓▒░░▒▒░░░▒▓░▒░▒░▓░▒▒▒▓▒▒▓░▓▒░
    ```

    Now a password store can be initialized by providing that same email address.
    This email is stored at **~/.password-store/.gpg-id**
    ```sh
    pass init email@example.com
    ```

    ```sh title="Add password"
    pass add email
    ```

    This produces a binary, encrypted file at **~/.password-store/email.gpg**.
    The password can be retrieved, after authenticating with the master password, with the following:
    ```sh
    pass email # (1)
    ```

    1. In fact, because this is simply a GPG encrypted file, GPG could be used equivalently. In fact, this appears to be the command executed by the pass shell script.
    ```sh
    gpg -dq ~/.password-store/email.gpg
    ```


    ```sh title="Display names of passwords"
    pass ls # (1)
    ```

    1. This command is equivalent to using **tree** on the password store directory.
    ```sh
    tree ~/.password-store
    ```

    Pass can also handle OTP generation for MFA, as long as you can retrieve the OTP URI (beginning with otpauth://). QR code images can be deciphered to retrieve these URIs.
    ```sh
    pass otp add 
    ```

    ??? info "Resources"

        [Luke Smith video](https://www.youtube.com/watch?v=sVkURNfxPd4)
