#include "PostgreSQLConnection.h"
#include "ClassDeclaration/Personne.h"
#include "ClassDeclaration/Position.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>


// Initialisation de l'instance statique
PostgreSQLConnection* PostgreSQLConnection::instance = nullptr;

// Constructeur
PostgreSQLConnection::PostgreSQLConnection()
    : conninfo("host=localhost port=5432 dbname=ProgrammationConcurrente user=postgres password=020106") {
    connection = PQconnectdb(conninfo.c_str());
    if (PQstatus(connection) != CONNECTION_OK) {
        std::cerr << "Erreur de connexion à la base de données : " << PQerrorMessage(connection) << std::endl;
        throw std::runtime_error("Impossible d'établir une connexion.");
    }
    std::cout << "Connexion établie avec succès à la base de données !" << std::endl;
}

PostgreSQLConnection* PostgreSQLConnection::getInstance() {
    if (!instance) {
        instance = new PostgreSQLConnection();
    }
    return instance;
}

PGconn* PostgreSQLConnection::getConnection() {
    return connection;
}

void PostgreSQLConnection::closeConnection() {
    if (connection) {
        PQfinish(connection);
        connection = nullptr;
        std::cout << "Connexion à la base de données fermée avec succès !" << std::endl;
    }
}

std::vector<Personne> PostgreSQLConnection::RecupPersonne() const {
    std::vector<Personne> mesPersonnes;
    try {
        // Préparer la requête
        std::string query = "SELECT id_personnel, nom, poste, disponibilite FROM personnel";

        // Exécuter la requête
        PGresult* result = PQexec(connection, query.c_str());

        // Vérifier le résultat
        if (PQresultStatus(result) != PGRES_TUPLES_OK) {
            std::cerr << "Erreur lors de la récupération : " << PQerrorMessage(connection) << std::endl;
            PQclear(result);
            throw std::runtime_error("Erreur lors de la récupération.");
        }

        int nRows = PQntuples(result);

        for (int i = 0; i < nRows; ++i) {
            Personne p  ;

            // Récupérer les attributs de Personne
            p.id =std::stoi(PQgetvalue(result, i, 0));  // id_personnel
            p.nom= PQgetvalue(result, i, 1);           // nom
            p.poste=PQgetvalue(result, i, 2);         // poste
            p.disponibilite=PQgetvalue(result, i, 3); // disponibilite

            // const char* positionStr = PQgetvalue(result, i, 4); // Index 4 pour "position"
            // std::vector<int> positions;
            //
            // // Séparer les valeurs par la virgule et les convertir en entiers
            // std::stringstream ss(positionStr);
            // std::string token;
            // while (std::getline(ss, token, ',')) {
            //     positions.push_back(std::stoi(token));
            // }
            //
            // // Créer l'objet `Position` à partir des valeurs récupérées (selon vos besoins)
            // Position pos = Position(positions);
            // p.positionActuelle=pos; // Assurez-vous que votre classe `Personne` a une méthode `setPosition`.


            mesPersonnes.push_back(p);
        }

        std::cout << "Récupération réussie : " << nRows << " enregistrements trouvés." << std::endl;

        // Nettoyer le résultat
        PQclear(result);
    } catch (const std::exception& ex) {
        std::cerr << "Une erreur est survenue lors de la récupération : " << ex.what() << std::endl;
    }
    return mesPersonnes;
}

// Destructeur
PostgreSQLConnection::~PostgreSQLConnection() {
    closeConnection();
}
