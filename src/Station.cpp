//
// Created by nesma on 09/03/2023.
//

#include "../header/Station.h"

Station::Station(){
    name_ = "";
    district_ = "";
    mun_ = "";
    township_ = "";
    line_ = "";
}

Station::Station(string name, string district, string mun, string township, string line) : name_(name), district_(district), mun_(mun), township_(township), line_(line) {}

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