# YAML
  - superset of JSON, and rapidly becoming its replacement
  - commonly used for configuration files
  - Two types of structures: Lists and Maps (key-value pairs)
  - indentation levels are significant
  - [CNCF](https://www.cncf.io/blog/2019/02/21/introduction-to-yaml-creating-a-kubernetes-deployment/)
`---`
  separator, optional
`key: value`
  key-value pair format (like JSON but without quotes or enclosing braces)
`- list-item`
  Markdown-style lists preceded by a hyphen (also no quotes or brackets)
## Python
`import ruamel.yaml`
  import YAML parser package
`yaml = ruamel.yaml.YAML()`
  workhorse function
`yaml.dump(data,sys.stdout)`
  print all `data` to stdout
`yaml.dump(data,f)`
  write `data` to `f`
`yaml.indent(mapping=4,sequence=6,offset=3)`
  adjust indentation levels
