#ifndef AND_H
#define AND_H

#include "Execution.h"

class And : public Execution
{
    private:
        Execution *leftCmd;
        Execution *rightCmd;
        int status;
    public:
        And();
        And(Execution *firstCmd, Execution *secondCmd);
        void execute();
        int cmdStatus();
};

#endif