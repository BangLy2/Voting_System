#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/POAlgorithm.h"
#include "../src/include/CandidatePO.h"
#include "../src/include/BallotPO.h"

class POAlgorithmTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(POAlgorithmTest, TestBallot) {
    vector<string> b1;
    b1.push_back("Ballot");
    vector<string> b2;
    b2.push_back("Ballot2");
    BallotPO* c = new BallotPO(b1);
    BallotPO* c1 = new BallotPO(b2);
    vector<BallotPO*> ballot;
    ballot.push_back(c);
    ballot.push_back(c1);

    POAlgorithm alg = POAlgorithm();
    
    // set ballot tests
    alg.setBallot(ballot);
    EXPECT_EQ(alg.getBallot() == ballot, true);

}

TEST(POAlgorithmTest, TestCandidates) {
    CandidatePO c1 = CandidatePO("CandidatePO1");
    CandidatePO c2 = CandidatePO("CandidatePO2");
    vector<CandidatePO> Candidate;
    Candidate.push_back(c1);
    Candidate.push_back(c2);
    
    POAlgorithm alg = POAlgorithm();
    
    // set CandidatePO tests
    alg.setCandidates(Candidate);
    EXPECT_EQ(alg.getCandidates().at(0).getCandidateName() == "CandidatePO1", true);
    EXPECT_EQ(alg.getCandidates().at(1).getCandidateName() == "CandidatePO2", true);
}

TEST(POAlgorithmTest, TestNumberOfCandidates) {
    POAlgorithm alg = POAlgorithm();

    // set num of CandidatePOs tests
    alg.setNumberOfCandidates(10);
    EXPECT_EQ(alg.getNumberOfCandidates() == 10, true);
}

TEST(POAlgorithmTest, TestNumberOfBallots) {
    POAlgorithm alg = POAlgorithm();
    
    // set num of ballots tests
    alg.setNumberOfBallots(10);
    EXPECT_EQ(alg.getNumberOfBallots() == 10, true);
}

TEST(POAlgorithmTest, getSteps) {
     POAlgorithm alg = POAlgorithm();
    // set winner tests
    vector<string> steps;
    EXPECT_EQ(alg.getSteps() == steps, true);
}

TEST(POAlgorithmTest, breakTie) { // start here james
    
    vector<CandidatePO> tiedCandidates;
    tiedCandidates.push_back(CandidatePO("Candidate x"));
    tiedCandidates.push_back(CandidatePO("Candidate y"));

    POAlgorithm alg = POAlgorithm();
    EXPECT_EQ(alg.breakTie(tiedCandidates).getCandidateName() == "Candidate x" || "Candidate y", true);
}

TEST(POAlgorithmTest, countBallots) {
    int numberOfCandidates = 3;

    vector<CandidatePO> candidates; // used for creating candidates
    candidates.push_back(CandidatePO("Candidate x"));
    candidates.push_back(CandidatePO("Candidate y"));
    candidates.push_back(CandidatePO("Candidate z"));

    vector<string> candidates1; // used for creating ballots
    candidates1.push_back("Candidate x");
    candidates1.push_back("Candidate y");
    candidates1.push_back("Candidate z");

    // ballot for parameter ballots
    vector<BallotPO*> ballots; // creating ballots
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 1));

    int numberOfBallots = 3;

    POAlgorithm alg = POAlgorithm(ballots, numberOfCandidates, candidates, numberOfBallots);
    alg.countBallots();
    EXPECT_EQ(alg.getCandidates().at(0).getCandidateTotalVote() == 2, true);
    EXPECT_EQ(alg.getCandidates().at(1).getCandidateTotalVote() == 1, true);
    EXPECT_EQ(alg.getCandidates().at(2).getCandidateTotalVote() == 0, true);
}

TEST(POAlgorithmTest, pickPopularCandidate) {
    int numberOfCandidates = 3;

    vector<CandidatePO> candidates; // used for creating candidates
    candidates.push_back(CandidatePO("Candidate x"));
    candidates.push_back(CandidatePO("Candidate y"));
    candidates.push_back(CandidatePO("Candidate z"));

    vector<string> candidates1; // used for creating ballots
    candidates1.push_back("Candidate x");
    candidates1.push_back("Candidate y");
    candidates1.push_back("Candidate z");

    // ballot for parameter ballots
    vector<BallotPO*> ballots; // creating ballots
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 1));

    int numberOfBallots = 3;

    POAlgorithm alg = POAlgorithm(ballots, numberOfCandidates, candidates, numberOfBallots);
    alg.countBallots();
    EXPECT_EQ(alg.pickPopularCandidate().getCandidateName() == "Candidate x", true);

}

