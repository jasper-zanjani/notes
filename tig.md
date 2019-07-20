# tig
##### Config: $HOME/.tigrc 

Provides a curses-based browser that allows you to navigate the commits in the current branch. It is essentially a wrapper around `git log`, and therefore accepts the same arguments that can be passed to it.

Syntax  | Effect
:---    | :---
`tig file` | browse the commit history for a single {file}
`tig --after="2017-01-01" --before="2018-05-16" -- README.md` | browse the commit history for a single {file}, filtering to a specific date range
`tig blame file` | find who made a change toa  file and why
`tig stash` | browse stash
`tig refs` | browse refs
`tig grep -i foo lib/Bar` | navigate the output of `git grep`
`git rev-list --author=olaf HEAD | tig show --stdin` | pipe a list of commit IDs to tig






## Sources
  - "How to use Tig to browse Git logs". [opensource.com](https://opensource.com/article/19/6/what-tig)
