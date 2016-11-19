#ifndef SingleCmd_H
#define SingleCmd_H

#include "Execution.h"

class SingleCmd : public Execution
{
    private:
        char* command;
        int status;
        std::vector <char*> commandDeconstructed;
    public:
        SingleCmd();
        SingleCmd(char* userCommand);
        void execute();
        int cmdStatus();
};

#endif