<<<<<<< HEAD
=======
// And.cpp implements the And class

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
#include "And.h"

using namespace std;

And::And(){}

<<<<<<< HEAD
=======
// The base class is the Execution class, And takes two objects of its type.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
And::And(Execution *firstCmd, Execution *secondCmd)
{
    leftCmd = firstCmd;
    rightCmd = secondCmd;
}

<<<<<<< HEAD
=======
// The And execute determines whether to run the right command depending on the
// value of the left commands status after its execution.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
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

<<<<<<< HEAD
int And::cmdStatus()
{
    return status;
}
=======
// This gives the status of the whole And object after execution
int And::cmdStatus()
{
    return status;
}
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
