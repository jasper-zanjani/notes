# Mkdocs Material

#### mkdocs.yml

```yml
site_name: Notes
theme:
    name: material
    features:
        - content.code.annotate # (1)
    palette:
        scheme: default
        primary: white
markdown_extensions:
    - admonition
    - attr_list # (5)
    - md_in_html
    - pymdownx.snippets # (2)
    - pymdownx.details
    - pymdownx.tabbed: # (4)
        alternate_style: true
    - pymdownx.superfences: # (3)
        custom_fences:
            - name: mermaid
              class: mermaid
              format: !!python/name:pymdownx.superfences.fence_code_format
```

1. This is a [code annotation](https://squidfunk.github.io/mkdocs-material/reference/code-blocks/?h=content+code+annotate#code-annotations)
2. [Snippets](https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown-extensions/?h=snippets#snippets) allow inclusions to be made from other files.
3. [Superfences](https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown-extensions/?h=snippets#superfences) allow code blocks to be palced inside tabs and admonitions.
4. [Tabbed](https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown-extensions/?h=snippets#tabbed) allows tabs. Note that the **alternate\_style** configuration is the only supported style and is required.
5. [Attribute lists](https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown/#attribute-lists) are necessary for [image alignment](https://squidfunk.github.io/mkdocs-material/reference/images/#image-alignment).

#### Audio

[Audio clips](https://github.com/squidfunk/mkdocs-material/discussions/4149) require the **md\_in\_html** extension.
Keep in mind that the filename of the audio will be appended to the route of the current page.

'''md 
<audio controls="controls"><source type="audio/mp4" src="gabriela.m4a"></source></audio>
'''