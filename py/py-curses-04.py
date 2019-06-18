#!/usr/bin/env python

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
