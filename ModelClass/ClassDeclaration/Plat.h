#ifndef PLAT_H
#define PLAT_H

#include <string>

class Plat {
public:
    Plat(int id, const std::string& nom, const std::string& categorie, double prix, int tempsPreparation);

    bool estDisponible() const;
    std::string getNom() const;

private:
    int id;
    std::string nom;
    std::string categorie;
    double prix;
    int tempsPreparation;
    bool disponible;
};

#endif // PLAT_H
