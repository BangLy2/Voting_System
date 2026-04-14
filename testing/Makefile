CXX=g++
CXXFLAGS = -std=c++14 -g
DEP_DIR= ../misc/dependencies

MAINEXEFILE = ../src/IRTable.cc ../src/Party.cc ../src/Result.cc ../src/Candidate.cc ../src/BallotIR.cc ../src/BallotCPL.cc ../src/CPLAlgorithm.cc ../src/IRAlgorithm.cc ../src/Election.cc ../src/AuditFile.cc ../src/BallotPO.cc ../src/CandidatePO.cc ../src/POAlgorithm.cc
MAINTESTFILE = PartyTest.cc ResultTest.cc CandidateTest.cc BallotIRTest.cc BallotCPLTest.cc CPLAlgorithmTest.cc IRAlgorithmTest.cc ElectionTest.cc AuditFileTest.cc BallotPOTest.cc CandidatePOTest.cc POAlgorithmTest.cc


LABTESTEXE = Test
LABEXE = Election


all: ${LABEXE} ${LABTESTEXE}

${LABEXE}: main.cc $(MAINEXEFILE)
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib main.cc $(MAINEXEFILE) -lgtest_main -lgtest -lgmock -pthread -o $@

${LABTESTEXE}: $(MAINEXEFILE) $(MAINTESTFILE)
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib $(MAINTESTFILE) $(MAINEXEFILE) -lgtest_main -lgtest -lgmock -pthread -o $@

test: ${LABTESTEXE}

clean:
	rm -f ${LABEXE}
	rm -f ${LABTESTEXE}
	rm -rf *.o *.txt
