#ifndef AUDITFILE
#define AUDITFILE
#include <iostream>
#include <string>
#include <vector> // #include directive
#include "Candidate.h"
#include "Party.h"
// #include "Result.h"

using namespace std;

class AuditFile{
    public:
        /**
        * @brief default constructor
        **/
        AuditFile();

        /**
        * @brief CPL Constructor
        * @param[in] date contain the date
        * @param[in] VotingType contain the type of voting
        * @param[in] CandidateNum contain number of candidate
        * @param[in] candidates contain a vector of candidate name
        * @param[in] ballotNum contain the number of ballot
        * @param[in] steps contain all the steps of how the winner is determined
        * @param[in] winnner contain the winner of the election
        **/
        AuditFile(string date, string VotingType, int CandidateNum, vector<Candidate>candidates, int ballotNum, vector<string> steps, string winnner);

        /**
        * @brief IR Constructor
        * @param[in] date contain the date
        * @param[in] VotingType contain the type of voting
        * @param[in] PartyNam contain number of party
        * @param[in] parties contain a vector of parties
        * @param[in] ballotNum contain the number of ballot
        * @param[in] steps contain all the steps of how the winner is determined
        * @param[in] winnner contain the winner of the election
        **/
        AuditFile(string date, string VotingType, int PartyNum, vector<Party*>parties, int ballotNum, vector<string> steps, string winnner);
        
         /**
        * @brief create the AuditfileCPL and write all the information to the auditFile
        * @return the file name
        **/
        string create_AuditFileCPL();

         /**
        * @brief create the AuditfileIR and write all the information to the auditFile
        * @return the file name
        **/
        string create_AuditFileIR();

         /**
        * @brief get the voting type (IR or CPL)
        * @return the voting type
        **/
        string getVotingType();

         /**
        * @brief get the number of Candidates
        * @return the number of Candidates
        **/
        int getNumberCandidates();

         /**
        * @brief get the vector contain all candidate's names
        * @return the vector contain candidate's name
        **/
        vector<Candidate> getCandidates();

        /**
        * @brief get the total ballot
        * @return the total number of ballot
        **/
        int getBallotNum();

        /**
        * @brief get the steps when determine the winner
        * @return the total number of ballot
        **/
        vector<string> getSteps();

        /**
        * @brief get the winner
        * @return the winner
        **/
        string getWinner();
    private:
        string date;
        string type_of_voting;
        int number_of_candidates;
        int number_of_parties;
        vector<Candidate> candidates;
        vector<Party*> parties;
        int NumberOfBallots;
        vector<string> steps;
        string winner;
        

};
#endif
