# CompTIA Linux+ 
LX0-103 and LX0-104, in cooperation with LPI

## CompTIA Linux+ LX0-103 - 101 System Architecture
In this episode, Don and Daniel explain the basics of the Linux command-line interface (CLI) and some of the built-in CLI commands. They explain what a shell is and even give you some tips for maneuvering around your command history. Also discussed is the Linux manual pages (man pages) which are a set of basic help documents for CLI programs.
103.1 Exploring Linux Command-Line Tools

- Understanding Command-Line Basics
- Exploring Your Linux Shell
- Bourne Again Shell (bash)
- Based on the Unix Bourne shell (sh)
- bash is the default shell in most Linux systems
- csh or the C Shell utilizes a syntax that is liken to the C programming language
- tcsh based off of csh
- More bash-like but still different
- The T stands for TENEX. An OS that inspired the author of tcsh
- There are 2 types of default shells
- Default Interactive Shell
  - The shell that the user works with to enter commands
- Default System Shell
  - The shell that they system uses to run startup scripts
  - Typically the file /bin/sh points to the default system shell
  - Usually /bin/bash in Linux
  - Points to /bin/dash in Ubuntu

Using a Shell
- Starting a shell
- Linux can drop you straight to a shell after startup
- In a GUI environment you can start a terminal emulator
  - XTERM, Konsole, Terminal, gnome-terminal
  - uname -a returns all the system information
- Internal vs. External Commands
- Internal commands are built-in to the shell
- External commands are programs that run in the shell but aren't native to the shell
- Internal command examples
  - cd Change Directory
  - cd ~/sally is the same as cd /home/sally
  - pwd Print Working Directory
  - echo prints a string of text
  - echo Hello
  - Useful when writing scripts and checking the content of environmental variables
  - exit terminates any shell
  - logout terminates only login shells
- You can find out whether a command is internal or external by using the type command
  - type pwd
  - type cd
  - type bash
- type -a will display different programs that use the same name
  - type -a cd
  - type -a pwd
- Shell tricks and tips
  - Auto-complete commands with Tab
  - history shows list of previously used commands, usually the last 500
  - !! lists and executes the last command
  - !210 lists and executes command #210 in the list
  - history -c clears the history
  - The history is stored in ~/.bash_history
  - Ctrl+P/Up arrow Ctrl+N/Down arrow scrolls through recently used commands
  - Ctrl+R performs a reverse search of commands
  - Ctrl+S performs a forward search of commands
  - Ctrl+G quits the search
  - Ctrl+A moves the cursor to the start of the line
  - Ctrl+E moves the cursor to the end of the line
  - Ctrl+Left or Right arrow keys move the cursor backward or forward a word at a time
  - Esc+B/F performs the same action
  - Ctrl+K deletes from the cursor to the end of the line
  - Ctrl+X+Backspace deletes text from cursor to the beginning of the line
  - Ctrl+T transpose the character before the cursor with the character under the cursor
  - Esc+T transposes the word
  - Ctrl+X+Ctrl+E quick launches the default text editor

Exploring Shell Configuration
- Shell configuration files are just plain text shell scripts
- `~/.bashrc` and `/etc/profile`
  - Make necessary changes to these files
  - `$PATH` add directories to search for executables

Using Environment Variables
- Variables are containers for data
- System Variables and User-Created Variables
- `$TERM`
```
$> PS1="My New Prompt$>"
My New Prompt$> export PS1
My New Prompt$> export PS1="Prompt$>"
Prompt$> echo $PS1
```

Using Environment Variables
- `env` lists all environmental variables
- `unset` removes the data from the variable

Getting Help
- `man` for the manual of a program
- `man man` to learn to use `man`
- `man -k` will perform a lookup
- `man -k "system information"`
- `man` is divided into 9 sections
- Some commands can reside in multiple sections
  - `passwd` resides in both sections 1 and 5
  - `man` defaults to the lowest numbered section
  - `man 5 passwd` will return the manual for section 5's entry for the `passwd` command
- `info` is like man but uses hypertext and has some internal options for navigating the manual
- `help` usually gives a succinct synopsis of use for built-in commands

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Processing Text Using Filters

