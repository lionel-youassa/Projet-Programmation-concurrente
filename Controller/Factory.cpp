//
// Created by lione on 10/12/2024.
//

#include "Factory.h"
#include  "../Model/ClassDeclaration/Position.h"

// Déclaration d'un tableau de 30 positions
Position positions[30] = {
    Position(535, 599), Position(643, 599), Position(747, 599), Position(855, 599), Position(963, 599),
    Position(1071, 599), Position(1181, 599), Position(1287, 599), Position(535, 775), Position(643, 775),
    Position(747, 775), Position(855, 775), Position(963, 775), Position(1071, 775), Position(1181, 775),
    Position(535, 1025), Position(643, 1025), Position(747, 1025), Position(855, 1025), Position(963, 1025),
    Position(1071, 1025), Position(1181, 1025), Position(1287, 1025), Position(535, 1155), Position(643, 1155),
    Position(747, 1155), Position(855, 1155), Position(963, 1155), Position(1071, 1155), Position(1181, 1155)
};




void Factory::creaTable() {
    for (int i = 0; i < 30; i++) {
        if (i < 10) {
            // pour les tables de 4 places
            tables.emplace_back(i, 4, "libre", positions[i].x, positions[i].y);

        } else if (i >= 10 && i < 15) {
            // pour les tables de 6 places
            tables.emplace_back(i, 6, "libre", positions[i].x, positions[i].y);
        } else if (i >= 15 && i < 25) {
            // pour les tables de 2 places
            tables.emplace_back(i, 2, "libre", positions[i].x, positions[i].y);
        } else if (i >= 25 && i < 30) {
            // pour les tables de 8 places
            tables.emplace_back(i, 8, "libre", positions[i].x, positions[i].y);
        }
    }
}

std::vector<Table> Factory::get_table_() {
    this->creaTable();
    return tables;
}





