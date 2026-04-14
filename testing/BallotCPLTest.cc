#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/BallotCPL.h"
class BallotCPLTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(BallotCPLTest, emptyContructorTest)
{
    BallotCPL ballot = BallotCPL();
    Party *party = ballot.getParty();
    vector<string> expectedCandidates;
    EXPECT_TRUE(party->getCandidates() == expectedCandidates);
    EXPECT_EQ(party->getRemainingVotes(), 0);
    EXPECT_EQ(party->getSeatsReceived(), 0);
}

TEST(BallotCPLTest, contructorTest)
{
    string partyName = "democrat";
    Party *party = new Party(partyName);
    BallotCPL ballot = BallotCPL(partyName, party);

    EXPECT_TRUE(ballot.getParty() == party);
}

TEST(BallotCPLTest, getParty)
{
    string partyName = "republican";
    Party *party = new Party(partyName);
    party->incrementVote();
    vector<string> candidates = {"Bob", "Joe", "Sarah"};
    party->setCandidates(candidates);

    BallotCPL ballot = BallotCPL(partyName, party);
    EXPECT_TRUE(ballot.getParty() == party);
}