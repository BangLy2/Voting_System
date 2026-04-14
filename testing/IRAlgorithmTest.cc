#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/IRAlgorithm.h"
#include "../src/include/Candidate.h"
#include "../src/include/BallotIR.h"

class IRAlgorithmTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(IRAlgorithmTest, GetSetBallot)
{

    vector<string> b1;
    b1.push_back("Ballot");
    vector<string> b2;
    b2.push_back("Ballot2");
    BallotIR *c = new BallotIR(b1, 1);
    BallotIR *c1 = new BallotIR(b2, 1);
    vector<BallotIR *> ballot;
    ballot.push_back(c);
    ballot.push_back(c1);

    IRAlgorithm alg = IRAlgorithm();

    // set ballot tests
    alg.setBallot(ballot);
    EXPECT_EQ(alg.getBallot().at(0)->getCandidate(0) == "Ballot", true);
    EXPECT_EQ(alg.getBallot().at(1)->getCandidate(0) == "Ballot2", true);
}

TEST(IRAlgorithmTest, GetSetCandidates)
{
    Candidate c1 = Candidate("Candidate1");
    Candidate c2 = Candidate("Candidate2");
    vector<Candidate> candidate;
    candidate.push_back(c1);
    candidate.push_back(c2);

    IRAlgorithm alg = IRAlgorithm();

    // set candidate tests
    alg.setCandidate(candidate);
    EXPECT_EQ(alg.getCandidates().at(0).getCandidateName() == "Candidate1", true);
    EXPECT_EQ(alg.getCandidates().at(1).getCandidateName() == "Candidate2", true);
}

TEST(IRAlgorithmTest, GetSetNumOfCandidates)
{

    IRAlgorithm alg = IRAlgorithm();

    // set num of candidates tests
    alg.setNumberOfCandidates(10);
    EXPECT_EQ(alg.getNumberOfCandidates() == 10, true);
}

TEST(IRAlgorithmTest, GetSetNumOfBallots)
{

    IRAlgorithm alg = IRAlgorithm();

    // set num of ballots tests
    alg.setNumberOfBallots(10);
    EXPECT_EQ(alg.getNumberOfBallots() == 10, true);
}

TEST(IRAlgorithmTest, GetStepsTest)
{
    IRAlgorithm alg = IRAlgorithm();
    // set winner tests
    vector<string> steps;
    EXPECT_EQ(alg.getSteps() == steps, true);
}

TEST(IRAlgorithmTest, GetSetWinnerTest)
{

    IRAlgorithm alg = IRAlgorithm();

    // set winner tests
    alg.setWinner("winner");
    EXPECT_EQ(alg.getWinner() == "winner", true);
}

TEST(IRAlgorithmTest, breakTieTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    // break tie tests, how?!?
    EXPECT_EQ(algpara.breakTie(candidates).getCandidateName() == "x" || "y" || "z", true);
}

TEST(IRAlgorithmTest, countBallotsTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    // count ballots tests
    algpara.countBallots();
    EXPECT_EQ(algpara.getCandidates().at(0).getCandidateTotalVote() == 2, true);
    EXPECT_EQ(algpara.getCandidates().at(1).getCandidateTotalVote() == 1, true);
    EXPECT_EQ(algpara.getCandidates().at(2).getCandidateTotalVote() == 0, true);
}

TEST(IRAlgorithmTest, redistributeBallotsTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    // redristribute ballot tests
    algpara.countBallots();
    algpara.redistributeBallots(candidatex);
    EXPECT_EQ(algpara.getCandidates().at(1).getCandidateTotalVote() == 2, true);
    EXPECT_EQ(algpara.getCandidates().at(2).getCandidateTotalVote() == 1, true);
}

