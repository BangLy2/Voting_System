#ifndef IRALGORITHM_H
#define IRALGORITHM_H

#include <string>
#include <vector>
#include "Candidate.h"
#include "BallotIR.h"
#include "IRAlgorithm.h"
#include "IRTable.h"
#include <stdlib.h>
using namespace std;

class IRAlgorithm
{
private:
    vector<BallotIR *> ballots;
    int numberOfCandidates;
    vector<Candidate> candidates;
    vector<Candidate> eliminatedCandidates;
    int numberOfBallots;
    string winner;
    vector<string> steps;
    IRTable irTable;

public:
    /**
     * @brief default constructor
     **/
    IRAlgorithm();

    /**
     * @brief constructor
     * @param[in] ballots contain the vector of ballotIR
     * @param[in] numberOfCandidates contain number of candidate
     * @param[in] candidates contain candidate
     * @param[in] numberOfBallots contain the number of ballot
     **/
    IRAlgorithm(vector<BallotIR *> ballots, int numberOfCandidates, vector<Candidate> candidates, int numberOfBallots);

    /**
     * @brief get ballots
     * @return vector of Ballots
     **/
    vector<BallotIR *> getBallot();

    /**
     * @brief get the number of Candidate
     * @return the number of candidate
     **/
    int getNumberOfCandidates();

    /**
     * @brief get the Candidates
     * @return the vector of Candidate
     **/
    vector<Candidate> getCandidates();

    /**
     * @brief get the number of ballots
     * @return the number of ballots
     **/
    int getNumberOfBallots();

    /**
     * @brief get the winner
     * @return the winner name
     **/
    string getWinner();

    /**
     * @brief get the step to find the winner
     * @return the vector of string contain all the step
     **/
    vector<string> getSteps();

    /**
     * @brief run the IR algorithm
     * @return the string contain the winner
     **/
    vector<Candidate> getEliminatedCandidates();
    /**
     * @brief set Ballots
     * @param[in] ballots contain the vector of ballots
     **/
    void setBallot(vector<BallotIR *> ballots);

    /**
     * @brief set Number Of Candidates
     * @param[in] numberOfCandidates contain the number of Candidates
     **/
    void setNumberOfCandidates(int numberOfCandidates);

    /**
     * @brief set Candidate
     * @param[in] candidates contain vector of candidate
     **/
    void setCandidate(vector<Candidate> candidates);

    /**
     * @brief set number of Ballots
     * @param[in] numberOfBallots contain number of ballots
     **/
    void setNumberOfBallots(int numberOfBallots);

    /**
     * @brief set the winner of the election
     * @param[in] winnerCandidate contain the winning candidate
     **/
    void setWinner(string winnerCandidate);

    /**
     * @brief break the tie
     * @param[in] candidates contain the list of candidate to break tie
     * @return the losing candidate from the tie
     **/
    Candidate breakTie(vector<Candidate> candidates);

    /**
     * @brief count the ballots
     **/
    void countBallots();

    /**
     * @brief redistribute the ballot
     * @param[in] candidate the ballot to redistribute
     **/
    int redistributeBallots(Candidate candidate);

    /**
     * @brief pick the Candidate using popular vote
     * @return the winning candidate
     **/
    Candidate pickPopularCandidate();

    /**
     * @brief get the majority winer
     * @return the 0 when found majority, -1 when no majority found
     **/
    int getMajority();

    /**
     * @brief get the least vote candidate
     * @return the least vote candidate
     **/
    Candidate getLeastVoteCandidate();

    /**
     * @brief run the IR algorithm
     * @return the winner
     **/
    string runIR();

    /**
     * @brief Add round to IR Table
     **/
    void appendRoundToIRTable(unordered_map<string, int>);

    /**
     * @brief get the IR table
     * @return IR Table
     **/
    IRTable getIRTable();

    /**
     * @brief create the IR Table
     * @return IR Table
     **/
    string createIRTable();
};
#endif
