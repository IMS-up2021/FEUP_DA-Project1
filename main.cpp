#include <iostream>
#include "header/Network.h"
#include "header/CSVReader.h"

using namespace std;
int main() {
    std::cout << "INFO BELOW:!" << std::endl;
    string stationsPath = "../Data/stations.csv";
    string networkPath = "../Data/network.csv";
    auto *n = new Network();
    CSVReader::read_stations(stationsPath,n);
    CSVReader::read_network(networkPath,n);
    //2.1
    n->maxFlowStations("Lisboa Oriente","Porto Campanhã");//2.1 works
    //2.2
    //n->maxFlowPairs();//2.2 works
    //cout <<n->maxArrivals("Lisboa Oriente")<<endl;
    //2.4
    //n->maxArriveStation("Porto Campanhã");//2.4 works, REVIEW
    //3.1
    //n->maxFlowStationsDijkstra("Lisboa Oriente","Porto Campanhã");//3.1 works!
    return 0;
}
