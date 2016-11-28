<<<<<<< HEAD
=======
// SingleCmd.cpp provides the implementation for the SingleCmd class

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
#include "SingleCmd.h"
<<<<<<< HEAD
#include "CDCmd.cpp"
=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
#include "TestCommand.cpp"

using namespace std;

<<<<<<< HEAD
=======
// The constructor takes a single char* user input and initializes it
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
SingleCmd::SingleCmd(){}

SingleCmd::SingleCmd(char* userCommand)
{
    command = userCommand;
}

<<<<<<< HEAD
=======
// This execute function provides the main source of executing for all of the other classes.
// The char* command is tokenized and sent into a char array, after which it is run through
// the execvp system call.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
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

<<<<<<< HEAD
    if (string(cmdToRun) == "cd")
    {
        CDCmd* cdCommand = new CDCmd(commandDeconstructed);
        cdCommand->execute();
        status = cdCommand->cmdStatus();
        return;
    }

=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4

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

<<<<<<< HEAD
int SingleCmd::cmdStatus()
{
    return status;
}
=======
// From the execvp the commands failure or success is piped and stored into status,
// This function returns the value of that status.
int SingleCmd::cmdStatus()
{
    return status;
}
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
