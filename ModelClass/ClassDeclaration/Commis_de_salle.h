#ifndef COMMIS_DE_SALLE_H
#define COMMIS_DE_SALLE_H

#include "Personne.h"
#include "Table.h"
#include <list>

class CommisDeSalle : public Personne {
public:
    CommisDeSalle(int id, const std::string& nom, bool poste);

    // Méthodes
    void ServirPlat(Table& table);
    void VerifierBesoinClient();
};

#endif // COMMIS_DE_SALLE_H
