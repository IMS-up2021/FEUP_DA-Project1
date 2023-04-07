//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_NETWORK_H
#define DAGRUPO_NETWORK_H

#include <unordered_map>
#include "Station.h"

using namespace std;

class Network {
    vector<Station> realStations;
    vector<vector<int>> residual; // residual capacity of each edge

private:
    unordered_map<string, int> stationsNameToIndex;
    vector<vector<int>> residualReset;
    int n{};//number of stations
public:
    const vector<vector<int>> &getResidual() const;

    void setResidual(const vector<vector<int>> &residualArg);

    const vector<vector<int>> &getResidualReset() const;

    void setResidualReset(const vector<vector<int>> &residualResetArg);

    Network();

    void addStation(const Station &station);

    vector<Station> &getRealStations();

    void setRealStations(const vector<Station> &realStations1);

    const unordered_map<string, int> &getStationsNameToIndex() const;

    int getN() const;

    void setStationsNameToIndex(const unordered_map<string, int> &stationsNToI);

    void setN(int i);

    int maxArrivals(const string &stb);

    int maxFlowStations(string station1 = "none", string station2 = "none");

    int bfsAugmentingPath(int s, int t);

    void fillResidual();

    void setResidualCap(int a, int b, int cap); //from a to b

    int max_flow(int s, int t);

    vector<pair<Station, Station>> maxFlowPairs();

    void maxArriveStation(const string& a);

    int maxFlowStationsDijkstra(string station1 = "none", string station2 = "none");

    int max_Flow_Dijkstra(int s, int t);

    pair<int,int> dijkstraAugmentingPath(int s, int t);






};

#endif //DAGRUPO_NETWORK_H
