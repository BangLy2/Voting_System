#include <string>
#include <vector>
#include <unordered_map>
#include "include/Result.h"
#include "include/BallotIR.h"
#include "include/Candidate.h"
#include "include/IRTable.h"
#include <iomanip> // std::setw
using namespace std;
Result::Result()
{
    type_of_voting = " ";
    number_of_votes = 0;
    winner = " ";
}
Result::Result(string VotingType, string date, int numCandidates, vector<Candidate> candidates, int numBallots, vector<BallotIR *> ballots, vector<Candidate> eliminatedCandidates, string winner, IRTable irTable)
{
    this->irTable = irTable;
    this->type_of_voting = VotingType;
    this->date = date;
    this->numCandidates = numCandidates;
    this->candidates = candidates;
    this->numBallots = numBallots;
    this->ballots = ballots;
    this->eliminatedCandidates = eliminatedCandidates;
    this->winner = winner;
}

Result::Result(string VotingType, string date, int numParties, vector<Party *> parties, int numBallots)
{
    this->number_of_votes = numBallots;
    this->type_of_voting = VotingType;
    this->date = date;
    this->numParties = numParties;
    this->parties = parties;
    this->numBallots = numBallots;
}

Result::Result(string VotingType, string date, vector<BallotPO*> ballots, int numberCandidates, vector<CandidatePO> candidates, int numBallots, string winner)
{
    this->type_of_voting = VotingType;
    this->ballotsPO = ballots;
    this->numCandidates = numberCandidates;
    this->candidatesPO = candidates;
    this->numBallots = numBallots;
    this->date = date;
    this->winner = winner;
}

void Result::displayCPLResult()
{
    cout << "CPL Results:" << endl;
    cout << "Date: " << date << endl;
    cout << "Type: " << type_of_voting << endl;
    cout << "Number of ballots cast: " << numBallots << endl;
    cout << "Number of Parties: " << numParties << endl;
    cout << "Winning candidates and their parties" << endl;
    this->winner = getWinningPartiesAndCandidates();
    cout << winner << endl;
}

void Result::displayIRResult()
{
    cout << "IR Results:" << endl;
    cout << "Date: " << date << endl;
    cout << "Type: " << type_of_voting << endl;
    cout << "Number of ballots: " << numBallots << endl;
    cout << "Number of candidates: " << numCandidates << endl;
    for (int i = 0; i < candidates.size(); i++)
    {
        cout << candidates.at(i).getCandidateName();
        cout << " recieved " << candidates.at(i).getCandidateTotalVote() << " votes, ";
        double percentage = (int)(candidates.at(i).getCandidateTotalVote() / float(numBallots) * 100);
        if (numBallots == 0)
        {
            percentage = 0.00;
        }
        cout << "(" << to_string(percentage) << "\% of the total votes)" << endl;
    }
    cout << endl;
    cout << "Winning candidate: " << winner << endl;
}

void Result::displayPOResult()
{
    cout << "PO Results:" << endl;
    cout << "Date: " << date << endl;
    cout << "Type: " << type_of_voting << endl;
    cout << "Number of ballots: " << numBallots << endl;
    cout << "Number of candidates: " << numCandidates << endl;
    for (int i = 0; i < candidatesPO.size(); i++)
    {
        cout << candidatesPO.at(i).getCandidateName();
        cout << " recieved " << candidatesPO.at(i).getCandidateTotalVote() << " votes, ";
        double percentage = (int)(candidatesPO.at(i).getCandidateTotalVote() / float(numBallots) * 100);
        if (numBallots == 0)
        {
            percentage = 0.00;
        }
        cout << "(" << to_string(percentage) << "\% of the total votes)" << endl;
    }
    cout << endl;
    cout << "Winning candidate: " << winner << endl;
}

void Result::displayIRTable()
{
    vector<unordered_map<string, int>> rounds = irTable.getRounds();
    unordered_map<string, vector<string>> candidates;

    if (rounds.size() == 0)
    {
        return;
    }
    unordered_map<string, int> round1 = rounds[0];

    for (auto e : round1)
    {
        string votes = to_string(e.second);
        candidates[e.first] = {votes, "+" + votes};
    }

    for (int i = 1; i < rounds.size(); i++)
    {
        for (auto e : rounds[i])
        {
            string candidate = e.first;
            int votes = e.second;

            vector<string> &vec = candidates[candidate];

            string prev_votes = vec.end()[-2];
            int prev_votes_int = stoi(prev_votes);
            int difference = votes - prev_votes_int;
            string difference_string = to_string(difference);
            vec.push_back(to_string(votes));

            if (difference >= 0)
            {
                difference_string = "+" + difference_string;
            }
            vec.push_back(difference_string);
        }
    }

    int maxLength = 0;
    for (auto e : candidates)
    {
        int length = e.first.size();
        if (length > maxLength)
        {
            maxLength = length;
        }
    }
    cout << "IR Table Results:" << endl;
    cout << setw(maxLength + 2) << "Candidates";
    for (int i = 1; i < rounds.size() + 1; i++)
    {
        cout << "|" << setw(8) << "Round " + to_string(i);
        cout << "|" << setw(8) << "+ or -";
    }
    cout << endl;
    for (auto candidate : candidates)
    {
        cout << setw(maxLength + 2) << candidate.first;
        vector<string> votes = candidate.second;
        for (auto v : votes)
        {
            cout << "|" << setw(8) << v;
        }
        cout << endl;
    }
}

string Result::getWinningPartiesAndCandidates()
{
    string winners = "";
    for (auto &party : parties)
    {
        int seats = party->getSeatsReceived();
        winners += party->getName() + " received: " + to_string(seats) + " seats with " + to_string(party->getOriginalVotes()) + " votes";
        double percentage = (int)(party->getOriginalVotes() / float(number_of_votes) * 100);

        if (number_of_votes == 0)
        {
            percentage = 0.00;
        }
        winners += +" (" + to_string(percentage) + "\% of the total votes) for candidates: ";
        vector<string> candidates = party->getCandidates();
        if (seats > 0)
        {
            for (int i = 0; i < seats; i++)
            {
                winners += candidates[i] + " ";
            }
        }
        winners += '\n';
    }
    return winners;
}

void Result::displayResult()
{
    cout << "Winner of the election: " << winner << endl;
}
string Result::getTypeOfVoting()
{
    return type_of_voting;
}
int Result::getNumberOfVote()
{
    return number_of_votes;
}
string Result::getWinner()
{
    return winner;
}
void Result::setTypeOfVoting(string votingType)
{
    type_of_voting = votingType;
}
void Result::setNumberOfVote(int numVote)
{
    number_of_votes = numVote;
}
void Result::setWinner(string electionWinner)
{
    winner = electionWinner;
}
