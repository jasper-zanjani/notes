#### curl
:   
    Accept a self-signed certificate by skipping verification
    ```sh
    curl -k https://192.168.1.10
    ```

    Use the [ `dict` network protocol ](https://tools.ietf.org/html/rfc2229) to retrieve the definition of a word.
    [ref](https://fedoramagazine.org/set-up-an-offline-command-line-dictionary-in-fedora/)
    ```sh
    curl dict://dict.org/d:<word>
    ```
    Sending a POST method to a FastAPI app ([src](https://app.pluralsight.com/guides/explore-python-libraries:-fastapi))
    ```sh
    curl -X POST "http://127.0.0.1:8000/purchase/item/" -H "accept: application/json" -H "Content-Type: application/json" -d "{\"name\":\"sample item\",\"info\":\"This is info for the item\",\"price\":40,\"qty\":2}"
    ```
