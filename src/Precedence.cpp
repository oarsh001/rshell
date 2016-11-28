<<<<<<< HEAD
class Precedence : public Execution
{
=======
// Precedence.cpp makes a solid attempt to tokenize and execute commands that are in 
// parantheseses.

class Precedence : public Execution
{
// There are 3 ints, one is the status of the Precedence, the other two are counters
// for each type of paranthesis, either right or left.
// The bools are used throughout as check for the existence of a connector.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
private:
    int status;
    int leftParanthesisCounter;
    int rightParanthesisCounter;
    char* command;
    bool paranCheck;
    bool connCheck;
    bool connCheck1;
    bool connCheck2;
    bool connCheck3;
<<<<<<< HEAD

=======
    
// Theres a vector for storing commands, for connectors, for statuses, and
// one for holding Execution base class objects.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
    vector<char*> commandsVector;
    vector<string> connectorsVector;
    vector<int> statusVector;
    vector<Execution*> execVector; 

public:
<<<<<<< HEAD
=======
// The Precedence constructor takes a users input as a char array.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
    Precedence(){};
    Precedence(char* input)
    {
        command = input;
    };

<<<<<<< HEAD
=======
// This function's purpose is to tokenize parantheses commands, by storing
// the contents that are inside of paranthesis in the appropriate vector.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
    void checkParanthesis()
    {   
        int leftParanthesisCounter = 0;  
        int rightParanthesisCounter = 0;  
        size_t firstLeftParanPos = 0;
        size_t lastRightParanPos = 0;
        string cmdInString = string(command);

<<<<<<< HEAD
        for (unsigned i = 0; i <= cmdInString.length(); i++)
        {   
            if (leftParanthesisCounter == 0 && rightParanthesisCounter == 0)
            {
=======
// The main for loop, it runs through each letter in the char*, treating it as an array.
        for (unsigned i = 0; i <= cmdInString.length(); i++)
        {   
// When both parantheses counters are 0, this means the contents are elements not in parantheses.
            if (leftParanthesisCounter == 0 && rightParanthesisCounter == 0)
            {
// When it finds an && not in parantheses it is added to the connectors vector.            
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
                if (command[i] == '&' && command[i+1] == '&')
                {
                    connectorsVector.push_back("&&");

                    if (commandsVector.empty())
                    {
                        string y = cmdInString.substr(0, i-0);
                        char* tokNonParCmd = new char[y.length()];
                        strcpy(tokNonParCmd, y.c_str());
                        commandsVector.push_back(tokNonParCmd);
                    }
                }

<<<<<<< HEAD
=======
// When it finds an || not in parantheses it is added to the connectors vector.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
                else if (command[i] == '|' && command [i+1] == '|')
                {
                    connectorsVector.push_back("||");
                    
                    if (commandsVector.empty())
                    {
                        string y = cmdInString.substr(0, i-0);
                        char* tokNonParCmd = new char[y.length()];
                        strcpy(tokNonParCmd, y.c_str());
                        commandsVector.push_back(tokNonParCmd);
                    }
                }
            }

            if (command[i] == '(')
            {
                leftParanthesisCounter++;
                if (leftParanthesisCounter == 1)
                {
                    firstLeftParanPos = i++;   
                }
            }
            else if (command[i] == ')')
            {
<<<<<<< HEAD
=======
// When the counters match and are not zero, the contents within the parantheses are 
// added to the commands vector            
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
                rightParanthesisCounter++;
                if (leftParanthesisCounter == rightParanthesisCounter)
                {
                    lastRightParanPos = i;

                    string x = cmdInString.substr(firstLeftParanPos+1,(lastRightParanPos-firstLeftParanPos)-1); 
                    int last = x.length();
                    if (x[0] == '(' && x[last] != ')')
                    {
                        x.append(")");
                    }
                    
                    char* tokParCmd = new char[x.length()];
                    strcpy(tokParCmd, x.c_str());
                    
                    if (x.find("(") != string::npos)
                    {
                        command = tokParCmd;
                        checkParanthesis();
                    }

                    commandsVector.push_back(tokParCmd);

<<<<<<< HEAD
=======
// The counter is reset and the loop starts again.
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
                    leftParanthesisCounter = 0;
                    rightParanthesisCounter = 0;

                }
            }
        }
<<<<<<< HEAD


=======
        
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
/*      string help = string(command).substr(strlen(command)-1);
        cout << help << endl;
        if (help != ")")
        {
            paranCheck = true;
        }

        if (connectorsVector.back() == "&&" && paranCheck)
        {
            char* lastAnd = strrchr(command, '&');
            string lastAndStr = string(lastAnd);
            string c = lastAndStr.substr(1);
            
            char* tokLastCmd = new char[c.length()];
            strcpy(tokLastCmd, c.c_str());
            cout << tokLastCmd << endl;
            commandsVector.push_back(tokLastCmd);
            
        }
        else if (connectorsVector.back() == "||")
        {
            char* lastAnd = strrchr(command, '|');
            string lastAndStr = string(lastAnd);
            string c = lastAndStr.substr(1);
            
            char* tokLastCmd = new char[c.length()];
            strcpy(tokLastCmd, c.c_str());
            commandsVector.push_back(tokLastCmd);
        } */
        execute();
    };

<<<<<<< HEAD
=======
// The execute functions purpose is to run the commands stored in the commands vector
// It also applies the right logic in regards to connectors, meaning which command
// to execute when determining the appropriate connector.
// Most of the logic is very similar to the connectors.cpp class implementation
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
    void execute()
    {
        if (connectorsVector.empty())
        {
            for (unsigned v = 0; v < commandsVector.size(); v++)
            {
                for (unsigned q = 0; q < string(commandsVector[v]).length(); q++)
                {
                    if (commandsVector[v][q] == '&' || commandsVector[v][q] == '|')
                    {
                        connCheck = true;
                    }
                }

                if (!connCheck)
                {
                    SingleCmd* lhs = new SingleCmd(commandsVector[v]);
                    lhs->execute();
                    statusVector.push_back(lhs->cmdStatus());
                    status = lhs->cmdStatus();
                }
                else if (connCheck)
                {
                    Connectors* lhs = new Connectors(commandsVector[v]);
                    lhs->execute();
                    statusVector.push_back(lhs->cmdStatus());
                    status = lhs->cmdStatus();
                }
            }
        }
        
        for (unsigned k = 0; k < connectorsVector.size(); k++)
        {
            execVector.clear();
            if (k == 0)
            {
                for (unsigned q = 0; q < string(commandsVector[k]).length(); q++)
                {
                    if (commandsVector[k][q] == '&' || commandsVector[k][q] == '|')
                    {
                        connCheck1 = true;
                    }
                }

                for (unsigned q = 0; q < string(commandsVector[k+1]).length(); q++)
                {
                    if (commandsVector[k+1][q] == '&' || commandsVector[k+1][q] == '|')
                    {
                        connCheck2 = true;
                    }
                }

                if (connectorsVector[k] == "&&")
                {
                    if (connCheck1)
                    {
                        Connectors* lhs = new Connectors(commandsVector[k]);
                        execVector.push_back(lhs);
                    }
                    else
                    {
                        SingleCmd* lhs = new SingleCmd(commandsVector[k]);
                        execVector.push_back(lhs);
                    }
                    
                    if (connCheck2)
                    {
                        Connectors* rhs = new Connectors(commandsVector[k+1]);
                        execVector.push_back(rhs);
                    }
                    else
                    {
                        SingleCmd* rhs = new SingleCmd(commandsVector[k+1]);
                        execVector.push_back(rhs);
                    }
                    And* andCmd = new And(execVector[0], execVector[1]);
                    andCmd->execute();
                    statusVector.push_back(andCmd->cmdStatus());
                    status = andCmd->cmdStatus();
                }
                else if (connectorsVector[k] == "||")
                {
                    if (connCheck1)
                    {
                        Connectors* lhs = new Connectors(commandsVector[k]);
                        execVector.push_back(lhs);
                    }
                    else
                    {
                        SingleCmd* lhs = new SingleCmd(commandsVector[k]);
                        execVector.push_back(lhs);
                    }
                    
                    if (connCheck2)
                    {
                        Connectors* rhs = new Connectors(commandsVector[k+1]);
                        execVector.push_back(rhs);
                    }
                    else
                    {
                        SingleCmd* rhs = new SingleCmd(commandsVector[k+1]);
                        execVector.push_back(rhs);
                    }
                    Or* orCmd = new Or(execVector[0], execVector[1]);
                    orCmd->execute();
                    statusVector.push_back(orCmd->cmdStatus());
                    status = orCmd->cmdStatus();
                }
            }
            else
            {
                for (unsigned q = 0; q < string(commandsVector[k+1]).length(); q++)
                {
                    if (commandsVector[k+1][q] == '&' || commandsVector[k+1][q] == '|')
                    {
                        connCheck3 = true;
                    }
                }

                if (connectorsVector[k] == "&&")
                {
                    if (statusVector[k-1] == 0)
                    {
                        if (connCheck3)
                        {
                            Connectors* nextCmd = new Connectors(commandsVector[k+1]);
                            nextCmd->execute();
                            statusVector.push_back(nextCmd->cmdStatus());
                            status = nextCmd->cmdStatus();
                        }
                        else
                        {
                            SingleCmd* nextCmd = new SingleCmd(commandsVector[k+1]);
                            nextCmd->execute();
                            statusVector.push_back(nextCmd->cmdStatus());
                            status = nextCmd->cmdStatus();
                        }
                    }
                }
                else if (connectorsVector[k] == "||")
                {
                    if (statusVector[k-1] == 1)
                    {
                        if (connCheck3)
                        {
                            Connectors* nextCmd = new Connectors(commandsVector[k+1]);
                            nextCmd->execute();
                            statusVector.push_back(nextCmd->cmdStatus());
                            status = nextCmd->cmdStatus();
                        }
                        else
                        {
                            SingleCmd* nextCmd = new SingleCmd(commandsVector[k+1]);
                            nextCmd->execute();
                            statusVector.push_back(nextCmd->cmdStatus());
                            status = nextCmd->cmdStatus();
                        }
                    }
                }
            }
            connCheck1 = false;
            connCheck2 = false;
            connCheck3 = false;
        }
    }

    int cmdStatus()
    {
        return status;
    };

<<<<<<< HEAD
};
=======
};
>>>>>>> 56bd62281e3d6e5bd0e649f1ac11460dca9929a4
