//
// Created by pedro on 09/03/2023.
//

#include "ReadFiles.h"
/*using namespace std;

void ReadFiles::readfile1(const string &file, Graph *g) {
    g->addAirport(Airport());
    ifstream in;
    in.open(file);

    string line;
    getline(in, line);
    int counter = 1;
    unordered_map<string, int> hashtable;
    set<string> setcities;


    while (getline(in, line)) {


        string code;
        string name;
        string city;
        string country;
        string latitude_s;
        string longitude_s;
        float latitude;
        float longitude;


        stringstream inputString(line);

        getline(inputString, code, ',');
        getline(inputString, name, ',');
        getline(inputString, city, ',');
        getline(inputString, country, ',');
        getline(inputString, latitude_s, ',');
        getline(inputString, longitude_s, ',');

        latitude = atof(latitude_s.c_str());
        longitude = atof(longitude_s.c_str());

        setcities.insert(city);
        Airport airport = Airport(code, name, city, country, latitude, longitude);

        g->addAirport(airport);


        hashtable[code] = counter++;

    }
    g->setN(--counter);
    g->setHashtableAirports(hashtable);
    g->setCities(setcities);



}

void ReadFiles::readfile2(const string &file, Graph *g) {


    ifstream in;
    in.open(file);

    string line;
    getline(in, line);

    unordered_map<string, int> hashtable;
    hashtable = g->getAirports();


    while (getline(in, line)) {

        string src;
        string dest;
        string airline;
        int source;
        int destiny;


        stringstream inputString(line);

        getline(inputString, src, ',');
        getline(inputString, dest, ',');
        getline(inputString, airline, ',');

        source = hashtable[src];
        destiny = hashtable[dest];

        Flight flight = Flight(destiny, airline);


        g->getRealAirports()[source].addFlight(flight);


    }

    unordered_map<string, list<Airport>> hashtab;

    vector<Airport> vectorairports = g->getRealAirports();
    for  (const Airport& airport : vectorairports){
        hashtab[airport.getCity()].push_back(airport);
    }
    g->setCityAirports(hashtab);


}

void ReadFiles::readfile3(const string &file, Graph *g) {

    ifstream in;
    in.open(file);

    string line;
    getline(in, line);

    unordered_map<string, Airline> hashtable;


    while (getline(in, line)) {

        string code;
        string name;
        string callSign;
        string country;


        stringstream inputString(line);

        getline(inputString, code, ',');
        getline(inputString, name, ',');
        getline(inputString, callSign, ',');
        getline(inputString, country, ',');




        Airline airline = Airline(code, name, callSign, country);
        hashtable.insert(make_pair(code,airline));


    }
    g->setAirlines(hashtable);
}*/