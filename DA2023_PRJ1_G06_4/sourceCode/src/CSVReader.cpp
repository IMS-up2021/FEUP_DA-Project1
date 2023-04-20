//
// Created by nesma on 09/03/2023.
//

#include "../header/CSVReader.h"

CSVReader::CSVReader()= default;;

void CSVReader::populate() {
    /*read_stations();
    read_network();*/
}

void CSVReader::read_stations(const string &file, Network *network) {
    ifstream in;
    in.open(file);
    static string line;
    getline(in,line);
    int counter = 1;
    unordered_map<string,int> hashTable;
    while (getline(in,line)){

        string name;
        string district;
        string mun;
        string township;
        string lineData;

        stringstream inputString(line);

        getline(inputString, name, ',');
        getline(inputString, district, ',');
        getline(inputString, mun, ',');
        getline(inputString, township, ',');
        getline(inputString, lineData, ',');
        if (hashTable.find(name) == hashTable.end() && !district.empty()) {
            Station station = Station(name,district,mun,township,lineData);
            network->addStation(station);
            hashTable[name] = counter++;
        }
    }
    network->setStationsNameToIndex(hashTable);
    network->setN(--counter);
}

void CSVReader::read_network(const string &file, Network *network) {
    network->fillResidual();
    ifstream in;
    in.open(file);
    static string line;
    getline(in, line);

    while(getline(in,line)){
        string stationSource;
        string stationDestination;
        string capacityString;
        string service;

        stringstream inputString(line);

        getline(inputString, stationSource, ',');
        getline(inputString, stationDestination, ',');
        getline(inputString,capacityString , ',');
        getline(inputString, service, ',');
        int capacity = atoi(capacityString.c_str());
        unordered_map<string,int> nameToIndex;
        nameToIndex = network->getStationsNameToIndex();
        int source;
        source = nameToIndex[stationSource] - 1;
        int destination ;
        destination = nameToIndex[stationDestination] - 1;
        network->setResidualCap(source,destination,capacity);
        network->setResidualCap(destination,source,capacity);
        Trip trip = Trip(source,destination,capacity,service);
        Trip tripReverse = Trip(destination,source, capacity, service);
        network->getRealStations()[source].addTrip(trip);
        network->getRealStations()[source].addIncomingTrip(tripReverse);
        network->getRealStations()[destination].addTrip(tripReverse);
        network->getRealStations()[destination].addIncomingTrip(trip);

    }
    network->setResidualReset(network->getResidual());
}

