// Connectors.cpp is the implementation for running commands with 
// multiple connectors in them, either && or ||

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

// The constructors, one is empty, the other takes a char* argument
// which is the users input.
Connectors::Connectors(){}

Connectors::Connectors(char* userCommandWithConn)
{
    command = userCommandWithConn;
}


// Connectors execute determines the logic of multiple && and || in a
// users input.
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
            }
            else if (connectorsVector[k] == "||")
            {
                SingleCmd* lhs = new SingleCmd(commandsVector[k]);
                SingleCmd* rhs = new SingleCmd(commandsVector[k+1]);
                Or* orCmd = new Or(lhs, rhs);
                orCmd->execute();
                statusVector.push_back(orCmd->cmdStatus());
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
                }
            }
            else if (connectorsVector[k] == "||")
            {
                if (statusVector[k-1] == 1)
                {
                    SingleCmd* nextCmd = new SingleCmd(commandsVector[k+1]);
                    nextCmd->execute();
                    statusVector.push_back(nextCmd->cmdStatus());
                }
            }
        }
    }
}

int Connectors::cmdStatus()
{
    return 0;
}

