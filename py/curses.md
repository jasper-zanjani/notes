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

#### Tutorials
Simple
```py
import curses
stdscr=curses.initscr()
curses.endwin()
```
Less simple
```py
import curses
stdscr = curses.initscr() # Initialization; window object returned is typically called "stdscr" following the convention in C
curses.noecho() # Turn off displaying keys pressed on-screen, allowing for interactivity
curses.cbreak() # Instantaneous reaction to keypresses, instead of waiting for Enter
stdscr.keypad(True) # special keypresses

# Preparing to close by undoing the changes made to the terminal above
curses.nocbreak()
curses.echo()
stdscr.keypad(False)

curses.endwin()
```
Complex
```py
import curses

def main(stdscr):
  # Clear screen
  stdscr.clear()
  
  while True:
    # Store the key value in the variable {c}
    c = stdscr.getch()
    # Clear the terminal
    stdscr.clear()
    if c == ord('a'):
      stdscr.addstr("You pressed the 'a' key.")
    elif c == curses.KEY_UP:
      stdscr.addstr("You pressed the up arrow.")
    else:
      stdscr.addstr("This program doesn't know that key...")

curses.wrapper(main)
```
Finally
```py
import time, curses
def main(stdscr):
  # Make stdscr.getch non-blocking
  stdscr.nodelay(True)
  width = 4
  count = 0
  direction = 1
  while True:
    c = stdscr.getch()
# Clear out anything else the user has typed in
    curses.flushinp()
    stdscr.clear()
# If the user presses 'p', increase the width of the springy bar
    if c == ord('p'):
      width += 1
    # Draw a springy bar
    stdscr.addstr("#" * count)
    count += direction
    if count == width:
      direction = -1
    elif count == 0:
      direction = 1
# Wait 0.1 seconds
    time.sleep(0.1)
curses.wrapper(main)

```

## Sources
- "Curses Tutorial" [steven.codes](https://steven.codes/blog/cs10/curses-tutorial/)
- "Getting started with curses in Python", Indian Pythonista. [YouTube](https://www.youtube.com/watch?v=BK7YvpTT4Sw).
