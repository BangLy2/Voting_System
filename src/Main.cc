#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "include/Election.h"
#include "include/AuditFile.h"
#include "include/Result.h"
#include "include/BallotIR.h"
#include "include/IRAlgorithm.h"
#include "include/BallotCPL.h"
#include "include/CPLAlgorithm.h"
#include "include/Party.h"
#include <bits/stdc++.h>
int main(int argc, char *argv[])
{
    vector<string> inputVector;
    string input;
    if (argc < 2) {
        cout << "./run (filename) if you want to input file name in command line." << endl;
    } else {
        for(int i = 1; i < argc; i++){
            inputVector.push_back(argv[i]);
        }
    }

    Election election = Election();
    AuditFile audit = AuditFile();
    Result result = Result();
    election.run(audit, result, inputVector);
    return 0;
}