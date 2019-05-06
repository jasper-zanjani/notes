# git

`git branch`: see a list of branches; a "*" indicates that branch is checked out; `-v` will display the last commit for each branch; `--no-merged` will display branches that have not been merged
`git cherry-pick commit` apply a single, specific {commit} from another branch
`git config --global alias.br branch`: set up alias "br" for `branch`
`git rebase`: combine branches by replaying the changes made on one branch to another

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



