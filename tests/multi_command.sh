!#/bin/sh

# This runs multiple echo commands
echo hello; echo world | ./rshell

# This runs multiple echo commands with &&
echo hello && echo world | ./rshell

# This runs multiple echo commands with && but first command will fail
ech hello && echo world | ./rshell

# This runs multiple statements with echo and &&
echo hello && echo world; echo hi && echo mr snuffles | ./rshell

# This runs even more multple echo commands with &&
echo hello && echo mr && echo snuffles | ./rshell

# This runs multiple echo commands with && and one of them will fail
echo hello && ech mr && echo snuffles | ./rshell 

