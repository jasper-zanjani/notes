# sed and awk

## Chapter 1: Power tools for editing
sed and awk are 
  - power tools for editing text files, essential for professional work
  - peculiar and require time to learn
  - useful for making repetitive edits to multiple text files
sed is a non-interactive, stream-oriented editor
  - input flows through the program and is directed to stdout
  - input can be from stdin or (more typically) from a file
sed commands are a sequence of actions, similar to simple shell scripts
  - most of these actions could be done manually within `vim`
  - non-interactive nature of sed means that many edits can be programmed prescriptively and then executed at once, across many files
  - usually invoked from a "shell wrapper" (script)
awk
  - more programmatical than sed
  - typically used to produce a formatted report from structured data
  - extends the idea of text editing into computation
4 challenges in mastering sed and awk
  1. mechanics, which fortunately are similar to one another
  2. regex, which itself has an arcane syntax
  3. interacting with the shell, which shares some special characters with both programs; use single-quotes to contain the script that is being run
  4. knack of script-writing

## Chapter 2: Understanding basic operations
awk descends from sed and `grep`, and further back to `ed`, the original UNIX line editor, which is also the ancestor to `vim` through `ex`
### ed
`ed test`
: open file `test`; outputs the number of characters in the file; positions cursor at the last line
`ed test < ed-script`
: ed can also run off of commands placed in a script
`p`
: "print"; displays current line
`1`
: navigates to line number '1'; prints that line
`d`
: delete current line
`/regular/d`
: delete the first line with the word 'regular' in it
`g/regular/d`
: delete _all_ lines with the word 'regular' in them (`g` for 'global')
`[address]s/pattern/replacement/flag` substitution command pattern
: replace {pattern} with {replacement} at {address}
: if no address is specified then the substitution takes place on the first instance of the _current_ line
: origin of the command `grep` (`g/re/p`)
`s/regular/complex`
: with no address specified, it affects only the first occurrence of 'regular' on the _current_ line
`s/regular/complex/g`
: change all occurrences on the _current_ line
`/regular/s/regular/complex/g`
  - affect the first line that matches the address (first `/regular`)
  - rest of command specifies the substitution to be performed on this line
`g/regular/s/regular/complex/g`
  - replace all occurrences on all lines
`g/regular expression/s/regular/complex/g`
  - replace the 'regular' in 'regular expression' with 'complex'

### comparison between text editors
#### ed
  - edits original file
  - scripts must include commands to save changes and exit the editor
#### sed 
  - made as a special-purpose editor meant to execute scripts exclusively
  - all output goes to stdout by default
  - input file not changed
  - supports additional commands in scripts
#### awk
  - also a stream-oriented editor
  - replaces the line-editor command set with an entire programming language modeled on C
  - `/regular/ {print}` concept of addressing is carried over

### command-line syntax
`command [options] script filename` 
  - command-line syntax is common to sed and awk
  - `script` specifies what instructions to perform; must be single-quoted if it contains characters that can be interpreted by the shell (space, $, * etc)
  - `-f` option, common to sed and awk, specifies name of a script file
each `instruction` has two parts:
  - `pattern` regex delimited with slashes
  - `procedure` actions to be performed
  - editor will apply each instruction in turn to each line of input; if the `pattern` does not match, the `procedure` is ignored

### sed
`sed [-e] 'instruction' file` : `-e` option is necessary only when more than one instruction is supplied on the CL
`sed 's/MA/Massachusetts/' list` expand `MA` to `Massachusetts`
3 ways to specify multiple instructions on the CL
  1. `sed 's/MA/Massachusetts/; s/PA/Pennsylvania/' list` semicolon within a single-quoted instruction sequence
  2. `sed -e 's/MA/Massachusetts/' -e 's/PA/Pennsylvania/' list` precede each separate single-quoted instructions with `-e`
  3. press enter after the first quote to enter multiline entry mode
`sed -f script file` : `-f` flag requires a script file be specified
`sed -f sedscr list > newlist`
: redirect output to a file to save changes; do not redirect to the file you are editing or it will be truncated while it is being read ("clobbered")
`sed -n -e 's/MA/Massachusetts/p' list`
: `-n` flag suppresses automatic output, which is the default behavior; now each instruction intended to produce output must explicitly call the `p` command

### awk
`awk 'instructions' files`
`awk -f script files`
: `-f` flag also works for awk
`awk '{ print $1 }' list`
: print the first field of each line in the input file
`awk '/MA/' list`
`awk '/MA/ {print $1}' list`
`awk -F, '/MA/ { print $1 }' list`
: `-F` flag is followed by field separator
`awk -F, '{ print $1; print $2; print $3 }' list`
`free -h | awk '/^Mem:/ {print $3 "/" $2}` 
: pipe output of `free` to `awk` to get free memory and total memory
`sensors | awk '/^temp1/ {print $2}`
: pipe output of `sensors` to `awk` to get CPU temperature
`ps axch -o cmd,%mem --sort=-%mem | sed 11q`
: pipe output of `ps` to `sed`, displaying top 10 memory-intensive processes
`ps axch -o cmd:15,%cpu --sort=-%cpu | sed 11q`
: pipe output of `ps` to `sed`, displaying top 10 CPU-intensive processes
