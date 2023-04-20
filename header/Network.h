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
     * complexity O(nlog n)
     * @param k top -k
     * @param x 1 for municipalities or 2 for districts
     *
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
    /*!
     * edmond karp max flow algorithm
     * complexity:O(VE^2)
     * @param station1 source station
     * @param station2 sink station
     *
     * */
    int maxFlowStations(string station1 = "none", string station2 = "none");
    /*!
     * bfs algorithm to find augmenting path
     * complexity O(V+E) V-number os nodes(stations) E- worst case 2*edges
     * @param s source station
     * @param t sink station
     *
     */
    int bfsAugmentingPath(int s, int t);

    void fillResidual();

    void setResidualCap(int a, int b, int cap); //from a to b
    /*!
     * apply edmond karp to all pairs save the pairs with the maximum flow
     * complexity O(n*(V*E^2)) V-number os nodes(stations)n-number of pairs E- worst case 2*edges
     */
    vector<pair<Station, Station>> maxFlowPairs();
    /*!
     * edmond karp algorithm
     * complexity O(V*E^2) V-number os nodes(stations) E- worst case 2*edges
     * @param s source station
     * @param t sink station
     *
     */
    int max_flow(int s, int t);
    /*!
     * apply edmond karp to a program created station with connection to all nodes with 1 adjacent edge (flow insertion stations) with infinite capacity and a snk node to calculate maximum amount of flow that can enter that station
     * complexity O((V*E^2)) V-number os nodes(stations) E- worst case 2*edges
     */
    int maxArriveStation(const string& a);

    int maxFlowStationsDijkstra(string station1 = "none", string station2 = "none");
    /*!
     * Algorithm similar to Edmond karp but uses Dijkstra's algorithm to find the augmenting paths, the purpose of this is to guarantee that only the paths where the cost for the company is minimum are being used
     * complexity O(V^2)
     * @param s source node
     * @param t sink node
     *
     */
    int max_Flow_Dijkstra(int s, int t);
    /*!
     *Dijkstra algorithm variation, used to find augmenting path with minimum cost
     *complexity: O(V^2)
     */
    pair<int,int> dijkstraAugmentingPath(int s, int t);
    /*!
     * Calculates maxflow between two stations after removing some edge
     * complexity: O(VE^2)
     * @param station1 source station
     * @param station2 sink station
     *
     */
    int maxFlowSubgraph(const string& station1 = "none", const string& station2 = "none");
    /*!
     *Function calculates the stations most affected by the removal of the line in terms of how many trains can get into the stations
     * complexity: O(NMlog(M))
     */
    vector<pair<int,int>> mostAffectedByFailure(const string& station1 = "none", const string& station2 = "none");

};

#endif //DAGRUPO_NETWORK_H
