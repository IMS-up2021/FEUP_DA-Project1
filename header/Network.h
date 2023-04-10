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
    /*!
     * function that calculates top k districts or municipalities in terms of maintenance needs, this is estimated by the capacity of incoming lines
     * @param k top -k
     * @param x 1 for municipalities or 2 for districts
     * complexity O(V+E) V-number os nodes(stations) E- number slightly bigger than 2*edges because some of them are added more than twice,even though this is undesirable, ideally sum would happen only once
     */
    void topKmaintenance( int k, const string& x);

    const vector<vector<int>> &getResidual() const;

    void setResidualReset(const vector<vector<int>> &residualResetArg);

    Network();

    void addStation(const Station &station);

    vector<Station> &getRealStations();

    const unordered_map<string, int> &getStationsNameToIndex() const;

    void setStationsNameToIndex(const unordered_map<string, int> &stationsNToI);

    void setN(int i);

    int maxFlowStations(string station1 = "none", string station2 = "none");
    /*!
     * bfs algorithm to find augmenting path
     * @param s source station
     * @param t sink station
     * complexity O(V+E) V-number os nodes(stations) E- number slightly bigger than 2*edges because some of them are added more than twice,even though this is undesirable, ideally sum would happen only once
     */
    int bfsAugmentingPath(int s, int t);

    void fillResidual();

    void setResidualCap(int a, int b, int cap); //from a to b
    /*!
     * edmond karp algorithm
     * @param s source station
     * @param t sink station
     * complexity O(V+E) V-number os nodes(stations) E- number slightly bigger than 2*edges because some of them are added more than twice,even though this is undesirable, ideally sum would happen only once
     */
    int max_flow(int s, int t);
    /*!
     * apply edmond karp to all pairs save the pairs with the maximum flow
     * complexity O(n*(V+E)) V-number os nodes(stations)n-number of pairs E- number slightly bigger than 2*edges because some of them are added more than twice,even though this is undesirable, ideally sum would happen only once
     */
    vector<pair<Station, Station>> maxFlowPairs();
    /*!
     * apply edmond karp to a program created station with connection to all nodes with 1 adjacent edge (flow insertion stations) with infinite capacity and a snk node to calculate maximum amount of flow that can enter that station
     * complexity O((V+E)) V-number os nodes(stations) E- number slightly bigger than 2*edges because some of them are added more than twice,even though this is undesirable, ideally sum would happen only once
     */
    int maxArriveStation(const string& a);

    int maxFlowStationsDijkstra(string station1 = "none", string station2 = "none");

    int max_Flow_Dijkstra(int s, int t);

    pair<int,int> dijkstraAugmentingPath(int s, int t);

    int maxFlowSubgraph(const string& station1 = "none", const string& station2 = "none");

    vector<pair<int,int>> mostAffectedByFailure(const string& station1 = "none", const string& station2 = "none");

};

#endif //DAGRUPO_NETWORK_H
