#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/Candidate.h"
#include "../src/include/BallotIR.h"

class CandidateTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(CandidateTest, fullTest)
{
    // First constructor test.
    Candidate candidate = Candidate();

    EXPECT_EQ(candidate.getBallots().empty() == true, true);
    EXPECT_EQ(candidate.getActive() == true, true);
    EXPECT_EQ(candidate.getCandidateTotalVote() == 0, true);
    EXPECT_EQ(candidate.getCandidateName() == "", true);

    candidate.setActive(false);
    EXPECT_EQ(candidate.getActive() == false, true);
    vector<string> c;
    c.push_back("Test");
    vector<string> c1;
    c1.push_back("Test1");
    BallotIR *ballot = new BallotIR(c, 1);
    BallotIR *ballot1 = new BallotIR(c1, 1);
    candidate.appendBallot(ballot);

    EXPECT_EQ(candidate.getBallots().at(0)->getCandidate(0) == "Test", true);
    EXPECT_EQ(candidate.getCandidateTotalVote() == 1, true);

    candidate.appendBallot(ballot1);

    EXPECT_EQ(candidate.getBallots().at(1)->getCandidate(0) == "Test1", true);
    EXPECT_EQ(candidate.getCandidateTotalVote() == 2, true);

    // Constructor with parameters test.
    Candidate candidate2 = Candidate("Test");

    EXPECT_EQ(candidate2.getBallots().empty() == true, true);
    EXPECT_EQ(candidate2.getActive() == true, true);
    EXPECT_EQ(candidate2.getCandidateTotalVote() == 0, true);
    EXPECT_EQ(candidate2.getCandidateName() == "Test", true);

    candidate2.setActive(false);
    EXPECT_EQ(candidate2.getActive() == false, true);
}