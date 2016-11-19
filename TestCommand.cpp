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

TestCmd::TestCmd(){}

TestCmd::TestCmd(std::vector<char*> inputTestCmd)
{
    tokenizedTestCmd = inputTestCmd;
}

void TestCmd::execute()
{
    struct stat tcmd;

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

int TestCmd::cmdStatus()
{
    return status;
}