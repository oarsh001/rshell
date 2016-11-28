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
#include "SingleCmd.h"
#include "CDCmd.cpp"
#include "TestCommand.cpp"

using namespace std;

SingleCmd::SingleCmd(){}

SingleCmd::SingleCmd(char* userCommand)
{
    command = userCommand;
}

void SingleCmd::execute()
{
    commandDeconstructed.clear();
    char* cmdToken = strtok(command, " ");
    while (cmdToken != 0)
    {
        commandDeconstructed.push_back(cmdToken);
        cmdToken = strtok(NULL, " ");
    }

    char *commandArray[30];
    for (unsigned j = 0; j < commandDeconstructed.size(); j++)
    {
        commandArray[j] = commandDeconstructed[j];
    }
    char* cmdToRun = commandDeconstructed[0];
    commandArray[commandDeconstructed.size()] = NULL;


    if (string(cmdToRun) == "test" || string(cmdToRun) == "[" )
    {
        TestCmd* aTestCommand = new TestCmd(commandDeconstructed);
        aTestCommand->execute();
        status = aTestCommand->cmdStatus();
        return;
    }

    if (string(cmdToRun) == "cd")
    {
        CDCmd* cdCommand = new CDCmd(commandDeconstructed);
        cdCommand->execute();
        status = cdCommand->cmdStatus();
        return;
    }


    int statusPipe[2];
    status = 0;

    pipe(statusPipe);

    int pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        close(statusPipe[0]);

        if (execvp(cmdToRun, commandArray) < 0)
        {
            status = 1;
            write(statusPipe[1], &status, sizeof(status));
            close(statusPipe[1]);
            exit(1);
        }     
    }
    else
    {
        wait(0);

        close(statusPipe[1]);
        read(statusPipe[0], &status, sizeof(status));
        close(statusPipe[0]);
    }
}

int SingleCmd::cmdStatus()
{
    return status;
}