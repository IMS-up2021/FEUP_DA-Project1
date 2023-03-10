//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_CSVREADER_H
#define DAGRUPO_CSVREADER_H

#include <string>
#include <list>
#include <set>
#include <stack>

using namespace std;

class CSVReader{
private:
    void read_network();
    void read_stations();

public:
    CSVReader();

};

#endif //DAGRUPO_CSVREADER_H
