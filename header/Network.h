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
    vector<Station> realStations;
private:
    unordered_map<string, int> stationsNameToIndex;
    int n{};//number of stations



public:
    Network();
    void addStation(const Station& station);

    vector<Station>& getRealStations() ;

    void setRealStations(const vector<Station> &realStations1);

    const unordered_map<string, int> &getStationsNameToIndex() const;

    int getN() const;

    void setStationsNameToIndex(const unordered_map<string, int> &stationsNToI);

    void setN(int i);
};

#endif //DAGRUPO_NETWORK_H
