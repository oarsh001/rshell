class Precedence : public Execution
    {
    private:
        int status;
        int leftParanthesisCounter;
        int rightParanthesisCounter;
        char* command;
        vector<char*> tokenizedPrecedenceCmds;

    public:
        Precedence(){};
        Precedence(char* input)
        {
            command = input;
        };

        void checkParanthesis()
        {   
            int leftParanthesisCounter = 0;  
            int rightParanthesisCounter = 0;  
            size_t firstLeftParanPos = 0;
            size_t lastRightParanPos = 0;;
            string cmdInString = string(command);

            for (unsigned i = 0; i < cmdInString.length(); i++)
            {   
                if (command[i] == '(')
                {
                    leftParanthesisCounter++;
                    if (leftParanthesisCounter == 1)
                    {
                        firstLeftParanPos = i;
                    }
                }
                else if (command[i] == ')')
                {
                    rightParanthesisCounter++;
                    if (leftParanthesisCounter == rightParanthesisCounter)
                    {
                        lastRightParanPos = i;

                        string x = cmdInString.substr(firstLeftParanPos+1,lastRightParanPos-1); 
                        cout << x << endl;
                        cmdInString = cmdInString.substr(lastRightParanPos)+1;
                        cout << cmdInString << endl;
                    }
                }
            }
        };

        void execute()
        {
            tokenizedPrecedenceCmds.clear();
            char* precedenceCmdToken = strtok(command, "()");

            while (precedenceCmdToken != 0)
            {
                tokenizedPrecedenceCmds.push_back(precedenceCmdToken);
                precedenceCmdToken = strtok(NULL, "()");
            }

            for (unsigned x = 0; x < tokenizedPrecedenceCmds.size(); x++ )
            {
                cout << tokenizedPrecedenceCmds[x] << x << "\n";
            }
        }

        int cmdStatus()
        {
            return status;
        };

    } ;