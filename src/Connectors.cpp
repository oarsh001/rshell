<<<<<<< HEAD
=======
// Connectors.cpp is the implementation for running commands with 
// multiple connectors in them, either && or ||

>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>
#include <errno.h>
#include <vector>
#include <sys/wait.h>
#include "Connectors.h"
#include "And.cpp"
#include "Or.cpp"

using namespace std;

<<<<<<< HEAD

=======
// The constructors, one is empty, the other takes a char* argument
// which is the users input.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
Connectors::Connectors(){}

Connectors::Connectors(char* userCommandWithConn)
{
    command = userCommandWithConn;
}

<<<<<<< HEAD
=======

// Connectors execute determines the logic of multiple && and || in a
// users input.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
void Connectors::execute()
{
    string cmdDupString = string(command);

    commandsVector.clear();
    char* cmdToken1 = strtok(command, "&&||");
    while (cmdToken1 != 0)
    {
        commandsVector.push_back(cmdToken1);
        cmdToken1 = strtok(NULL, "&&||");
    }

    connectorsVector.clear();
    char* cmdDupChar = new char[cmdDupString.length() + 1];
    strcpy(cmdDupChar, cmdDupString.c_str());
    char* cmdToken2 = strtok(cmdDupChar, " ");
    while (cmdToken2 != 0)
    {
        if (string(cmdToken2) == "&&" || string(cmdToken2) == "||")
        {
            connectorsVector.push_back(cmdToken2);
        }
        cmdToken2 = strtok(NULL, " ");
    }

    statusVector.clear();
    for (unsigned k = 0; k < connectorsVector.size(); k++)
    {
        if (k == 0)
        {
            if (connectorsVector[k] == "&&")
            {
                SingleCmd* lhs = new SingleCmd(commandsVector[k]);
                SingleCmd* rhs = new SingleCmd(commandsVector[k+1]);
                And* andCmd = new And(lhs, rhs);
                andCmd->execute();
                statusVector.push_back(andCmd->cmdStatus());
<<<<<<< HEAD
                status = andCmd->cmdStatus();
=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
            }
            else if (connectorsVector[k] == "||")
            {
                SingleCmd* lhs = new SingleCmd(commandsVector[k]);
                SingleCmd* rhs = new SingleCmd(commandsVector[k+1]);
                Or* orCmd = new Or(lhs, rhs);
                orCmd->execute();
                statusVector.push_back(orCmd->cmdStatus());
<<<<<<< HEAD
                status = orCmd->cmdStatus();
=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
            }
        }
        else
        {
            if (connectorsVector[k] == "&&")
            {
                if (statusVector[k-1] == 0)
                {
                    SingleCmd* nextCmd = new SingleCmd(commandsVector[k+1]);
                    nextCmd->execute();
                    statusVector.push_back(nextCmd->cmdStatus());
<<<<<<< HEAD
                    status = nextCmd->cmdStatus();
=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
                }
            }
            else if (connectorsVector[k] == "||")
            {
                if (statusVector[k-1] == 1)
                {
                    SingleCmd* nextCmd = new SingleCmd(commandsVector[k+1]);
                    nextCmd->execute();
                    statusVector.push_back(nextCmd->cmdStatus());
<<<<<<< HEAD
                    status = nextCmd->cmdStatus();
=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
                }
            }
        }
    }
}

int Connectors::cmdStatus()
{
<<<<<<< HEAD
    return status;
=======
    return 0;
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
}

