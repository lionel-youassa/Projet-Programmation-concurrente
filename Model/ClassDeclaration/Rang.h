//
// Created by siefo on 11/12/2024.
//
// Rang.h
#ifndef RANG_H
#define RANG_H

#include "Carree.h"

class Rang {
private:
    int id;
    Carree carree;  // Composition : Un rang possède une ou plusieurs carrees

public:
    Rang(int id, const Carree& carree);
    void ajouterCarree(const Carree& carree);
    Carree obtenirCarree();
};

#endif // RANG_H