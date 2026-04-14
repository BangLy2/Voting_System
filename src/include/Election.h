#ifndef ELECTION
#define ELECTION

#include <iostream>
#include <string>
#include <vector> // #include directive
#include "AuditFile.h"
#include "Result.h"
#include "BallotIR.h"
#include "BallotPO.h"
#include "Party.h"

using namespace std;

class Election
{
private:
    /**
     * @brief remove all the space of the string
     * @param[in] input the string to be modified
     * return the string that have been removed all spaces
     **/
    string removeSpaces(string input);

public:
    /**
     * @brief default constructor
     **/
    Election();

    /**
     * @brief run the election
     * @param[in] auditFile the auditfile modified
     * @param[in] result return the winner result
     **/
    void run(AuditFile auditFile, Result result, vector<string> name);

    /**
     * @brief prompt the user to get the filename
     * @return the name of the file
     **/
    vector<string> obtainFileName(std::istream &input);

    /**
     * @brief read the content in the file
     * @param[in] fileName the name of the file
     * @param[in] input the input file name
     * @return 1 when sucess and -1 when fail
     **/
    int parseFile(vector<string> fileName, std::istream &input);

    /**
     * @brief reading the ballotString
     * @param[in] ballotStr name of the ballot
     * @param[in] numCandidates number of candidate
     * @param[in] candidates a vector of Candidate
     * @return the Ballot IR
     **/
    BallotIR *IRParsing(string ballotStr, int numCandidates, vector<Candidate> candidates);

    /**
     * @brief parsing the Party
     * @param[in] partyStr the name of the party
     * @return the vector of Party
     **/
    vector<Party *> CPLParsingParties(string partyStr);

    /**
     * @brief parsing the candidate
     * @param[in] partyStr the name of the candidates
     * @return the vector of string
     **/
    vector<string> CPLParsingCandidates(string candidatesStr);

    /**
     * @brief obtain the date of the election
     * @param[in] input the input information
     * @return the date of the election
     **/
    string obtainDate(std::istream &input);

    /**
     * @brief set the edge
     * @param[in] num the num
     * @return the edge
     **/
    bool edge(const int num);

    /**
     * @brief set the candidates
     * @param[in] line the line
     * @return vector of candidates
     **/
    vector<string> PoParsingCandidates(string line);
};
#endif
