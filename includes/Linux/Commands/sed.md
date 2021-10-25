#### sed
: 
    [sed -&#110;]: #sed '```&#10;$ sed -n&#10;$ sed --quiet&#10;```&#10;Suppress automatic printing of pattern space'
    [sed -&#101;]: #sed '```&#10;$ sed -e&#10;```&#10;When providing more than one instruction, this flag precedes each one'
    [sed -&#102;]: #sed '```&#10;$ sed -f&#10;$ sed --file&#10;```&#10;Read from a "command file" or "program file" (i.e., a sed script)'
    [sed -&#105;]: #sed '```&#10;$ sed -i&#10;```&#10;Edit the file in-place instead of outputting to STDOUT'

    <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`e`][sed -&#101;] [`f`][sed -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> [`i`][sed -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`n`][sed -&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

    Run sed commands in `$SCRIPT` on `$FILE`
    ```sh
    sed -f $SCRIPT $FILE
    ```
    Suppress automatic printing of pattern space
    ```sh
    sed -n
    sed --quiet
    sed --silent
    ```
    `sed` ("Stream-oriented editor") is typically used for applying repetitive edits across all lines of multiple files. In particular it is, alongside `awk` one of the two primary commands which accept regular expressions in Unix systems. 

    | Script syntax | Effect                                                                                            |
    | ------------- | ------------------------------------------------------------------------------------------------- |
    | `#`           | comments begin with **octothorpe**                                                                |
    | `#n`          | If first line of script begins with these two characters, it is equivalent to using the `-n` flag |

    Invocation syntax has two forms:

    === "Inline"

        ```sh
        sed options 'instruction' $FILE
        ```
    
    === "Command file"

        ```sh
        sed options -f $SCRIPT $FILE
        ```
    
    Sed instructions are made of two components:

    - **Addresses** or patterns
    - **Procedures** (also called actions or instructions)
    
    Zero, one, or two addresses can precede a procedure. In the absence of an address, the procedure is executed over every line of input. With one address, the procedure will be executed over every line of input that matches.

    With two addresses, the procedure will be executed over groups of lines whereby:

    - The first address selects the first line in the first group
    - The second address selects the next subsequent line that it matches, which becomes the last line in the first group
    - If no match for the second address is found, it point to the end of the file
    - After the match, the selection process for the next group begins by searching for a match to the first address

    Addressing can be done in one of two ways:

    - **Line addressing**, specifying line numbers separated by a comma (e.g. `3,7p`); `$` represents the last line of input
    - **Context addressing**, using a regular expression enclosed by forward slashes (e.g. `/From:/p`)

    | Procedure                     | Description                                                                                                                                                                                   |
    | :---------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    | `!c`                          | negation operator can be used with any procedure {c}                                                                                                                                          |
    | `a`                           | append text to the addressed lines                                                                                                                                                            |
    | `d`                           | cause sed not to display the addressed lines ("delete"); can emulate `grep -v`, which selects lines which do _not_ match the specified pattern                                                |
    | `i`                           | prepend text to the addressed lines                                                                                                                                                           |
    | `n`                           | write out the currently selected line if appropriate, read the next input line, and start processing the new line with the next instruction                                                   |
    | `x`                           | where {x} is a number, specifying occurrence (e.g. `2` would replace only the second occurrence of each pattern per line)                                                                     |
    | `g`                           | replace all occurrences                                                                                                                                                                       |
    | `p`                           | print original content (e.g. `sed -n 's/test/another test/p' myfile`)                                                                                                                         |
    | `w outputfile`                | write results to {outputfile} (e.g. `sed 's/test/another test/w output' myfile`)                                                                                                              |
    | `s/pattern/replacement/flags` | replace regex {pattern} with {replacement} ("substitute")                                                                                                                                     |
    | `g`                           | replace **all** instances of the search pattern with the replacement, rather than the first instance (global)                                                                                 |
    | `&`                           | known as the **repeated pattern**, represents the represents the entire source string; the only special character used in the replacement string - all other characters are treated literally |

    Edit the file in-place, but save a backup copy of the original with {suffix} appended to - the filename
    ```sh
    -i=suffix
    ```
    Display first 3 lines YUG: 450
    ```sh
    sed '3q' emp.lst
    ```
    Display first 5 lines, similar to `head -5 emp.lst` PGL : 569
    ```sh
    sed '5q' new
    ```
    Pipe output of `ps` to `sed`, displaying top 10 memory-intensive processes
    ```sh
    ps axch -o cmd,%mem --sort=-%mem | sed 11q
    ```
    Pipe output of `ps` to `sed`, displaying top 10 CPU-intensive processes
    ```sh
    ps axch -o cmd:15,%cpu --sort=-%cpu | sed 11q
    ```
    Display first two lines of file
    Without `-n`, each line will be printed twice
    ```sh
    sed -n '1,2p' emp.lst
    ```
    Prepending `!` to the procedure reverses the sense of the command (YUG: 450)
    ```sh
    sed -n '3,$!p' emp.lst
    ```
    Display a range of lines
    ```sh
    sed -n '9,11p' emp.lst
    ```
    Use the `-e` flag to precede multiple instructions
    ```sh
    sed -n -e '1,2p' -e '7,9p' -e '$p' emp.lst
    ```
    Delete lines
    Delete second line alone
    ```sh
    sed '2d' myfile
    ```
    Delete a range of lines: from the 2nd through the 3rd
    ```sh
    sed '2,3d' myfile
    ```
    Delete a range of lines, from the first occurrence of 'second' to the line with the first occurrence of 'fourth'
    ```sh
    sed '/second/,/fourth/d' myfile
    ```
    Print all of a file except for specific lines
    Suppress any line with 'test' in it
    ```sh
    sed '/test/d' myfile
    ```
    Suppress from the 3rd line to EOF
    ```sh
    sed '3,$d' myfile
    ```
    Replace text
    Replace the first instance of the `|` character with `:` and display the first two lines [YUG:455]
    ```sh
    sed 's/|/:/ emp.lst | head -2
    ```
    Replace all instances of the `|` character with `:`, displaying the first two lines [YUG:455]
    ```sh
    sed 's/|/:/g' emp.lst | head -2
    ```
    Substitute HTML tags:
    ```sh
    sed 's/<I>/<EM>/g'
    ```
    These commands will replace "director" with "executive director"
    ```sh
    sed 's/director/executive director/' emp.lst
    ```
    ```sh
    sed 's/director/executive &/' emp.lst
    ```
    ```sh
    sed '/director/s//executive &/' emp.lst
    ```
    [YUG: 456-457]
    Searching for text\
    Equivalent to `grep MA *`
    ```sh
    sed -n '/MA/p' *
    ```
    Stringing sed statements together with pipe
    Take lines beginning with "fake" and remove all instances of "fake.", piping them... remove all parentheses with content and count lines of output (results)
    ```sh
    sed -n '/^fake/s/fake\.//p' * | sed -nr 's/\(.*\)//p' | wc -l
    ```
    Take lines of all files in CWD beginning with "fake" and remove all instances of string "fake." Then remove all parentheses with any content within them and print only the top 10 lines
    ```sh
    sed -ne '/^fake/p' * | sed -n 's/fake\.//p' | sed -nr 's/\(.*\)//p' | sed 11q
    ```
    Count the number of pipes replaced by piping output to `cmp`, which will use the `-l` option to output byte numbers of differing values, then counting the lines of output (YUG:456)
    ```sh
    sed 's/|/:/g' emp.lst | cmp -l - emp.lst | wc -l
    ```