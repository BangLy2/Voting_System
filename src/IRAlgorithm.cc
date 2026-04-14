#include <string>
#include <vector>
#include "include/Candidate.h"
#include "include/BallotIR.h"
#include "include/IRAlgorithm.h"
#include "include/IRTable.h"
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;

void IRAlgorithm::setBallot(vector<BallotIR *> ballots)
{
    this->ballots = ballots;
}
void IRAlgorithm::setNumberOfCandidates(int numberOfCandidates)
{
    this->numberOfCandidates = numberOfCandidates;
}
void IRAlgorithm::setCandidate(vector<Candidate> candidates)
{
    this->candidates = candidates;
}
void IRAlgorithm::setNumberOfBallots(int numberOfBallots)
{
    this->numberOfBallots = numberOfBallots;
}
void IRAlgorithm::setWinner(string winnerCandidate)
{
    this->winner = winnerCandidate;
}

IRAlgorithm::IRAlgorithm()
{
    this->numberOfCandidates = 0;
    this->numberOfBallots = 0;
}
IRAlgorithm::IRAlgorithm(vector<BallotIR *> ballots, int numberOfCandidates, vector<Candidate> candidates, int numberOfBallots)
{
    this->ballots = ballots;
    this->numberOfCandidates = numberOfCandidates;
    this->candidates = candidates;
    this->numberOfBallots = numberOfBallots;
}
vector<BallotIR *> IRAlgorithm::getBallot()
{
    return ballots;
}
int IRAlgorithm::getNumberOfCandidates()
{
    return numberOfCandidates;
}
vector<Candidate> IRAlgorithm::getCandidates()
{
    return candidates;
}
int IRAlgorithm::getNumberOfBallots()
{
    return numberOfBallots;
}
string IRAlgorithm::getWinner()
{
    return winner;
}

Candidate IRAlgorithm::breakTie(vector<Candidate> candidates)
{ // Grabs a random candidate from a vector of candidates
    int index = rand() % candidates.size();
    return candidates[index];
}
void IRAlgorithm::countBallots()
{ // checks ballots first vote and adds that ballot to its corresponding candidate who was first
    for (BallotIR *ballot : this->ballots)
    { // Iterates through ballots
        if (ballot->getValid() == true)
        { // Check ballot is still valid meaning that it has something left to read from
            for (int i = 0; i < candidates.size(); i++)
            {
                if (ballot->getRank() < ballot->getCandidates().size() && candidates.at(i).getActive() == true && candidates.at(i).getCandidateName() == ballot->getCandidate(ballot->getRank()))
                { // Adds ballot first vote to corresponding candidate
                    candidates.at(i).appendBallot(ballot);
                    steps.push_back("Added Ballot to " + candidates.at(i).getCandidateName()); // Add history of adding ballot to its corresponding candidate to steps.
                }
            }
        }
    }
}
int IRAlgorithm::redistributeBallots(Candidate candidate)
{ // Redistributes ballots from chosen candidate
    int j;
    int exhausted_votes = 0;
    steps.push_back("Removing Ballots from " + candidate.getCandidateName() + " and redistributing if needed.");
    for (int i = 0; i < candidates.size(); i++)
    {
        if ((candidates.at(i).getCandidateName() == candidate.getCandidateName()) && (candidates.at(i).getActive() == true))
        { // Saves the index of the candidate in j to use in the next for loop. And sets the candidates total vote to 0 meaning its empty
            j = i;
            candidates.at(i).setCandidateTotalVote(0);
        }
    }
    vector<BallotIR *> ballots = candidates.at(j).getBallots();
    for (BallotIR *ballot : ballots)
    { // iterates through ballots in corresponding candidate and incrememts their ranks by 1 to get the ballots next top choice
        ballot->incrementRank();
        int rank = ballot->getRank();
        if (rank < ballot->getCandidates().size())
        {
            string candidateName = ballot->getCandidate(rank);
            for (int i = 0; i < candidates.size(); i++)
            {
                if (candidates.at(i).getCandidateName() == candidateName)
                {
                    candidates.at(i).appendBallot(ballot);                                                                                          // Add the ballots next top choice to its corresponding candidate
                    steps.push_back("Ballot is redistributed from " + candidate.getCandidateName() + " to " + candidates.at(i).getCandidateName()); // Added history for when a ballot is redistributed to a new candidate
                }
            }
        }
        else
        {
            exhausted_votes++;
        }
    }
    candidates.at(j).setActive(false); // sets candidate being removed to Active is false to prevent using this candidate again during search
    return exhausted_votes;
}
Candidate IRAlgorithm::pickPopularCandidate()
{ // looks through candidates votes and picks the most popular voted candidate, if more then one has most popular votes then call break tie
    int maximumVote = 0;
    vector<Candidate> mostVoted;
    for (Candidate candidate : this->candidates)
    { // grabs the highest vote from all the candidates
        if (candidate.getActive() == true)
        {
            int maxVotes = candidate.getCandidateTotalVote();
            if (maxVotes > maximumVote)
            {
                maximumVote = maxVotes;
            }
        }
    }
    for (Candidate candidate : candidates)
    { // checks if more then 1 candidate has the highest vote
        if (candidate.getActive() == true)
        {
            if (candidate.getCandidateTotalVote() == maximumVote)
            {
                mostVoted.push_back(candidate);
            }
        }
    }
    if (mostVoted.size() > 1)
    { // if more then 1 candidate has the highest vote call break tie
        return breakTie(mostVoted);
    }
    return mostVoted[0];
}
int IRAlgorithm::getMajority()
{ // this function picks the candidate who has more then 50% of the total votes. Return -1 if couldnt find a majority
    for (Candidate candidate : this->candidates)
    {
        if (candidate.getActive() == true && ((float)candidate.getCandidateTotalVote() / (float)this->numberOfBallots) > 0.5)
        {
            this->winner = candidate.getCandidateName();
            return 0;
        }
    }
    return -1;
}
Candidate IRAlgorithm::getLeastVoteCandidate()
{ // grabs the candidate with the least number of votes. If there is more then one, does break tie on them to choose candidate with least number of votes
    vector<Candidate> leastVoted;
    int leastVotes = 99999;

    for (Candidate candidate : this->candidates)
    { // gets the lowest votes from the candidates
        if (candidate.getActive() == true)
        {
            int minVotes = candidate.getCandidateTotalVote();
            if (minVotes < leastVotes)
            {
                leastVotes = minVotes;
            }
        }
    }
    for (Candidate candidate : candidates)
    { // checks if there are more then 1 candidate with the lowest votes
        if (candidate.getActive() == true)
        {
            if (candidate.getCandidateTotalVote() == leastVotes)
            {
                leastVoted.push_back(candidate);
            }
        }
    }
    if (leastVoted.size() > 1)
    { // if there are mroe then 1 candidate with the lowes votes call break tie
        return breakTie(leastVoted);
    }
    return leastVoted[0];
}

