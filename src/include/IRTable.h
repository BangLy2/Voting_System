#ifndef IRTABLE_H
#define IRTABLE_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class IRTable
{
private:
    vector<unordered_map<string, int>> rounds;

public:
    /**
     * @brief default constructor
     **/
    IRTable();
    /**
     * @brief add round to round vector
     **/
    void appendRound(unordered_map<string, int>);
    /**
     * @brief get the rounds vector
     * @return vector contain rounds name
     **/
    vector<unordered_map<string, int>> getRounds();
};
#endif