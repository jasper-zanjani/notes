# git

#### Remove untracked files
```
# Perform a "dry run" with `-n` to show what files and directories will be deleted
git clean -d -n

# Interactively delete files with `-i`
git clean -d -i

# Force delete with `-f`
git clean -d -f

# Limit clean operation to directory $DIR
git clean -d $DIR

# Remove ignored files and directories with `-x`
git clean -d -x

# Remove **only** ignored files and directories with `-X`
git clean -d -X
```
#### Add file, located in $HOME to the git repo at gitpath
```
git --git-dir=$gitpath.git --work-tree=$HOME add file
```
#### Update index to include all files in the working tree, including removals
```
git add -A
git add --no-ignore-removal
```
#### Stage all modifications in work-tree, including deletions
```
git add -u
```
#### See a list of branches
A "*" indicates that branch is checked out; 
```
git branch

# Display the last commit for each branch
git branch -v

# Display branches that have not been merged
git branch --no-merged
```
#### Discard unstaged uncommitted changes to file
```
git checkout -- file
```
#### Switch to branch
```
git checkout branch
```
#### Apply a single, specific commit from another branch
```
git cherry-pick commit
```
#### Remove untracked files from local repo
```
git clean
```
#### Delete untracked files in the current directory
```
git clean -f
```
#### Remove untracked directories
```
git clean -f -d
```
#### Clean working directory interactively
```
git clean -f -i
```
#### Set up alias "br" for `branch`
```
git config --global alias.br branch
```
#### Store authentication details in a cache
```
git config --global credential.helper cache
```
#### Show commits between January 1 and January 5, 2016
```
git log --after="2016-01-01" --before="2016-01-05"
```
#### See commits that are on {branch} but not on {master}
```
git logs master..branch
```
#### Show tracked files that have been deleted
```
git ls-files --deleted
```
#### Show tracked files
```
git ls-files
```
#### Show tracked files, each line is terminated by a null byte
```
git ls-files -z
```
#### Move or rename a tracked file
```
git mv file
```
#### Transfer data from local branch {master} to remote {origin}
```
git push -u origin master
```
#### Combine branches by replaying the changes made on one branch to another
```
git rebase
```
#### Manage repositories whose branches you track
```
git remote
```
#### Add remote repo named {name} at {url}
```
git remote add name url
```
#### Display URL of remote {repo}
```
git remote get-url repo
```
#### Set {url} for existing {repo}
```
git remote set-url url repo
```
#### Undo unstaged changes since last commit
```
git reset --hard
```
#### Reset master to state before last commit
```
git reset --hard HEAD~
```
#### Remove (committed) changes in {commit}
```
git revert commit
```
#### Remove tracked file from repo
```
git rm file
```
### Stash
#### Stash changes to work-tree
```bash
git stash
```
#### View stashes in stash stack
```bash
git stash list
```
#### Apply changes in most recent stash
```bash
git stash apply
```
#### Apply changes in stash <n>
```bash
git stash apply stash@{n}
```
#### Rebase changes committed to <branch> onto <master>
```sh
git checkout branch
git rebase master
```
This will rewind {branch} to the commit shared by the two branches, then applying all changes made subsequently to {master}. 
```sh
git checkout <master>
git merge <branch>
```
Now the history will appear as though all changes were made in series, when they were actually made in parallel on separate branches.
#### Move the last commit to a new branch
```sh
git branch test         # create a new branch with current HEAD
git reset --hard HEAD~  # reset master to before last commit 
git checkout test       # continue on new branch
```
#### Line endings
Git will automatically append CRLF endings on Windows. This setting can be displayed with the following command:
```bash
git config core.autocrlf
```
In order to disable this, adjust the setting
```bash
git config core.autocrlf false
```
#### Squashing commits
Sometimes many commits are made to resolve a single issue. These should be "squashed". To squash the last 4 commits:
```bash
git rebase -i HEAD~4
```
This will open a text editor where you will have to select what to do with each of the 4 commits. Most recent commits are at the bottom, and at least the top (oldest) commit has to remain "pick" in order to squash the others.
The repo will have to be force-pushed once these changes have been made. 
```bash
git push --force
```
#### Add a change to the latest commit
Useful when you forget to stage a change
```git
git add README.md
git commit --amend 
```
## Sources
  1. "Dealing with line endings". [GitHub Help](https://help.github.com/en/articles/dealing-with-line-endings)
  2. "Squash All Commits Related to a Single Issue into a Single Commit". [GitHub](https://github.com/todotxt/todo.txt-android/wiki/Squash-All-Commits-Related-to-a-Single-Issue-into-a-Single-Commit)
  3. "Git - Stashing". [git-scm.com](https://git-scm.com/book/en/v1/Git-Tools-Stashing).
  4. [Dev.to](https://dev.to/jacobherrington/4-useful-patterns-in-git-19ac)