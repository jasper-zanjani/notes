Generate a public and private ("secret") key pair ("keyring") after displaying interactive prompts to the user, who must enter real name and email address and specify variables like key length, encryption algorithm etc.
```sh
gpg --full-generate-key
gpg --generate-key # (1)
```

1. Generate a new keyring using current default parameters.

The rngd daemon found in the **rng-tools** package can be enabled for additional entropy if needed by the system.
```sh
pacman -S community/rng-tools
```

The generates a public and private key in **~/.gnupg**.
The public key, which can be distributed publicly so that people can encrypt messages to the user, is named **pubring.kbx**
More than one master keypair can be generated in this manner, even for the same email address.