Introduction:

This project is a basic r shell that lets us emulate the terminal and lets us type commands where they will be tested according to their connector which can be ;, && or ||. Also allows for the use of parantheses, and has a special built in implementation of the test and cd commands. These commands will execute depending on which connector is typed before them.

Features:

A shell composed from c++ that emulates behavior of a bash shell.

Asks user for input and will execute that command if it exists in the /bin/ of bash

Allows for multiple commands in one line.

Allows for the use of connectors, && and ||, in conjunction with user's commands

Allows for comments on the line, everything after the comment is ignored by the execution.

Allows for the use of parantheses to change the order of execution of commands.

Allows for the use of the test command.

Allows for the use of the cd command.

Commands include : || which means it will execute only if the previous command failed && which means it will execute only if the previous command succeeded ; It will execute no matter what happened in the previous command # which means that everything after the sign will be commented

Bugs

When a command connected by an && comand fails, then all following commands fail
The || symbol is not currently being detected by the parser

The test command inside parantheses only work in certain parantheses combinations.

The ls command will sometimes return as having failed despite running succesfully.

Nested paranthesis are buggy, certain combinations of parantheses will not execute correctly.

The dd and Test commands with parameters/arguments within paranthesis do not execute correctly, only the single cd and test command inside parantheseses work as expected.
