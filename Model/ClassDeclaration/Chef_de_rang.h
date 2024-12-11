#ifndef CHEF_DE_RANG_H
#define CHEF_DE_RANG_H

#include "Table.h"
#include "Commis_de_salle.h"
#include <list>
#include <string>

class ChefDeRang {
public:
    ChefDeRang(int id, const std::string& nom, bool estEnPoste);
    void DistribuerCarte(Table& table);
    void CoordonnerCommis(std::list<CommisDeSalle>& commis);
    void DresserTable(Table& table, const std::string& nappe);

private:
    int id;
    std::string nom;
    bool estEnPoste;
};

#endif // CHEF_DE_RANG_H
