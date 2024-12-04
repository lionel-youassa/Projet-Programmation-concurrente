#ifndef SERVEUR_H
#define SERVEUR_H

#include "Table.h"
#include "Commande.h"

class Serveur {
public:
    void PrendreCommande(Table& table);
    void ServirCommande(Table& table);
    void RamasserVaisselle(Table& table);
};

#endif // SERVEUR_H
