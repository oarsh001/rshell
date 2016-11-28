<<<<<<< HEAD
=======
// This is the base class, it has two functions,
// one is for executing the users input command
// two is for returning the status of whether the last execute failed or succeeded.

>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
#ifndef Execution_H
#define Execution_H

class Execution
{
    public:
        Execution(){};
        virtual void execute() = 0;
        virtual int cmdStatus() = 0;
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
