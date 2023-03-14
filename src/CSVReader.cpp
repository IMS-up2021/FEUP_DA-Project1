//
// Created by nesma on 09/03/2023.
//

#include "../header/CSVReader.h"

CSVReader::CSVReader(){
    populate();
};

void CSVReader::populate() {
    read_airports();
    read_airlines();
    read_flights();
}