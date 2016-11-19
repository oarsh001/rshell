// The Or class is impemented here.

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
#include "Or.h"

using namespace std;

// Two Execution base class inputs are taken and initilizaed in the constructor.
Or::Or(){}

Or::Or(Execution *firstCmd, Execution *secondCmd)
{
    leftCmd = firstCmd;
    rightCmd = secondCmd;
}

// Depending on the leftCmd execute's return status, the rightCmd will execute
void Or::execute()
{
    leftCmd->execute();
    if (leftCmd->cmdStatus() == 1)
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
        status = 0;
    }
}

int Or::cmdStatus()
{
    return status;
}
