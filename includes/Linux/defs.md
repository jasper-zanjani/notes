## 📘 Glossary

**address space**{: #address-space }
:   An **address space** consists of a set of pages in memory allocated to the process. (ULSAH: 90)

**display manager**{: #display-manager }
:   Basically display managers are the login screens, while the GUI manipulated during normal use represents the desktop environment (i.e. GNOME, KDE, XFCE, etc).

**Mail Delivery Agent**{: #mda }
:   Service that downloads email from an MTA, such as procmail and fetchmail

**Mail Transfer Agent**{: #mta }
:   Email server, such as sendmail, postfix, smail, and qmail

**Mail User Agent**{: #mua }
:   Program that allows a user to view mail, such as mutt, pine, printmail, elm, mail, Thunderbird, Evolution, and Eudora

**Process**{: #process }
:   A process consists of an [address space](#address-space) and a set of data structures within the kernel. 

**qmail**{: #qmail }
:   MTA designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". 
    Its various modular subcomponents run independently and are mutually untrustful. 
    It uses SMTP to exchange messages with other MTAs. 

    It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. 
    qmail was deprecated and removed from Arch repos in 2005.

**thread**{: #thread }
:   A **thread** is an execution context within a [process][#process].

### ⚙&#xfe0f; Configs

**/etc/bluetooth/input.conf**
:   Fix bluetooth mouse constantly disconnecting ([src](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects 'Ask Ubuntu: "Bluetooth mouse constantly disconnects and reconnects"'))
    ```ini
    UserspaceHID=true
    ```

**/etc/bluetooth/main.conf**
:   Power on Bluetooth adapter at startup ([src](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects 'Ask Ubuntu: "Bluetooth mouse constantly disconnects and reconnects"'))
    ```ini
    [Policy]
    AutoEnable=true
    ```

**/etc/group**
:   Colon-delimited file describing group membership
    ```
    $GROUP:$PASSWORD:$GID:$USER1:$USER2:$USER3...
    ```
    /etc/resolv.conf
    Use DNS queries prior to consulting /etc/hosts
    ```sh
    nameserver dns
    nameserver files
    ```

**/etc/shadow**
:   Colon-delimited file containing password hashes for every user listed in [/etc/passwd][/etc/passwd]
    ```
    $USERNAME:$PASSWORD:$LASTCHANGED:$MIN:$MAX:$WARN:$INACTIVE:$EXPIRE
    ```

    - **$USERNAME** Login name
    - **$PASSWORD** Encrypted password; dollar signs delimit encryption hash function ([`$1`](#etcshadow "MD5"), [`$2a`](#etcshadow "Blowfish"), [`$2y`](#etcshadow "Blowfish"), [`$5`](#etcshadow "SHA-256"), or [`$6`](#etcshaodw "SHA-512")), then salt, then hash value. After locking the account with `usermod -L`, an exclamation point `!` is placed in front of this field, making the password inoperable and locking the account.  When an account has not yet had a password set, this value is `!!`
    - **$LASTCHANGED** Days since 01/01/1970 that password was last changed
    - **$MIN** minimum number of days required between password changes
    - **$MAX** maximum number of days the password is valid before user is forced to change password
    - **$WARN** number of days the password is to expire that user is warned that password must be changed
    - **$INACTIVE** number of days after password expires that account is disabled
    - **$EXPIRE** days since 01/01/1970 that account is disabled
