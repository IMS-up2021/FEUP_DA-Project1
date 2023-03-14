//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_CSVREADER_H
#define DAGRUPO_CSVREADER_H

#include <fstream>
#include <sstream>
#include <queue>
#include <string>
#include <list>

using namespace std;

class CSVReader{
private:
    void read_network();
    void read_stations();
    void populate();
    int calculateNrTrains(const string& stat1, const string& stat2);

public:
    CSVReader();


};

#endif //DAGRUPO_CSVREADER_H
