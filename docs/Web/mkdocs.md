Supporting emoji ([src](https://squidfunk.github.io/mkdocs-material/reference/icons-emojis/#emoji))

=== "mkdocs.yml"

```yml
markdown_extensions:
    - pymdownx.emoji: # from https://squidfunk.github.io/mkdocs-material/reference/icons-emojis/#emoji
        emoji_index: !!python/name:materialx.emoji.twemoji
        emoji_generator: !!python/name:materialx.emoji.to_svg
```