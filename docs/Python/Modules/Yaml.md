# Yaml

```sh
pip install pyyaml
```

=== ":material-import: Deserialize"

    ```py hl_lines="5"
    import yaml


    with open('./starships.yaml') as f:
        starships = yaml.safe_load(f)
    ```

    There is a `load` method but it requires specifying [one of four possible values](https://github.com/yaml/pyyaml/wiki/PyYAML-yaml.load(input)-Deprecation) for the **Loader** kwarg.

=== ":material-export: Serialize"

    ```py hl_lines="5"
    import yaml


    with open('./starships.yaml','w') as f:
        yaml.dump(starships, f)
    ```

??? info "Resources"

    - [Introduction to YAML](https://www.cncf.io/blog/2019/02/21/introduction-to-yaml-creating-a-kubernetes-deployment/)

