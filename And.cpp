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
#include "And.h"

using namespace std;

And::And(){}

And::And(Execution *firstCmd, Execution *secondCmd)
{
    leftCmd = firstCmd;
    rightCmd = secondCmd;
}

void And::execute()
{
    leftCmd->execute();
    if (leftCmd->cmdStatus() == 0)
    {
        rightCmd->execute();
        if (rightCmd->cmdStatus() == 0)
        {
            status = 0;
        }
        else
        {
            status = 1;
        }
    }
    else
    {
        status = 1;
    }
}

int And::cmdStatus()
{
    return status;
}