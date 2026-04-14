#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/BallotIR.h"
#include <iostream>
using namespace std;

class BallotIRTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(BallotIRTest, fullTest)
{
    BallotIR ballot = BallotIR();

    EXPECT_EQ(ballot.getRank() == 0, true);
    ballot.incrementRank();
    EXPECT_EQ(ballot.getRank() == 1, true);

    EXPECT_EQ(ballot.getValid() == true, true);
    ballot.setValid(false);
    EXPECT_EQ(ballot.getValid() == false, true);

    vector<string> candidates;
    candidates.push_back("test");
    candidates.push_back("test1");
    BallotIR ballot2 = BallotIR(candidates, 2);

    for (int i = 0; i < candidates.size(); i++)
    {
        EXPECT_EQ(ballot2.getCandidates().at(i) == candidates.at(i), true);
        EXPECT_EQ(ballot2.getCandidate(i) == candidates.at(i), true);
    }

    EXPECT_EQ(ballot2.getRank() == 0, true);
    ballot2.incrementRank();
    EXPECT_EQ(ballot2.getRank() == 1, true);

    EXPECT_EQ(ballot2.getValid() == true, true);
    ballot2.setValid(false);
    EXPECT_EQ(ballot2.getValid() == false, true);
}