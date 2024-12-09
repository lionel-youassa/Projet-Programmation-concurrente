//
// Created by siefo on 09/12/2024.
//
#include "../ClassDeclaration/Carree.h"

Carree::Carree(int id) : id(id) {}

void Carree::AjouterTable(Table& table) {
    tables.push_back(table);
}

Table Carree::ObtenirTable(int tableId) {
    for (auto& table : tables) {
        if (table.getId() == tableId) {
            return table;
        }
    }
    // Gestion d'une table non trouvée
    return Table(-1, 0, "non trouvée");
}