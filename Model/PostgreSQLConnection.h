#ifndef POSTGRESQLCONNECTION_H
#define POSTGRESQLCONNECTION_H

#include <libpq-fe.h>
#include <string>
#include <vector>

#include "ClassDeclaration/Personne.h"

class PostgreSQLConnection {
private:
    static PostgreSQLConnection* instance; // Instance unique
    PGconn* connection; // Objet de connexion PostgreSQL
    const std::string conninfo; // Chaîne de connexion

    // Constructeur privé
    PostgreSQLConnection();

    // Désactiver la copie et l'affectation
    PostgreSQLConnection(const PostgreSQLConnection&) = delete;
    PostgreSQLConnection& operator=(const PostgreSQLConnection&) = delete;

public:
    static PostgreSQLConnection* getInstance(); // Obtenir l'instance unique
    PGconn* getConnection(); // Récupérer l'objet de connexion
    void closeConnection(); // Fermer la connexion
    std::vector<Personne> RecupPersonne() const;//Recuperation de personne
    ~PostgreSQLConnection(); // Destructeur
};

#endif // POSTGRESQLCONNECTION_H
