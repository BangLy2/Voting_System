#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <vector>
#include "BallotIR.h"
using namespace std;
class BallotIR;
class Candidate {
    private:
        vector<BallotIR*> ballots;
        bool active;
        string candidate_Name;
        int candidate_Total_Vote;
    public:

        /**
        * @brief Default Constructor
        **/ 
        Candidate();

        /**
        * @brief Constructor
        * @param[in] candidate_Name the name of Candidate
        **/ 
        Candidate(string candidate_Name);
        
        /**
        * @brief get all the ballot from the candidate
        * @return the vector of ballot
        **/ 
        vector<BallotIR*> getBallots();
        
        /**
        * @brief get to see if the candidate is active or not
        * @return boolean of active
        **/ 
        bool getActive();
        
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
        void appendBallot(BallotIR* ballot);

        /**
        * @brief increment the candidate total vote by 1
        **/ 
        void increment_Candidate_Total_Vote();
        
        /**
        * @brief set the active of the candidate
        * @param[in] active candidate's active
        **/ 
        void setActive(bool active);
};
#endif