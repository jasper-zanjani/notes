# Python curses module
terminal-independent screen-painting and keyboard-handling facility for text-based facilities

## History
The first curses library was put together at UC Berkeley in 1980 to support the Rogue computer game, using an earlier library called `termcap` which had been used in the vi editor. This library was almost single-handedly to credit for moving Unix past the line-oriented interfaces inherited from the teletype days.  Bell Labs later released enhanced curses libraries in System III and System V, but the source code was not made available, so throughout the 80s software programmers relied on the older BSD curses library.  Open-source developers took on the challenge in the early 90s and created `ncurses`, a Unix library meant to finally recover and overtake the capabilities of the Bell Labs curses library as FOSS.

## Commands
Command                 | Effect
:---                    | :---
`stdscr`                | conventional name for the curses instance, from C
`curses.wrapper`        | function that is passed the name of the main function i.e. `wrapper(main)`, and which manages the details of building up and tearing down the terminal modifications
`stdscr.clear()`        | clear the screen
`stdscr.getch()`        | read a keypress, or -1 if no key has been pressed yet
`stdscr.addstr()`       | similar to "print", text output to screen
`curses.flushinp()`     | clear out anything that the user has typed in
`stdscr.nodelay(True)`  | doesn't wait for input, making `getch` non-blocking

## Sources
  - "Curses Tutorial" [steven.codes](https://steven.codes/blog/cs10/curses-tutorial/)
  - "Getting started with curses in Python", Indian Pythonista. [YouTube](https://www.youtube.com/watch?v=BK7YvpTT4Sw).
