# 🦪 Perl

Perl6 offers an interactive shell, but previous versions needed a specialized command to be run through the interpreter

General syntax
- Semicolons terminate lines
- Whitespace is irrelevant, except inside strings
- Enclosing function arguments in parentheses is optional

Inline execution of code

Compare similar syntax for sed (MP:17, YUG:614)
```sh
perl6 -e 'code'
```
Enable warning messages
```sh
perl6 -w
```
Request an implicit input-reading loop that stores records in `$_`
```sh
perl6 -n
```
Request an implicit input-reading loop that stores records in `$_` and automatically prints that variable after optional processing of its contents
```sh
perl6 -p
```

`-l`
:automatically insert an output record separator at end of the output of `print`

`-0digits`
: define the character that marks the end of an input record, using octal digits

Shebang
```perl
#!/usr/bin/env perl`
```


Perl variables are of three types, associated with 3 corresponding sigils which begin the identifiers
  - Scalars: `$`
  - Arrays: `@`
  - Hashes (associative arrays): `%`

**`my`** declares and initializes a variable. 
Variables can be typed by placing a type between `my` and the identifier.
```pl
my $animal = "camel"
my Str $animal = "camel"
```


Predefined variables
```pl
$.    # current line number
$_    # conventionally used as a default pattern space for searches; is already initialized but not defined; does **not** function like in bash
$[    # current array base subscript (0 by default)
$/    # input line separator (newline by default)
@ARGV # arguments passed from the command-line; index 0 is the first **additional** argument passed subsequent to the name of the script
```

Sources:

- [Python to Perl6 - nutshell](https://docs.perl6.org/language/py-nutshell)

### Scalar

#### Operations
`$pbj = 'peanut butter'.' and '.'jelly'`
: string concatenation was performed with `.` operator in Perl5 (YUG:617)

`$pbj = 'peanut butter'~' and '~'jelly'`
: string concatenation now performed with `~` operator in Perl6

`print '*' x 40`
: `x` operator repeats the string (YUG:617)

### Array
`my @array = (element, element, element)` | `my @array = element, element, elmeent`
: initialize arrays by (optionally) enclosing elements in parentheses (not brackets)

`@array[n]`
: retrieve element at (0-based) index {n}

`$matrix[0]->[0]`
: arrow or infix operator can also be used to dereference array refrences

`$#array`
: return number of the last subscript in the array (effectively length-1)

```perl
@colors=('red','green','yellow','orange');
($c[0], $c[1], $c[3], $c[5]) = @colors;
```
: arrays can be declared by initializing constituent elements (array slicing) (PBX:85)

#### Operations
`@list=(2..10);`
: assign a range of numbers (arr-rng) (PBX:81)

`@letters=( 'A' .. 'Z' );`
: assign a range of letters (PBX:82)

`my @biglist = |@smalllist, |@littlelist`
: array unpacking is done using the `|` prefix operator, allowing for concatenation

### Hash
Hashes are key-value pairs
`my %fruits = (apple => red, ...)`
: declare a hash

`%fruits{'apple'}`
: values are obtained by referencing the key in curly braces (vice brackets) (p6)

## Functions
`defined`
: return 1 if the variable passed as argument has a value and null if it does not

`die mesg`
: print {mesg} and exit; used to implement error-handling

`join` (YUG...)

`print`
: print to STDOUT, but with no ending string specified

`prompt`
: take input from STDIN

`read filehandle, variable, n`
: read {n} bytes into {variable} from {filehandle} (deprecated in Perl6) (PBX:96)

`say`
: print to STDOUT, but with a newline at the end (Perl6)

`undef`
: undefine a defined variable, releasing the memory allocated for it

### Arrays
`pop @array`
: remove and return last element of {array}

`push @array, elements`
: append {elements} to {array}

`shift @array`
: remove and return first element of {array}

`splice @array, index, n[, elements]`
: remove {n} {elements} from {array}, starting at {index}; or, add {elements} to {array} at {index}

`unshift @array, elements`
: prepend elements to an array (on the left side)

### Strings
`chomp`
: remove last character from a scalar or last character from each word in an array if and only if that character is the input line separator

`chop`
: remove last character from a scalar or last character from each word in an array; intended for use in removing newlines

`s/pattern/substitution/g ;`
: substitution command works similar to sed

`tr/regex1/regex2/ ;`
: replace instances of {regex1} with {regex2}; like replacing lowercase letters with uppercase

`split /delim/`

### Hashes
`keys(%hash) ;`
: return an array of the keys of {hash}

`values(%hash) ;`
: return an array of the values of {hash}

## Filehandles
`<>`
: null filehandle (YUG:618)

`INFILE`
: filehandle used when opening a file for input (YUG:632)

`OUTFILE`
: filehandle used when opening a file for writing

`STDIN`
: deprecated in Perl6 (PBX:96)

## Special literals
These have been deprecated in Perl6 (PBX:51)

`__LINE__` (Perl5) | `$?LINE` (Perl6)
: current line number

`__FILE__` (Perl5) | `$?FILE` (Perl6)
: current filename

`__END__`
: logical end of the script (\004 in Unix and \032 in Windows)

`__DATA__`
: special filehandle

`__PACKAGE__` (Perl5) | `$?PACKAGE` (Perl6)
: current package; default package is main

## Control flow

### Loops
`for @array { action }` | deprecated: `foreach $var (@arr) { statements}` 
: `foreach` loops have been replaced by `for` in Perl6

`for @array { .print }` | deprecated: `for @array { print }`
: here the `print` function is working as a method on `$_`, the default variable

`for @array1 Z @array2`
: zip up elements of two separate arrays (Source)[https://perl6advent.wordpress.com/2009/12/07/day-7-looping-for-fun-and-profit/]

## Documentation
Implemented using markup language called "pod", which uses directives distinguishable by the `=` character

`=begin pod`
: start documentation

`=end pod`
: end documentation

## Glossary
lvalue
: any value that can be "assigned to", and which represents a named region of storage (PBX:71)

array slice
: when the elements of one array are assigned values from another (PBX:84)


## Object-oriented programming
instance variables declared with `has` keyword: `has $.name;`
class attributes are declard with `my` keyword, then a method is declared to allow it to be referenced 

## Math
Mathematical consonants have their own keywords in Perl6: `pi`, `e`, and `tau` (2*pi)

## Other topics
#### rename function in Debian
[The Rename Command](https://www.putorius.net/rename-command-linux.html)

# Visual Basic

VB script doing manual backup
```vb
On Error Resume Next 
Set objNetwork = WScript.CreateObject("WScript.Network")
objNetwork.RemoveNetworkDrive "P:"
objNetwork.MapNetworkDrive "P:", "\\islfs02.hlm.ad.moffitt.usf.edu\research\lab_proteomics",, "hlm\proteomics_backup","orbitrap"

Dim WSHShell
Set WSHShell = WScript.CreateObject("WScript.Shell")
q = """"
sp = " "

from = q & "c:\xcalibur\Data\*.*" & q
dest = sp & q & "p:\backup\QE_FOCUS\data" & q
cmd = "c:\windows\system32\xcopy " & from & dest & " /D /H /E /C /K /R /Y /I"
WSHShell.Run cmd, 1, true

from = q & "c:\xcalibur\methods\*.*" & q
dest = sp & q & "p:\backup\QE_FOCUS\methods" & q
cmd = "c:\windows\system32\xcopy " & from & dest & " /D /H /E /C /K /R /Y /I"
WSHShell.Run cmd, 1, true

Set WSHShell = Nothing
WScript.Quit(0)
```