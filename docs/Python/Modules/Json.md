# Json

=== ":material-import: Deserialize"

    ```py
    import json


    with open('starships.json') as f:
        data=json.load(f)
    ```

=== ":material-export: Serialize"

    ```py
    import json


    with open('starships.json',"w") as f:
        json.dump(data,f)
    ```
