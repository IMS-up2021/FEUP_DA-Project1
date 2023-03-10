//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_NETWORK_H
#define DAGRUPO_NETWORK_H

#include "Station.h"

using namespace std;

class Network{
private:
    Station a_;
    Station b_;
    string cap_;
    string ser_;

public:
    Network();
    Network(Station a, Station b, string cap, string ser);
};

#endif //DAGRUPO_NETWORK_H
