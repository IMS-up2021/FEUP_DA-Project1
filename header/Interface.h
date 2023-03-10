//
// Created by nesma on 09/03/2023.
//

#ifndef DAGRUPO_INTERFACE_H
#define DAGRUPO_INTERFACE_H

#include <queue>
#include <string>
#include <list>
#include <math.h>
#include "CSVReader.h"

using namespace std;

class Interface{
private:
    CSVReader* database;
public:
    Interface();
    Interface(CSVReader& reader);
    int initiate();
}

#endif //DAGRUPO_INTERFACE_H

/*Informações do projeto: (Pelo que percebi)
 * Dados dois destinos, ver a quantidade de comboios que viajam entre esses dois destinos
 * Tendo em conta todos os pares de estações (na Network), ver qual tem o max de comboios, tirando vantagem da cap da network (?)
 *
*/