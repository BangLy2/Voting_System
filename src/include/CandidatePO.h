#ifndef CANDIDATEPO_H
#define CANDIDATEPO_H

#include <string>
#include <vector>
#include "BallotPO.h"
using namespace std;
class BallotPO;
class CandidatePO {
    private:
        vector<BallotPO*> ballots;
        string candidate_Name;
        int candidate_Total_Vote;
    public:

        /**
        * @brief Default Constructor
        **/ 
        CandidatePO();

        /**
        * @brief Constructor
        * @param[in] candidate_Name the name of Candidate
        **/ 
        CandidatePO(string candidate_Name);
        
        /**
        * @brief get all the ballot from the candidate
        * @return the vector of ballot
        **/ 
        vector<BallotPO*> getBallots();
        
        /**
        * @brief get the number of vote that the candidate have
        * @return total number of votes
        **/ 
        int getCandidateTotalVote();

        /**
        * @brief set the candidate total votes 
        * @return void
        **/ 
        void setCandidateTotalVote(int vote);
        
        /**
        * @brief get the candidate name
        * @return return the candidate name
        **/ 
        string getCandidateName();

        /**
        * @brief Append the new ballot into the candidate
        * @param[in] ballot the ballot to append
        **/ 
        void appendBallot(BallotPO* ballot);

        /**
        * @brief increment the candidate total vote by 1
        **/ 
        void increment_Candidate_Total_Vote();
        
};
#endif