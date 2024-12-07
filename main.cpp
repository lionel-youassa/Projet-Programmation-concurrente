#include <iostream>
#include <stdexcept>
#include "Model/PostgreSQLConnection.h"
#include <string>
#include <libpq-fe.h>

#include <QApplication>
#include "View/formulaire.h"

























void insertIntoCarre(const std::string& nom_carre) {
    try {
        // Obtenir une instance de la connexion
        PostgreSQLConnection* dbConnection = PostgreSQLConnection::getInstance();
        PGconn* conn = dbConnection->getConnection();

        // Préparer la requête d'insertion
        std::string query = "INSERT INTO Carre (nom_carre) VALUES ('" + nom_carre + "')";

        // Exécuter la requête
        PGresult* result = PQexec(conn, query.c_str());

        // Vérifier le résultat de l'insertion
        if (PQresultStatus(result) != PGRES_COMMAND_OK) {
            std::cerr << "Erreur lors de l'insertion : " << PQerrorMessage(conn) << std::endl;
            PQclear(result);
            throw std::runtime_error("Insertion échouée.");
        }

        std::cout << "Insertion réussie dans la table Carre avec le nom : " << nom_carre << std::endl;

        // Nettoyer le résultat
        PQclear(result);
    } catch (const std::exception& ex) {
        std::cerr << "Une erreur est survenue lors de l'insertion : " << ex.what() << std::endl;
    }
}







int main(int argc, char *argv[]) {

    // try {
    //     // Appeler la fonction pour insérer un carré
    //     insertIntoCarre("Carré Principal");
    // } catch (const std::exception& ex) {
    //     std::cerr << "Une erreur est survenue dans main : " << ex.what() << std::endl;
    //     return EXIT_FAILURE;
    // }
    //
    // return EXIT_SUCCESS;

    QApplication app(argc, argv);

   MainWindow main;
    main.show();

    return app.exec();
}