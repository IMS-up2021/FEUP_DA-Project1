//
// Created by nesma on 09/03/2023.
//
#include "../header/Network.h"


Network::Network() = default;

void Network::addStation(const Station& station) {
    this->realStations.push_back(station);
}

void Network::setStationsNameToIndex(const unordered_map<string, int> &stationsNameToIndex) {
    Network::stationsNameToIndex = stationsNameToIndex;
}

void Network::setN(int n) {
    Network::n = n;
}
