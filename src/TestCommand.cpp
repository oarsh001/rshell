// TestCommand.cpp is the implementation file for the test command in rshell.

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
#include <sys/types.h>
#include <sys/stat.h>
#include "TestCommand.h"

using namespace std;

// These are the constructors, one is empty one takes a vector of char.
TestCmd::TestCmd(){}

TestCmd::TestCmd(std::vector<char*> inputTestCmd)
{
    tokenizedTestCmd = inputTestCmd;
}

// The execute function determines the flag of the user's test command
// and will use the appropriate macro in determining the result of the test command
void TestCmd::execute()
{
    struct stat tcmd;

// testflag is the flag the user uses in the test command.
    string testFlag = tokenizedTestCmd[1];
    if (testFlag == "-e")
    {
        if (stat(tokenizedTestCmd[2], &tcmd) != -1)
        {
            cout << "(True)\n";
            status = 0;
        }
        else
        {
            cout << "(False)\n";
            status = 1;
            //perror("stat");  
        }
    }
    else if (testFlag == "-f")
    {
        if (stat(tokenizedTestCmd[2], &tcmd) != -1)
        {
            if (S_ISREG(tcmd.st_mode) == true)
            {
                cout << "(True)\n";
                status = 0;
            }
            else
            {
                cout << "(False)\n";
                status = 1;
            }
        }
        else
        {
            perror("stat");
            status = 1;
        }
    }
    else if (testFlag == "-d")
    {
        if (stat(tokenizedTestCmd[2], &tcmd) != -1)
        {
            if (S_ISDIR(tcmd.st_mode) == true)
            {
                cout << "(True)\n";
                status = 0;
            }
            else
            {
                cout << "(False)\n";
                status = 1;
            }
        }
        else
        {
            perror("stat");
            status = 1;
        }
    }

// if there is no user input, it uses the implementation of that of an e flag.
    else if (testFlag != "-e" && testFlag != "-f" && testFlag != "-d")
    {
        if (stat(tokenizedTestCmd[1], &tcmd) != -1)
        {
            cout << "(True)\n";
            status = 0;
        }
        else
        {
            cout << "(False)\n";
            status = 1;
            //perror("stat");  
        }
    }
}

// cmdStatus returns 0 if command succeeded or 1 if it failed.
int TestCmd::cmdStatus()
{
    return status;
}