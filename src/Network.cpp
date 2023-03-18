//
// Created by nesma on 09/03/2023.
//
#include "../header/Network.h"


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
