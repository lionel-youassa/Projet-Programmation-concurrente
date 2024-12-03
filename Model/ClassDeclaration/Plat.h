#ifndef PLAT_H
#define PLAT_H

#include <string>

class Plat {
public:
    int id;
    std::string nom;
    std::string categorie;
    double prix;
    int tempsPreparation;
    bool estDisponible;

    Plat(int id, const std::string& nom, const std::string& categorie, double prix, int tempsPreparation, bool estDisponible = true);

    void verifierDisponible();
};

#endif // PLAT_H
