#ifndef BALLOTIR_H
#define BALLOTIR_H

#include <string>
#include <vector>
// #include "Candidate.h"
using namespace std;

class BallotIR
{
private:
    vector<string> candidates;
    int rank;
    bool valid;
    int numCandidates;

public:
    /**
     * @brief default Constructor
     **/
    BallotIR();

    /**
     * @brief Constructor
     * @param[in] candidates contain vector of candidates
     **/
    BallotIR(vector<string> candidates, int numCandidates);

    /**
     * @brief return the vector of candidates
     * @return a vector of Candidates
     **/
    vector<string> getCandidates();

    /**
     * @brief getCandidate based on their rank in ballot
     * @param[in] rank the current rank of the BallotIR point to
     * @return Candidate
     **/
    string getCandidate(int rank);

    /**
     * @brief getRank that the ballotIR is currently point to
     * @return the rank
     **/
    int getRank();

    /**
     * @brief increment the rank to point to the next candidate
     **/
    void incrementRank();

    /**
     * @brief check to see if the current candidate point to is not eliminated
     * @return the boolean
     **/
    bool getValid();

    /**
     * @brief set the Candidate's valid to see if he is eliminated or not
     * @return the boolean
     **/
    void setValid(bool valid);

    /**
     * @brief get the number of candidates
     * @return the number of candidates
     **/
    int getNumCandidates();

    /**
     * @brief increment the number of candidates
     **/
    void incrementNumCandidates();
};
#endif