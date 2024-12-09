//
// Created by siefo on 09/12/2024.
//

#ifndef CARREE_H
#define CARREE_H

#include "Table.h"
#include <list>

class Carree {
public:
    Carree(int id);
    void AjouterTable(Table& table);
    Table ObtenirTable(int tableId);

private:
    int id;
    std::list<Table> tables;
};

#endif // CARREE_H
