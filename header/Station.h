//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_STATION_H
#define DAGRUPO_STATION_H

#include <unordered_set>
#include<math.h>
#include <List>
#include<string>
#include <iostream>

using namespace std;

class Station{
private:
    string name_;
    string district_;
    string mun_;
    string township_;
    string line_;

public:
    Station();
    Station(string name, string district, string mun, string township, string line);

    string getName() const;
    string getDistrict() const;
    string getMun() const;
    string getTownship() const;
    string getLine() const;
    bool operator==(const Station& other) const;
    bool operator <(const Station& other) const;
};

struct StationHash{
    size_t operator() (const Station& other) const{
        size_t res = 0;
        for (char c : other.getName()) {
            res += 13 * c;
        }
        return res;
    }
};

#endif //DAGRUPO_STATION_H
