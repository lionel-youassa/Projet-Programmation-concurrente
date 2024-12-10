#include <iostream>
#include <stdexcept>
#include <string>
#include <libpq-fe.h>


#include <QApplication>
#include "View/formulaire.h"
#include <SFML/Graphics.hpp>
#include "View/RestaurantDashboard.h"
#include "Controller/Factory.h"

int main(int argc, char *argv[]) {
    // Initialiser l'application Qt
    QApplication app(argc, argv);

    // Créer la fenêtre Qt
    Formulaire formulaire;
    auto *restaurantDashboard= new RestaurantDashboard();
    Factory factory;
    factory.creaTable();
    //for(size_t i =0; i<factory.get_table_().size(); i++)  {
        restaurantDashboard->updateTableState(5,factory.get_table_()[5].statut.data());
        std::cout<<5 << factory.get_table_()[5].statut.data() << std::endl;
    //}
    formulaire.show();


    // Exécuter l'application Qt
    return app.exec();
}
