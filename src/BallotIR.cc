#include <string>
#include "include/BallotIR.h"
using namespace std;

BallotIR::BallotIR()
{
    this->rank = 0;
    this->valid = true;
    this->numCandidates = 0;
}
BallotIR::BallotIR(vector<string> candidates, int numCandidates)
{
    this->candidates = candidates;
    this->rank = 0;
    this->valid = true;
    this->numCandidates = numCandidates;
}
vector<string> BallotIR::getCandidates()
{
    return candidates;
}
string BallotIR::getCandidate(int rank)
{
    return candidates[rank];
}
int BallotIR::getRank()
{
    return rank;
}
void BallotIR::incrementRank()
{
    this->rank++;
}
bool BallotIR::getValid()
{
    return valid;
}
void BallotIR::setValid(bool valid)
{
    this->valid = valid;
}

int BallotIR::getNumCandidates()
{
    return numCandidates;
}

void BallotIR::incrementNumCandidates()
{
    this->numCandidates += 1;
}