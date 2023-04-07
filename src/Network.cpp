//
// Created by nesma on 09/03/2023.
//
#include "../header/Network.h"
#include <bits/stdc++.h>

#include <utility>

using namespace std;


Network::Network() = default;

void Network::addStation(const Station &station) {
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

/*void Network::setRealStations(const vector<Station> &realStations1) {
    Network::realStations = realStations1;
}*/

const unordered_map<string, int> &Network::getStationsNameToIndex() const {
    return stationsNameToIndex;
}
/*
int Network::getN() const {
    return n;
}*/

int Network::maxArrivals(const string &stb) {
    int capSum = 0;
    int i = getStationsNameToIndex().at(stb);
    i--;
    for (const auto &station: getRealStations()) {
        for (const auto &trip: station.getTrips()) {
            if (trip.getDestination() == i) {
                capSum += trip.getCapacity();
            }
        }
    }
    return capSum;
}

int Network::maxFlowStations(string station1, string station2) {
    int stationOne, stationTwo;
    if (station1 == "none") {
        cout << "Enter station of origin:\n";
        getline(cin, station1);
        cout << "Enter station of destination:\n";
        getline(cin, station2);
        cout << "From " << station1 << " to " << station2 << " ";

    }

    stationOne = stationsNameToIndex[station1] - 1;

    stationTwo = stationsNameToIndex[station2] - 1;
    int mf = max_flow(stationOne, stationTwo);
    residual = residualReset;
    cout <<station1<<" to "<<station2<<":" << mf << endl;
    return mf;

}


vector<int> parent; // parent of each node in the BFS tree

int Network::bfsAugmentingPath(int s, int t) {
    parent.resize(n+1);
    fill(parent.begin(), parent.end(),  -1);
    parent[s] = -2; // mark source node as visited
    queue <pair<int, int>> q;
    q.push({s, 1e9}); // push source node and its capacity
    while (!q.empty()) {
        int u = q.front().first;
        int cap = q.front().second;
        q.pop();
        int new_cap;
        for (const Trip &trip: this->realStations[u].getTrips()) {
            int v = trip.getDestination();
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                new_cap = min(cap, residual[u][v]);//min para ir guardando bottleneck no path
                if (v == t) return new_cap;
                q.push({v, new_cap});//para cada node, guardamos na queue com a capacidade até ele
            }
        }
        for (const Trip &trip: this->realStations[u].getIncomingTrips()) {
            int v = trip.getOrigin();
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                new_cap = min(cap, residual[u][v]);//min para ir guardando bottleneck no path
                if (v == t) return new_cap;
                q.push({v, new_cap});//para cada node, guardamos na queue com a capacidade até ele
            }
        }
    }
    return 0;
}
int Network::max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        int bottleneck = bfsAugmentingPath(s, t);
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
void Network::fillResidual() {
    residual.assign(n+1, vector<int>(n+1, 0));
}


void Network::setResidualCap(int a, int b, int cap) {
    residual[a][b] = cap;//from a to b cost is cap
}



const vector<vector<int>> &Network::getResidual() const {
    return residual;
}

/*void Network::setResidual(const vector<vector<int>> &residualArg) {
    Network::residual = residualArg;
}*/

/*const vector<vector<int>> &Network::getResidualReset() const {
    return residualReset;
}*/

void Network::setResidualReset(const vector<vector<int>> &residualResetArg) {
    Network::residualReset = residualResetArg;
}

vector<pair<Station, Station>> Network::maxFlowPairs() {
    int max = -1;
    vector<pair<Station, Station>> pairs;

    for (int i = 0; i <realStations.size()  ; i++) {
        for (int j = i + 1; j <realStations.size()  ; j++) {
            Station station = realStations[i];
            Station station2 = realStations[j];
            int a = maxFlowStations(station.getName(), station2.getName());
            if (a > max) {
                max = a;
                pairs.clear();
                pairs.emplace_back(station, station2);

            } else if (a == max) {
                pairs.emplace_back(station, station2);
            }
        }

    }


    return pairs;
}

void Network::maxArriveStation(const string& sinkString) {
    //criar source node capacidade infinita
    //ligar a todos os nodes menos o que queremos saber max flow
    //max flow de source até station //done
    int sink = stationsNameToIndex[sinkString] - 1;
    Station sourceStation = Station("source");
    for (int i = 0; i < realStations.size(); i++) {
        if(i==sink || realStations[i].getTrips().size()!=1){
            continue;
        }
        residual[n][i]=1e9;
        Trip trip = Trip(realStations.size(),i,1e9);
        sourceStation.addTrip(trip);
    }
    realStations.push_back(sourceStation);

    stationsNameToIndex["source"] = realStations.size();
    cout << "MaxFlowSourceSink:" <<  maxFlowStations("source", sinkString);
    realStations.pop_back();
}

