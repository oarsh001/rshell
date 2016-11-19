!#/bin/sh

# just the exit command
exit | ./rshell

# the exit command after some other command
ls; exit | ./rshell