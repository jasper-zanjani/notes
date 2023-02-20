Fish [switch statements](https://fishshell.com/docs/current/cmds/case.html) look completely different from bash case statements, with an incompatible syntax.

```sh title="Conditionally setting $PATH:"
switch "$PATH" # (1)
    case "*$HOME/.cargo/bin*" # (2)
        echo '$PATH already contains $HOME/.cargo/bin' # (3)
    case '*'
        set --global PATH $HOME/.cargo/bin $PATH # (4)
end # (5)
```

1. Because the $PATH is rendered as a list delimited by whitespace, without quotes this statement will be expanded to many arguments and will produce an error.
2. Double quotes must be used, because with single quotes fish will not expand the $HOME variable.
3. I have not found an empty placeholder similar to **`pass`** in Python which could simply occupy space here. 
Without a statement, fish appears to execute the following block by default.
4. Environment variables use the [**set**](https://fishshell.com/docs/current/cmds/set.html#cmd-set) keyword.
The **--universal** option, which would otherwise make sense here, does not work because $PATH is a global variable.
Note that there is no equal sign, only a space separating the variable identifier and value.
5. 
```sh title="Bash equivalent"
case ":${PATH}:" in
    *:"$HOME/.cargo/bin":*)
        ;;
    *)
        export PATH="$HOME/.cargo/bin:$PATH"
        ;;
esac
```

```sh title="Setting environment variables"
set -x EDITOR /usr/bin/vim # (1)
```

1. Without **-x** this variable will not be visible to applications.
```sh title="Bash equivalent"
export EDITOR=/usr/bin/vim
```

Fish [**for-in loops**](https://fishshell.com/docs/current/cmds/for.html) are concluded with **end**.
```sh title="Set metadata in a loop"
for i in $(exa Godfrey*)
    echo Processing $i
    set title $(string replace -r "\(.*mp3$" "" $i) # (1)
    ffmpeg -i $i -metadata title="$title" -metadata album="Godfrey" -metadata artist="Vlad TV" -codec copy output/$i
end
```

1. [**string replace**](https://fishshell.com/docs/current/cmds/string.html?highlight=string#replace-subcommand) is used here to remove the ending of a filename, including extension.