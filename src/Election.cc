#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "include/Election.h"
#include "include/AuditFile.h"
#include "include/Result.h"
#include "include/BallotIR.h"
#include "include/IRAlgorithm.h"
#include "include/BallotCPL.h"
#include "include/CPLAlgorithm.h"
#include "include/POAlgorithm.h"
#include "include/Party.h"
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

Election::Election() {}

void Election::run(AuditFile auditFile, Result result, vector<string> name)
{
    srand(time(NULL));              // Create a random seat based on the time
    vector<string> fileName = name; // Store the filename in a string
    if (fileName.size() == 0)
    {                                   // If a string is empty
        fileName = obtainFileName(cin); // obtain file name
    }

    parseFile(fileName, cin); // parse the file with the filename and the stream
}
vector<string> Election::obtainFileName(std::istream &input)
{
    vector<string> files;
    string fileName; // input the filename from the terminal
    cout << "Enter the name of the ballot voting data (with .csv at the end of the file)" << endl;
    input >> fileName;
    while (fileName.substr(fileName.length() - 4) != ".csv") // error checking for when the end of the file does not end with the .csv tag
    {
        cout << "Invalid file name. Enter the name of the ballot voting data (with .csv at the end of the file)" << endl;
        input >> fileName;
    }
    files.push_back(fileName);
    string yesOrNo;
    cout << "Do you want to enter another file (Y or N)" << endl;
    input >> yesOrNo;
    while (yesOrNo == "Y")
    {
        cout << "Enter the name of the ballot voting data (with .csv at the end of the file)" << endl;
        input >> fileName;
        while (fileName.substr(fileName.length() - 4) != ".csv") // error checking for when the end of the file does not end with the .csv tag
        {
            cout << "Invalid file name. Enter the name of the ballot voting data (with .csv at the end of the file)" << endl;
            input >> fileName;
        }
        files.push_back(fileName);
        cout << "Do you want to enter another file (Y or N)" << endl;
        input >> yesOrNo;
        if (yesOrNo == "N")
        {
            break;
        }
        if (yesOrNo != "N" && yesOrNo != "Y")
        {
            cout << "Invalid input. Enter Y or N." << endl;
            continue;
        }
    }

    return files;
}
string Election::obtainDate(std::istream &input)
{
    string date; // Used as a string to store the date from the user

    bool goodDate = false; // Used as a condition to leave the while loop

    while (!goodDate)
    {
        goodDate = true;
        cout << "Enter the data of the election in MM-DD-YYYY format" << endl;
        input >> date;
        string month = date.substr(0, 2); // Parse the date by the month, day, year
        string day = date.substr(3, 2);
        string year = date.substr(6, 4);
        if (date.substr(2, 1) != "-" && date.substr(5, 1) != "-") // ERROR CHECKING: To make sure the string is an actual date and contains dashes in certain indexes
        {
            cout << "Invalid format " << endl;
            goodDate = false;
            continue;
        }
        if (month.length() != 2 || day.length() != 2 || year.length() != 4) // ERROR CHECKING: Making sure the month contains two digits, day contains two digits, and the year contains 4 digits
        {
            cout << "Month, Day, Year is entered in the incorrect format" << endl;
            goodDate = false;
            continue;
        }
        if (!(isdigit(month[0]) && isdigit(month[1])))
        { // ERROR CHECKING: Making sure the month contains a digit for the month
            cout << "MM needs to be an integer between 01 and 12" << endl;
        }
        if (!(isdigit(day[0]) && isdigit(day[1])))
        { // ERROR CHECKING: Making sure the day contains a digit for the two characters
            cout << "DD needs to be an integer" << endl;
        }
        if (!(isdigit(year[0]) && isdigit(year[1]) && isdigit(year[2]) && isdigit(year[3])))
        { // ERROR CHECKING: Making sure the year contains a digit for all four characters
            cout << "YYYY needs to be an integer" << endl;
        }
        int m = stoi(month); // Convert the string version of month, day and year into integers
        int d = stoi(day);
        int y = stoi(year);
        if (m > 12 || m < 1) // ERROR CHECKING: Making sure the month parameter is a number between 01 and 12
        {
            cout << "Month needs to be a vale beteween 01 and 12" << endl;
            goodDate = false;
            continue;
        }
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) // ERROR CHECKING: Making sure the day parameter contains the valid number of days based on the month
        {
            if (d > 31 || d < 1) // MONTHS WITH A MAXIMUM OF 31 DAYS
            {
                cout << "Invalid day. Please pick a day between 01 and 30 for month: " << month << endl;
                goodDate = false;
                continue;
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            if (d > 30 || d < 1) // MONTHS WITH A MAXIMUM OF 30 DAYS
            {
                cout << "Invalid day. Please pick a day between 01 and 30 for month: " << month << endl;
                goodDate = false;
                continue;
            }
        }
        else if (m == 2)
        {
            int leapYear = -1;
            if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) // DETERMINE IF THE YEAR IS A LEAP YEAR
            {
                leapYear = 1;
            }
            if (leapYear = 1) // CASE 1: If the year is a leap year
            {
                if (d > 29 || d < 1) // ERROR CHECKING: Make sure the number of days is between 1 and 29
                {
                    cout << "Invalid day. Please pick a day between 01 and 29 for leap year" << endl;
                    goodDate = false;
                    continue;
                }
            }
            else // CASE 2: If the year is a leap year
            {
                if (d > 28 || d < 1) // ERROR CHECKING: Make sure the number of days is between 1 and 28
                {
                    cout << "Invalid day. Please pick a day between 01 and 28 for non leap year" << endl;
                    goodDate = false;
                    continue;
                }
            }
        }
        if (y > 2023) // ERROR CHECKING: Making sure the year is in the past
        {
            cout << "Invalid year. Please pick a year before 2023" << endl;
            goodDate = false;
            continue;
        }
    }
    return date;
}
int Election::parseFile(vector<string> fileName, std::istream &input)
{
    string line = "";
    ifstream file;                          // Creation of the ifstrean to parse the file
    Election myelec = Election();           // Create an instance of election to use the functions
    string date = myelec.obtainDate(input); // obtain the date of the election
    int parseInfo = -1;
    string votingType;

    int NumberOfBallots = 0;
    vector<BallotIR *> ballotsIR; // vector contiaining the vector of ballots
    vector<Candidate> candidates; // A vector of candidate to store all the candidates
    int numCandidates = 0;

    int numParties = 0;
    vector<Party *> parties;
    int NumberOfSeats = 0;
    vector<BallotCPL> ballotsCPL; // vector contiaining the vector of ballots

    vector<string> candidatesPo;
    vector<CandidatePO> POcandidates;
    int numBallots = 0;
    vector<BallotPO *> ballotsPO;

    for (int i = 0; i < fileName.size(); i++)
    {
        file.open(fileName.at(i)); // OPEN THE FILE
        if (file.is_open())        // FILE IS SUCCESSFULLY OPENED
        {
            getline(file, line);         // get the frist line of the file
            if (line.compare("IR") == 0) // CASE 1: If the voting type of the file  is an IR algorithm
            {
                if (votingType == "")
                {
                    votingType = line;
                }
                else
                {
                    if (votingType.compare(line) != 0)
                    {
                        cout << "All files must have the same voting type (CPL, IR, or PO)" << endl;
                        return 1;
                    }
                }
                getline(file, line); // get the number of candidates for the IR algorithm
                numCandidates = stoi(line);
                getline(file, line); // get the string containing the different candidates

                if (parseInfo == -1)
                {
                    string candidatesStr = line + ',';
                    string singleCandidate = "";
                    for (int i = 0; i < candidatesStr.length(); i++)
                    {
                        if (candidatesStr[i] != ',') // if the character is not a comma
                        {
                            singleCandidate += (candidatesStr[i]); // add the character to the string
                        }
                        else
                        {
                            candidates.push_back(Candidate(removeSpaces(singleCandidate))); // push the canindate onto the vector containing the vectors
                            singleCandidate = "";
                        }
                    }
                    parseInfo = 1;
                }
                getline(file, line); // obtain the number of ballots from the file
                NumberOfBallots += stoi(line);

                while (!file.eof())
                {
                    getline(file, line);
                    string ballotStr = line + ',';
                    BallotIR *ballot = this->IRParsing(ballotStr, numCandidates, candidates); // parse the ballot using the helper function

                    if (ballot->getNumCandidates() >= numCandidates / 2)
                    {
                        ballotsIR.push_back(ballot);
                    }; // add the ballot to the vector of ballots
                }
            }
            else if (line.compare("CPL") == 0) // CASE 2: The voting algorithm is considered to be a CPL algorithm
            {
                if (votingType == "")
                {
                    votingType = line;
                }
                else
                {
                    if (votingType.compare(line) != 0)
                    {
                        cout << "All files must have the same voting type (CPL, IR, or PO)" << endl;
                        return 1;
                    }
                }
                if (parseInfo == -1)
                {
                    cout << "VotingType " << votingType << endl;
                    getline(file, line); // get the number of parties

                    numParties = stoi(line);

                    getline(file, line); // get the string contianing the lsit of parties

                    string partyStr = line + ',';
                    parties = Election::CPLParsingParties(partyStr); // parse the string of parties into a vector of Party*

                    for (int i = 0; i < numParties; i += 1)
                    {
                        getline(file, line); // get the string of canindates for each party
                        string candidatesStr = line + ',';
                        vector<string> candidates = this->CPLParsingCandidates(candidatesStr); // parse the string of candidates for each party and store it in a vector of string
                        parties[i]->setCandidates(candidates);                                 // Set the vector of candidates to the main
                    }
                    getline(file, line); // get the nummber of seats avaliable

                    NumberOfSeats = stoi(line);
                    parseInfo = 1;
                }
                else
                {
                    for (int i = 0; i < (numParties + 3); i++)
                    {
                        getline(file, line);
                    }
                }

                getline(file, line); // get the number of ballots
                NumberOfBallots += stoi(line);
                while (!file.eof()) // Iterate through the ballots
                {
                    getline(file, line);
                    string ballotStr = line + ','; // store a ballot into a string
                    for (int i = 0; i < ballotStr.length(); i++)
                    {
                        if (ballotStr[i] != ',') // if the string is not a comma
                        {
                            BallotCPL ballot = BallotCPL(parties[i]->getName(), parties[i]); // create a ballot with the BallotCPL
                            ballotsCPL.push_back(ballot);                                    // add the ballot  to the vector of ballots
                            break;
                        }
                    }
                }
            }
            else if (line.compare("PO") == 0)
            {
                if (votingType == "")
                {
                    votingType = line;
                }
                else
                {
                    if (votingType.compare(line) != 0)
                    {
                        cout << "All files must have the same voting type (CPL, IR, or PO)" << endl;
                        return 1;
                    }
                }
                getline(file, line); // get the number of candidates for the IR algorithm
                numCandidates = stoi(line);
                getline(file, line);

                if (parseInfo == -1)
                {
                    candidatesPo = PoParsingCandidates(line);
                    for (int i = 0; i < candidatesPo.size(); i++)
                    {
                        POcandidates.push_back(CandidatePO(candidatesPo.at(i)));
                    }
                    parseInfo = 1;
                }

                // candidatesPo = PoParsingCandidates(line);
                // for(int i = 0; i < candidatesPo.size(); i++){
                //     POcandidates.push_back(CandidatePO(candidatesPo.at(i)));
                // }
                getline(file, line);
                numBallots += stoi(line);
                // vector<BallotPO*> ballots;
                while (!file.eof())
                {
                    getline(file, line);
                    int rank = 0;
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line[i] == ',')
                        {
                            rank += 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                    BallotPO *myballot = new BallotPO(candidatesPo, rank);
                    ballotsPO.push_back(myballot);
                }
            }

            file.close(); // close the file
            // return 0;
        }
        else // ERROR CHECKING IF THE FILE DOES NOT OPEN
        {
            cout << "ERROR OPENING FILE make sure your file name is correct" << endl;
            return 1;
        }
    }
    if (votingType.compare("IR") == 0)
    {
        // printf("Fall into IR\n");
        IRAlgorithm ir = IRAlgorithm(ballotsIR, numCandidates, candidates, NumberOfBallots); // create an instance of the IR algorithm
        ir.runIR();                                                                          // run the IR algorithm
        string winner = ir.getWinner();

        Result result = Result("IR", date, ir.getNumberOfCandidates(), ir.getCandidates(), ir.getNumberOfBallots(), ir.getBallot(), ir.getEliminatedCandidates(), winner, ir.getIRTable()); // Determine the result of the election and create a result to display information
        result.displayIRResult();                                                                                                                                                           // display the result onto the screen
        result.displayIRTable();
        AuditFile audit = AuditFile(date, "IR", ir.getNumberOfCandidates(), ir.getCandidates(), ir.getNumberOfBallots(), ir.getSteps(), ir.getWinner()); // Create an instance of the audit file class with the neccessary information
        audit.create_AuditFileIR();                                                                                                                      // create an audit file for the IR class
        return 0;
    }
    else if (votingType.compare("CPL") == 0)
    {

        CPLAlgorithm cpl = CPLAlgorithm(ballotsCPL, numParties, parties, NumberOfSeats, NumberOfBallots); // create an instance of a CPL algorithm

        cpl.runCPL(); // run the CPL algortithm

        vector<string> steps = cpl.getSteps();                                                                     // store the steps taken when performing the algorithm into the steps vector
        Result result = Result("CPL", date, cpl.getNumberOfParties(), cpl.getParties(), cpl.getNumberOfBallots()); // create an instance of the Result class with the neccessary infromation
        result.displayCPLResult();                                                                                 // display the result of the CPL onto to the screen
        string winners = result.getWinner();                                                                       // Get the winners of the CPL algortihm

        AuditFile audit = AuditFile(date, "CPL", cpl.getNumberOfParties(), cpl.getParties(), cpl.getNumberOfBallots(), steps, winners); // Create an instance of the auditFile
        audit.create_AuditFileCPL();                                                                                                    // Create the audit file of the CPL algorithm
        return 0;
    }
    else if (votingType.compare("PO") == 0)
    {
        POAlgorithm po = POAlgorithm(ballotsPO, POcandidates.size(), POcandidates, numBallots);
        po.runPO();
        string winner = po.getWinner();

        Result result = Result("PO", date, po.getBallot(), po.getNumberOfCandidates(), po.getCandidates(), po.getNumberOfBallots(), winner);
        result.displayPOResult();
    }
    else
    {
        cout << "Voting type is incorrected" << endl;
        return 1;
    }
    return 0;
}