int Network::maxFlowStationsDijkstra(string station1, string station2) {
    int stationOne, stationTwo;
    if (station1 == "none") {
        cout << "Enter station of origin:\n";
        getline(cin, station1);
        cout << "Enter station of destination:\n";
        getline(cin, station2);
        cout << "From " << station1 << " to " << station2 << " ";

    }

    stationOne = stationsNameToIndex[station1] - 1;

    stationTwo = stationsNameToIndex[station2] - 1;
    int mf = max_Flow_Dijkstra(stationOne, stationTwo);
    residual = residualReset;
    cout <<station1<<" to "<<station2<<":" << mf << endl;
    return mf;
}

int Network::max_Flow_Dijkstra(int s, int t) {
    int flow = 0;
    int cost = 0;
    int min=10000;
    while (true) {
        pair<int,int> pathResult = dijkstraAugmentingPath(s, t);
        int bottleneck = pathResult.first;//NOT , its dijkstraAP
        int costLocal = pathResult.second;
        if (bottleneck == 0) break;
        int u = t;
        cout<<"we are in :"<<realStations[u].getName()<<endl;
        cout<<endl<<"full path below"<<endl;
        while (u != s) { // update residual graph
            int v = parent[u];
            cout<<"father :"<<realStations[v].getName()<<endl;
            residual[v][u] -= bottleneck;
            residual[u][v] += bottleneck;
            u = v;
        }
        cout<<endl<<"full path above costed: "<< pathResult.second<<endl<<"  min is : "<<min;
        if (costLocal>min){
            continue;
        } else if (costLocal<min){
            min = costLocal;
            flow = 0;
            cost = 0;
            cout<<endl<<endl<<"found new min !!!!"<<endl<<endl;
        }
         // no more augmenting paths
        flow += bottleneck;
        cost += costLocal*bottleneck ;


    }
    cout<<endl<<"Path with mincost has a cost of :"<< min<<endl;
    cout<<endl<<"So total cost is  :"<< cost<<endl;
    return flow;
}
struct StationDistance {
    pair<int, int> stationCapacity;
    int cost;

    StationDistance(pair<int, int> stationCapacity, int cost) : stationCapacity(std::move(stationCapacity)), cost(cost) {}

    bool operator<(const StationDistance& other) const {
        return cost > other.cost;
    }
};
pair<int,int> Network::dijkstraAugmentingPath(int s, int t) {
    parent.resize(n+1);
    fill(parent.begin(), parent.end(),  -1);
    parent[s] = -2; // mark source node as visited
    unordered_map<int, int> stationToCost;
    for (int i=0;i<realStations.size();i++) {
        stationToCost[i] = numeric_limits<int>::max();
    }
    stationToCost[s] = 0;
    priority_queue<StationDistance> pq;
    pq.emplace(StationDistance({s,1e9},0));// push source node and its capacity and cost
    while (!pq.empty()) {
        int u = pq.top().stationCapacity.first;//station
        int cap = pq.top().stationCapacity.second;//capacity, more like flow
        int costUntilNow = pq.top().cost;
        pq.pop();
        int new_cap;
        for (const Trip &trip: this->realStations[u].getTrips()) {
            int v = trip.getDestination();
            if (parent[v] == -1 && residual[u][v] > 0) {
                int cost = trip.getService() == "STANDARD" ? 2 : 4;
                int newCost = costUntilNow + cost;
                parent[v] = u;
                new_cap = min(cap, residual[u][v]);//min para ir guardando bottleneck no path
                if (newCost < stationToCost[trip.getDestination()]) {
                    stationToCost[trip.getDestination()] = newCost;
                    //para cada node, guardamos na pqueue com a capacidade(flow) até ele
                    pq.emplace(StationDistance({v,new_cap}, newCost));
                }
                if (v == t) return {new_cap,stationToCost[t]};
            }
        }
        for (const Trip &trip: this->realStations[u].getIncomingTrips()) {
            int v = trip.getOrigin();
            if (parent[v] == -1 && residual[u][v] > 0) {
                int cost = trip.getService() == "STANDARD" ? 2 : 4;
                int newCost = costUntilNow + cost;
                parent[v] = u;
                new_cap = min(cap, residual[u][v]);//min para ir guardando bottleneck no path
                if (newCost < stationToCost[trip.getDestination()]) {
                    stationToCost[trip.getDestination()] = newCost;
                    //para cada node, guardamos na pqueue com a capacidade(flow) até ele
                    pq.emplace(StationDistance({v,new_cap}, newCost));
                }
                if (v == t) return {new_cap,stationToCost[t]};
            }
        }
    }
    return {0,1e9};
}








