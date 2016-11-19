!#/bin/sh

# This will run a command that has a comment in it.
echo hello#world | ./rshell

# This will run a command with a comment and an &&.
echo hello && echo mr # echo snuffles | ./rshell

# This will run a command with a comment in it.
echo hello mr snuff#les | ./rshell

# This will run a command with a comment in it.
(echo A) # Hello | ./RShell
(echo A && echo B) # (echo C)| ./RShell
(echo A && echo B) || (echo C && echo D) # (echo E && echo F)| ./RShell
(echo A) && (echo B) # (each || echo D)| ./RShell
(echo A) && (echo B) && (echo C) # (ls -a)| ./RShell

#This will exit after testing flags
[ -f Or.cpp ] # echo A| ./RShell
test –e Or.cpp && test –e And.cpp # test -d And.cpp | ./RShell
test –d And.cpp # (echo A)| ./RShell