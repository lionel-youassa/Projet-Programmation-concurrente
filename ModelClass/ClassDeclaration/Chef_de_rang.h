#ifndef CHEF_DE_RANG_H
#define CHEF_DE_RANG_H

#include "Table.h"
#include "Commis_de_salle.h"

class ChefDeRang {
public:

    void DistribuerCarte(Table& table);
    void Coordonner(CommisDeSalle& commis);
    void DresserTable(Table& table, const std::string& nappe);
};

#endif // CHEF_DE_RANG_H