TEST(POAlgorithmTest, TestConstructor) {
    POAlgorithm alg0 = POAlgorithm();
    EXPECT_EQ(alg0.getBallot().empty() == true, true);
    EXPECT_EQ(alg0.getCandidates().empty() == true, true);
    EXPECT_EQ(alg0.getNumberOfCandidates() == 0, true);
    EXPECT_EQ(alg0.getNumberOfBallots() == 0, true);
    EXPECT_EQ(alg0.getWinner().empty() == true, true);
    EXPECT_EQ(alg0.getSteps().empty() == true, true);
    
    int numberOfCandidates = 3;

    vector<CandidatePO> candidates; // used for creating candidates
    candidates.push_back(CandidatePO("Candidate x"));
    candidates.push_back(CandidatePO("Candidate y"));
    candidates.push_back(CandidatePO("Candidate z"));

    vector<string> candidates1; // used for creating ballots
    candidates1.push_back("Candidate x");
    candidates1.push_back("Candidate y");
    candidates1.push_back("Candidate z");

    // ballot for parameter ballots
    vector<BallotPO*> ballots; // creating ballots
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 1));

    int numberOfBallots = 3;

    POAlgorithm alg = POAlgorithm(ballots, numberOfCandidates, candidates, numberOfBallots);

    EXPECT_EQ(alg.getBallot() == ballots, true);
    EXPECT_EQ(alg.getCandidates().at(0).getCandidateName() == "Candidate x", true);
    EXPECT_EQ(alg.getCandidates().at(1).getCandidateName() == "Candidate y", true);
    EXPECT_EQ(alg.getCandidates().at(2).getCandidateName() == "Candidate z", true);
    EXPECT_EQ(alg.getNumberOfCandidates() == numberOfCandidates, true);
    EXPECT_EQ(alg.getNumberOfBallots() == numberOfBallots, true);
    EXPECT_EQ(alg.getWinner().empty() == true, true);
    EXPECT_EQ(alg.getSteps().empty() == true, true);
}

TEST(POAlgorithmTest, runPO1) {
    int numberOfCandidates = 3;

    vector<CandidatePO> candidates; // used for creating candidates
    candidates.push_back(CandidatePO("Candidate x"));
    candidates.push_back(CandidatePO("Candidate y"));
    candidates.push_back(CandidatePO("Candidate z"));

    vector<string> candidates1; // used for creating ballots
    candidates1.push_back("Candidate x");
    candidates1.push_back("Candidate y");
    candidates1.push_back("Candidate z");

    // ballot for parameter ballots
    vector<BallotPO*> ballots; // creating ballots
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 1));

    int numberOfBallots = 3;

    POAlgorithm alg = POAlgorithm(ballots, numberOfCandidates, candidates, numberOfBallots);

    alg.runPO();
    EXPECT_EQ(alg.getWinner() == "Candidate x", true);
}

TEST(POAlgorithmTest, runPO2) {
    int numberOfCandidates = 3;

    vector<CandidatePO> candidates; // used for creating candidates
    candidates.push_back(CandidatePO("Candidate x"));
    candidates.push_back(CandidatePO("Candidate y"));
    candidates.push_back(CandidatePO("Candidate z"));

    vector<string> candidates1; // used for creating ballots
    candidates1.push_back("Candidate x");
    candidates1.push_back("Candidate y");
    candidates1.push_back("Candidate z");

    // ballot for parameter ballots
    vector<BallotPO*> ballots; // creating ballots
    ballots.push_back(new BallotPO(candidates1, 0));
    ballots.push_back(new BallotPO(candidates1, 2));
    ballots.push_back(new BallotPO(candidates1, 2));
    ballots.push_back(new BallotPO(candidates1, 2));
    ballots.push_back(new BallotPO(candidates1, 1));
    ballots.push_back(new BallotPO(candidates1, 0));

    int numberOfBallots = 6;

    POAlgorithm alg = POAlgorithm(ballots, numberOfCandidates, candidates, numberOfBallots);

    alg.runPO();
    EXPECT_EQ(alg.getWinner() == "Candidate z", true);
}