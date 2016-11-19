!#/bin/sh

# This will run a command that has a comment in it.
echo hello#world | ./rshell

# This will run a command with a comment and an &&.
echo hello && echo mr # echo snuffles | ./rshell

# This will run a command with a comment in it.
echo hello mr snuff#les | ./rshell