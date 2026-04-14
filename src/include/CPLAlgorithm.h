#ifndef CPLAlgorithm_H
#define CPLAlgorithm_H

#include <string>
#include <vector>
#include "Party.h"
#include "BallotCPL.h"
#pragma once

using namespace std;

class CPLAlgorithm
{
private:
    vector<BallotCPL> ballots;
    int numberOfParties;
    vector<Party *> parties;
    int numberOfSeats;
    int numberOfBallots;
    vector<string> steps;
    int quota;

public:
    /**
     * @brief default Constructor
     **/
    CPLAlgorithm();

    /**
     * @brief Constructor
     * @param[in] ballots contain vector of ballots
     * @param[in] numberOfParties contain number of Parties
     * @param[in] parties contain a vector of Party
     * @param[in] numberOfSeats contain the number of seats
     * @param[in] numberOfBallots contain the number of ballots
     **/
    CPLAlgorithm(vector<BallotCPL> ballots, int numberOfParties, vector<Party *> parties, int numberOfSeats, int numberOfBallots);

    /**
     * @brief count all the ballots that belong to which seats
     **/
    void countBallots();

    /**
     * @brief tie breaker to redistribute the remaining seat randomly
     * @param[in] seats the number of seats need to distribute randomly
     **/
    void distributeSeatsRandomly(int seats);

    /**
     * @brief calculate the Quota
     * @param[in] totalVotes the total amount of votes
     * @param[in] votes the amount of available seats
     * @return the quota
     **/
    int calculateQuota(int totalVotes, int votes);

    /**
     * @brief calculate the seats will be received
     * @param[in] quota the quota
     * @param[in] vote the amount of available
     * @return the amount of seats given to that party
     **/
    int calculateSeats(int quota, int votes);

    /**
     * @brief calculate the remaining votes
     * @param[in] quota the quota
     * @param[in] votes amount of vote for each party
     * @return the remainder votes
     **/
    int calculateRemainderVotes(int quota, int votes);

    /**
     * @brief break the Tie
     * @param[in] parties a vector of  parties
     * @return the winning party
     **/
    Party *breakTie(vector<Party *> parties);

    /**
     * @brief get the ballots CPL
     * @return the vector of ballotCPL
     **/
    vector<BallotCPL> getBallots();

    /**
     * @brief get the number of Parties
     * @return the number of party
     **/
    int getNumberOfParties();

    /**
     * @brief get the parties
     * @return the vector of parties
     **/
    vector<Party *> getParties();

    /**
     * @brief get the number of seats
     * @return the number of seats
     **/
    int getNumberOfSeats();

    /**
     * @brief get the number of ballots
     * @return the number of ballots
     **/
    int getNumberOfBallots();

    /**
     * @brief get the winners()
     * @return the winners
     **/
    string getWinners();

    /**
     * @brief get the steps
     * @return the steps
     **/
    vector<string> getSteps();

    /**
     * @brief run the CPL algorithm
     **/
    void runCPL();


    /**
     * @brief get the quota
     * @return the quota
     **/  
    int getQuota();
};

#endif
