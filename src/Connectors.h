#ifndef Connectors_H
#define Connectors_H

#include "Execution.h"

class Connectors : public Execution
{
    private:
        char* command;
<<<<<<< HEAD
        int status;
=======
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
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