#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/CPLAlgorithm.h"
class CPLAlgorithmTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};

TEST(CPLAlgorithmTest, emptyConstructor)
{
    CPLAlgorithm cpl = CPLAlgorithm();
    vector<BallotCPL> ballots;
    vector<string> steps;
    vector<Party *> parties;
    EXPECT_TRUE(cpl.getBallots().size() == 0);
    EXPECT_EQ(cpl.getNumberOfParties(), 0);
    EXPECT_TRUE(cpl.getParties() == parties);
    EXPECT_EQ(cpl.getNumberOfSeats(), 0);
    EXPECT_EQ(cpl.getNumberOfBallots(), 0);
    EXPECT_TRUE(cpl.getSteps() == steps);
}

TEST(CPLAlgorithmTest, constructor)
{
    vector<BallotCPL> ballots;

    string partyName1 = "democrats";
    Party* party1 = new Party(partyName1);
    BallotCPL ballot1 = BallotCPL(partyName1, party1);

    ballots.push_back(ballot1);

    int numberOfParties = 1;
    vector<Party*>parties = {party1};

    int numberOfSeats = 1;
    int numberOfBallots = 1;

    vector<string> steps;

    CPLAlgorithm cpl = CPLAlgorithm(ballots, numberOfParties, parties, numberOfSeats, numberOfBallots);
    EXPECT_EQ(cpl.getBallots()[0].getParty(), party1);
    EXPECT_EQ(cpl.getNumberOfParties(), 1);
    EXPECT_TRUE(cpl.getParties() == parties);
    EXPECT_EQ(cpl.getNumberOfSeats(), 1);
    EXPECT_EQ(cpl.getNumberOfBallots(), 1);
    EXPECT_TRUE(cpl.getSteps() == steps);
}

TEST(CPLAlgorithmTest, countBallots)
{
    vector<Party*> parties;

    string partyName1 = "democrats";
    string partyName2 = "republicans";
    string partyName3 = "independent";

    Party* party1 = new Party(partyName1);
    Party* party2 = new Party(partyName2);
    Party* party3 = new Party(partyName3);

    parties.push_back(party1);
    parties.push_back(party2);
    parties.push_back(party3);

    vector<BallotCPL> ballots;

    BallotCPL ballot11 = BallotCPL(partyName1, party1);

    BallotCPL ballot21 = BallotCPL(partyName2, party2);
    BallotCPL ballot22 = BallotCPL(partyName2, party2);

    BallotCPL ballot31 = BallotCPL(partyName3, party3);
    BallotCPL ballot32 = BallotCPL(partyName3, party3);
    BallotCPL ballot33 = BallotCPL(partyName3, party3);

    ballots.push_back(ballot11);
    ballots.push_back(ballot21);
    ballots.push_back(ballot22);
    ballots.push_back(ballot31);
    ballots.push_back(ballot32);
    ballots.push_back(ballot33);

    CPLAlgorithm cpl = CPLAlgorithm(ballots, 3, parties, -1, 6);
    cpl.countBallots();
    EXPECT_EQ(parties[0]->getRemainingVotes(), 1);
    EXPECT_EQ(parties[1]->getRemainingVotes(), 2);
    EXPECT_EQ(parties[2]->getRemainingVotes(), 3);

}

TEST(CPLAlgorithmTest, calculateQuota){
    CPLAlgorithm cpl = CPLAlgorithm();

    EXPECT_EQ(cpl.calculateQuota(8, 3), 2);
    EXPECT_EQ(cpl.calculateQuota(9, 3), 3);
    EXPECT_EQ(cpl.calculateQuota(10, 3), 3);
}

TEST(CPLAlgorithmTest, calculateSeats){
    CPLAlgorithm cpl = CPLAlgorithm();

    EXPECT_EQ(cpl.calculateSeats(8, 3), 2);
    EXPECT_EQ(cpl.calculateSeats(9, 3), 3);
    EXPECT_EQ(cpl.calculateSeats(10, 3), 3);
}

TEST(CPLAlgorithmTest, calculateRemainderVotes){
    CPLAlgorithm cpl = CPLAlgorithm();

    EXPECT_EQ(cpl.calculateRemainderVotes(8, 3), 2);
    EXPECT_EQ(cpl.calculateRemainderVotes(9, 3), 0);
    EXPECT_EQ(cpl.calculateRemainderVotes(10, 3), 1);
}

