Introduction:

This project is a basic r shell that lets us emulate the terminal and lets us type commands where they will be tested according to their connector which can be ;, && or ||. These commands will execute depending on which connector is typed before them.

Features:

Commands include : || which means it will execute only if the previous command failed && which means it will execute only if the previous command succeeded ; It will execute no matter what happened in the previous command # which means that everything after the sign will be commented

Bugs

When a command connected by an && comand fails, then all following commands fail
The || symbol is not currently being detected by the parser
