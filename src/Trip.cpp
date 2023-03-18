//
// Created by pedro on 16/03/2023.
//

#include <utility>

#include "../header/Trip.h"

int Trip::getDestination() const {
    return destination;
}

void Trip::setDestination(int destination1) {
    Trip::destination = destination1;
}

int Trip::getCapacity() const {
    return capacity;
}

void Trip::setCapacity(int capacity1) {
    Trip::capacity = capacity1;
}

const string &Trip::getService() const {
    return service;
}

void Trip::setService(const string &service1) {
    Trip::service = service1;
}

Trip::Trip(int destination, int capacity, string service) : destination(destination), capacity(capacity),
                                                                   service(std::move(service)) {}
