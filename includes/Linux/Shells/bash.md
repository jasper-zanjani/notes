The systemwide config for bash is at **/etc/profile**.

Command-line arguments are available as the positional arguments **`$1`**, **`$2`**, etc. with the script itself being **`$0`**.
Handling command-line arguments is conventionally done with the **shift** command in a `while` loop.

```sh title="Conditionally setting $PATH"
--8<-- "includes/Linux/Shells/scripts/path.sh"
```

The **shopt** internal command is used to set (**-s**) or unset (**-u**) various shell settings.

```sh title="Disable case sensitivity"
shopt -s nocasematch
```

```sh title="Tag audio with metadata"
--8<-- "includes/Linux/Shells/scripts/tag.sh"
```

A more useful and less brittle version of this script may be possible using the **getopts** function to define a named parameter, rather than forcing the first positional argument to be one of a number of set values.