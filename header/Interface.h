//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_INTERFACE_H
#define DAGRUPO_INTERFACE_H

#include <queue>
#include <string>
#include <list>
#include <math.h>
#include "CSVReader.h"

using namespace std;

class Interface{
private:
    CSVReader* database;
public:
    Interface();
    bool is_in(string choice, int lim_start, int lim_end) const;
    int initiate();
    void networkDisplay();
};

#endif //DAGRUPO_INTERFACE_H
