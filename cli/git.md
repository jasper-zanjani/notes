# git

`git --git-dir=gitpath.git --work-tree=pwd add file` : add {file}, located in {pwd} to the git repo at {gitpath}
`git add -A` | `git add --no-ignore-removal` : update index to include all files in the working tree, including removals
`git add -u` : stage all modifications in work-tree, including deletions
`git branch` : see a list of branches; a "*" indicates that branch is checked out; `-v` will display the last commit for each branch; `--no-merged` will display branches that have not been merged
`git checkout -- file` : discard unstaged uncommitted changes to {file}
`git checkout branch` : switch to {branch}
`git cherry-pick commit` : apply a single, specific {commit} from another branch
`git clean` : remove untracked files from local repo
`git clean -f` : delete untracked files in the current directory
`git clean -f -d` : remove untracked directories
`git clean -f -i` : clean working directory interactively
`git config --global alias.br branch` : set up alias "br" for `branch`
`git config --global credential.helper cache` : store authentication details in a cache
`git log --after="2016-01-01" --before="2016-01-05"` : show commits between January 1 and January 5, 2016
`git logs master..branch` : see commits that are on {branch} but not on {master}
`git ls-files --deleted` : show tracked files that have been deleted
`git ls-files` : show tracked files
`git ls-files -z` : show tracked files, each line is terminated by a null byte
`git mv file` : move or rename a tracked file
`git push -u origin master` : transfer data from local branch {master} to remote {origin}
`git rebase` : combine branches by replaying the changes made on one branch to another
`git remote` : manage repositories whose branches you track
`git remote add name url`: add remote repo named {name} at {url}
`git remote get-url repo` : display URL of remote {repo}
`git remote set-url url repo` : set {url} for existing {repo}
`git reset --hard` : undo unstaged changes since last commit
`git reset --hard HEAD~` : reset master to state before last commit
`git revert commit` : remove (committed) changes in {commit}
`git rm file` : remove tracked {file} from repo

##### Example 1
Rebase changes committed to _scrollFix_ onto _master_
```sh
git checkout scrollFix
git rebase master
```
This will rewind _scrollFix_ to the commit shared by the two branches, then applying all changes made subsequently to _master_. 

```sh
git checkout master
git merge scrollFix
```
Now the history will appear as though all changes were made in series, when they were actually made in parallel on separate branches.


#### Move the last commit to a new branch
```sh
git branch test         # create a new branch with current HEAD
git reset --hard HEAD~  # reset master to before last commit 
git checkout test       # continue on new branch
```
