//
// Created by nesma on 09/03/2023.
//

#include "../header/CSVReader.h"

CSVReader::CSVReader()= default;;

void CSVReader::populate() {

    /*read_airports();
    read_airlines();
    read_flights();*/
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
        //if (hashTable.find(name) == hashTable.end()) {
            Station station = Station(name,district,mun,township,lineData);
            network->addStation(station);
            hashTable[name] = counter++;
        //}
    }
    network->setStationsNameToIndex(hashTable);
    network->setN(--counter);
}

void CSVReader::read_network(const string &file, Network *network) {

}
