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


Connectors::Connectors(){}

Connectors::Connectors(char* userCommandWithConn)
{
    command = userCommandWithConn;
}

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
                status = andCmd->cmdStatus();
            }
            else if (connectorsVector[k] == "||")
            {
                SingleCmd* lhs = new SingleCmd(commandsVector[k]);
                SingleCmd* rhs = new SingleCmd(commandsVector[k+1]);
                Or* orCmd = new Or(lhs, rhs);
                orCmd->execute();
                statusVector.push_back(orCmd->cmdStatus());
                status = orCmd->cmdStatus();
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
                    status = nextCmd->cmdStatus();
                }
            }
            else if (connectorsVector[k] == "||")
            {
                if (statusVector[k-1] == 1)
                {
                    SingleCmd* nextCmd = new SingleCmd(commandsVector[k+1]);
                    nextCmd->execute();
                    statusVector.push_back(nextCmd->cmdStatus());
                    status = nextCmd->cmdStatus();
                }
            }
        }
    }
}

int Connectors::cmdStatus()
{
    return status;
}

