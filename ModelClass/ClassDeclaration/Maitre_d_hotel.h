#ifndef MAITRE_DHOTEL_H
#define MAITRE_DHOTEL_H

#include <vector>
#include "Table.h"
#include "Chef_de_rang.h"

class Maitre_dHotel : public Personne {
public:
    MaitreDHotel(int id, const std::string& nom, bool poste);

    // Méthodes
    void AttribuerTable(std::vector<Client>& clients);
    void AppelerChef(ChefDeRang& chef, Table& table);
};

#endif // MAITRE_D_HOTEL_H