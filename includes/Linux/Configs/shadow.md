#### /etc/shadow
:   
    Colon-delimited file containing password hashes for every user listed in [/etc/passwd](#etc-passwd)
    
    ```
    #  (1)       (2)         (3)      (4)  (5)  (6)     (7)      (8)
    $USERNAME:$PASSWORD:$LASTCHANGED:$MIN:$MAX:$WARN:$INACTIVE:$EXPIRE
    ```

    1. Login name
    2. Encrypted password; dollar signs delimit encryption hash function then salt, then hash value. After locking the account with **usermod -L**, an exclamation point **!** is placed in front of this field, making the password inoperable and locking the account.  When an account has not yet had a password set, this value is **!!**
        - $1: MD5
        - $2a: Blowfish
        - $2y: Blowfish
        - $5: SHA-256
        - $6: SHA-512, 
    3. Days since 01/01/1970 that password was last changed
    4. Minimum number of days required between password changes
    5. Maximum number of days the password is valid before user is forced to change password
    6. Number of days the password is to expire that user is warned that password must be changed
    7. Number of days after password expires that account is disabled
    8. Days since 01/01/1970 that account is disabled
