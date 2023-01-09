# CI/CD

## Github Actions

All that's needed is a yaml file in **.github/workflows** with the following keys:
<sup>[YouTube](https://www.youtube.com/watch?v=7aBjzZkaGhU)</sup>
- `name`
- `on`
- `jobs`

In order to use the 
Python projects need to have a **.spec** file 

GitHub actions can be either Docker or JavaScript

```yaml
name: Build and publish presentation with reveal-md
on: push
jobs:
  release:
    name: Build & Publish
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v1
      - name: Install dependencies and build presentation
        run: | 
          sudo npm install -g reveal-md --unsafe-perm
          sudo reveal-md Presentation.md --static _site --highlight-...


```
#### on

<sub>[src](https://github.com/JackMcKew/pandas_alive/blob/main/.github/workflows/update-readme.yml)</sub>
```yaml
on:
  push:
    branches:
      - main
```

#### jobs

<sub>[src](https://github.com/JackMcKew/pandas_alive/blob/main/.github/workflows/update-readme.yml)</sub>

```yaml
jobs:
  release:
    if: github.actor == 'JackMcKew' && startsWith(github.event.head_commit.message, 'Update README')
    name: Build
    runs-on: ubuntu-latest
    steps:

    - uses: actions/checkout@v1
    - name: Set up Python 3.7
      uses: actions/setup-python@v1
      with:
        python-version: 3.7

    - name: Install dependencies & Convert README.ipynb
      run: |
        python -m pip install --upgrade pip
        pip install -r requirements.txt
        jupyter nbconvert --template "pythoncodeblocks.tpl" --ClearMetadataPreprocessor.enabled=True --ClearOutput.enabled=True  --to markdown README.ipynb
    - name: Commit files
      run: |
        git config --local user.email "action@github.com"
        git config --local user.name "GitHub Action"
        git add README.md
        git commit -m "Convert README.ipynb to README.md" -a
    - name: Push changes
      if: success()
      uses: ad-m/github-push-action@master
      with:
        branch: main
        github_token: ${{ secrets.ACCESS_TOKEN }}
```
