<<<<<<< HEAD
=======
// The Or class is impemented here.

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
#include "Or.h"

using namespace std;

<<<<<<< HEAD
=======
// Two Execution base class inputs are taken and initilizaed in the constructor.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
Or::Or(){}

Or::Or(Execution *firstCmd, Execution *secondCmd)
{
    leftCmd = firstCmd;
    rightCmd = secondCmd;
}

<<<<<<< HEAD
=======
// Depending on the leftCmd execute's return status, the rightCmd will execute
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