TEST(CPLAlgorithmTest, runCPL)
{
    vector<Party*> parties;

    string partyName1 = "democrats";
    string partyName2 = "republicans";
    string partyName3 = "independent";

    Party* party1 = new Party(partyName1);
    Party* party2 = new Party(partyName2);
    Party* party3 = new Party(partyName3);

    vector<string> candidates = {"bob", "joe", "sarah"};

    party1->setCandidates(candidates);
    party2->setCandidates(candidates);
    party3->setCandidates(candidates);

    parties.push_back(party1);
    parties.push_back(party2);
    parties.push_back(party3);

    vector<BallotCPL> ballots;

    BallotCPL ballot11 = BallotCPL(partyName1, party1);

    BallotCPL ballot21 = BallotCPL(partyName2, party2);
    BallotCPL ballot22 = BallotCPL(partyName2, party2);

    BallotCPL ballot31 = BallotCPL(partyName3, party3);
    BallotCPL ballot32 = BallotCPL(partyName3, party3);
    BallotCPL ballot33 = BallotCPL(partyName3, party3);

    ballots.push_back(ballot11);
    ballots.push_back(ballot21);
    ballots.push_back(ballot22);
    ballots.push_back(ballot31);
    ballots.push_back(ballot32);
    ballots.push_back(ballot33);

    CPLAlgorithm cpl = CPLAlgorithm(ballots, 3, parties, 2, 6);
    cpl.runCPL();
    EXPECT_EQ(parties[0]->getSeatsReceived(), 0);
    EXPECT_EQ(parties[1]->getSeatsReceived(), 1);
    EXPECT_EQ(parties[2]->getSeatsReceived(), 1);
}

TEST(CPLAlgorithmTest, breakTie)
{
    CPLAlgorithm cpl = CPLAlgorithm();
    string partyName1 = "democrats";
    string partyName2 = "republicans";
    string partyName3 = "independent";
    vector<Party*> parties;
    Party* party1 = new Party(partyName1);
    Party* party2 = new Party(partyName2);
    Party* party3 = new Party(partyName3);

    parties.push_back(party1);
    parties.push_back(party2);
    parties.push_back(party3);

    Party* party = cpl.breakTie(parties);

    EXPECT_TRUE(party == party1 || party == party2 || party == party3);
}

TEST(CPLAlgorithmTest, distributeSeatsRandomly)
{
    vector<Party*> parties;

    string partyName1 = "democrats";
    string partyName2 = "republicans";
    string partyName3 = "independent";

    Party* party1 = new Party(partyName1);
    Party* party2 = new Party(partyName2);
    Party* party3 = new Party(partyName3);

    vector<string> candidates = {"bob", "joe", "sarah"};

    party1->setCandidates(candidates);
    party2->setCandidates(candidates);
    party3->setCandidates(candidates);

    parties.push_back(party1);
    parties.push_back(party2);
    parties.push_back(party3);

    vector<BallotCPL> ballots;

    BallotCPL ballot11 = BallotCPL(partyName1, party1);

    BallotCPL ballot21 = BallotCPL(partyName2, party2);
    BallotCPL ballot22 = BallotCPL(partyName2, party2);

    BallotCPL ballot31 = BallotCPL(partyName3, party3);
    BallotCPL ballot32 = BallotCPL(partyName3, party3);
    BallotCPL ballot33 = BallotCPL(partyName3, party3);

    ballots.push_back(ballot11);
    ballots.push_back(ballot21);
    ballots.push_back(ballot22);
    ballots.push_back(ballot31);
    ballots.push_back(ballot32);
    ballots.push_back(ballot33);

    CPLAlgorithm cpl = CPLAlgorithm(ballots, 3, parties, 2, 6);
    cpl.countBallots();
    cpl.distributeSeatsRandomly(1);

    int count = 0;
    for(auto &party: parties){
        count += party->getSeatsReceived();
    }

    EXPECT_EQ(count, 1);

    cpl.distributeSeatsRandomly(2);

    count = 0;
    for(auto &party: parties){
        count += party->getSeatsReceived();
    }

    EXPECT_EQ(count, 3);
}
