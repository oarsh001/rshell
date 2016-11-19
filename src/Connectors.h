#ifndef Connectors_H
#define Connectors_H

#include "Execution.h"

class Connectors : public Execution
{
    private:
        char* command;
        vector<char *> commandsVector;
        vector<string> connectorsVector;
        vector<int> statusVector;
    public:
        Connectors();
        Connectors(char* userCommandWithConn);
        void execute();
        int cmdStatus();
};

#endif