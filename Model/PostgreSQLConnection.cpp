#include "PostgreSQLConnection.h"
#include <iostream>
#include <stdexcept>

// Initialisation de l'instance statique
PostgreSQLConnection* PostgreSQLConnection::instance = nullptr;

// Constructeur
PostgreSQLConnection::PostgreSQLConnection() : conninfo("host=localhost port=5432 dbname=ProgrammationConcourrente user=postgres password=lionel") {
    connection = PQconnectdb(conninfo.c_str());
    if (PQstatus(connection) != CONNECTION_OK) {
        std::cerr << "Erreur de connexion a la base de donnees : " << PQerrorMessage(connection) << std::endl;
        throw std::runtime_error("Impossible d'etablir une connexion.");
    }
    std::cout << "Connexion etablie avec succes a la base de donnees !" << std::endl;
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
        std::cout << "Connexion a la base de donnees fermee avec succes !" << std::endl;
    }
}

// Destructeur
PostgreSQLConnection::~PostgreSQLConnection() {
    closeConnection();
}
