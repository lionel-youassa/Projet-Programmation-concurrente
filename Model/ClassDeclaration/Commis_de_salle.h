#ifndef COMMIS_DE_SALLE_H
#define COMMIS_DE_SALLE_H

#include "Table.h"

class CommisDeSalle {
public:
    CommisDeSalle(int id, const std::string& nom, bool estEnPoste);
    void ServirPlat(Table& table);
    void VerifierBesoinClient();
    int getId() const;

private:
    int id;
    std::string nom;
    bool estEnPoste;
};

#endif // COMMIS_DE_SALLE_H
