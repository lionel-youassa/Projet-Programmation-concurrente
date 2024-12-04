#ifndef MAITRE_DHOTEL_H
#define MAITRE_DHOTEL_H

#include <vector>
#include "Table.h"
#include "Chef_de_rang.h"

class Maitre_dHotel {
public:
    void AttribuerTable(const std::vector<int>& clients, Table& table);
    void AppelerChef(ChefDeRang& chef, Table& table);
};

#endif // MAITRE_DHOTEL_H
