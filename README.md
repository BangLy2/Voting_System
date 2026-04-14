# Voting_System
Team number: 08

Member names and x500: James Kropiwka (kropi015), Aiden Fujiwara (fujiw011), Nuh Misirli (misir002), Bang Ly (ly000051)

Do this before any thing else! To get Access to file in this github repo:

Create a directory.
Go into the newly created directory and open the terminal to it.
In the terminal, input “git clone git@github.umn.edu:umn-csci-5801-01-S23/repo-Team8.git” to git clone our project into a directory.
Now you will have the repository on your local machine. You can move onto the next steps now.
The steps to run the simulation in a lab machine are:

SSH into a lab machine.
In the terminal, get to the directory with the repository in it.
In the terminal, input “cd Project1/src” to change the directory of the terminal to the source file for our Ballot Buddy system.
In the terminal, input “make” to compile our project.
In the terminal, input “./run [fileName1] [fileName2] [fileName3]..." where fileName1, fileName2, and fileName3 are csv files to run our Ballot Buddy system. You can run BallotBuddy with at least one csv file.
If there are anything wrong you can remake by inputting "make clean" and the "make" again.
The steps to run the unit test in a lab machine are:

SSH into a lab machine.
In the terminal, get to the directory with the repository in it.
In the terminal, input “cd Project1/testing to change the directory of the terminal to the testing directory our Ballot Buddy unit test.
In the terminal, input “make test” to compile our unit test.
In the terminal, input “./Test" to run our Ballot Buddy system unit test.
The steps to run the system tests in a lab machine are:

SSH into a lab machine.
move system test files found in /testing/testingFiles like "SystemTestIR1" to the /src and run the simulation normally
The steps to run doxygen are:

In the terminal, get to the directory with the repository in it.
In the terminal, input "cd Project1/documentation/docs" then input "doxygen Doxyfile" which will create the doxygen.
go to ~/repo-team8/documentation/docs/html in your file explorer and open index.html in your preferred browser
Any special handling or issues:
