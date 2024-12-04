#include <iostream>
#include <stdexcept>
#include "Model/PostgreSQLConnection.h"
#include <string>
#include <libpq-fe.h>

#include <QApplication>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QGridLayout>







class MainWindow : public QWidget {
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Layout principal pour la fenêtre
        auto *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // --- Widget principal contenant tout ---
        auto *mainWidget = new QWidget(); // Contiendra la cuisine et la salle
        auto *mainWidgetLayout = new QVBoxLayout(mainWidget);
        mainWidgetLayout->setContentsMargins(0, 0, 0, 0);

        // --- Cuisine ---
        auto *kitchenFrame = new QFrame();
        kitchenFrame->setFrameShape(QFrame::Box);
        kitchenFrame->setStyleSheet("border: 2px solid #4682B4; background-color: #ADD8E6;"); // Bleu clair
        kitchenFrame->setFixedSize(900, 300);

        auto *kitchenLayout = new QGridLayout(kitchenFrame);
        kitchenLayout->setContentsMargins(10, 10, 10, 10);
        kitchenLayout->setSpacing(20);

        auto *washingMachine = new QLabel("Machine à laver");
        washingMachine->setFixedSize(100, 60);
        washingMachine->setStyleSheet("background-color: #B0C4DE; border: 1px solid black; font-size: 10px;");
        washingMachine->setAlignment(Qt::AlignCenter);
        kitchenLayout->addWidget(washingMachine, 0, 0);

        auto *dishwasher = new QLabel("Lave-vaisselle");
        dishwasher->setFixedSize(100, 60);
        dishwasher->setStyleSheet("background-color: #B0C4DE; border: 1px solid black; font-size: 10px;");
        dishwasher->setAlignment(Qt::AlignCenter);
        kitchenLayout->addWidget(dishwasher, 0, 1);

        for (int i = 0; i < 2; ++i) {
            auto *kitchenTable = new QLabel("Table de cuisine");
            kitchenTable->setFixedSize(300, 50);
            kitchenTable->setStyleSheet("background-color: #D3D3D3; border: 1px solid black; font-size: 10px;");
            kitchenTable->setAlignment(Qt::AlignCenter);
            kitchenLayout->addWidget(kitchenTable, 1, i, 1, 2, Qt::AlignCenter);
        }

        auto *freezer = new QLabel("Stock");
        freezer->setFixedSize(100, 100);
        freezer->setStyleSheet("background-color: #ADD8E6; border: 1px solid black; font-size: 12px;");
        freezer->setAlignment(Qt::AlignCenter);
        kitchenLayout->addWidget(freezer, 2, 3, Qt::AlignRight);

        mainWidgetLayout->addWidget(kitchenFrame);

        // --- Salle de restauration ---
        auto *diningFrame = new QFrame();
        diningFrame->setFrameShape(QFrame::Box);
        diningFrame->setStyleSheet("border: 5px solid #8B4513; background-color: #FFE4B5;");
        diningFrame->setFixedSize(900, 600);

        auto *diningLayout = new QGridLayout(diningFrame);
        diningLayout->setContentsMargins(20, 20, 20, 20);
        diningLayout->setHorizontalSpacing(80);
        diningLayout->setVerticalSpacing(60);

        for (int row = 0; row < 2; ++row) {
            for (int col = 0; col < 2; ++col) {
                auto *tableGroup = new QWidget();
                tableGroup->setFixedSize(200, 200);
                auto *groupLayout = new QGridLayout(tableGroup);
                groupLayout->setContentsMargins(0, 0, 0, 0);
                groupLayout->setSpacing(0);

                auto *table = new QLabel();
                table->setFixedSize(80, 80);
                table->setStyleSheet("background-color: #D2B48C; border-radius: 40px; border: 2px solid #8B4513;");
                groupLayout->addWidget(table, 1, 1, Qt::AlignCenter);

                for (int i = 0; i < 4; ++i) {
                    auto *chair = new QLabel();
                    chair->setFixedSize(30, 30);
                    chair->setStyleSheet("background-color: #8B4513; border-radius: 5px;");
                    if (i == 0) groupLayout->addWidget(chair, 0, 1, Qt::AlignCenter);
                    else if (i == 1) groupLayout->addWidget(chair, 1, 2, Qt::AlignCenter);
                    else if (i == 2) groupLayout->addWidget(chair, 2, 1, Qt::AlignCenter);
                    else groupLayout->addWidget(chair, 1, 0, Qt::AlignCenter);
                }

                diningLayout->addWidget(tableGroup, row, col, Qt::AlignCenter);
            }
        }

        auto *receptionArea = new QLabel("Accueil");
        receptionArea->setFixedSize(150, 80);
        receptionArea->setStyleSheet("background-color: #FFD700; border: 2px solid #8B4513; font-size: 16px; font-weight: bold;");
        receptionArea->setAlignment(Qt::AlignCenter);
        diningLayout->addWidget(receptionArea, 2, 0, Qt::AlignLeft | Qt::AlignBottom);

        mainWidgetLayout->addWidget(diningFrame);

        // --- Ajout dans un QScrollArea ---
        auto *scrollArea = new QScrollArea(this);
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(mainWidget);

        mainLayout->addWidget(scrollArea);

        // Configuration de la fenêtre principale
        setLayout(mainLayout);
        setWindowTitle("Disposition du restaurant");
        resize(1000, 700); // Taille ajustée pour activer le défilement
    }
};
























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

    QApplication a(argc, argv);
        MainWindow window;
        window.show();

     return QApplication::exec();
}
