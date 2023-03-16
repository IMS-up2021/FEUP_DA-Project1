#include <iostream>
#include "header/Network.h"
#include "header/CSVReader.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    string stationsPath = "../Data/stations.csv";
    Network *n = new Network();
    CSVReader::read_stations(stationsPath,n);
    return 0;
}
