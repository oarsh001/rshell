#ifndef TestCmd_H
#define TestCmd_H

#include "Execution.h"

class TestCmd : public Execution
{
    private:
        int status;
        std::vector <char*> tokenizedTestCmd;
    public:
        TestCmd();
        TestCmd(std::vector<char*> inputTestCmd);
        void execute();
        int cmdStatus();
};

#endif