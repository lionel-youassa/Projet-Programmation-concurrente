#include <iostream>
#include <stdexcept>
#include <string>
#include <libpq-fe.h>

#include <QApplication>
#include "View/formulaire.h"
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
    // Initialiser l'application Qt
    QApplication app(argc, argv);

    // Créer la fenêtre Qt
    MainWindow main;
    main.show();

    // Exécuter l'application Qt
    return app.exec();
}
