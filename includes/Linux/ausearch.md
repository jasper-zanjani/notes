**ausearch**{: #ausearch }
:   Display audit logs from `$STARTDATE` to `$ENDDATE`
    ```sh
    ausearch --start $STARTDATE --end $ENDDATE
    ```
    Search audit logs for today for logins of UID 500
    ```sh
    ausearch --start today --loginuid 500
    ```