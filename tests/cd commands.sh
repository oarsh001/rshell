!#/bin/sh

# test cases using cd

cd | ./RShell                     # this will take to to the home directory

cd - | ./RShell                 # this will go back to the last working directory 
         
cd check | ./RShell        #this will check if the folder is in the dir. and go the directory called check
 
cd blah | ./RShell           # this keeps us in the same directory because folder does not exist

cd check; cd - | ./RShell  	      #this show you can change to a path and return using cd - 

cd check; cd -; cd - | ./RShell          #this will go from check to the last working dir and then back to check 

cd check && echo A | ./RShell        #this should change our dir to check and display A

cd blah && echo A | ./RShell  	     # this does not output A

cd check || echo A | ./RShell  	     # this does not output A but it changes our directory

cd blah || echo A | ./RShell  	     # this does out put A and keeps us in the same directory since the one typed 
			     #doesn’t not exist.

cd check .. ; cd src ; cd | ./RShell   #this shows you can go to home after multiple cd commands

(cd) | ./RShell       		    #This shows cd works within parenthesis

(cd && echo A) | ./RShell  	     # this shows cd works within parenthesis 

(cd -) | ./RShell  			    # This shows you can change to previous directory in parenthesis   