File-Combining Commands
  cat (Concatenate)
    Combines files together
    Files combined one after another
    Can also display the contents of a file
      Combines file with STDOUT
    Using cat:
      Combine two files together
      cat first.txt second.txt > combined.txt
      Display the contents of first.txt
      cat first.txt
      Display the contents of second.txt
      cat second.txt
      Display the contents of combined.txt
      cat combined.txt
  join
    Combines files together
    Files combined based on fields
    Useful for building tables
    Joins on first column by default
    Using join:
      Display two files together
      join listing1.1.txt listing1.2.txt
  paste
    Similar to join except that it combines data by inserting a tab in between the first and second data set
    No column is used for comparison
    Using paste:
      Display two files together paste listing1.1.txt listing1.2.txt
File-Transforming Commands
  expand
    Converts tabs into spaces
  unexpand
    Converts spaces to tabs
    The opposite of expand
  od (Octal Dump)
    Displays a file in Octal (Base 8)
    Useful for viewing binaries
    Using od:
      Display a file in octal format
      od listing1.2.txt
  sort
    Displays data reorganized to suite your needs
    Using sort
      Display the contents of listing1.1.txt sorted by first name
      sort -k 3 listing1.1.txt
  split
    Divides a file based on criteria
    Useful for dividing up large files across smaller media
    Can split by:
      Bytes
      Number of lines
    Output files will have two letters attached to indicate sequence
      filenameaa
      filenameab
      …
      filenamezy
      filenamezz
    Can use cat to recombine
    Using split
      Divide a file every 2 lines
      split -l 2 listing1.1.txt numbers
  tr (Translate)
    Converts or removes characters from a file
    Using tr
      Replace every instance of B in a file to b. In the same command, replace the characters C and J with the character c
      `tr BCJ bc < listing1.1.txt` 
  uniq (Unique)
    Displays data excluding duplicate entries
    Using uniq
      Display the contents of a file, excluding duplicate entries. Sort the entries alphabetically.
      sort shakespeare.txt | uniq
File-Formatting Commands
  fmt (Format)
    Applies manual word-wrapping to a file
    Defaults to 75 character width
  nl (Numbered Lines)
    Adds line numbers to each line
    Useful for readability
    Useful for troubleshooting script errors that return a line number
    Similar to cat -b but with advanced options
    nl -b a filename.txt
    a option causes all lines to be numbered, including blank lines
  pr (Prepare for Printing)
    Formats a file for output to a line printer
    Assumes 80 character width and mono-space font
    Can also set headers, footers, margins, etc.
    Using pr
      Display the contents of a file double-spaced and with line numbering
      cat -n /etc/profile | pr -d
      Repeat step 1, but apply word wrapping at 50 characters
      cat -n /etc/profile | pr -dfl 50

File-Viewing Commands
  head
    Displays the first 10 lines of a file
    Use -n option to set the number of lines
  tail
    Displays the last 10 lines of a file
    Use -n option to set the number of lines
  less
    Displays the contents of a file
    Allows for scrolling and searching
    Replacement for more command
File-Summarizing Commands
  cut
    Extracts portions of a file
    Usually combined with other commands
    Using cut
      Display only the MAC address for each network interface on your system
      ifconfig | grep ether | cut -d " " -f 10
  wc (Word Count)
    Displays the word count for a file

Lab

