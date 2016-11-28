<<<<<<< HEAD
=======
// The RShell class starts a prompt and asks user for input
// It removes comments from the user's input and sends them to the
// RShellInterpreter class.

>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>
#include <vector>
#include "RShellInterpreter.cpp"
#include "RShell.h"

using namespace std;

RShell::RShell()
{
    while(1)
    {
<<<<<<< HEAD
        char* currentDir = getenv("PWD");
        cout << getlogin() << " " << currentDir << " $ ";
=======
        cout << getlogin() << "$ ";
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
        getline(cin, userInput);
        if (userInput == "exit")
        {
            exit(0);
        }
        size_t commentSymPos = userInput.find("#");
        string userInputCommentsRemoved = userInput.substr(0,commentSymPos);
        
        RShellInterpreter* shell = new RShellInterpreter(userInputCommentsRemoved);
        shell->interpret();
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
