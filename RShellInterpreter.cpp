#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>
#include <vector>
#include "SingleCmd.cpp"
#include "Connectors.cpp"
#include "Precedence.cpp"
#include "RShellInterpreter.h"

using namespace std;

RShellInterpreter::RShellInterpreter(){}

RShellInterpreter::RShellInterpreter(string input)
{
    fullUserInput = input;
}

void RShellInterpreter::interpret()
{
    char* fullUserInputChar = new char[fullUserInput.length() + 1];
    strcpy(fullUserInputChar, fullUserInput.c_str());

    char* cmdToken = strtok(fullUserInputChar, ";");
    while (cmdToken != 0)
    {
        cmds.push_back(cmdToken);
        cmdToken = strtok(NULL, ";");
    }

    for (unsigned i = 0; i < cmds.size(); i++)
    {
        if (string(cmds[i]).find("(") != string::npos 
        && string(cmds[i]).find(")") != string::npos)
        {
            Precedence* aCommandWithPara = new Precedence(cmds[i]);
            aCommandWithPara->checkParanthesis();
        }
        else if (string(cmds[i]).find("&&") == string::npos 
        && string(cmds[i]).find("||") == string::npos)
        {
            SingleCmd* aCommand = new SingleCmd(cmds[i]);
            aCommand->execute();
        }
        else
        {
            Connectors* aCommandWithConn = new Connectors(cmds[i]);
            aCommandWithConn->execute();
        }
    }
    delete[] fullUserInputChar;
}
