# git

#### Remove untracked files
```sh
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
```sh
git --git-dir=$gitpath.git --work-tree=$HOME add file
```
#### Update index to include all files in the working tree, including removals
```sh
git add -A
git add --no-ignore-removal
```
#### Stage all modifications in work-tree, including deletions
```sh
git add -u
```
#### See a list of branches
A "*" indicates that branch is checked out; 
```sh
git branch

# Display the last commit for each branch
git branch -v

# Display branches that have not been merged
git branch --no-merged
```
#### Discard unstaged uncommitted changes to file
```sh
git checkout -- file
```
#### Switch to branch
```sh
git checkout branch
```
#### Apply a single, specific commit from another branch
```sh
git cherry-pick commit
```
#### Remove untracked files from local repo
```sh
git clean
```
#### Delete untracked files in the current directory
```sh
git clean -f
```
#### Remove untracked directories
```sh
git clean -f -d
```
#### Clean working directory interactively
```sh
git clean -f -i
```
#### Set up alias "br" for `branch`
```sh
git config --global alias.br branch
```
#### Store authentication details in a cache
```sh
git config --global credential.helper cache
```
#### Show commits between January 1 and January 5, 2016
```sh
git log --after="2016-01-01" --before="2016-01-05"
```
#### See commits that are on {branch} but not on {master}
```sh
git logs master..branch
```
#### Show tracked files that have been deleted
```sh
git ls-files --deleted
```
#### Show tracked files
```sh
git ls-files
```
#### Show tracked files, each line is terminated by a null byte
```sh
git ls-files -z
```
#### Move or rename a tracked file
```sh
git mv file
```
#### Transfer data from local branch {master} to remote {origin}
```sh
git push -u origin master
```
#### Combine branches by replaying the changes made on one branch to another
```sh
git rebase
```
#### Manage repositories whose branches you track
```sh
git remote
```
#### Add remote repo named {name} at {url}
```sh
git remote add name url
```
#### Display URL of remote {repo}
```sh
git remote get-url repo
```
#### Set {url} for existing {repo}
```sh
git remote set-url url repo
```
#### Undo unstaged changes since last commit
```sh
git reset --hard
```
#### Reset master to state before last commit
```sh
git reset --hard HEAD~
```
#### Remove (committed) changes in {commit}
```sh
git revert commit
```
#### Remove tracked file from repo
```sh
git rm file
```
#### Stash
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
### Rebase
#### Rebase changes committed to `branch` onto <master>
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
#### Add a change to a previous commit
To add changes to the most recent commit, stage changes as normal (including removals), but when committing use the `--amend` option. This will present an editor, allowing you to edit the commit message, if necessary. [[6](#sources)]
```git
git add README.md
git commit --amend 
```
To add changes to a commit that is not the most recent, a rebase is necessary. First [stash](#stash) the changes to be added, then initiate a rebase and mark the commit to be edited with `edit` or `e`. Leave the other commits alone, save, and drop back to the stash. Pop the stash (`git stash pop`), which will apply the changes stored in the most recent stash. Now you can stage the changes and commit:
```sh
git commit --amend --no-edit
```
Finally, continue the rebase, rewriting the rest of the commits against the new one.
```sh
git rebase --continue
```

#### Split up a commit
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


## Sources
1. "Dealing with line endings". [GitHub Help](https://help.github.com/en/articles/dealing-with-line-endings)
2. "Squash All Commits Related to a Single Issue into a Single Commit". [GitHub](https://github.com/todotxt/todo.txt-android/wiki/Squash-All-Commits-Related-to-a-Single-Issue-into-a-Single-Commit)
3. "Git - Stashing". [git-scm.com](https://git-scm.com/book/en/v1/Git-Tools-Stashing).
4. "4 Useful Solutions to Common Git Problems". [Dev.to](https://dev.to/jacobherrington/4-useful-patterns-in-git-19ac): 2019/08/26.
5. "Code cleanup: splitting `git` commits in the middle of a branch". [Web](https://embeddedartistry.com/blog/2018/2/19/code-cleanup-splitting-up-git-commits-in-the-middle-of-a-branch): 2018/02/19.
6. "How to add a changed file to an older (not last) commit in Git". [StackOverflow](https://stackoverflow.com/questions/2719579/how-to-add-a-changed-file-to-an-older-not-last-commit-in-git).
