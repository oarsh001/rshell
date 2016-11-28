!#/bin/sh

# just the exit command
exit | ./rshell

# the exit command after some other command
ls; exit | ./rshell

# the exit command after using precedence 
(echo A); exit | ./Shell
(echo A && echo B) ; exit | ./RShell
(echo A && echo B); exit || (echo C && echo D) | ./RShell
(echo A) && (echo B) && exit | ./RShell

# the exit command after test 
[ -f Or.c ] || exit | ./RShell
test –e Or.cpp && test –e And.cpp ; exit | ./RShell
test –d And.cpp && exit | ./RShell