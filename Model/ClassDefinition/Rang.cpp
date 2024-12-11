// Rang.cpp
#include "../ClassDeclaration/Rang.h"


Rang::Rang(int id, const Carree& carree)
    : id(id), carree(carree) {

}

void Rang::ajouterCarree(const Carree& carree) {
    this->carree = carree;
}

Carree Rang::obtenirCarree() {
    return carree;
}