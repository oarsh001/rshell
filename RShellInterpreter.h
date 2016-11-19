#ifndef RShellInterpreter_H
#define RShellInterpreter_H

class RShellInterpreter
{
    private:
        string fullUserInput;
        vector<char*> cmds;
    public:
        RShellInterpreter();
        RShellInterpreter(string input);
        void interpret();
};

#endif