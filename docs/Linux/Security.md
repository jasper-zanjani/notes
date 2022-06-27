# Security

## GPG

GPG keys are used to sign packages and repos.
For example, [yum](../Package/#dnf) repos and [apt](../Package/#apt-key) incorporate APIs and handle GPG keys.

The **KWallet Manager** and [**GNOME Keyring**](https://wiki.gnome.org/Projects/GnomeKeyring) (Seahorse) applications can also be used to manage GPG keys.

## PAM

**Pluggable authentication modules** form an authentication framework that can be used by "PAM-aware applications".
These applications have config files that are found in **/etc/pam.d**
The various pam modules have man pages prefixed with **pam\_**, i.e. "pam\_wheel" etc.

## Commands

--8<--
includes/Linux/Commands/gpg.md

includes/Linux/Commands/pass.md

--8<--
