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

public:
    Station();
    Station(string name, string district, string mun, string township);
    

};

#endif //DAGRUPO_STATION_H
