#include <string>
#include <vector>
#include "include/Party.h"

using namespace std;

Party::Party()
{
    this->originalVotes = 0;
    this->remainingVotes = 0;
    this->seatsReceived = 0;
}
Party::Party(string name)
{
    this->name = name;
    this->originalVotes = 0;
    this->remainingVotes = 0;
    this->seatsReceived = 0;
}

string Party::getName()
{
    return name;
}
void Party::incrementVote()
{
    this->remainingVotes++;
    this->originalVotes++;
}

int Party::getRemainingVotes()
{
    return this->remainingVotes;
}

int Party::getSeatsRemaining()
{
    return candidates.size() - seatsReceived; // calculate and return the number seats a party can receive
}

void Party::addSeatsReceived(int seats)
{
    this->seatsReceived += seats;
}

void Party::setRemainingVotes(int votes)
{
    this->remainingVotes = votes;
}

vector<string> Party::getCandidates()
{
    return candidates;
}

int Party::getSeatsReceived()
{
    return seatsReceived;
}

void Party::setCandidates(vector<string> candidates)
{
    this->candidates = candidates;
}

int Party::getOriginalVotes()
{
    return originalVotes;
}