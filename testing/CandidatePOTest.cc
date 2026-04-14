#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/CandidatePO.h"
#include "../src/include/BallotPO.h"

class CandidatePOTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(CandidatePOTest, TestBallots)
{
    vector<string> c;
    c.push_back("Test");
    c.push_back("Test1");
    
    BallotPO *ballot = new BallotPO(c);
    CandidatePO Candidate = CandidatePO();


    EXPECT_EQ(Candidate.getBallots().empty() == true, true);
    Candidate.appendBallot(ballot);

    vector <BallotPO *> ballots;
    ballots.push_back(ballot);
    EXPECT_EQ(Candidate.getBallots() == ballots, true);
}

TEST(CandidatePOTest, TestCandidateTotalVote)
{
    vector<string> c;
    c.push_back("Test");
    c.push_back("Test1");
    
    BallotPO *ballot = new BallotPO(c);
    CandidatePO Candidate = CandidatePO();

    for (int i = 0; i < 10 ; i++) {
        EXPECT_EQ(Candidate.getCandidateTotalVote() == i, true);
        Candidate.appendBallot(ballot);
    }
    Candidate.setCandidateTotalVote(0);
    EXPECT_EQ(Candidate.getCandidateTotalVote() == 0, true);
}

TEST(CandidatePOTest, getCandidateName)
{
    
    CandidatePO Candidate = CandidatePO();
    CandidatePO Candidate1 = CandidatePO("Test");

    EXPECT_EQ(Candidate.getCandidateName() == "", true);
    EXPECT_EQ(Candidate1.getCandidateName() == "Test", true);
}

TEST(CandidatePOTest, TestConstructor)
{

    vector<string> c;
    c.push_back("Test2");
    c.push_back("Test3");
    
    BallotPO *ballot = new BallotPO(c);

    // First constructor test.
    CandidatePO Candidate = CandidatePO();

    EXPECT_EQ(Candidate.getBallots().empty() == true, true);
    EXPECT_EQ(Candidate.getCandidateTotalVote() == 0, true);
    EXPECT_EQ(Candidate.getCandidateName() == "", true);


    CandidatePO Candidate1 = CandidatePO("Test");

    EXPECT_EQ(Candidate1.getBallots().empty() == true, true);
    EXPECT_EQ(Candidate1.getCandidateTotalVote() == 0, true);
    EXPECT_EQ(Candidate1.getCandidateName() == "Test", true);

    Candidate1.appendBallot(ballot);
    vector <BallotPO *> ballots;
    ballots.push_back(ballot);
    EXPECT_EQ(Candidate1.getBallots() == ballots, true);
    EXPECT_EQ(Candidate1.getCandidateTotalVote() == 1, true);
}