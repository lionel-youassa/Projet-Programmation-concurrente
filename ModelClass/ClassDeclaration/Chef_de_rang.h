#ifndef CHEF_DE_RANG_H
#define CHEF_DE_RANG_H

#include "Personne.h"
#include "Table.h"
#include <list>
#include "Commis_de_salle.h"
class ChefDeRang {
public:
    ChefDeRang(int id, const std::string& nom, bool estEnPoste);
    void DistribuerCarte(Table& table);
    void CoordonnerCommis(std::list<Commis_de_salle>& commis);
    void DresserTable(Table& table, std::string nappe);
};

#endif // CHEF_DERANG_H
