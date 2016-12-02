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