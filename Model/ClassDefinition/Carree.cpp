//
// Created by siefo on 11/12/2024.
//
// Carree.cpp
#include "../ClassDeclaration/Carree.h"

Carree::Carree(int id) : id(id) {}

void Carree::ajouterTable(const Table& table) {
    tables.push_back(table);
}

Table Carree::obtenirTable() {
    return tables.empty() ? Table(0, 0, "vide") : tables[0];  // Retourne la première table (exemple simple)
}
