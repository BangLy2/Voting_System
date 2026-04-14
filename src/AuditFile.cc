#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "include/AuditFile.h"
#include "include/Candidate.h"
using namespace std;
AuditFile::AuditFile()
{
    type_of_voting = " ";
    number_of_candidates = 0; // candidates is already an empty vector?? So no need to initalize?
    NumberOfBallots = 0;      // steps is already an empty vector?? So no need to initalize?
    winner = " ";
}
AuditFile::AuditFile(string date, string VotingType, int CandidateNum, vector<Candidate> candidates, int ballotNum, vector<string> steps, string winner)
{
    this->date = date;
    type_of_voting = VotingType;
    number_of_candidates = CandidateNum;
    this->candidates = candidates;
    NumberOfBallots = ballotNum;
    this->steps = steps;
    this->winner = winner;
}
AuditFile::AuditFile(string date, string VotingType, int PartyNum, vector<Party *> parties, int ballotNum, vector<string> steps, string winners)
{
    this->date = date;
    type_of_voting = VotingType;
    number_of_parties = PartyNum;
    this->parties = parties;
    NumberOfBallots = ballotNum;
    this->steps = steps;
    this->winner = winners;
}
string AuditFile::create_AuditFileIR()
{
    string fileName = type_of_voting + date + ".txt";
    string date = "MM/DD/YYYY";
    ofstream file(fileName, ofstream::out); // create a output file name with the type of voting + date of election.txt
    if (file.is_open())
    {                                                                    // If the file is created successfuly
        file << "Voting Type: " + type_of_voting << "\n";                // write the voting type to the file
        file << "Number of Candidates: " + number_of_candidates << "\n"; // wrtie the number of candidates onto the file
        file << "Candidates: ";
        // write  the list of candidates onto the file
        for (int i = 0; i < candidates.size(); i++)
        {
            file << candidates.at(i).getCandidateName() << " ";
        }
        file << endl;
        file << "Number of Ballots: " << NumberOfBallots << "\n"; // write out the number of ballots onto the file
        file << "Steps: ";                                        // write out the steps taken to create the audit file
        for (int i = 0; i < steps.size(); i++)
        {
            file << steps.at(i) << " ";
        }
        file << endl;
        file << "Winner: " << winner << "\n"; // write out the winner of the election onto the file
        file.close();
        return fileName;
    }
    else
    {
        cout << "Problem creating the audit file " << endl; // error creating the audit file
        return "error";
    }
}

string AuditFile::create_AuditFileCPL()
{
    // ofstream file;
    string fileName = type_of_voting + date + ".txt";
    // file.open(fileName);
    ofstream file(fileName);

    if (!file.is_open())
    {
        cout << "Problem creating the audit file " << endl;
        return "error";
    }

    file << "Voting Type: " + type_of_voting << "\n";
    file << "Number of Parties: " + to_string(number_of_parties) << "\n";
    file << "Parties:\n";
    for (auto &party : parties)
    {
        file << party->getName() << endl;
    }
    file << endl;
    file << "Number of Ballots: " << NumberOfBallots << "\n";
    file << "Steps: "
         << "\n";

    for (string step : steps)
    {
        file << step << endl;
    }

    file << "Winners: " << endl;
    file << winner << endl;
    file.close();
    return fileName;
}

string AuditFile::getVotingType()
{
    return type_of_voting;
}
int AuditFile::getNumberCandidates()
{
    return number_of_candidates;
}
vector<Candidate> AuditFile::getCandidates()
{
    return candidates;
}
int AuditFile::getBallotNum()
{
    return NumberOfBallots;
}
vector<string> AuditFile::getSteps()
{
    return steps;
}
string AuditFile::getWinner()
{
    return winner;
}
