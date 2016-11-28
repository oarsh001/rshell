#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>
#include <errno.h>
#include <vector>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

class CDCmd: public Execution
{
	private:
		std::vector<char*> cdVector;
		int status;
	public:
		CDCmd(){};
		CDCmd(std::vector<char*> inputTestCmd)
		{
			cdVector = inputTestCmd; 
		};

		void execute ()
		{
			if (cdVector.size() == 1)
			{
				setenv("OLDPWD", getenv("PWD"), 1);	
				setenv("PWD", getenv("HOME"), 1);
				chdir(getenv("HOME"));
			}
			else if ( std::string(cdVector[1]) == "-")
			{
				char* temp = getenv("PWD");
				setenv("PWD", getenv("OLDPWD"), 1);
				chdir(getenv("OLDPWD"));
				setenv("OLDPWD", temp, 1);
			}

			else if (cdVector.size() > 1)
			{
				struct stat checker;

				if (stat(cdVector[1], &checker) != -1)
				{
					if (S_ISDIR(checker.st_mode) == true)
					{
						setenv("OLDPWD", getenv("PWD"), 1);
						
						stringstream ss1;
						string s1;
						
						stringstream ss2;
						string s2;

						string nextDir;
						
						char* presentDir = get_current_dir_name();
						ss1 << presentDir;
						ss1 >> s1;
						
						char* inputDir = cdVector[1];
						ss2 << inputDir;
						ss2 >> s2;

						nextDir = s1 + "/" + s2;
						
						setenv("PWD", nextDir.c_str(), 1);
						chdir(nextDir.c_str());
						status = 0;
					}
					else
					{
						status = 1;
					}
				}	
				else
				{
					status = 1;
				}
			}

			if ( errno != 0)
			{
				status = 1; 
				errno = 0;
			}
		};

	int cmdStatus()
	{
		return status;
	};
};
