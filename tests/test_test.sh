!#/bin/sh

#testing e flag
test –e And.cpp | ./RShell
test –e Or.cpp && test –e And.cpp | ./RShell
[ -e Or.cpp ] | ./RShell
[ Or.cpp ] | ./RShell

#testing f flag
test –f And.cpp | ./RShell
test –f Or.cpp && test –e And.cpp | ./RShell
[ -f Or.cpp ] | ./RShell

#testing d flag
test –d And.cpp | ./RShell
test –d Or.cpp && test –e And.cpp | ./RShell
[ -d Or.cpp ] | ./RShell
