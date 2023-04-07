//
// Created by pedro on 16/03/2023.
//

#ifndef DA_2022_2023P1_TRIP_H
#define DA_2022_2023P1_TRIP_H

#include <string>

using namespace std;

class Trip {
private:
    int origin;
public:
    int getOrigin() const;

    void setOrigin(int originArg);

private:
    int destination;
    int capacity;
    string service;
public:
    Trip(int origin,int destination, int capacity, string service);

    Trip(int origin, int destination, int capacity);

    int getDestination() const;

    void setDestination(int destination1);

    int getCapacity() const;

    void setCapacity(int capacity1);

    const string &getService() const;

    void setService(const string &service1);
};

#endif //DA_2022_2023P1_TRIP_H