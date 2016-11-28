#!/bin/bash
# This script will test if single commands work in our rshell

# Should run the ls command with the a option and exit
ls -a; exit | ./rshell

# Should run the echo command which displays hello world
echo hello | ./rshell

# Should run the touch command and create a file called check
touch check | ./rshell

# Should run the rm command and remove the file called check
rm check | ./rshell