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
        if (hashTable.find(name) == hashTable.end()) {
            Station station = Station(name,district,mun,township,lineData);
            network->addStation(station);
            hashTable[name] = counter++;
        }
    }
    network->setStationsNameToIndex(hashTable);
    network->setN(--counter);
}

void CSVReader::read_network(const string &file, Network *network) {
    ifstream in;
    in.open(file);
    static string line;
    getline(in, line);

    while(getline(in,line)){
        string stationA;
        string stationB;
        string capacityString;
        string service;

        stringstream inputString(line);

        getline(inputString, stationA, ',');
        getline(inputString, stationB, ',');
        getline(inputString,capacityString , ',');
        getline(inputString, service, ',');
        int capacity = atoi(capacityString.c_str());
        unordered_map<string,int> nameToIndex;
        nameToIndex = network->getStationsNameToIndex();
        int source;
        source = nameToIndex[stationA];
        Trip trip = Trip(nameToIndex[stationB],capacity,service);
        network->getRealStations()[source -1].addTrip(trip);
    }
}

int CSVReader::maxArrivals(const Netwowrk& net, const string& stb){
    int capSum = 0;
    int i = network.getStationsNameToIndex().at(stb);

    for (const auto& station : net.getRealStations()) {
        for (const auto& trip : station.getTrips()) {
            if (trip.getDestination() == i) {
                capSum += trip.getCapacity();
            }
        }
    }
    return capSum;
}