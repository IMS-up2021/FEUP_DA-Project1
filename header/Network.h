//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_NETWORK_H
#define DAGRUPO_NETWORK_H

#include <vector>
#include <unordered_map>
#include "Station.h"

using namespace std;

class Network{
private:
    vector<Station> realStations;
    unordered_map<string, int> stationsNameToIndex;
    int n;//number of stations



public:
    Network();
    void addStation(const Station& station);

    void setStationsNameToIndex(const unordered_map<string, int> &stationsNameToIndex);

    void setN(int n);
};

#endif //DAGRUPO_NETWORK_H
