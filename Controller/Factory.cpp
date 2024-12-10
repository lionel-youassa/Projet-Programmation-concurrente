//
// Created by lione on 10/12/2024.
//

#include "Factory.h"


struct Position {
    int x;
    int y;
};

// Déclaration d'un tableau de 30 positions
Position positions[30] = {
    {535, 599}, {643, 599}, {747, 599}, {855, 599}, {963, 599},
    {1071, 599}, {1181, 599}, {1287, 599}, {535, 775}, {643, 775},
    {747, 775}, {855, 775}, {963, 775}, {1071, 775}, {1181, 775},
    {535, 1025}, {643, 1025}, {747, 1025}, {855, 1025}, {963, 1025},
{1071, 1025}, {1181, 1025}, {1287, 1025}, {535, 1155}, {643, 1155},
{747, 1155}, {855, 1155}, {963, 1155}, {1071, 1155}, {1181, 1155}
};



void Factory::creaTable() {
    for (int i=0; i<30; i++)
        if(i<10) {
            //pour les tables de 4 places
            Table *table = new Table(i, 4, "Occupee", positions[i].x, positions[i].y);
            tables.push_back(*table);

        }else if(i>=10 && i<15) {
            //pour les tables de 6 places
            Table *table = new Table(i, 6, "Occupee", positions[i].x, positions[i].y);
            tables.push_back(*table);

        }else if(i>=15 && i<25) {
            //pour les tables de 2 places
            Table *table = new Table(i, 2, "Occupee", positions[i].x, positions[i].y);
            tables.push_back(*table);
            //pour les tables de 8 places
        }else if(i>=25 && i<30) {
            Table *table = new Table(i, 8, "Non occupee", positions[i].x, positions[i].y);
            tables.push_back(*table);
        }
}

std::vector<Table> Factory::get_table_() {
    return tables;
}





