#include <iostream>
#include <stdexcept>
#include <string>
#include <libpq-fe.h>

#include <QApplication>
#include "View/formulaire.h"
#include <SFML/Graphics.hpp>
#include "View/RestaurantDashboard.h"
#include "Controller/Factory.h"
#include "Model/PostgreSQLConnection.h"
#include "Model/ClassDeclaration/Plat.h"

int main(int argc, char *argv[]) {
    try {
        // Initialiser l'application Qt
        QApplication app(argc, argv);

        // Initialiser la connexion PostgreSQL
        PostgreSQLConnection *postgre_sql_connection = PostgreSQLConnection::getInstance();
        if (!postgre_sql_connection) {
            throw std::runtime_error("Échec de l'initialisation de la connexion PostgreSQL.");
        }



        // Créer et afficher la fenêtre Qt
        Formulaire formulaire;
        formulaire.show();

        // Exécuter l'application Qt
        return app.exec();
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Une erreur inconnue s'est produite." << std::endl;
        return EXIT_FAILURE;
    }
}
