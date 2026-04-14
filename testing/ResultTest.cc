#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/include/Result.h"
class ResultTest : public ::testing::Test
{
public:
  void SetUp() {}
  void TearDown() {}
};
TEST(ResultTest, emptyContructorTest)
{
  Result myResult = Result();

  string output1 = myResult.getTypeOfVoting();
  string expect1 = " ";

  int output2 = myResult.getNumberOfVote();
  int expect2 = 0;

  string output3 = myResult.getWinner();
  string expect3 = " ";

  EXPECT_EQ(output1, expect1);
  EXPECT_EQ(output2, expect2);
  EXPECT_EQ(output3, expect3);
}
TEST(ResultTest, getterSetterTest)
{
  vector<Party *> parties;
  Party *party1 = new Party("Democrat");
  Party *party2 = new Party("Republican");
  parties.push_back(party1);
  parties.push_back(party2);
  Result myResult = Result("IR", "12-12-2022", 2, parties, 3);
  string output1 = myResult.getTypeOfVoting();
  string expect1 = "IR";

  int output2 = myResult.getNumberOfVote();
  int expect2 = 3;

  myResult.setWinner("Dorthy");
  string output3 = myResult.getWinner();
  string expect3 = "Dorthy";

  myResult.setTypeOfVoting("CPL");
  myResult.setNumberOfVote(4546);
  myResult.setWinner("Larry");

  string output4 = myResult.getTypeOfVoting();
  string expect4 = "CPL";

  int output6 = myResult.getNumberOfVote();
  int expect6 = 4546;

  string output5 = myResult.getWinner();
  string expect5 = "Larry";

  EXPECT_EQ(output1, expect1);
  EXPECT_EQ(output2, expect2);
  EXPECT_EQ(output3, expect3);
  EXPECT_EQ(output4, expect4);
  EXPECT_EQ(output5, expect5);
}

TEST(ResultTest, displayResultPercentage)
{
  // This can be an ofstream as well or any other ostream
  std::stringstream buffer;

  // Save cout's buffer here
  std::streambuf *sbuf = std::cout.rdbuf();

  // Redirect cout to our stringstream buffer or any other ostream
  std::cout.rdbuf(buffer.rdbuf());

  // When done redirect cout to its old self

  vector<Party *> parties;
  Party *party1 = new Party("Democrat");
  Party *party2 = new Party("Republican");
  parties.push_back(party1);
  parties.push_back(party2);
  Result myResult = Result("CPL", "12-12-2022", 2, parties, 0);
  myResult.setWinner("Democrat");

  std::stringstream expected;
  expected << "CPL Results:" << endl;
  expected << "Date: 12-12-2022" << endl;
  expected << "Type: CPL" << endl;
  expected << "Number of ballots cast: 0" << endl;
  expected << "Number of Parties: 2" << endl;
  expected << "Winning candidates and their parties" << endl;
  expected << "Democrat received: 0 seats with 0 votes (0.000000\% of the total votes) for candidates: " << endl;
  expected << "Republican received: 0 seats with 0 votes (0.000000\% of the total votes) for candidates: " << endl
           << endl;

  myResult.displayCPLResult();
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(expected.str(), buffer.str());
}

TEST(ResultTest, displayIRTable)
{
  IRTable irTable = IRTable();
  unordered_map<string, int> round1;
  round1["Bob Kiss"] = 2585;
  round1["Kurt Wright"] = 2951;
  round1["Andy Montroll"] = 2063;
  round1["Dan Smith"] = 1306;
  round1["James Simpson"] = 35;
  round1["EXHAUSTED PILE"] = 4;

  irTable.appendRound(round1);

  unordered_map<string, int> round2;
  round2["Bob Kiss"] = 2981;
  round2["Kurt Wright"] = 3294;
  round2["Andy Montroll"] = 2554;
  round2["Dan Smith"] = 0;
  round2["James Simpson"] = 0;
  round2["EXHAUSTED PILE"] = 151;
  irTable.appendRound(round2);

  unordered_map<string, int> round3;
  round3["Bob Kiss"] = 4313;
  round3["Kurt Wright"] = 4061;
  round3["Andy Montroll"] = 0;
  round3["EXHAUSTED PILE"] = 151;
  irTable.appendRound(round3);

  Result result = Result("ir", "01-01-2022", 0, {}, 0, {}, {}, "Bob Kiss", irTable);
  result.displayIRTable();
}