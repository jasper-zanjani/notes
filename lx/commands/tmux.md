### tmux

Configuration files                     | Effect
:---                                    | :---
$HOME/.tmux.conf                        | configuration file

Change prefix to vim-style `$KEYCOMBO` (`C-b` by default)
```sh
set-option -g prefix $KEYCOMBO
```
Name a new session
```sh
tmux new-session -s 'my rails project'
```
