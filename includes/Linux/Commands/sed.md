#### sed
:   
    **sed** ("Stream-oriented editor") is typically used for applying repetitive edits across all lines of multiple files. In particular it is, alongside `awk` one of the two primary commands which accept regular expressions in Unix systems. 
    
    sed instructions can be defined **inline** or in a **command file** (i.e. script).
    
    ```sh title="Inline"
    sed $OPTIONS $INSTRUCTION $FILE
    ```

    ```sh title="Command file"
    sed $OPTIONS -f $SCRIPT $FILE
    ```
    

    sed instructions are made of two components: **addresses** (i.e. patterns) and
    **procedures** (i.e. actions).

    Run sed commands in `$SCRIPT` on `$FILE`

    ```sh
    sed -f $SCRIPT $FILE
    ```
    Suppress automatic printing of pattern space
    ```sh
    sed -n # --quiet , --silent
    ```
    
    Zero, one, or two addresses can precede a procedure. In the absence of an address, the procedure is executed over every line of input. With one address, the procedure will be executed over every line of input that matches.

    With two addresses, the procedure will be executed over groups of lines whereby:

    - The first address selects the first line in the first group
    - The second address selects the next subsequent line that it matches, which becomes the last line in the first group
    - If no match for the second address is found, it point to the end of the file
    - After the match, the selection process for the next group begins by searching for a match to the first address

    Addressing can be done in one of two ways:

    - **Line addressing**, specifying line numbers separated by a comma (e.g. `3,7p`); `$` represents the last line of input
    - **Context addressing**, using a regular expression enclosed by forward slashes (e.g. `/From:/p`)

    Edit the file in-place, but save a backup copy of the original with {suffix} appended to - the filename
    ```sh
    -i=suffix
    ```

    In some circles, sed is recommended as a replacement for other filters like [head](/Linux/Filters/Commands#head).
    Here, the first 10 lines of a file are displayed.
    ```sh
    sed 10q $FILE
    ```

    Display the top 10 processes by memory or cpu usage.
    ```sh
    ps axch -o cmd,%mem --sort=-%mem | sed 11q
    ps axch -o cmd:15,%cpu --sort=-%cpu | sed 11q
    ```

    Replace angle brackets with their HTML codes, piped in from a heredoc:
    ```sh
    sed -e 's/</\&lt;/g' -e 's/>/\&gt;/g' << EOF
    ```

    <!-- 
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
    
    
    Searching for text

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
    -->