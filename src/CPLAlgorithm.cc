#include <string>
#include <vector>
#include "include/Party.h"
#include "include/BallotCPL.h"
#include "include/CPLAlgorithm.h"
#include <iostream> //remove
#include <ostream>  //remove
#include <stdlib.h>
#include <math.h>
using namespace std;

CPLAlgorithm::CPLAlgorithm()
{
    this->numberOfParties = 0;
    this->numberOfSeats = 0;
    this->numberOfBallots = 0;
}
CPLAlgorithm::CPLAlgorithm(vector<BallotCPL> ballots, int numberOfParties, vector<Party *> parties, int numberOfSeats, int numberOfBallots)
{
    this->ballots = ballots;
    this->numberOfParties = numberOfParties;
    this->parties = parties;
    this->numberOfSeats = numberOfSeats;
    this->numberOfBallots = numberOfBallots;
}

void CPLAlgorithm::countBallots()
{

    // for each ballot, get the party and increment the vote and track it for the audit file
    for (auto &ballot : this->ballots)
    {
        Party *party = ballot.getParty();
        string step = party->getName() + " gets a vote";
        steps.push_back(step);
        party->incrementVote();
    }

    steps.push_back("");

    // for each party, track the number of votes each party has intially for the audit file
    for (auto &party : this->parties)
    {
        int remainingVotes = party->getRemainingVotes();
        string step = party->getName() + " has " + to_string(remainingVotes) + " votes initially";
        steps.push_back(step);
    }
}

int CPLAlgorithm::calculateQuota(int totalVotes, int seats)
{
    return totalVotes / seats;
}

int CPLAlgorithm::calculateSeats(int votes, int quota)
{
    return votes / quota;
}

int CPLAlgorithm::calculateRemainderVotes(int votes, int quota)
{
    return votes % quota;
}

Party *CPLAlgorithm::breakTie(vector<Party *> parties)
{
    // pick a random index from 0 to the (length of parties - 1) and return the associated party
    int r = rand();
    int index = r % parties.size();
    return parties[index];
}

void CPLAlgorithm::runCPL()
{
    int totalVotes = numberOfBallots;
    // if there are no seats available for ballots, simply return
    if (this->numberOfSeats == 0 || totalVotes == 0)
    {
        return;
    }
    countBallots();

    quota = calculateQuota(totalVotes, this->numberOfSeats);
    steps.push_back("");
    steps.push_back("total votes: " + to_string(totalVotes));
    steps.push_back("number of seats: " + to_string(this->numberOfSeats));
    steps.push_back("quota is " + to_string(quota) + " from " + to_string(totalVotes) + "/" + to_string(this->numberOfSeats));
    steps.push_back("");

    // for each party, calculate how many seats each party should get
    for (auto &party : this->parties)
    {
        int votes = party->getRemainingVotes();
        steps.push_back(party->getName() + " has " + to_string(votes) + " votes");
        int seats = calculateSeats(votes, quota);

        steps.push_back(to_string(seats) + " seats have been calculated");
        int seatsRemaining = party->getSeatsRemaining();

        if (seatsRemaining >= seats) // If a party has enough seats available for the seats it wins
        {
            steps.push_back(party->getName() + " gets " + to_string(seats) + " seats");
            party->addSeatsReceived(seats);
            this->numberOfSeats -= seats;
            int remainingVotes = calculateRemainderVotes(votes, quota);
            steps.push_back(party->getName() + " has " + to_string(remainingVotes) + " remaining votes\n");
            party->setRemainingVotes(remainingVotes);
        }
        else // If a party does not have enough seats available for the seats it in wins
        {

            steps.push_back(party->getName() + " gets " + to_string(seatsRemaining) + " seats");
            party->addSeatsReceived(seatsRemaining); // reward the party as many seats as it can have
            this->numberOfSeats -= seatsRemaining;
            steps.push_back(party->getName() + " does not have enough seats remaining and " + to_string(seats - seatsRemaining) + " seats are being distributed randomly");
            this->distributeSeatsRandomly(seats - seatsRemaining); // distribute the remaining seats to other parties
        }
    }
    steps.push_back("");
    steps.push_back("There are " + to_string(numberOfSeats) + " remaining seats that need to be distributed to the parties with the most remaining votes");
    steps.push_back("");
    while (this->numberOfSeats > 0) // finish distributing remaining seats to the parties with the most votes
    {
        int maxVotes = 0;
        Party *partySeat = NULL;
        // get the party that has the most votes
        for (auto &party : this->parties)
        {
            if (party->getSeatsRemaining() == 0) // if a party cannot receive more seats, do not consider it
            {
                continue;
            }
            int votes = party->getRemainingVotes();
            if (votes > maxVotes)
            {
                maxVotes = party->getRemainingVotes();
                partySeat = party;
            }
            else if (votes == maxVotes) // if a party is tied in having the most votes, break tie
            {
                vector<Party *> tie = {partySeat, party};
                partySeat = this->breakTie(tie);
            }
        }
        if (partySeat == NULL) // if not party is chosen, then no party either has votes or seats remaining, so break the loop
        {
            break;
        }
        steps.push_back(partySeat->getName() + " with " + to_string(maxVotes) + " votes gets a seat");
        partySeat->addSeatsReceived(1);
        this->numberOfSeats -= 1;
        partySeat->setRemainingVotes(-1);
    }
}

void CPLAlgorithm::distributeSeatsRandomly(int seats)
{
    vector<Party *> valid_parties;
    // for each party, only add parties that have seats remainaing to distribute
    for (auto &party : this->parties)
    {
        if (party->getSeatsRemaining() > 0)
        {
            valid_parties.push_back(party);
        }
    }
    for (int i = 0; i < seats; i += 1)
    {
        if (valid_parties.size() == 0) // if not party has seats remaining, break out of the loop
        {
            break;
        }
        Party *chosenParty = breakTie(valid_parties); // choose a party randomly to give a seat to
        steps.push_back(chosenParty->getName() + " has been randomly chosen to get a seat");
        chosenParty->addSeatsReceived(1);
        if (chosenParty->getSeatsRemaining() == 0) // if the chosen party has no more seats remainaing, remove it from the valid parties
        {
            for (int i = 0; i < valid_parties.size(); i += 1)
            {
                if (valid_parties[i] == chosenParty)
                {
                    valid_parties.erase(valid_parties.begin() + i);
                    break;
                }
            }
        }
    }
}

vector<BallotCPL> CPLAlgorithm::getBallots() { return ballots; }

int CPLAlgorithm::getNumberOfParties() { return numberOfParties; }

vector<Party *> CPLAlgorithm::getParties() { return parties; }

int CPLAlgorithm::getNumberOfSeats() { return numberOfSeats; }

int CPLAlgorithm::getNumberOfBallots() { return numberOfBallots; }

vector<string> CPLAlgorithm::getSteps() { return steps; }

int CPLAlgorithm::getQuota() { return quota; }