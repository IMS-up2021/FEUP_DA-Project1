//
// Created by nesma on 09/03/2023.
//
#include "../header/Network.h"
#include <bits/stdc++.h>

using namespace std;


Network::Network() = default;

void Network::addStation(const Station& station) {
    this->realStations.push_back(station);
}

void Network::setStationsNameToIndex(const unordered_map<string, int> &stationsNToI) {
    Network::stationsNameToIndex = stationsNToI;
}

void Network::setN(int i) {
    Network::n = i;
}

vector<Station> &Network::getRealStations() {
    return realStations;
}

void Network::setRealStations(const vector<Station> &realStations1) {
    Network::realStations = realStations1;
}

const unordered_map<string, int> &Network::getStationsNameToIndex() const {
    return stationsNameToIndex;
}

int Network::getN() const {
    return n;
}
int Network::maxArrivals( const string& stb){
    int capSum = 0;
    int i = getStationsNameToIndex().at(stb);

    for (const auto& station : getRealStations()) {
        for (const auto& trip : station.getTrips()) {
            if (trip.getDestination() == i) {
                capSum += trip.getCapacity();
            }
        }
    }
    return capSum;
}

int Network::maxFlowTrains(const string& station1, const string& station2) {
    int stationOne,stationTwo;
    stationOne = stationsNameToIndex[station1] - 1;
    stationTwo = stationsNameToIndex[station2] - 1;
    return max_flow(stationOne,stationTwo);
}


const int INF = 1e9;

//int n, m; // number of nodes and edges
vector<vector<int>> graph; // adjacency list of the graph
vector<vector<int>> capacity; // capacity of each edge
//vector<vector<int>> residual; // residual capacity of each edge
vector<int> parent; // parent of each node in the BFS tree

int Network::bfs(int s, int t){
    parent.resize(n);
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2; // mark source node as visited
    queue<pair<int, int>> q;
    q.push({s, INF}); // push source node and its capacity
    while (!q.empty()) {
        int u = q.front().first;
        int cap = q.front().second;
        q.pop();
        for (const Trip& trip : this->realStations[s].getTrips()) {
            int v = trip.getDestination();
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                int new_cap = min(cap, residual[u][v]);
                if (v == t) return new_cap;
                q.push({v, new_cap});
            }
        }
    }
    return 0;
}

void Network::fillResidual() {
    residual.assign(n, vector<int>(n, 0));
}


void Network::setResidualCap(int a,int b, int cap) {
    residual[a][b]= cap;//from a to b cost is cap
}

int Network::max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        int bottleneck = bfs(s, t);
        if (bottleneck == 0) break; // no more augmenting paths
        flow += bottleneck;
        int u = t;
        while (u != s) { // update residual graph
            int v = parent[u];
            residual[v][u] -= bottleneck;
            residual[u][v] += bottleneck;
            u = v;
        }
    }
    return flow;
}

const vector<vector<int>> &Network::getResidual() const {
    return residual;
}

void Network::setResidual(const vector<vector<int>> &residual) {
    Network::residual = residual;
}

const vector<vector<int>> &Network::getResidualReset() const {
    return residualReset;
}

void Network::setResidualReset(const vector<vector<int>> &residualReset) {
    Network::residualReset = residualReset;
}






