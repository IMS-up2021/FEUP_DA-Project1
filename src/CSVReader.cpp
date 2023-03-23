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

int CSVReader::maxArrivals(const Network& net, const string& stb){
    int capSum = 0;
    int i = net.getStationsNameToIndex().at(stb);

    for (const auto& station : net.getRealStations()) {
        for (const auto& trip : station.getTrips()) {
            if (trip.getDestination() == i) {
                capSum += trip.getCapacity();
            }
        }
    }
    return capSum;
}

/*This code creates two vectors of pairs: sortedMunicipalities and sortedDistricts. Each pair has a string as the
 first element and an int as the second element. The string element represents the name of the municipality or
 district, and the int element represents the sum of capacities of all trips starting or ending in the corresponding
 municipality or district.
The constructor of each vector receives two arguments: the first argument is an iterator pointing to the beginning
 of the source container, and the second argument is an iterator pointing to the end of the source container (map).
After the vectors are created, the sort() algorithm is used to sort them in descending order of the int values
 (i.e., the sum of capacities) */

void CSVReader::topKmaintenance(const vector<Station>& stations, int k, const string& x){
    if (x == "1"){
        unordered_map<string, int> munCapacity;

        // Sum the capacity by municipality
        for (const auto& station : stations) {
            int capacitySum = 0;
            for (const auto& trip : station.getTrips()) {
                capacitySum += trip.getCapacity();
            }
            munCapacity[station.getMun()] += capacitySum;
        }

        //creating a sorted vector
        vector<pair<string, int>> sortedMunicipalities(munCapacity.begin(), munCapacity.end());
        sort(sortedMunicipalities.begin(), sortedMunicipalities.end(), [](auto& left, auto& right) { return left.second > right.second; });
        vector<pair<string, int>> topKMunicipalities(sortedMunicipalities.begin(), sortedMunicipalities.begin() + k);

        while (int x = 0; x <= topKMunicipalities.size(); x++){
            cout << topKMunicipalities[x] << endl;
        }
    }
    else if (x == "2"){
        unordered_map<string, int> districtCapacity;

        // Sum the capacity by district
        for (const auto& station : stations) {
            int capacitySum = 0;
            for (const auto& trip : station.getTrips()) {
                capacitySum += trip.getCapacity();
            }
            districtCapacity[station.getDistrict()] += capacitySum;
        }

        //creating a sorted vector
        vector<pair<string, int>> sortedDistricts(districtCapacity.begin(), districtCapacity.end());
        sort(sortedDistricts.begin(), sortedDistricts.end(), [](auto& left, auto& right) { return left.second > right.second; });
        vector<pair<string, int>> topKDistricts(sortedDistricts.begin(), sortedDistricts.begin() + k);

        for (auto x : topKDistricts){
            cout << x << endl;
        }
    }
}

void CSVReader::topKfailure(const vector<pair<Station,Station>>& segmentFailures, int k){
    unordered_map<string, int> station_impact;

    //calculate the impact of each station
    for (const auto& segment : segmentFailures){
        const auto& startStation = segment.first;
        const auto& endStation = segment.second;

        //increment impact for each station involved in segment failure
        station_impact[startStation.getName()]++;
        station_impact[endStation.getName()]++;
    }

    //sort affected stations by impact
    vector<pair<string, int>> affectedStations(station_impact.begin(),station_impact.end());
    sort(affectedStations.begin(), affectedStations.end(), [](const auto& left, const auto& right){ return left.second > right.second;});
    vector<pair<string, int>> topK(affectedStations.begin(), affectedStations.begin() + k);

    //print top-k
    for (auto x : topK){
        cout << x << endl;
    }
}