# The CXXFLAGS variable sets compile flags for g++:
#  -g          compile with debug information
#  -std=c++11  use the c++ standard language definition

CXX=g++
CXXFLAGS = -std=c++11 -g

# run: Party.o AuditFile.o BallotCPL.o CPLAlgorithm.o Result.o 
# 	$(CXX) $(CXXFLAGS)  Party.o AuditFile.o BallotCPL.o CPLAlgorithm.o Result.o -o run 

run: IRTable.o POAlgorithm.o IRAlgorithm.o BallotIR.o Candidate.o Election.o AuditFile.o BallotCPL.o CPLAlgorithm.o Party.o Result.o Main.o BallotPO.o CandidatePO.o
	$(CXX) $(CXXFLAGS) IRTable.o POAlgorithm.o IRAlgorithm.o BallotIR.o Candidate.o Election.o AuditFile.o BallotCPL.o CPLAlgorithm.o Party.o Result.o  Main.o BallotPO.o CandidatePO.o -o run 

# AuditFile_UnitTest: AuditFileTest.o AuditFile.o
# 	$(CXX)  $(CXXFLAGS) AuditFileTest.o AuditFile.o -o AuditFile_UnitTest

Election.o: Election.cc
	$(CXX) $(CXXFLAGS) -c Election.cc -o Election.o

AuditFile.o: AuditFile.cc 
	$(CXX) $(CXXFLAGS) -c AuditFile.cc -o AuditFile.o

BallotCPL.o: BallotCPL.cc 
	$(CXX) $(CXXFLAGS) -c BallotCPL.cc -o BallotCPL.o

CPLAlgorithm.o: CPLAlgorithm.cc 
	$(CXX) $(CXXFLAGS) -c CPLAlgorithm.cc -o CPLAlgorithm.o

POAlgorithm.o: POAlgorithm.cc 
	$(CXX) $(CXXFLAGS) -c POAlgorithm.cc -o POAlgorithm.o

Party.o: Party.cc 
	$(CXX) $(CXXFLAGS) -c Party.cc -o Party.o

Result.o: Result.cc 
	$(CXX) $(CXXFLAGS) -c Result.cc -o Result.o

IRAlgorithm.o: IRAlgorithm.cc 
	$(CXX) $(CXXFLAGS) -c IRAlgorithm.cc -o IRAlgorithm.o

BallotIR.o: BallotIR.cc 
	$(CXX) $(CXXFLAGS) -c BallotIR.cc -o BallotIR.o

Candidate.o: Candidate.cc 
	$(CXX) $(CXXFLAGS) -c Candidate.cc -o Candidate.o

IRtable.o: IRtable.cc
	$(CXX) $(CXXFLAGS) -c IRtable.cc -o IRtable.o

AuditFileTest.o: AuditFileTest.cc 
	$(CXX) $(CXXFLAGS) -c AuditFileTest.cc -o AuditFileTest.o

ElectionTest.o: ElectionTest.cc 
	$(CXX) $(CXXFLAGS) -c ElectionTest.cc -o ElectionTest.o

# HelloTest.o: HelloTest.cc 
# 	$(CXX) $(CXXFLAGS) -c HelloTest.cc -o HelloTest.o

PartyTest.o: PartyTest.cc 
	$(CXX) $(CXXFLAGS) -c PartyTest.cc -o PartyTest.o

ResultTest.o: ResultTest.cc 
	$(CXX) $(CXXFLAGS) -c ResultTest.cc -o ResultTest.o

Main.o: Main.cc
	$(CXX) $(CXXFLAGS) -c Main.cc -o Main.o

BallotPO.o: BallotPO.cc
	$(CXX) $(CXXFLAGS) -c BallotPO.cc -o BallotPO.o

CandidatePO.o: CandidatePO.cc
	$(CXX) $(CXXFLAGS) -c CandidatePO.cc -o CandidatePO.o

test: test1.o test2.o -lgtest_main -lgtest -lgmock 
	$(CXX) $(CXXFLAGS) test1.o test2.o -o test
test1: test1.cc
	$(CXX) $(CXXFLAGS) -c test1.cc -o test1.o
test2: test2.cc
	$(CXX) $(CXXFLAGS) -c test2.cc -o test2.o

queue_unittest: queue.o
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib queue_unittest.cc queue.o -lgtest_main -lgtest -lgmock -pthread -o $@
	
clean:
	rm -f *.o run test_unit *.txt