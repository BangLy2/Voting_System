#include <vector> // #include directive
#include <string>
#pragma once
using namespace std;
class Party
{
private:
    int originalVotes;
    int remainingVotes;
    int seatsReceived;
    string name;
    vector<string> candidates;

public:

     /**
    * @brief default constructor
    **/ 
    Party();

     /**
    * @brief constructor
    * @param[in] name the name of the party
    **/ 
    Party(string name);

     /**
    * @brief get the name of the party
    * @return the name of the party
    **/ 
    string getName();

    /**
    * @brief increment the vote that party received
    **/ 
    void incrementVote();

    /**
    * @brief get the vote  that the current party have
    * @return the remaining vote
    **/ 
    int getRemainingVotes();

    /**
    * @brief number of seat that party can have
    * @return the remaining seats
    **/ 
    int getSeatsRemaining();

    /**
    * @brief add the seat to the party
    * @param[in] seats the number of seat that party received
    **/ 
    void addSeatsReceived(int seats);

    /**
    * @brief set the remaining vote that party have
    * @param[in] votes the remaining votes
    **/ 
    void setRemainingVotes(int votes);

    /**
    * @brief get the candidates name in that party
    * @return vector contain candidates name
    **/ 
    vector<string> getCandidates();

    /**
    * @brief get the numer of seat that party received
    * @return the number of seats recevied
    **/ 
    int getSeatsReceived();

    /**
    * @brief set the candidates in that party
    * @return vector contain candidates's name
    **/ 
    void setCandidates(vector<string> candidates);

    /**
    * @brief get the original number of votes
    * @return the original number of votes
    **/ 
    int getOriginalVotes();
};