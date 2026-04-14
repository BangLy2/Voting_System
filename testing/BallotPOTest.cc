#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/BallotPO.h"
#include <iostream>
using namespace std;

class BallotPOTest : public ::testing::Test
{
public:
    void SetUp() {}
    void TearDown() {}
};



TEST(BallotPO, testCandidate)
{
    vector<string> candidates;
    candidates.push_back("test");
    candidates.push_back("test1");
    BallotPO ballot1 = BallotPO(candidates, 0);
    BallotPO ballot2 = BallotPO(candidates, 1);
    
    EXPECT_EQ(ballot1.getCandidate() == "test", true);
    EXPECT_EQ(ballot2.getCandidate() == "test1", true); 
    EXPECT_EQ(ballot1.getCandidates() == candidates, true); 

    vector<string> candidates2;
    candidates2.push_back("test2");
    candidates2.push_back("test3");
    candidates2.push_back("test4");
    candidates2.push_back("test5");
    candidates2.push_back("test6");
    candidates2.push_back("test7");
    candidates2.push_back("test8");
    candidates2.push_back("test9");

    ballot1.setCandidates(candidates2);

    EXPECT_EQ(ballot1.getCandidates() == candidates2, true);
}  


TEST(BallotPO, testChoice)
{
    vector<string> candidates;
    candidates.push_back("test");
    candidates.push_back("test1");
    BallotPO ballot1 = BallotPO(candidates, 0);
    BallotPO ballot2 = BallotPO(candidates, 1);
    
    EXPECT_EQ(ballot1.getChoice() == 0, true);
    EXPECT_EQ(ballot2.getChoice() == 1, true);    

    ballot1.setChoice(1);
    ballot2.setChoice(0);

    EXPECT_EQ(ballot1.getChoice() == 1, true);
    EXPECT_EQ(ballot2.getChoice() == 0, true);  
}

TEST(BallotPO, testConstructor)
{
    vector<string> candidates;
    candidates.push_back("test");
    candidates.push_back("test1");
    BallotPO ballot1 = BallotPO(candidates);
    BallotPO ballot2 = BallotPO(candidates, 0);
    BallotPO ballot3 = BallotPO(candidates, 1);
    BallotPO ballot4 = BallotPO();
        
    EXPECT_EQ(ballot1.getCandidate() == "test", true); 
    EXPECT_EQ(ballot2.getCandidate() == "test", true);
    EXPECT_EQ(ballot3.getCandidate() == "test1", true); 

    EXPECT_EQ(ballot1.getCandidates() == candidates, true); 
    EXPECT_EQ(ballot2.getCandidates() == candidates, true);
    EXPECT_EQ(ballot3.getCandidates() == candidates, true); 
    EXPECT_EQ(ballot4.getCandidates().empty() == true, true);   

    EXPECT_EQ(ballot1.getChoice() == 0, true); 
    EXPECT_EQ(ballot2.getChoice() == 0, true);
    EXPECT_EQ(ballot3.getChoice() == 1, true);   
}  