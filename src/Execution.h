// This is the base class, it has two functions,
// one is for executing the users input command
// two is for returning the status of whether the last execute failed or succeeded.

#ifndef Execution_H
#define Execution_H

class Execution
{
    public:
        Execution(){};
        virtual void execute() = 0;
        virtual int cmdStatus() = 0;
};

#endif
