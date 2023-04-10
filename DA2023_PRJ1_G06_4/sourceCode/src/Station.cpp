//
// Created by nesma on 09/03/2023.
//

#include <utility>
#include <limits>
#include <queue>
#include "../header/Station.h"

Station::Station(){
    name_ = "";
    district_ = "";
    mun_ = "";
    township_ = "";
    line_ = "";
}

Station::Station(string name, string district, string mun, string township, string line) : name_(std::move(name)), district_(std::move(district)), mun_(std::move(mun)), township_(std::move(township)), line_(std::move(line)) {}

Station::Station(string name) : name_(std::move(name)) {}

string Station::getName() const{
    return name_;
}
string Station::getDistrict() const{
    return district_;
}
string Station::getMun() const{
    return mun_;
}
string Station::getTownship() const{
    return township_;
}
string Station::getLine() const{
    return line_;
}

bool Station::operator==(const Station& other) const{
    return name_==other.getName();
}

bool Station::operator <(const Station& other) const{
    if(this->getName()<other.getName()) return true;
    else if(this->getName()==other.getName()){
        if(this->getDistrict()<other.getDistrict()) return true;
        else if(this->getDistrict()==other.getDistrict()){
            if (this->getMun()<other.getMun()) return true;
            else if (this->getMun()==other.getMun()){
                return this->getTownship()<other.getTownship();
            }
        }
    }
    return false;
}

void Station::setName(const string &name) {
    name_ = name;
}

void Station::setDistrict(const string &district) {
    district_ = district;
}

void Station::setMun(const string &mun) {
    mun_ = mun;
}

void Station::setTownship(const string &township) {
    township_ = township;
}

void Station::setLine(const string &line) {
    line_ = line;
}

const vector<Trip> &Station::getTrips() const {
    return trips;
}

void Station::setTrips(const vector<Trip> &trips1) {
    Station::trips = trips1;
}

void Station::addTrip(Trip& trip)  {
    trips.push_back(trip);
}
void Station::addIncomingTrip(Trip& trip)  {
    incomingTrips.push_back(trip);
}

const vector<Trip> &Station::getIncomingTrips() const {
    return incomingTrips;
}

void Station::setIncomingTrips(const vector<Trip> &incomingTrips1) {
    incomingTrips = incomingTrips1;
}




