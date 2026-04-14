#include <string>
#include "include/Party.h"
#include "include/BallotCPL.h"

using namespace std;

BallotCPL::BallotCPL()
{
    this->partyName = "";
    this->party = new Party();
}
BallotCPL::BallotCPL(string partyName, Party *party)
{
    this->partyName = partyName;
    this->party = party;
}

Party *BallotCPL::getParty()
{
    return this->party;
}