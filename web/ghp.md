#GitHub Pages
[Run your blog on GitHub Pages with Python](https://opensource.com/article/19/5/run-your-blog-github-pages-python#comment-177311)
Requires index.html in the `master` branch of a repository with a specific name: `username.github.io` where {username} is your GitHub username

##Pelican
static site generator that can process markdown (depends on Python Markdown package)
`pelican-quickstart` CLI-based initialization of a pelican project after asking a series of questions
`pelican content -o output -s publishconf.py` generate html files in {output}
  - `-t` specify theme
/content/first-post.md
/content/images/image.jpg
/content/pages/about.md
`pelican-themes -l` list installed themes

## ghp-import
`ghp-import -m "Generate Pelican site" --no-jekyll -b master output`  add contents of {output} directory to {master} branch (still requires `git push`)
