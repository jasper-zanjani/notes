# Git

Git is a very complex utility with multiple commands and subcommands and a strong dependency on **version control system** concepts.

The most basic useful command may be **clone** which simply downloads a repository.
```sh
git clone https://gitlab.gnome.org/GNOME/gtk.git

# The depth of the tree can be specified, and various configuration parameters can be passed with -c
git clone https://gitlab.gnome.org/GNOME/gtk.git --depth 1 -c http.sslVerify=false
```

Add file, located in `$HOME` to the git repo at `$PATH`

```sh
git --git-dir=$PATH.git --work-tree=$HOME add file
```

```sh
# Update index to include all files in the working tree, including removals
git add -A # --no-ignore-removal

# Stage all modifications in work-tree, including deletions
git add -u
```

See a list of branches. 
A "*" indicates that branch is checked out.
```sh
git branch
```

```sh
# Display the last commit for each branch
git branch -v

# Display branches that have not been merged
git branch --no-merged
```

```sh
# Discard unstaged uncommitted changes to file
git checkout -- file

# Switch to branch
git checkout branch
```

Apply a single, specific commit from another branch
```sh
git cherry-pick commit
```

Provides a frontend to the INI formatted config files typically found within `.git/config` (or `~/.gitconfig` when using `--global`)

```sh
# Set up alias "br" for `branch`
git config --global alias.br branch # (1)

# Store authentication details in a cache
git config --global credential.helper cache # (2)
```

1. Equivalent to:
```ini
[alias]
br = branch
```
1. Equivalent to 
```ini
[credential]
helper = cache
```

Show commits between January 1 and January 5, 2016
```sh
git log --after="2016-01-01" --before="2016-01-05"
```

See commits that are on {branch} but not on {master}
```sh
git log master..branch
```

Show tracked files
```sh
git ls-files
```

Show tracked files, each line is terminated by a null byte
```sh
git ls-files -z
```

Show tracked files that have been deleted
```sh
git ls-files --deleted
```

Move or rename a tracked file
```sh
git mv file
```

Transfer data from local branch {master} to remote {origin}
```sh
git push -u origin master
```

To add changes to a commit that is not the most recent, a rebase is necessary. 
First [stash](#stash) the changes to be added, then initiate a rebase and mark the commit to be edited with `edit` or `e`. 
Leave the other commits alone, save, and drop back to the stash. 
Pop the stash (`git stash pop`), which will apply the changes stored in the most recent stash. 
Now you can stage the changes and commit:
```sh
git commit --amend --no-edit
```

Finally, continue the rebase, rewriting the rest of the commits against the new one.
```sh
git rebase --continue
```

Combine branches by replaying the changes made on one branch to another
```sh
git rebase
```

Add remote repo
```sh
git remote add $REPO $URL
```

```sh
# Display URL of remote repo
git remote get-url $REPO

# Set url for existing repo
git remote set-url $URL $REPO
```

Undo unstaged changes since last commit
```sh
git reset --hard
```

Reset master to state before last commit
```sh
git reset --hard HEAD~
```

Remove (committed) changes in {commit}
```sh
git revert commit
```

Remove tracked file from repo
```sh
git rm file
```

Stash changes to work-tree
```bash
git stash
```
View stashes in stash stack
```bash
git stash list
```
Apply changes in most recent stash
```bash
git stash apply
```
Apply changes in stash `$STASH`
```bash
git stash apply stash@$STASH
```

## Tasks

#### Existing codebase
:   
    An existing directory can be turned into a repo.

    ```sh
    git init

    # Define an upstream repo
    git remote add origin $REPO

    # Before a first commit, the global email and user name must be set.
    git config --global user.name $NAME
    git config --global user.email $EMAIL

    # Add and commit as normal
    git add .
    git commit -m $MESSAGE

    # The first push must have the upstream repo set
    git push --set-upstream origin master
    ```

#### Rebasing
:   

    Rebase changes committed to branch onto MASTER

    ```sh
    git checkout $BRANCH
    git rebase $MASTER
    ```

    This will rewind $BRANCH to the commit shared by the two branches, then applying all changes made subsequently to $MASTER. 

    ```sh
    git checkout <master>
    git merge <branch>
    ```
    Now the history will appear as though all changes were made in series, when they were actually made in parallel on separate branches.
    Move the last commit to a new branch
    ```sh
    git branch test         # create a new branch with current HEAD
    git reset --hard HEAD~  # reset master to before last commit 
    git checkout test       # continue on new branch
    ```
    Line endings
    Git will automatically append CRLF endings on Windows. This setting can be displayed with the following command:
    ```bash
    git config core.autocrlf
    ```
    In order to disable this, adjust the setting
    ```bash
    git config core.autocrlf false
    ```

#### Squashing
:   
    Sometimes many commits are made to resolve a single issue. These should be "squashed". To squash the last 4 commits:
    ```bash
    git rebase -i HEAD~4
    ```
    This will open a text editor where you will have to select what to do with each of the 4 commits. Most recent commits are at the bottom, and at least the top (oldest) commit has to remain "pick" in order to squash the others.
    The repo will have to be force-pushed once these changes have been made. 
    ```bash
    git push --force
    ```
    To add changes to the most recent commit, stage changes as normal (including removals), but when committing use the `--amend` option. This will present an editor, allowing you to edit the commit message, if necessary. [[6](#sources)]
    ```git
    git add README.md
    git commit --amend 
    ```
    To split up `$COMMIT`
    ```sh
    git rebase -i "$COMMIT"^ # Start a rebase at the commit you want to split
    ```
    Mark the commit to be split with `edit`. Now reset state to the previous commit
    ```sh
    git reset HEAD^
    ```
    The files are presented unstaged, and can be added to new commits as needed. Finally, finish the rebase
    ```sh
    git rebase --continue
    ```

#### tig
:   
    Provides a curses-based browser that allows you to navigate the commits in the current branch. 
    It is essentially a wrapper around `git log`, and therefore accepts the same arguments that can be passed to it.
    Tig's config is at **~/.tigrc**.

    ```sh
    # Browse the commit history for a single file
    tig $FILE

    # Filter commits to a date range
    tig --after="2017-01-01" --before="2018-05-16" -- $FILE

    # Find who made a change to a file and why
    tig blame $FILE

    # Browse stash
    tig stash

    # Browse refs
    tig refs

    # Navigate the output of git grep
    tig grep -i foo lib/Bar

    # Pipe a list of commit IDs to tig
    git rev-list --author=olaf HEAD | tig show --stdin
    ```