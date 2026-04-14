#include "include/IRTable.h"
#include <unordered_map>

IRTable::IRTable()
{
}

void IRTable::appendRound(unordered_map<string, int> round)
{
    rounds.push_back(round);
}

vector<unordered_map<string, int>> IRTable::getRounds()
{
    return rounds;
}