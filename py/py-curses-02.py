#!/usr/bin/env python

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