vector<string> IRAlgorithm::getSteps()
{
    return steps;
}

vector<Candidate> IRAlgorithm::getEliminatedCandidates()
{
    return eliminatedCandidates;
}

string IRAlgorithm::runIR()
{
    int exhausted_votes = numberOfBallots - ballots.size();
    numberOfBallots = ballots.size();
    if (numberOfBallots == 0)
    {
        winner = breakTie(candidates).getCandidateName();
    }
    countBallots(); // distributes ballots
    getMajority();  // tries to get the majority, if there isn't go into while loop else return completed

    int candidatesLeft = numberOfCandidates;
    if (!winner.empty())
    {
        unordered_map<string, int> IRTableRound;
        for (Candidate candidate : candidates)
        {
            if (candidate.getActive())
            {
                IRTableRound.insert(make_pair(candidate.getCandidateName(), candidate.getCandidateTotalVote()));
            }
        }
        IRTableRound.insert(make_pair("EXHAUSTED_PILE", exhausted_votes));
        appendRoundToIRTable(IRTableRound);
    }
    while (winner.empty())
    { // while no majority checks stay in while loop
        if (candidatesLeft > 1)
        { // checks if there are more than 1 candidate left, if so grab the least voted candidate and redistribute its ballots
            bool isSameCount = true;
            bool sameCounter = false;
            int count = 0;
            for (int i = 0; i < candidates.size(); i++)
            {
                if (candidates.at(i).getActive() == true)
                {
                    for (int j = 0; j < candidates.at(i).getBallots().at(0)->getCandidates().size(); j++)
                    {
                        if (candidates.at(i).getBallots().at(0)->getCandidate(j) != "")
                        {
                            count++;
                        }
                    }
                    break;
                }
            }
            int counter = 0;
            int totalcount = 0;
            int votecountpercandidate = candidates.at(0).getCandidateTotalVote();
            for (int i = 0; i < candidates.size(); i++)
            {
                if (candidates.at(i).getActive() == true)
                {
                    for (BallotIR *ballot : candidates.at(i).getBallots())
                    {
                        int temp = 0;
                        totalcount++;
                        for (int j = 0; j < ballot->getCandidates().size(); j++)
                        {
                            if (ballot->getCandidate(j) != "")
                            {
                                temp++;
                            }
                        }
                        if (count == temp)
                        {
                            counter++;
                        }
                    }
                    if (votecountpercandidate != candidates.at(i).getCandidateTotalVote())
                    {
                        isSameCount = false;
                    }
                }
            }
            if (counter == totalcount)
            {
                sameCounter = true;
            }
            if (isSameCount && !sameCounter)
            {
                for (BallotIR *ballot : this->ballots)
                {
                    if (ballot->getValid())
                    {
                        ballot->incrementRank();
                    }
                }
                countBallots();
            }
            else
            {
                steps.push_back("There are " + to_string(candidatesLeft) + " candidates left.");
                Candidate LeastVoted = getLeastVoteCandidate();
                exhausted_votes += redistributeBallots(LeastVoted);
                eliminatedCandidates.push_back(LeastVoted);
                candidatesLeft--;
            }
        }
        else if (candidatesLeft == 1)
        { // if there is one candidate left set winner to the most popular candidate

            winner = pickPopularCandidate().getCandidateName();
        }
        unordered_map<string, int> IRTableRound;
        for (Candidate candidate : candidates)
        {
            if (candidate.getActive())
            {
                IRTableRound.insert(make_pair(candidate.getCandidateName(), candidate.getCandidateTotalVote()));
            }
        }
        IRTableRound.insert(make_pair("EXHAUSTED_PILE", exhausted_votes));
        appendRoundToIRTable(IRTableRound);
        getMajority(); // tries to get the majority and the while loop repeats if this is no majority again
    }

    return "Completed";
}

void IRAlgorithm::appendRoundToIRTable(unordered_map<string, int> round)
{
    irTable.appendRound(round);
}

IRTable IRAlgorithm::getIRTable()
{
    return irTable;
}