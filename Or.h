#ifndef Or_H
#define Or_H

#include "Execution.h"

class Or : public Execution
{
    private:
        Execution *leftCmd;
        Execution *rightCmd;
        int status;
    public:
        Or();
        Or(Execution *firstCmd, Execution *secondCmd);
        void execute();
        int cmdStatus();
};

#endif