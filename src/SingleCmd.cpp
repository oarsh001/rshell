// SingleCmd.cpp provides the implementation for the SingleCmd class

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
#include "TestCommand.cpp"

using namespace std;

// The constructor takes a single char* user input and initializes it
SingleCmd::SingleCmd(){}

SingleCmd::SingleCmd(char* userCommand)
{
    command = userCommand;
}

// This execute function provides the main source of executing for all of the other classes.
// The char* command is tokenized and sent into a char array, after which it is run through
// the execvp system call.
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

// From the execvp the commands failure or success is piped and stored into status,
// This function returns the value of that status.
int SingleCmd::cmdStatus()
{
    return status;
}