TEST(IRAlgorithmTest, pickPopularCandidateTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    candidatex.appendBallot(ballot1);
    candidatex.appendBallot(ballot1);
    Candidate candidatey = Candidate("y");
    candidatey.appendBallot(ballot1);
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    // pick popular candidate tests
    algpara.countBallots();
    EXPECT_EQ(algpara.pickPopularCandidate().getCandidateName() == "x", true);
}

TEST(IRAlgorithmTest, getLeastVoteCandidateTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    candidatex.appendBallot(ballot1);
    candidatex.appendBallot(ballot1);
    Candidate candidatey = Candidate("y");
    candidatey.appendBallot(ballot1);
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    // get least vote candidate tests
    algpara.countBallots();
    EXPECT_EQ(algpara.getLeastVoteCandidate().getCandidateName() == "z", true);
}

TEST(IRAlgorithmTest, getMajorityTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    // get majority tests
    algpara.countBallots();
    algpara.getMajority();
    EXPECT_EQ(algpara.getWinner() == "x", true);
}

TEST(IRAlgorithmTest, emptyContructorTest)
{
    IRAlgorithm alg = IRAlgorithm();

    // get num of candidates tests
    EXPECT_EQ(alg.getNumberOfCandidates() == 0, true);

    // get num of ballots tests
    EXPECT_EQ(alg.getNumberOfBallots() == 0, true);
}

TEST(IRAlgorithmTest, contructorParameterTest)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);

    EXPECT_EQ(algpara.getBallot() == ballots, true);
    EXPECT_EQ(algpara.getNumberOfCandidates() == numOfCandidates, true);
    EXPECT_EQ(algpara.getCandidates().at(0).getCandidateName() == "x", true);
    EXPECT_EQ(algpara.getCandidates().at(1).getCandidateName() == "y", true);
    EXPECT_EQ(algpara.getCandidates().at(2).getCandidateName() == "z", true);
    EXPECT_EQ(algpara.getNumberOfBallots() == numOfBallots, true);
}

TEST(IRAlgorithmTest, RunIRTest1)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    b11.push_back("y");
    b11.push_back("z");
    BallotIR *ballot1 = new BallotIR(b11, 3);
    vector<string> b22;
    b22.push_back("x");
    b22.push_back("z");
    b22.push_back("y");
    BallotIR *ballot2 = new BallotIR(b22, 3);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("z");
    b33.push_back("x");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 3;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);
    string result = algpara.runIR();

    EXPECT_EQ(result == "Completed", true);
    EXPECT_EQ(algpara.getWinner() == "x", true);
}

TEST(IRAlgorithmTest, RunIRTest2)
{
    // Constructor with paramater tests
    vector<string> b11;
    b11.push_back("x");
    BallotIR *ballot1 = new BallotIR(b11, 1);
    vector<string> b22;
    b22.push_back("x");
    BallotIR *ballot2 = new BallotIR(b22, 1);
    vector<string> b33;
    b33.push_back("y");
    b33.push_back("x");
    b33.push_back("z");
    BallotIR *ballot3 = new BallotIR(b33, 3);
    vector<string> b44;
    b44.push_back("y");
    b44.push_back("x");
    b44.push_back("z");
    BallotIR *ballot4 = new BallotIR(b44, 3);
    vector<BallotIR *> ballots;
    ballots.push_back(ballot1);
    ballots.push_back(ballot2);
    ballots.push_back(ballot3);
    ballots.push_back(ballot4);

    int numOfCandidates = 3;
    Candidate candidatex = Candidate("x");
    Candidate candidatey = Candidate("y");
    Candidate candidatez = Candidate("z");
    vector<Candidate> candidates;
    candidates.push_back(candidatex);
    candidates.push_back(candidatey);
    candidates.push_back(candidatez);
    int numOfBallots = 4;

    IRAlgorithm algpara = IRAlgorithm(ballots, numOfCandidates, candidates, numOfBallots);
    string result = algpara.runIR();

    EXPECT_EQ(result == "Completed", true);
    EXPECT_EQ(algpara.getWinner() == "x", true);
}