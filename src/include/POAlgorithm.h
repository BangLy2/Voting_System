#ifndef POALGORITHM_H
#define POALGORITHM_H

#include <string>
#include <vector>
#include "CandidatePO.h"
#include "BallotPO.h"
#include "POAlgorithm.h"
#include <stdlib.h>
using namespace std;

class POAlgorithm {
    private:
        vector<BallotPO*> ballots;
        vector<CandidatePO> candidates;
        int numberOfCandidates;
        int numberOfBallots;
        string winner;
        vector<string> steps;

        
    public:

        /**
        * @brief default constructor
        **/ 
        POAlgorithm();

        /**
        * @brief constructor
        * @param[in] ballots contain the vector of ballotIR
        * @param[in] numberOfCandidates contain number of candidate
        * @param[in] candidates contain candidate
        * @param[in] numberOfBallots contain the number of ballot
        **/ 
        POAlgorithm(vector<BallotPO*> ballots, int numberOfCandidates, vector<CandidatePO> candidates, int numberOfBallots);

         /**
        * @brief get ballots
        * @return vector of Ballots
        **/ 
        vector<BallotPO*> getBallot();

        /**
        * @brief set Ballots
        * @param[in] ballots contain the vector of ballots
        **/ 
        void setBallot(vector<BallotPO*> ballots);

        /**
        * @brief get the Candidates
        * @return the vector of Candidate
        **/ 
        vector<CandidatePO> getCandidates();


        /**
        * @brief set Candidate
        * @param[in] candidates contain vector of candidate
        **/ 
        void setCandidates(vector<CandidatePO> candidates);
        
        /**
        * @brief get the number of Candidate
        * @return the number of candidate
        **/ 
        int getNumberOfCandidates();

        /**
        * @brief set Number Of Candidates
        * @param[in] numberOfCandidates contain the number of Candidates
        **/ 
        void setNumberOfCandidates(int numberOfCandidates);

        /**
        * @brief get the number of ballots
        * @return the number of ballots
        **/ 
        int getNumberOfBallots();

        /**
        * @brief set number of Ballots
        * @param[in] numberOfBallots contain number of ballots
        **/ 
        void setNumberOfBallots(int numberOfBallots);

        /**
        * @brief get the winner
        * @return the winner name
        **/ 
        string getWinner();

        /**
        * @brief set the winner of the election
        * @param[in] winnerCandidate contain the winning candidate
        **/ 
        void setWinner(string winnerCandidate);

        /**
        * @brief get the step to find the winner
        * @return the vector of string contain all the step
        **/ 
        vector<string> getSteps();

        /**
        * @brief break the tie 
        * @param[in] candidates contain the list of candidate to break tie
        * @return the losing candidate from the tie
        **/ 
        CandidatePO breakTie(vector<CandidatePO> candidates);

        /**
        * @brief count the ballots
        **/ 
        void countBallots();


        /**
        * @brief find the winning candidate based on their vote
        * @return the winning candidate
        **/ 
        CandidatePO pickPopularCandidate();
        
        /**
        * @brief run the PO algorithm
        * @return the winner 
        **/ 
        string runPO();
};
#endif
