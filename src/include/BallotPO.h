
#ifndef BALLOTPO_H
#define BALLOTPO_H

#include <string>
#include <vector>
// #include "Candidate.h"
using namespace std;

class BallotPO
{
private:
    vector<string> candidates;
    int choice;

public:
    /**
     * @brief default Constructor
     **/
    BallotPO();

    /**
     * @brief Constructor
     * @param[in] candidates contain vector of candidates
     **/
    BallotPO(vector<string> candidates);


    /**
     * @brief Constructor
     * @param[in] candidates contain vector of candidates
     * @param[in] choice the choice that chose the candidate
     **/
    BallotPO(vector<string> candidates, int choice);

    /**
     * @brief getCandidate based on their choice in ballot
     * @return Candidate
     **/
    string getCandidate();

    /**
     * @brief get the candidates in that party
     * @return vector contain candidates's name
     **/
    vector<string> getCandidates();

    /**
     * @brief set the candidates in that party
    * @param[in] candidates contain vector of candidates's name
     **/
    void setCandidates(vector<string> candidates);

    /**
     * @brief get the choice
     * @return the choice
     **/
    int getChoice();

    /**
     * @brief set the choice
     **/
    void setChoice(int choice);
};
#endif