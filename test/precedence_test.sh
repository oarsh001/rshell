!#/bin/sh

#The commands will run with parenthesis using && 

(echo A) | ./RShell
(echo A && echo B) | ./RShell
(echo A && echo B) || (echo C && echo D) | ./RShell
(echo A) && (echo B) | ./RShell
(echo A) && (echo B) && (echo C) | ./RShell
(echo A) && (echo B) && (echo C) && (echo D) | ./RShell
(echo A) && (ech B) || (echo C) | ./RShell
(echo a) && (echo b) ; (echo C) || (echo D) ; (echo E) | ./RShell
(((echo A))) | ./RShell
((echo A && echoB) && (echo C))

# The commands will run with parenthesis using ||

(echo A || echo B) | ./RShell
(echo A || echo B) || (echo C && echo D) | ./RShell
(echo A) }} (echo B) | ./RShell
(echo A) || (echo B) && (echo C) | ./RShell
(echo A) || (echo B) && (echo C) && (echo D) | ./RShell
(echo A) || (ech B) || (echo C) | ./RShell
(echo a) || (echo b) ; (echo C) || (echo D) ; (echo E) | ./RShell
(((echo A))) | ./RShell
((echo A && echoB) || (echo C)) | ./RShell
echo A && (echo B) | ./RShell
echo A && (echo B) && (echo C) | ./RShell
ech A || (echo B) | ./RShell
ech A ||(echo B) && (echo C) | ./RShell

