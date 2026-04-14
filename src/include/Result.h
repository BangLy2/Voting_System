#ifndef RESULT
#define RESULT

#include <iostream>
#include <string>
#include <vector> // #include directive
#include "Party.h"
#include "Candidate.h"
#include "BallotIR.h"
#include "IRTable.h"
#include "BallotPO.h"
#include "CandidatePO.h"
using namespace std;
class Result
{
public:
  /**
   * @brief default constructor
   **/
  Result();

  /**
   * @brief constructor
   * @param[in] VotingType the type of voting
   * @param[in] date the date of election
   * @param[in] numCandidates the number of candidate
   * @param[in] candidates the vector of candidates
   * @param[in] numBallots the number of ballots
   * @param[in] ballots the vector of BallotIR
   * @param[in] eliminatedCandidates the vector of eliminatedCandidates
   * @param[in] winner the winning candidate
   **/
  Result(string VotingType, string date, int numCandidates, vector<Candidate> candidates, int numBallots, vector<BallotIR *> ballots, vector<Candidate> eliminatedCandidates, string winner, IRTable irTable);

  /**
   * @brief constructor
   * @param[in] VotingType the type of voting
   * @param[in] date the date of election
   * @param[in] numParties the number of parties
   * @param[in] parties the vector of Party
   * @param[in] numBallots the number of ballots
   **/
  Result(string VotingType, string date, int numParties, vector<Party *> parties, int numBallots);

  /**
   * @brief constructor
   * @param[in] VotingType the type of voting
   * @param[in] date the date of election
   * @param[in] numParties the number of parties
   * @param[in] parties the vector of Party
   * @param[in] numBallots the number of ballots
   **/
  Result(string VotingType, string date, vector<BallotPO *> ballots, int numberCandidates, vector<CandidatePO> candidates, int numBallots, string winner);

  /**
   * @brief display the result
   **/
  void displayResult();

  /**
   * @brief get the voting type
   * @return the type of voting
   **/
  string getTypeOfVoting();

  /**
   * @brief get the number of vote
   * @return the number of vote
   **/
  int getNumberOfVote();

  /**
   * @brief get the winner
   * @return the winner name
   **/
  string getWinner();

  /**
   * @brief set the type of voting
   * @param[in] VotingType the type of voting
   **/
  void setTypeOfVoting(string votingType);

  /**
   * @brief set the total number of Vote
   * @param[in] numVote the type of voting
   **/
  void setNumberOfVote(int numVote);

  /**
   * @brief set the winner
   * @param[in] electionWinner the name of the winner
   **/
  void setWinner(string electionWinner);

  /**
   * @brief display CPL Result
   **/
  void displayCPLResult();

  /**
   * @brief display IR Result
   **/
  void displayIRResult();

  /**
   * @brief display PO Result
   **/
  void displayPOResult();

  /**
   * @brief get the winning Parties and Candidates
   * @return the winning parties and candidates
   **/
  string getWinningPartiesAndCandidates();

  /**
   * @brief display IR Table
   **/
  void displayIRTable();

private:
  string type_of_voting;
  int number_of_votes;
  string winner;
  string date;
  int numParties;
  vector<Party *> parties;
  int numCandidates;
  vector<Candidate> candidates;
  vector<Candidate> eliminatedCandidates;
  int numBallots;
  vector<BallotIR *> ballots;
  vector<CandidatePO> candidatesPO;
  vector<BallotPO *> ballotsPO;
  IRTable irTable;
  int quota;
};
#endif