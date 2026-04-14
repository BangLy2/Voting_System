#include <string>
#include <vector>
#include "include/Candidate.h"
#include "include/BallotPO.h"
#include "include/POAlgorithm.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void POAlgorithm::setBallot(vector<BallotPO*> ballots) {
    this->ballots = ballots;
}
void POAlgorithm::setNumberOfCandidates(int numberOfCandidates) {
    this->numberOfCandidates = numberOfCandidates;
}
void POAlgorithm::setCandidates(vector<CandidatePO> candidates) {
    this->candidates = candidates;
}
void POAlgorithm::setNumberOfBallots(int numberOfBallots) {
    this->numberOfBallots = numberOfBallots;
}
void POAlgorithm::setWinner(string winnerCandidate) {
    this->winner = winnerCandidate;
}

POAlgorithm::POAlgorithm() {
    this->numberOfCandidates = 0;
    this->numberOfBallots = 0;
}
POAlgorithm::POAlgorithm(vector<BallotPO*> ballots, int numberOfCandidates, vector<CandidatePO> candidates, int numberOfBallots) {
    this->ballots = ballots;
    this->numberOfCandidates = numberOfCandidates;
    this->candidates = candidates;
    this->numberOfBallots = numberOfBallots;
}
vector<BallotPO*> POAlgorithm::getBallot() {
    return ballots;
}
int POAlgorithm::getNumberOfCandidates() {
    return numberOfCandidates;
}
vector<CandidatePO> POAlgorithm::getCandidates() {
    return candidates;
}
int POAlgorithm::getNumberOfBallots() {
    return numberOfBallots;
}
string POAlgorithm::getWinner() {
    return winner;
}

CandidatePO POAlgorithm::breakTie(vector<CandidatePO> candidates) { // Grabs a random candidate from a vector of candidates
    int index = rand() % candidates.size();
    return candidates[index];
}

void POAlgorithm::countBallots() { //checks ballots first vote and adds that ballot to its corresponding candidate who was first    
    for (int i = 0; i < ballots.size(); i ++) {
        int choice = ballots.at(i)->getChoice();
        this->candidates.at(choice).appendBallot(ballots.at(i));
    }
}


CandidatePO POAlgorithm::pickPopularCandidate() { //looks through candidates votes and picks the most popular voted candidate, if more then one has most popular votes then call break tie
    int maximumVote = 0;
    vector<CandidatePO> mostVoted;

    for (CandidatePO candidate: this->candidates) { //grabs the highest vote from all the candidates
            int maxVotes = candidate.getCandidateTotalVote();
            if (maxVotes > maximumVote) {
                maximumVote = maxVotes;
            }
    }
    for (CandidatePO candidate: candidates) { // checks if more then 1 candidate has the highest vote
            if (candidate.getCandidateTotalVote() == maximumVote) {
            mostVoted.push_back(candidate);
            }
    }
    if (mostVoted.size() > 1) { // if more then 1 candidate has the highest vote call break tie
        return breakTie(mostVoted);
    }

    return mostVoted.at(0);
}



vector<string> POAlgorithm::getSteps() {
    return steps;
}


string POAlgorithm::runPO() {
    countBallots(); // distributes ballots
    
    this->winner = pickPopularCandidate().getCandidateName(); // tries to get the majority, if there isn't go into while loop else return completed

    return "Completed";
}