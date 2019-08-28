# YAML
  - superset of JSON, and rapidly becoming its replacement
  - commonly used for configuration files
  - Two types of structures: Lists and Maps (key-value pairs)
  - indentation levels are significant

#### YAML Syntax
Syntax        | Effect
:---          | :---
`---`         | separator, optional
`key: value`  | key-value pair format (like JSON but without quotes or enclosing braces)
`- list-item` | Markdown-style lists preceded by a hyphen (also no quotes or brackets)

## Python
#### Import YAML parser package
```py
import ruamel.yaml
```
#### Workhorse function
```py
yaml = ruamel.yaml.YAML()
```
#### Print all `data` to stdout
```py
yaml.dump(data,sys.stdout)
```
#### Write `data` to `f`
```py
yaml.dump(data,f)
```
#### Adjust indentation levels
```py
yaml.indent(mapping=4,sequence=6,offset=3)
```
## Sources
  - "Introduction to YAML". [CNCF](https://www.cncf.io/blog/2019/02/21/introduction-to-yaml-creating-a-kubernetes-deployment/)