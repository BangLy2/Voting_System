#include <string>
#include <vector>
#include "include/CandidatePO.h"
using namespace std;

CandidatePO::CandidatePO() {
    this->candidate_Name = "";
    this->candidate_Total_Vote = 0;
}
CandidatePO::CandidatePO (string candidate_Name) {
    this->candidate_Name = candidate_Name;
    this->candidate_Total_Vote = 0;
}
vector<BallotPO*> CandidatePO::getBallots() {return ballots;}

int CandidatePO::getCandidateTotalVote() {return candidate_Total_Vote;}

string CandidatePO::getCandidateName() {return candidate_Name;}

void CandidatePO::setCandidateTotalVote(int vote) {candidate_Total_Vote = vote;}

void CandidatePO::appendBallot(BallotPO* ballot) {
    ballots.push_back(ballot);
    this->candidate_Total_Vote ++ ;
}