BallotIR *Election::IRParsing(string ballotStr, int numCandidates, vector<Candidate> candidates)
{
    vector<string> candidates_string(numCandidates, ""); // Vector of string that represents the list of candidates separated by commas
    string rank = "";
    int candidateIndex = 0;
    int numValidCandidates = 0;
    for (int i = 0; i < ballotStr.length(); i++)
    {
        if (ballotStr[i] != ',') // If the character is not a comma
        {
            rank += ballotStr[i]; // add the character onto the rank string
        }
        else // If the character is a comma
        {
            if (rank != "") // If the current rank string is empty
            {
                candidates_string.at(stoi(rank) - 1) = candidates[candidateIndex].getCandidateName(); // get the Name of the canidate and placed in the correct index on the vetor
                rank = "";
                numValidCandidates++;
            }
            candidateIndex += 1;
        }
    }
    BallotIR *ballot = new BallotIR(candidates_string, numValidCandidates); // create an instance of a BallotIR with the string of candidates
    return ballot;
}
vector<Party *> Election::CPLParsingParties(string partyStr)
{
    vector<Party *> parties; // create a vector of Party*
    string singleParty = "";
    for (int i = 0; i < partyStr.length(); i++)
    {
        if (partyStr[i] != ',') // if the character is not a comma
        {
            singleParty += (partyStr[i]); // Add the character to the empty string
        }
        else
        {
            string party = removeSpaces(singleParty); // remove any extra spaces
            parties.push_back(new Party(party));      // Add the new party to the vector of parties
            singleParty = "";
        }
    }
    return parties; // return the vector of parties
}

