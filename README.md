# Trying C
This is the C source code I've done, starting in January 2022, to learn how to code and get used to the tools, which so far have been just Vim and tmux on a bash terminal in a linux mint VM.
Vim rules!
Sluntations.

## Clock
This was the first, a simple clock using time() from the time.h header to get used with simple functions like printf, loops, and variables, converting UNIX into hours minutes and seconds, etc.

## Timer
Looks close the clock but counting down and accepting user input through scanf(), also trying making my own functions ( displayTime() in this case)

## Timer2
Pretty similar to the other timer but with a more intuitive display, hours, minutes, and seconds are entered and it counts down just like the last one

## ~~Stopwatch (W.I.P)
The Stopwatch will count up until user provides input, this will require to run multiple processes via fork() or other form, will also take the opportunity to use multiple source files to understand how it works~~ Too complicated for now

## Interactive Interface
Instead of the Stopwatch I will do a simple interface, that doesn't require multi processing, that will connect you to the Timer, clock, or leave the program

## Tic-Tac-Toe (Haven't Started)
Will attempt to do a simple game of tic-tac-toe on the terminal that will be operated with arrow keys and enter to be used and be able to determine the victor
