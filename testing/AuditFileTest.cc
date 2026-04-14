#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/AuditFile.h"
class AuditTest : public ::testing::Test
{
public:
  void SetUp() {}
  void TearDown() {}
};
TEST(AuditTest, emptyConstructor)
{
  AuditFile audit = AuditFile();
  EXPECT_EQ(audit.getVotingType(), " ");
  EXPECT_EQ(audit.getBallotNum(), 0);
  EXPECT_EQ(audit.getNumberCandidates(), 0);
  EXPECT_EQ(audit.getWinner(), " ");
}

TEST(AuditTest, CPLConstructor)
{
  vector<Party*> parties;
  parties.push_back(new Party("Democrat"));
  parties.push_back(new Party("Republican"));
  vector<string> steps;
  steps.push_back("step1");
  steps.push_back("step2");
  AuditFile audit = AuditFile("12-12-2022", "CPL",2, parties, 2, steps, "Democratic") ;
  EXPECT_EQ(audit.getVotingType(), "CPL");
  EXPECT_EQ(audit.getBallotNum(), 2);
  EXPECT_EQ(audit.getSteps().at(0), "step1");
  EXPECT_EQ(audit.getSteps().at(1), "step2");
  EXPECT_EQ(audit.getWinner(), "Democratic");
} 
TEST(AuditTest, IRConstructor)
{
  vector<Candidate> candidates;
  candidates.push_back(Candidate("Dorthy"));
  candidates.push_back(Candidate("Larry"));
  vector<string> steps;
  steps.push_back("step1");
  steps.push_back("step2");
  AuditFile audit = AuditFile("12-12-2022", "IR",2, candidates, 2, steps, "Dorthy") ;
  EXPECT_EQ(audit.getVotingType(), "IR");
  EXPECT_EQ(audit.getNumberCandidates(), 2);
  // EXPECT_EQ(audit.getCandidates(), candidates);
  EXPECT_EQ(audit.getCandidates().at(0).getCandidateName(), "Dorthy");
  EXPECT_EQ(audit.getCandidates().at(1).getCandidateName(), "Larry");
  EXPECT_EQ(audit.getBallotNum(), 2);
  EXPECT_EQ(audit.getSteps().at(0), "step1");
  EXPECT_EQ(audit.getSteps().at(1), "step2");
  EXPECT_EQ(audit.getWinner(), "Dorthy");
} 
 TEST(AuditTest, createAuditFileCPLTest){
  vector<Party*> parties;
  parties.push_back(new Party("Democrat"));
  parties.push_back(new Party("Republican"));

  vector<string> steps;
  steps.push_back("step1");
  steps.push_back("step2");
  AuditFile audit = AuditFile("12-12-2022", "CPL",2, parties, 2, steps, "Democrat") ;
  EXPECT_EQ(audit.getVotingType(), "CPL");
  EXPECT_EQ(audit.getBallotNum(), 2);
  EXPECT_EQ(audit.getSteps().at(0), "step1");
  EXPECT_EQ(audit.getSteps().at(1), "step2");
  EXPECT_EQ(audit.getWinner(), "Democrat");
  string filename = "CPL12-12-2022.txt";
  string actual = audit.create_AuditFileCPL();
  EXPECT_EQ(filename, actual);
 }
 
 TEST(AuditTest, createAuditFileIRTest){
  vector<Candidate> candidates;
  candidates.push_back(Candidate("Dorthy"));
  candidates.push_back(Candidate("Larry"));

  vector<string> steps;
  steps.push_back("step1");
  steps.push_back("step2");
  AuditFile audit = AuditFile("12-12-2022", "IR",2, candidates, 2, steps, "Dorthy") ;
  EXPECT_EQ(audit.getVotingType(), "IR");
  EXPECT_EQ(audit.getNumberCandidates(), 2);
  // EXPECT_EQ(audit.getCandidates(), candidates);
  EXPECT_EQ(audit.getCandidates().at(0).getCandidateName(), "Dorthy");
  EXPECT_EQ(audit.getCandidates().at(1).getCandidateName(), "Larry");
  EXPECT_EQ(audit.getBallotNum(), 2);
  EXPECT_EQ(audit.getSteps().at(0), "step1");
  EXPECT_EQ(audit.getSteps().at(1), "step2");
  EXPECT_EQ(audit.getWinner(), "Dorthy");
  string filename = "IR12-12-2022.txt";

  string actual = audit.create_AuditFileIR();
  EXPECT_EQ(filename, actual);
 }
  