vector<string> Election::CPLParsingCandidates(string candidatesStr)
{
    vector<string> candidates; // create a vector of string representing the candidates frin the file
    string singleCandidate = "";
    for (int i = 0; i < candidatesStr.length(); i++)
    {
        if (candidatesStr[i] != ',') // if the character is not a comma
        {
            singleCandidate += (candidatesStr[i]); // add the character onto the string
        }
        else
        {
            string candidate = removeSpaces(singleCandidate); // remove any spaces from the character
            candidates.push_back(candidate);                  // add the candidate to the vector of candidates
            singleCandidate = "";
        }
    }
    return candidates;
}
bool Election::edge(const int num)
{
    return num == 1;
}

vector<string> Election::PoParsingCandidates(string line)
{
    std::vector<std::string> all;
    int bracket = 0;
    std::string::size_type start = 0;
    for (int i = 0; i < line.size(); i++)
    {
        const char c = line[i];
        if (c == '[')
        {
            bracket++;
            if (edge(bracket))
            {
                start = i + 1;
            }
        }
        if (c == ']')
        {
            if (edge(bracket))
            {
                all.push_back(line.substr(start, i - start));
            }
            bracket--;
        }
        if (c == '|' && edge(bracket))
        {
            all.push_back(line.substr(start, i - start));
            start = i + 1;
        }
    }
    return all;
}

string Election::removeSpaces(string input)
{
    string output = "";
    int i = 0;
    int n = input.size();

    for (int i = 0; i < n; i++)
    {
        if (input[i] != ' ') // if the character is not a space add it onto the final string
        {
            output += input[i];
        }
    }
    return output; // putput the string
}
