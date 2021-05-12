# git


[git-add]: #git-add '```&#10;$ git add &#10;```&#10;Add file contents to the index'
[git-branch]: #git-branch '```&#10;$ git branch &#10;```&#10;List, create, or delete branches'
[git-checkout]: #git-checkout '```&#10;$ git checkout &#10;```&#10;Switch branches or restore working tree files'
[git-cherry-pick]: #git-cherry-pick '```&#10;$ git cherry-pick &#10;```&#10;Apply the changes introduced by some existing commits'
[git-clean]: #git-clean '```&#10;$ git clean &#10;```&#10;Remove untracked files from the working tree'
[git-config]: #git-config '```&#10;$ git config &#10;```&#10;Get and set repository or global options'
[git-log]: #git-log '```&#10;$ git log &#10;```&#10;Show commit logs'
[git-ls-files]: #git-ls-files '```&#10;$ git ls-files &#10;```&#10;Show information about files in the index and the working tree'
[git-mv]: #git-mv '```&#10;$ git mv &#10;```&#10;Move or rename a file, a directory, or a symlink'
[git-push]: #git-push '```&#10;$ git push &#10;```&#10;Update remote refs along with associated objects'
[git-rebase]: #git-rebase '```&#10;$ git rebase &#10;```&#10;Reapply commits on top of another base tip'
[git-remote]: #git-remote '```&#10;$ git remote &#10;```&#10;Manage set of tracked repositories'
[git-reset]: #git-reset '```&#10;$ git reset &#10;```&#10;Reset current HEAD to the specified state'
[git-revert]: #git-revert '```&#10;$ git revert &#10;```&#10;Revert some existing commits'
[git-rm]: #git-rm '```&#10;$ git rm &#10;```&#10;Remove files from the working tree and from the index'
[git-stash]: #git-stash '```&#10;$ git stash &#10;```&#10;Stash changes away in a dirty working directory'

[doc:git-add]: https://git-scm.com/docs/git-add "git add documentation"
[doc:git-branch]: https://git-scm.com/docs/git-branch "git branch documentation"
[doc:git-checkout]: https://git-scm.com/docs/git-checkout "git checkout documentation"
[doc:git-cherry-pick]: https://git-scm.com/docs/git-cherry-pick "git cherry-pick documentation"
[doc:git-clean]: https://git-scm.com/docs/git-clean "git clean documentation"
[doc:git-config]: https://git-scm.com/docs/git-config "git config documentation"
[doc:git-log]: https://git-scm.com/docs/git-log "git log documentation"
[doc:git-ls-files]: https://git-scm.com/docs/git-ls-files "git ls-files documentation"
[doc:git-mv]: https://git-scm.com/docs/git-mv "git mv documentation"
[doc:git-push]: https://git-scm.com/docs/git-push "git push documentation"
[doc:git-rebase]: https://git-scm.com/docs/git-rebase "git rebase documentation"
[doc:git-remote]: https://git-scm.com/docs/git-remote "git remote documentation"
[doc:git-reset]: https://git-scm.com/docs/git-reset "git reset documentation"
[doc:git-revert]: https://git-scm.com/docs/git-revert "git revert documentation"
[doc:git-rm]: https://git-scm.com/docs/git-rm "git rm documentation"
[doc:git-stash]: https://git-scm.com/docs/git-stash "git stash documentation"

[add][git-add] [?][doc:git-add]
[branch][git-branch] [?][doc:git-branch]
[checkout][git-checkout] [?][doc:git-checkout]
[cherry-pick][git-cherry-pick] [?][doc:git-cherry-pick]
[clean][git-clean] [?][doc:git-clean]
[config][git-config] [?][doc:git-config]
[log][git-log] [?][doc:git-log]
[ls-files][git-ls-files] [?][doc:git-ls-files]
[mv][git-mv] [?][doc:git-mv]
[push][git-push] [?][doc:git-push]
[rebase][git-rebase] [?][doc:git-rebase]
[remote][git-remote] [?][doc:git-remote]
[reset][git-reset] [?][doc:git-reset]
[revert][git-revert] [?][doc:git-revert]
[rm][git-rm] [?][doc:git-rm]
[stash][git-stash] [?][doc:git-stash]

#### git clean
[git clean -&#102;]: #git-clean '```&#10;$ git clean -f&#10;```&#10;Remove untracked files without confirmation'
[git clean -&#100;]: #git-clean '```&#10;$ git clean -d $PATH&#10;```&#10;Remove untracked files from the specified directory'
[git clean -&#105;]: #git-clean '```&#10;$ git clean -i&#10;```&#10;Remove untracked files interactively'
[git clean -&#110;]: #git-clean '```&#10;$ git clean -n&#10;```&#10;Perform a dry run'
[git clean -&#120;]: #git-clean '```&#10;$ git clean -x&#10;```&#10;Remove ignored files'
[git clean -&#88;]: #git-clean '```&#10;$ git clean -X&#10;```&#10;Remove only ignored files'

<code>&nbsp;</code>   <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`d`][git clean -&#100;] <code>&nbsp;</code> [`f`][git clean -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> [`i`][git clean -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`n`][git clean -&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`x`][git clean -&#120;] <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`X`][git clean -&#88;] <code>&nbsp;</code> <code>&nbsp;</code> 

#### git add
Add file, located in `$HOME` to the git repo at `$PATH`
```sh
git --git-dir=$PATH.git --work-tree=$HOME add file
```
Update index to include all files in the working tree, including removals
```sh
git add -A
git add --no-ignore-removal
```
Stage all modifications in work-tree, including deletions
```sh
git add -u
```
#### git branch
See a list of branches. 
A "*" indicates that branch is checked out.
```sh
git branch
```
Display the last commit for each branch
```sh
git branch -v
```
Display branches that have not been merged
```sh
git branch --no-merged
```
#### git checkout
Discard unstaged uncommitted changes to file
```sh
git checkout -- file
```
Switch to branch
```sh
git checkout branch
```
#### git cherry-pick
Apply a single, specific commit from another branch
```sh
git cherry-pick commit
```
#### git config
Provides a frontend to the INI formatted config files typically found within `.git/config` (or `~/.gitconfig` when using `--global`)

Set up alias "br" for `branch`
```sh
git config --global alias.br branch
```
Equivalent to:
```ini
[alias]
br = branch
```
Store authentication details in a cache
```sh
git config --global credential.helper cache
```
Equivalent to 
```ini
[credential]
helper = cache
```
#### git log
Show commits between January 1 and January 5, 2016
```sh
git log --after="2016-01-01" --before="2016-01-05"
```
See commits that are on {branch} but not on {master}
```sh
git log master..branch
```
#### git ls-files
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
#### git mv
Move or rename a tracked file
```sh
git mv file
```
#### git push
Transfer data from local branch {master} to remote {origin}
```sh
git push -u origin master
```
#### git rebase
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
#### git remote
Manage repositories whose branches you track
```sh
git remote
```
Add remote repo
```sh
git remote add $REPO $URL
```
Display URL of remote repo
```sh
git remote get-url $REPO
```
Set url for existing repo
```sh
git remote set-url $URL $REPO
```
#### git reset
Undo unstaged changes since last commit
```sh
git reset --hard
```
Reset master to state before last commit
```sh
git reset --hard HEAD~
```
#### git revert
Remove (committed) changes in {commit}
```sh
git revert commit
```
#### git rm
Remove tracked file from repo
```sh
git rm file
```
#### git stash
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
#### Rebasing
Rebase changes committed to `branch` onto <master>
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
Provides a curses-based browser that allows you to navigate the commits in the current branch. 
It is essentially a wrapper around `git log`, and therefore accepts the same arguments that can be passed to it.

| Config file  | Description |
| :----------- | :---------- |
| $HOME/.tigrc |

Browse the commit history for a single {file}
```sh
tig file
```
Browse the commit history for a single {file}, filtering to a specific date range
```sh
tig --after="2017-01-01" --before="2018-05-16" -- README.md
```
Find who made a change toa  file and why
```sh
tig blame file
```
Browse stash
```sh
tig stash
```
Browse refs
```sh
tig refs
```
Navigate the output of `git grep`
```sh
tig grep -i foo lib/Bar
```
Pipe a list of commit IDs to tig
```sh
git rev-list --author=olaf HEAD | tig show --stdin
```