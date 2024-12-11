//
// Created by siefo on 11/12/2024.
//
// Carree.h
#ifndef CARREE_H
#define CARREE_H

#include "Table.h"
#include <vector>

class Carree {
private:
    int id;
    std::vector<Table> tables;  // Composition : une carree possède une ou plusieurs tables

public:
    Carree(int id);
    void ajouterTable(const Table& table);
    Table obtenirTable();
};

#endif // CARREE_H
