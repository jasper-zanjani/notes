# curses
terminal-independent screen-painting and keyboard-handling facility for text-based facilities
## History
First curses library was put together at UC Berkeley in 1980 to support the Rogue computer game, using an earlier library called `termcap` which had been used in the vi editor. This library was almost single-handedly to credit for moving Unix past the line-oriented interfaces inherited from the teletype days.
Bell Labs later released enhanced curses libraries in System III and System V, but the source code was not made available, so throughout the 80s software programmers relied on the older BSD curses library.
Open-source developers took on the challenge in the early 90s and created `ncurses`, a Unix library meant to finally recover and overtake the capabilities of the Bell Labs curses library as FOSS.
## Syntax
`import curses`
  syntax closely follows the original C, for which this module is a wrapper
`stdscr=curses.initscr()`
  initialize curses
`curses.noecho()`
  enable echoing of keys to the screen, which is off by default
`curses.cbreak()`
  allow applications to react to keys instantly, instead of waiting for <Enter>
`stdscr.keypad(True)`
  enable curses interpretation of special keys (cursor keys, navigation keys, etc) as special values (`curses.KEY_LEFT`) instead of multibyte escape sequences
```py
curses.nocbreak()
stdscr.keypad(False)
curses.echo()
curses.endwin()
```
  return terminal to original operating mode, then exit

