#include <string>
#include "include/BallotPO.h"
using namespace std;

BallotPO::BallotPO()
{
}
BallotPO::BallotPO(vector<string> candidates)
{
    this->candidates = candidates;
    this->choice = 0;
}

BallotPO::BallotPO(vector<string> candidates, int choice)
{
    this->candidates = candidates;
    this->choice = choice;
}

string BallotPO::getCandidate() {
    return candidates[choice];
}

vector<string> BallotPO::getCandidates() {
    return this->candidates;
}

void BallotPO::setCandidates(vector<string> candidates) {
    this->candidates = candidates;
}

int BallotPO::getChoice() {
    return this->choice;
}

void BallotPO::setChoice(int choice) {
    this->choice = choice;
}


// [Pike, D], [Foster, D], [Deutsch, R], [Borg, R], [Jones, R], [Smith, I]

//     0           1           2              3        4           5

// [Smith, I], [Deutsch, R]

// ,,1,,, === choice = 2

// 0
// 1

// PO
// 6
// [Pike, D], [Foster, D], [Deutsch, R], [Borg, R], [Jones, R], [Smith, I]
// 9
// 1,,,,,
// 1,,,,,
// ,1,,,,
// ,,,,1,
// ,,,,,1
// ,,,1,,
// ,,,1,,
// 1,,,,,
// ,1,,,,