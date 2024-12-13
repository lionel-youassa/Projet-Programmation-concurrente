#include <iostream>
#include <stdexcept>
#include <string>
#include <libpq-fe.h>

#include <QApplication>
#include "View/formulaire.h"
#include "View/RestaurantDashboard.h"
#include "Controller/Factory.h"

int main(int argc, char *argv[]) {
    // Initialiser l'application Qt
    QApplication app(argc, argv);

    // Créer la fenêtre Qt
    MainWindow mainWindow(4, 1, 60);

    // Afficher la fenêtre
    mainWindow.show();

    // Exécuter l'application Qt
    return app.exec();
}
