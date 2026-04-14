#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/Party.h"
class PartyTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(PartyTest, emptyContructorTest)
{
    Party party = Party();
    vector<string> expectedCandidates;
    int expectedRemainingVotes = 0;
    int expectedSeatsReceived = 0;
    EXPECT_EQ(party.getCandidates() == expectedCandidates, true);
    EXPECT_EQ(party.getRemainingVotes() == expectedRemainingVotes, true);
    EXPECT_EQ(party.getSeatsReceived(), expectedSeatsReceived);
}

TEST(PartyTest, contructorTest)
{
    string partyName = "dems";
    int expectedRemainingVotes = 10;
    vector<string> expectedCandidates;
    int expectedSeatsReceived = 5;
    Party party = Party(partyName);
    party.setRemainingVotes(expectedRemainingVotes);
    party.addSeatsReceived(expectedSeatsReceived);
    EXPECT_EQ(party.getCandidates() == expectedCandidates, true);
    EXPECT_EQ(party.getRemainingVotes(), expectedRemainingVotes);
    EXPECT_EQ(party.getSeatsReceived(), expectedSeatsReceived);
}

TEST(PartyTest, getName)
{
    string partyName = "dems";
    Party party = Party(partyName);
    EXPECT_EQ(party.getName(), partyName);
}

TEST(PartyTest, incrementVote)
{
    Party party = Party();
    EXPECT_EQ(party.getRemainingVotes(), 0);
    party.incrementVote();
    EXPECT_EQ(party.getRemainingVotes(), 1);
    party.incrementVote();
    EXPECT_EQ(party.getRemainingVotes(), 2);
}

TEST(PartyTest, getAndSetRemainingVotes)
{
    Party party = Party();
    int votes = 832;
    party.setRemainingVotes(votes);
    EXPECT_EQ(party.getRemainingVotes(), votes);
}

TEST(PartyTest, addAndGetSeatsReceived)
{
    Party party = Party();
    EXPECT_EQ(party.getSeatsReceived(), 0);
    int seats = 5;
    party.addSeatsReceived(seats);
    EXPECT_EQ(party.getSeatsReceived(), seats);
}

TEST(PartyTest, getAndSetCandidates)
{
    Party party = Party();
    vector<string> candidates = {"Bob", "Joe", "Sarah"};
    party.setCandidates(candidates);
    EXPECT_EQ(party.getCandidates() == candidates, true);
}

TEST(PartyTest, getSeatsRemaining)
{
    Party party = Party();
    vector<string> candidates = {"Bob", "Joe", "Sarah"};
    party.setCandidates(candidates);
    party.addSeatsReceived(2);
    EXPECT_EQ(party.getSeatsRemaining(), 1);
}