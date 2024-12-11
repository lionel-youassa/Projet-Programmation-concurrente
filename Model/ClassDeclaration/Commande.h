#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include <vector>
#include "Plat.h"
#include "Table.h"

class Table;
class Commande {
public:
    int id;
    Table* table;                // Pointeur vers une instance de Table
    std::string statut;
    std::vector<Plat> plats;     // Collection de plats dans la commande

public:
    Commande(int id, Table* table);
    void AjouterPlat(const Plat& plat);
    void ChangerStatut(const std::string& nouveauStatut);
};

#endif // COMMANDE_H
