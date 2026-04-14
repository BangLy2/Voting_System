#include <string>
#include <vector>
#include "include/Candidate.h"
using namespace std;

Candidate::Candidate() {
    this->active = true;
    this->candidate_Name = "";
    this->candidate_Total_Vote = 0;
}
Candidate::Candidate(string candidate_Name) {
    this->active = true;
    this->candidate_Name = candidate_Name;
    this->candidate_Total_Vote = 0;
}
vector<BallotIR*> Candidate::getBallots() {return ballots;}

bool Candidate::getActive() {return active;}

int Candidate::getCandidateTotalVote() {return candidate_Total_Vote;}

string Candidate::getCandidateName() {return candidate_Name;}

void Candidate::setCandidateTotalVote(int vote) {candidate_Total_Vote = vote;}

void Candidate::appendBallot(BallotIR* ballot) {
    ballots.push_back(ballot);
    this->candidate_Total_Vote ++ ;
}

void Candidate::setActive(bool active) {this->active = active;}