Requirements:
  Text file named first.txt
    Contents: Data from first file.
  Text file named second.txt
    Contents: Data from second file.
  Text file named listing1.1.txt
    Contents:
    555-2397 Beckett, Barry
    555-5116 Carter, Gertrude
    555-7929 Jones, Theresa
    555-9871 Orwell, Samuel
  Text file named listing1.2.txt
    Contents:
    555-2397 unlisted
    555-5116 listed
    555-7929 listed
    555-9871 unlisted
  Text file named shakespeare.txt
    Contents:
    to be
    or
    not
    to be
    that
    is
    the
    question 

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Using Regular Expressions

    Understanding Regular Expressions
        Specialized wildcard system used in many programs
        Can be very complex
        Useful for finding text and editing/replacing strings
        Sometimes called RegEx
    Common syntax
        Brackets ( [ and ] )
            Indicates a collection of acceptable values
            b[aeiou]g matches bag, beg, big, bog and bug
        Hyphen ( - )
            Denotes a range of characters
            Indicates sequential acceptable values
            a[2-4]z matches a2z, a3z and a4z
        Period ( . )
            True wildcard
            Indicates any single character
            1.1 matches 101, 111, 121 as well as 1a1 and 1z1
        Asterisk ( * )
            True wildcard
            Indicates any number of characters
            Paired with "." to indicate any number of repititions
            Ab.* matches Abe and Abraham 
        Carat ( ^ )
            Indicates the start of a line
        Dollar Sign ( $ )
            Indicates the end of a line
        Vertical Bar ( | )
            Indicates multiple possible values
            (first|second) would match first or second
        Parenthesis ( ( and ) )
            Indicates a sub-expression to be handled separately from the main expression
            Can also be used to divide up text for replace operations
        Backslash ( \ )
            Used to "escape" a special character
            Useful when matching a character that is normally interpreted
            For example, all of the commands above
    Using grep
        Grep is a very old Unix command
        Globally Search a Regular Expression and Print
        Searches files for a string and returns the matching lines
        Leverages regular expressions to locate text
        Example 1
            grep -r eth0 /etc/*
            Basic regular expression
            Searches all files in /etc for the occurrence of "eth0"
        Example 2
            ifconfig | grep ether
            Basic regular expression
            Filters the output of ifconfig to only display lines containing "ether"
        Example 3
            ifconfig | grep -E "ether|eno)"
            Extended regular expression
            Filters the output of ifconfig to only display lines containing "ether" or "eno"
        Example 4
            ifconfig | grep -E "^eno[13].*"
            Extended regular expression
            Filters the output of ifconfig to only display lines beginning with "eno1" or "eno3" 
    Using sed
        Another classic Unix command
        Stream Editor
        Modifies a files contents based on command-line criteria
        Command modifiers
            a: Append text to file
            i: Insert text in file
            r: Append text from one file into another
            c: Replace selected range of lines with text
            s: Replace text that matches a regular expression
        Example
            sed 's/2012/2015' cal-2012.txt > cal-2015.txt
            Replaces any occurrence of "2012" in cal-2012.txt with "2015"
            Redirects output into "cal-2015.txt"

Lab
Requirements:
  Text file named cal-2012.txt
    Contents:
    01/01/2012 New Year's Day
    07/04/2012 Independence Day
    10/31/2012 Halloween
    12/25/2012 Christmas 

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Editing Files with vi
vi (and vim)
      :
          Command mode
      :w
          Save file
          :w to "Save As"
      :wq or :x
          Save and exit
      :q!
          Exit without saving
      i
          Insert at current location
      I
          Insert at beginning of line
      a
          Append to end of word
      A
          Append to end of line
      dw
          delete word
      :d or dd
          delete line
      <#>G or :<#>
          Move to a particular line #
  Ranges
      :#,#
      :1,10d
          Deletes line 1-10
      :set number
          Displays line numbers
          :set number! to disable
          vi +# filename opens a file to a particular line
              vi +12 file.txt
          To be permanent
              vi ~/.vimrc
              set number
  Search
      / or :s/
          Search forward for text
          ? for backward
          n for next
          N for previous
      vi +/ filename.txt
          Opens a file to the first occurrence of a term
  Search and Replace
      :s//
          Replaces text on one line
      :%s//
          Replaces text throughout the file
      :#,#s//
          Replaces text within a range

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Using RPM
Package Naming Convention
`httpd-2.4.6-31.el7.centos.x86_64.rpm`

A B C D E

A = Package Name B = Version # C = Build # D = Distribution E = Architecture

x86_64 / amd64 i386 ARM noarch
Install a local package with RPM

`rpm -Uvh samba-4.1.9-4.fc20.x86_64.rpm rpm -ivh webmin-1.750-1.noarch.rpm`
`-i` Install only (no upgrade) `-U` Install or Upgrade `-vh` Displays hash marks on the screen to represent progress

Webmin Dependencies yum -y install perl perl-Net-SSLeay openssl perl-IO-Tty
List details of an installed package with RPM

`rpm -qi webmin`
: `-q` Queries the package if it exists `-i` Displays information

Removing a package with RPM
`rpm -e webmin-1.750-1.noarch.rpm`

Extracting a package's contents
`rpm2cpio webmin-1.750-1.noarch.rpm > webmin-1.750-1.noarch.cpio cpio -i --make-directories < webmin-1.750-1.noarch.rpm`
Installing a package with Yum

yum list httpd yum install httpd yum info httpd yum erase httpd
Yum repositories

/etc/yum.repos.d/[name].repo

[Webmin]
name=Webmin Distribution Neutral
#baseurl=http://download.webmin.com/download/yum
mirrorlist=http://download.webmin.com/download/yum/mirrorlist
enabled=1

`wget http://www.webmin.com/jcameron-key.asc rpm --import jcameron-key.asc`

`yum install webmin`

## CompTIA Linux+ LX0-103 - 102 Managing Software

In this episode, Daniel and Don explain package management when using Debian Linux distributions. They describe the different Debian package management systems like dpkg, apt-get, dselect, and aptitude; how to use them to install, configure, and remove software from your Linux system.

102.4 Use Debian Package Management

    Using Debian Packages
    Debian Distributions and Conventions
        Originates with the Debian distro
        Adopted to other Linux distros (Ubuntu, Mint, Xandros)
        Debian supports many different CPU architectures
        x86, x86-64, IA-64, ARM, PowerPC, Alpha, 680x0, MIPS, and SPARC
        x86 native
    The dpkg Command Set
        Syntax
        dpkg [options][action] [package-files|package-name]
            action is the action to be taken by dpkg
            -i or --install
            --configure (Reconfigures an installed package)
            -r or --remove
            -P or --purge (removes package and configs)
            --get-selections (Lists installed packages)
            -p or --print-avail (Info about installed)
            -I or --info (Info about installable)
            -l or --list List packages that match the pattern
    Using apt-cache
        Provides info about the Debian package database
        apt-cache showpkg [package name]
        Displays package info
        apt-cache stats
        Shows package statistics
        How many packages are installed, dependencies
        apt-cache unmet
        Finds unmet dependencies
        apt-cache depends [package]
        Displays specific package dependencies
        rdepends finds packages that depend on the one you specify
        apt-cache pkgnames [string]
        Lists installed packages that begin with the specified string
    Using apt-get
        Similar to the YUM utility
        Gets packages from a package repository
        Repositories are defined in /etc/apt/sources.list
        apt-get update
        Gets package info updates
        apt-get upgrade
        Upgrades all install packages
        apt-get dist-upgrade
        Upgrades all packages except those that would break a dependent package
        apt-get install
        Installs a package
        apt-get remove
        Removes a package
        Options to use with apt-get
        -d/--download-only doesn't install
        -f/--fix-broken attempts to fix broken depend
        -q/--quiet no output or progress info
        -y/--yes/--assume-yes answers all with yes
        --no-upgrade won't upgrade if older version already installed
    Using dselect, aptitude, and Synaptic
        Show demos of dselect, aptitude, and Synaptic
    Reconfiguring Packages
        Linux programs tend to be configured through the use of configuration files
        Sometimes you can mess things up when trying to configure the config files
        You can reconfigure the config files back to their original state using
        # dpkg-reconfigure [program-name]
    Debian Packages Compared to Other Package Formats
        Debian packages aren't single files, they're groups of files…
        The Source Tarball
        Patch file (used to modify the source code)
        A .dcs file (contains the digital signature)
        Debian packages tend to be more compatible with any Debian derived distro
        More obscure programs might not be available in Debian package
    Configuring Debian Package Tools
        Debian packages usually don't require you to configure them at install
        The Debian system has set defaults that work most of the time
        Still, from time-to-time config might be needed
        If you need to add config info then…
        Main configuration file for dpkg is located at
        /etc/dpkg/dpkg.cfg or ~/.dpkg.cfg
        Edit this file to include needed arguments
        Main configuration file for APT is located at
        /etc/apt/apt.conf (works for DSELECT too)
        SHOW THIS sample config file
            /usr/share/doc/apt/examples/apt.conf
        Package tools rely on various files found in the /var/lib/dpkg directory
        This is basically the database of install files
        Handle with care ;)

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Shared Libraries

    Libraries typically end in .so
    Fully qualified name:
        /usr/lib/libreadline.so.3
        /usr/lib64/mysql/libmysqlclient.so.18
    ldconfig name:
        /usr/lib/libreadline.so.3.0
        /usr/lib64/mysql/libmysqlclient.so.18.0.0
    link name:
        /usr/lib/libreadline.so
        /usr/lib64/mysql/libmysqlclient.so
    Display all shared libraries:
        ldconfig -v
        /etc/ld.so.conf
        /etc/ld.so.conf.d/mariadb-x86_64.conf
    Specify a new library location
        ldconfig -n /home/dpezet/lib
        or
        vi /etc/ld.so.conf
    Display the library dependencies of a file
        ldd /bin/bash
        ldd /bin/vim

Links
ln
  Hard link
    Default link type
    Links to a file's inode
    Can only link to files in the same filesystem
    More efficient
    ln
    ln /sbin/fsck ~/fsck
  Soft link / symlink / Symbolic Link
    Links to a file path
    Can link to any file anywhere
    Less efficient
    ln -s /sbin/fsck ~/fsck 
  copying vs linking

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Managing Processes
Understanding the Kernel
  uname
    -n/--nodename
    -v/--kernel-version
    -a/--all
    [kernel-name][nodename][kernel-release][kernel-version] [machine][processor][hardware-platform][operating-system]
  ps (Process List)
    3 options
    Unix options
      Single dash before options
    BSD options
      No dash before options
    GNU Long options
      Two dashes before options
    Common usage
    ps -A/-ef List all processes
    ps -u user List processes of specific user
      ps -u jbond
    ps -xf/-AH List process hierarchy
    Use grep to find specific process
      ps -Af | grep lynx
  top
    top -d 10 Delay updates 10 seconds
    top -p 4244 Display stats on PID# 4244
    Single letter commands
    k Kill a process
    r Change a process' priority
    P Sort by CPU usage
    M Sort by MEM usage
      free Displays basic MEM stats
  jobs
    Checks for running jobs before logging out
  pgrep
    Same basic output as ps | grep
    ps -u root | grep cron
    pgrep -u root cron
  Foreground and Background processes
    Ctrl+Z pauses a program
    fg unpauses a program $>nano ctrl+Z $>fg
    bg unpauses the program but runs it in the background
    Adding an & to a command runs it in the background as soon as its initiated

* Managing Process Priorities

    nice launch a program with a specified priority
        3 ways to run nice to set priorities
        $>nice -12 number-crunch data.txt
        $>nice -n 12 number-crunch data.txt
        $>nice --adjustment=12 number-crunch data.txt
        nice values are -20 to 19
        Negative values are higher priority
            Only root can run negative values and increase priority
            Regular users can run positive values and decrease priority
            Default nice value is 10
            Default program priority value is 0
    renice change the priority of an already running process
        renice 12 [PID] [[-g] pgrps] [[-u] users] $>renice 12 6051 -u dpezet 

* Killing Processes

    kill command
        kill -l lists all the kill signals
        1 SIGHUP
        9 SIGKILL
        15 SIGTERM
        kill -9 -s 9 --signal 9 $> ./stress_cpu.sh $> ps -u dpezet $> kill -9 PID for stress_cpu.sh 
    killall command $>killall stress_cpu.sh $>killall -i stress_cpu.sh

## CompTIA Linux+ LX0-103 - 101 System Architecture - Hardware Settings
Hardware devices are mapped to files in /dev
    Udev <--> HAL <--> Dbus
      Udev is the system that maps hardware to files in /dev
      Provides dynamic naming so files represent hardware that is actually present
    HAL populates the files with XML data
    Dbus enables communications between HAL and the software process (file managers, media players, etc)
  Device mappings can be overridden if necessary
    /etc/udev/rules.d
    For example, say you removed eth0 and you now want eth1 to be eth0
      vi /etc/udev/rules.d/70-persistent-net.rules
      Correct names as required
      Reboot is generally required
  List loaded modules
    lsmod Calls /proc which contains a wide variety of system information cat /proc/modules
  Cold plug / Hot plug
  Loading modules
    modprobe -v Not normally needed as kmod should load them when hardware is detected modinfo
  List connected hardware
    `lspci`
    `lsusb`
    Both commands call `/sys` (the sysfs) which contains a wide variety of device information
    `ls /sys/bus/pci/devices` or `ls /sys/bus/pci/drivers/e1000`
  All hardware is represented in /dev
    - `/dev/cdrom`
    - `/dev/cpu`
    - `/dev/mem`
    - `/dev/sda`
    - `/dev/sda1`
    - `/dev/snd`
    - `/dev/stdout`
    - `/dev/tty##`

    Disabling Hardware
        Option #1: If you installed the driver, simply remove the package.
        Option #2: If it is built in to the distro, add it to the modprobe blacklist:
            Determine the module name (lsmod) vi /etc/modprobe.d/blacklist.conf
        Option #3: Use one of the following to temporarily remove it from memory (will return after reboot)
            rmmod
                rmmod bluetooth
                -f to force
                -w to wait until unused
            modprobe -r

## CompTIA Linux+ LX0-103 - 102 Managing Software
In this episode, Daniel and Don explain package management when using Debian Linux distributions. They describe the different Debian package management systems like dpkg, apt-get, dselect, and aptitude; how to use them to install, configure, and remove software from your Linux system.

102.4 Use Debian Package Management
Using Debian Packages
    Debian Distributions and Conventions
        Originates with the Debian distro
        Adopted to other Linux distros (Ubuntu, Mint, Xandros)
        Debian supports many different CPU architectures
        x86, x86-64, IA-64, ARM, PowerPC, Alpha, 680x0, MIPS, and SPARC
        x86 native
    The dpkg Command Set
        Syntax
        dpkg [options][action] [package-files|package-name]
            action is the action to be taken by dpkg
            -i or --install
            --configure (Reconfigures an installed package)
            -r or --remove
            -P or --purge (removes package and configs)
            --get-selections (Lists installed packages)
            -p or --print-avail (Info about installed)
            -I or --info (Info about installable)
            -l or --list List packages that match the pattern
    Using apt-cache
        Provides info about the Debian package database
        apt-cache showpkg [package name]
        Displays package info
        apt-cache stats
        Shows package statistics
        How many packages are installed, dependencies
        apt-cache unmet
        Finds unmet dependencies
        apt-cache depends [package]
        Displays specific package dependencies
        rdepends finds packages that depend on the one you specify
        apt-cache pkgnames [string]
        Lists installed packages that begin with the specified string
    Using apt-get
        Similar to the YUM utility
        Gets packages from a package repository
        Repositories are defined in /etc/apt/sources.list
        apt-get update
        Gets package info updates
        apt-get upgrade
        Upgrades all install packages
        apt-get dist-upgrade
        Upgrades all packages except those that would break a dependent package
        apt-get install
        Installs a package
        apt-get remove
        Removes a package
        Options to use with apt-get
        -d/--download-only doesn't install
        -f/--fix-broken attempts to fix broken depend
        -q/--quiet no output or progress info
        -y/--yes/--assume-yes answers all with yes
        --no-upgrade won't upgrade if older version already installed
    Using dselect, aptitude, and Synaptic
        Show demos of dselect, aptitude, and Synaptic
    Reconfiguring Packages
        Linux programs tend to be configured through the use of configuration files
        Sometimes you can mess things up when trying to configure the config files
        You can reconfigure the config files back to their original state using
        # dpkg-reconfigure [program-name]
    Debian Packages Compared to Other Package Formats
        Debian packages aren't single files, they're groups of files…
        The Source Tarball
        Patch file (used to modify the source code)
        A .dcs file (contains the digital signature)
        Debian packages tend to be more compatible with any Debian derived distro
        More obscure programs might not be available in Debian package
    Configuring Debian Package Tools
        Debian packages usually don't require you to configure them at install
        The Debian system has set defaults that work most of the time
        Still, from time-to-time config might be needed
        If you need to add config info then…
        Main configuration file for dpkg is located at
        /etc/dpkg/dpkg.cfg or ~/.dpkg.cfg
        Edit this file to include needed arguments
        Main configuration file for APT is located at
        /etc/apt/apt.conf (works for DSELECT too)
        SHOW THIS sample config file
            /usr/share/doc/apt/examples/apt.conf
        Package tools rely on various files found in the /var/lib/dpkg directory
        This is basically the database of install files
        Handle with care ;)

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools - Shared Libraries
Libraries typically end in .so
    Fully qualified name:
        /usr/lib/libreadline.so.3
        /usr/lib64/mysql/libmysqlclient.so.18
    ldconfig name:
        /usr/lib/libreadline.so.3.0
        /usr/lib64/mysql/libmysqlclient.so.18.0.0
    link name:
        /usr/lib/libreadline.so
        /usr/lib64/mysql/libmysqlclient.so
    Display all shared libraries:
        ldconfig -v
        /etc/ld.so.conf
        /etc/ld.so.conf.d/mariadb-x86_64.conf
    Specify a new library location
        ldconfig -n /home/dpezet/lib
        or
        vi /etc/ld.so.conf
    Display the library dependencies of a file
        ldd /bin/bash
        ldd /bin/vim

Links
ln
  Hard link
    Default link type
    Links to a file's inode
    Can only link to files in the same filesystem
    More efficient
    ln
    ln /sbin/fsck ~/fsck
  Soft link / symlink / Symbolic Link
    Links to a file path
    Can link to any file anywhere
    Less efficient
    ln -s /sbin/fsck ~/fsck 
  copying vs linking

## CompTIA Linux+ (LX0-103) - Exploring Linux Command-Line Tools
Managing Processes

    Understanding the Kernel
    uname
        -n/--nodename
        -v/--kernel-version
        -a/--all
        [kernel-name][nodename][kernel-release][kernel-version] [machine][processor][hardware-platform][operating-system]
    ps (Process List)
        3 options
        Unix options
            Single dash before options
        BSD options
            No dash before options
        GNU Long options
            Two dashes before options
        Common usage
        ps -A/-ef List all processes
        ps -u user List processes of specific user
            ps -u jbond
        ps -xf/-AH List process hierarchy
        Use grep to find specific process
            ps -Af | grep lynx
    top
        top -d 10 Delay updates 10 seconds
        top -p 4244 Display stats on PID# 4244
        Single letter commands
        k Kill a process
        r Change a process' priority
        P Sort by CPU usage
        M Sort by MEM usage
            free Displays basic MEM stats
    jobs
        Checks for running jobs before logging out
    pgrep
        Same basic output as ps | grep
        ps -u root | grep cron
        pgrep -u root cron
    Foreground and Background processes
        Ctrl+Z pauses a program
        fg unpauses a program $>nano ctrl+Z $>fg
        bg unpauses the program but runs it in the background
        Adding an & to a command runs it in the background as soon as its initiated

* Managing Process Priorities

    nice launch a program with a specified priority
        3 ways to run nice to set priorities
        $>nice -12 number-crunch data.txt
        $>nice -n 12 number-crunch data.txt
        $>nice --adjustment=12 number-crunch data.txt
        nice values are -20 to 19
        Negative values are higher priority
            Only root can run negative values and increase priority
            Regular users can run positive values and decrease priority
            Default nice value is 10
            Default program priority value is 0
    renice change the priority of an already running process
        renice 12 [PID] [[-g] pgrps] [[-u] users] $>renice 12 6051 -u dpezet 

* Killing Processes

    kill command
        kill -l lists all the kill signals
        1 SIGHUP
        9 SIGKILL
        15 SIGTERM
        kill -9 -s 9 --signal 9 $> ./stress_cpu.sh $> ps -u dpezet $> kill -9 PID for stress_cpu.sh 
    killall command $>killall stress_cpu.sh $>killall -i stress_cpu.sh

