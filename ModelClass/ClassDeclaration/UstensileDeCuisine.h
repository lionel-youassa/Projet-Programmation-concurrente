//
// Created by siefo on 09/12/2024.
//

#ifndef USTENSILE_DECUISINE_H
#define USTENSILE_DECUISINE_H

#include <string>

class UstensileDeCuisine {
public:
    UstensileDeCuisine(int id, const std::string& nom, bool etat);

    bool verifierEtat() const;

private:
    int id;
    std::string nom;
    bool etat;
};

#endif // USTENSILE_DECUISINE_H
