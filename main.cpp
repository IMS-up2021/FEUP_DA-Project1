#include <iostream>
#include "header/Network.h"
#include "header/CSVReader.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    string stationsPath = "../Data/stations.csv";
    string networkPath = "../Data/network.csv";
    auto *n = new Network();
    CSVReader::read_stations(stationsPath,n);
    CSVReader::read_network(networkPath,n);
    //n->maxArrivals("Lisboa Oriente");
    n->maxFlowStations();
    n->maxFlowStations("Casa Branca","Monte das Flores");
    n->maxFlowPairs();

    return 0;
}
