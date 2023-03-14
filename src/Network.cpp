//
// Created by nesma on 09/03/2023.
//

#include "../header/Network.h"

Network::Network(Station a, Station b, string cap, string ser) : a_(a), b_(b), cap_(cap), ser_(ser){}

Network& Network::operator=(const Network &other){
    this->a_ = other.a_;
    this->b_ = other.b_;
    this->cap_ = other.cap_;
    this->ser_ = other.ser_;
}