#### chage
:   
    ```sh title="Expire password in 30 days"
    chage -E $(date -d +30days +%Y-%m-%d) $USER
    ```