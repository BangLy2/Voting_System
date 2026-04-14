#include <string>
#include "Party.h"
using namespace std;
#pragma once

class BallotCPL
{
private:
    string partyName;
    Party *party;

public:
    /**
     * @brief default Constructor
     **/
    BallotCPL();

    /**
     * @brief Constructor
     * @param[in] partyName contain the name of the party that is being voted for
     * @param[in] party contain the party class
     **/
    BallotCPL(string partyName, Party *party);

    /**
     * @brief get the Party that the ballotCPL vote for
     * @return Party pointer
     **/
    Party *getParty();
};