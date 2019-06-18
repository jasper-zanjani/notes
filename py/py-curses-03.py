#!/usr/bin/env python

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
