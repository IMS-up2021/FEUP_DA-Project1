//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_INTERFACE_H
#define DAGRUPO_INTERFACE_H

#include <queue>
#include <string>
#include <list>
#include <cmath>
#include "CSVReader.h"

using namespace std;

class Interface{
public:
    Interface();

    static bool is_in(const string& choice, int lim_start, int lim_end) ;
    static int initiate(Network n);
    static void networkDisplay();
};

#endif //DAGRUPO_INTERFACE_H
