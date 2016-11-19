class Precedence : public Execution
{
private:
    int status;
    int leftParanthesisCounter;
    int rightParanthesisCounter;
    char* command;
    bool connCheck;
    bool connCheck1;
    bool connCheck2;
    bool connCheck3;

    vector<char*> commandsVector;
    vector<string> connectorsVector;
    vector<int> statusVector;
    vector<Execution*> execVector; 

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
        size_t lastRightParanPos = 0;
        string cmdInString = string(command);

        //char* lastAnd = strrchr(command,'&');
        //char* lastOr = strrchr(command,'|');
        //cout << strlen(command);

        //cout << lastAnd << endl;

        for (unsigned i = 0; i <= cmdInString.length(); i++)
        {   
            if (leftParanthesisCounter == 0 && rightParanthesisCounter == 0)
            {
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
                        //checkParanthesis();
                    }

                    commandsVector.push_back(tokParCmd);
                    
                   // cout << "\n check\n" << commandsVector[0] << endl;

                    leftParanthesisCounter = 0;
                    rightParanthesisCounter = 0;

                }
            }
          
        }
       /* for (unsigned e = 0; e < commandsVector.size(); e++)
        {
            cout << commandsVector[e] << " " << endl;
        }
             for (unsigned e = 0; e < connectorsVector.size(); e++)
        {
            cout << connectorsVector[e] << " " << endl;
        }*/
  
        //cout << lastOr << " " << lastAnd;
            /*if (lastAnd > lastOr)
            {
                cout << "heyy.\n";
            }
            else
            {
                cout << "yeah.\n";
            }*/
        
        //execute();
    };

    void execute()
    {
        if (connectorsVector.empty())
        {
            for (unsigned v = 0; v < commandsVector.size(); v++)
            {
                for (unsigned q = 0; q < string(commandsVector[v]).length(); q++)
                {
                    //cout << commandsVector[v][q] << " ";
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

};

      /*  for (unsigned e = 0; e < statusVector.size(); e++)
        {
            cout << statusVector[e] << " " << endl;
        }*/