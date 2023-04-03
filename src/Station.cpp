//
// Created by nesma on 09/03/2023.
//

#include <utility>
#include <limits>
#include "../header/Station.h"

Station::Station(){
    name_ = "";
    district_ = "";
    mun_ = "";
    township_ = "";
    line_ = "";
}

Station::Station(string name, string district, string mun, string township, string line) : name_(std::move(name)), district_(std::move(district)), mun_(std::move(mun)), township_(std::move(township)), line_(std::move(line)) {}

string Station::getName() const{
    return name_;
}
string Station::getDistrict() const{
    return district_;
}
string Station::getMun() const{
    return mun_;
}
string Station::getTownship() const{
    return township_;
}
string Station::getLine() const{
    return line_;
}

bool Station::operator==(const Station& other) const{
    return name_==other.getName();
}

bool Station::operator <(const Station& other) const{
    if(this->getName()<other.getName()) return true;
    else if(this->getName()==other.getName()){
        if(this->getDistrict()<other.getDistrict()) return true;
        else if(this->getDistrict()==other.getDistrict()){
            if (this->getMun()<other.getMun()) return true;
            else if (this->getMun()==other.getMun()){
                return this->getTownship()<other.getTownship();
            }
        }
    }
    return false;
}

void Station::setName(const string &name) {
    name_ = name;
}

void Station::setDistrict(const string &district) {
    district_ = district;
}

void Station::setMun(const string &mun) {
    mun_ = mun;
}

void Station::setTownship(const string &township) {
    township_ = township;
}

void Station::setLine(const string &line) {
    line_ = line;
}

const vector<Trip> &Station::getTrips() const {
    return trips;
}

void Station::setTrips(const vector<Trip> &trips1) {
    Station::trips = trips1;
}

void Station::addTrip(Trip& trip)  {
    trips.push_back(trip);
}
//I don't know if it's needed
struct StationDistance {
    Station* station;
    int distance;

    StationDistance(Station* station, int distance) : station(station), distance(distance) {}

    bool operator<(const StationDistance& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's shortest path algorithm, from a source station to a destination station
int Station::minCost(Station* src, Station* dest) {
    unordered_map<Station*, int> dist;
    for (auto& station : allStations) {
        dist[station] = numeric_limits<int>::max();
    }
    dist[src] = 0;

    priority_queue<StationDistance> pq;
    pq.emplace(source, 0);

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.station == dest) {
            return dist[curr.station];
        }

        for (const auto& trip : curr.station->getTrips()) {
            int cost = trip.getService() == "STANDARD" ? 2 : 4;

            int newDist = curr.distance + cost;
            if (newDist < dist[allStations[trip.getDestination()]]) {
                dist[allStations[trip.getDestination()]] = newDist;
                pq.emplace(allStations[trip.getDestination()], newDist);
            }
        }
    }

    //destination isn't reachable
    return -1;
}


// Helper function to get the index of a station in the graph
int getStationIndex(const vector<Station>& graph, const Station& station) {
    auto it = find(graph.begin(), graph.end(), station);
    if (it != graph.end()) {
        return distance(graph.begin(), it);
    } else {
        return -1;  //not found
    }
}

// Modified version of Dijkstra's algorithm
int maxTrainsBetweenStations(const vector<Station>& graph, const Station& source, const Station& destination) {
    int sourceIndex = getStationIndex(graph, source);
    int destIndex = getStationIndex(graph, destination);
    if (sourceIndex < 0 || destIndex < 0) {
        return -1;  // Invalid
    }

    int numStations = graph.size();
    vector<int> dist(numStations, numeric_limits<int>::max());
    vector<int> prev(numStations, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[sourceIndex] = 0;
    pq.push({0, sourceIndex});

    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();

        if (x == destIndex) {
            break;  // Found shortest path
        }

    int maxTrains = 0;
    int c = destIndex;
    while (prev[c] != -1) {
        for (const auto& trip : graph[c].getTrips()) {
            if (trip.getDestination() == prev[c]) {
                maxTrains = max(maxTrains, trip.getCapacity());
                break;
            }
        }
        c = prev[c];
    }

    return maxTrains;
}