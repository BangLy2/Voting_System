#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <sstream>
#include "../src/include/Election.h"
#include "../src/include/Candidate.h"
class ELectionTest : public ::testing::Test
{
public:
  void SetUp() {}
  void TearDown() {}
};
TEST(ElectionTest, obtainFileNameTest)
{
  Election election = Election();
  vector<string> files;
  files.push_back("test1.csv");
  files.push_back("test2.csv");
  files.push_back("test3.csv");
  stringstream s(files.at(0));
  vector<string> actual = election.obtainFileName(s);
  EXPECT_EQ(files.at(0), actual.at(0));
  stringstream s1(files.at(1));
  vector<string> actual1 = election.obtainFileName(s1);
  EXPECT_EQ(files.at(1), actual1.at(0));
  stringstream s2(files.at(2));
  vector<string> actual2 = election.obtainFileName(s2);
  EXPECT_EQ(files.at(2), actual2.at(0));  
}

TEST(ElectionTest, obtainDate)
{
  Election election = Election();
  string date = "12-12-2022";
  stringstream s(date);
  string actual = election.obtainDate(s);
  EXPECT_EQ(date, actual);
}

TEST(ElectionTest, parseFile)
{
  Election election = Election();

  vector<string> files;
  files.push_back("test1.csv");
  files.push_back("test2.csv");
  files.push_back("test3.csv");
  string date = "12-12-2022";
  stringstream s(date);
  int res = election.parseFile(files, s);
  EXPECT_EQ(0, res);
  
 
}

TEST(ElectionTest, IRParsing)
{
  Election election = Election();

  string ballotStr = "4,2,3,1,";
  Candidate candidate1 = Candidate("bob");
  Candidate candidate2 = Candidate("joe");
  Candidate candidate3 = Candidate("sarah");
  Candidate candidate4 = Candidate("jessica");

  vector<Candidate> candidates;
  candidates.push_back(candidate1);
  candidates.push_back(candidate2);
  candidates.push_back(candidate3);
  candidates.push_back(candidate4);

  BallotIR *ballot = election.IRParsing(ballotStr, candidates.size(), candidates);
  EXPECT_EQ(ballot->getCandidate(0), "jessica");
  EXPECT_EQ(ballot->getCandidate(1), "joe");
  EXPECT_EQ(ballot->getCandidate(2), "sarah");
  EXPECT_EQ(ballot->getCandidate(3), "bob");
}

TEST(ElectionTest, CPLParsingParties)
{
  Election election = Election();
  string partyStr = "Democrats, Republicans, Independent,";
  vector<Party *> parties = election.CPLParsingParties(partyStr);
  EXPECT_EQ(parties[0]->getName(), "Democrats");
  EXPECT_EQ(parties[1]->getName(), "Republicans");
  EXPECT_EQ(parties[2]->getName(), "Independent");
}

TEST(ElectionTest, CPLParsingCandidates)
{
  Election election = Election();
  string candidateString = "Bob, Joe, Jessica, Sarah,";
  vector<string> candidates = election.CPLParsingCandidates(candidateString);

  EXPECT_EQ(candidates[0], "Bob");
  EXPECT_EQ(candidates[1], "Joe");
  EXPECT_EQ(candidates[2], "Jessica");
  EXPECT_EQ(candidates[3], "Sarah");
}
TEST(ElectionTest, edge)
{
  Election election = Election();
  EXPECT_EQ(election.edge(0), false);
  EXPECT_EQ(election.edge(1), true);
}
TEST(ElectionTest, PoParsingCandiates)
{
  string inputstr = "[Pike, D], [Foster, D], [Deutsch, R], [Borg, R], [Jones, R], [Smith, I]";
  Election election = Election();
  vector<string> output = election.PoParsingCandidates(inputstr);
  EXPECT_EQ(output.at(0), "Pike, D");
  EXPECT_EQ(output.at(1), "Foster, D");
  EXPECT_EQ(output.at(2), "Deutsch, R");
  EXPECT_EQ(output.at(3), "Borg, R");
  EXPECT_EQ(output.at(4), "Jones, R");
  EXPECT_EQ(output.at(5), "Smith, I");
}