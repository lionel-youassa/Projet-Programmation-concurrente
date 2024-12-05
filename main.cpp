#include <iostream>
#include <stdexcept>
#include "Model/PostgreSQLConnection.h"
#include <string>
#include <libpq-fe.h>

#include <QApplication>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QScrollArea>
#include <QLabel>
#include <QPixmap>
#include <QString>




QWidget* createImageWidget(const QString &imagePath, int width, int height) {
    QLabel *imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("border: none;");

    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("Image introuvable");
    }

    return imageLabel;
}



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
        kitchenFrame->setFixedSize(1520, 400);

        auto *kitchenLayout = new QGridLayout(kitchenFrame);
        kitchenLayout->setContentsMargins(10, 10, 10, 10);
        kitchenLayout->setSpacing(20);

        auto *washingMachine = new QLabel("Machine à laver");
        washingMachine->setFixedSize(100, 60);
        washingMachine->setStyleSheet("background-color: #B0C4DE; border: 1px solid black; font-size: 10px;");
        washingMachine->setAlignment(Qt::AlignCenter);
        kitchenLayout->addWidget(washingMachine, 0, 4);

        auto *dishwasher = new QLabel("Lave-vaisselle");
        dishwasher->setFixedSize(100, 60);
        dishwasher->setStyleSheet("background-color: #B0C4DE; border: 1px solid black; font-size: 10px;");
        dishwasher->setAlignment(Qt::AlignCenter);
        kitchenLayout->addWidget(dishwasher, 0, 5);

        auto  *kitchenTableWidget= new  QWidget();
        kitchenTableWidget->setStyleSheet("border: none;");
        kitchenTableWidget->setFixedSize(800, 120);
        auto  *kitchenTableLayout = new QHBoxLayout();;

        for(int i=0 ; i<2 ; i++) {
            auto *kitchenTable = new QLabel("Table de cuisine");
            kitchenTable->setFixedSize(200, 60);
            kitchenTable->setStyleSheet("background-color: #D3D3D3; border: 1px solid black; font-size: 10px;");
            kitchenTable->setAlignment(Qt::AlignCenter);
            kitchenTableLayout->addWidget(kitchenTable);
            kitchenTableLayout->setSpacing(10);
        }
            kitchenTableWidget->setLayout(kitchenTableLayout);

            kitchenLayout->addWidget(kitchenTableWidget, 3, 3, 1, 2, Qt::AlignCenter);


        auto *freezer = new QLabel("Stock");
        freezer->setFixedSize(100, 100);
        freezer->setStyleSheet("background-color: #ADD8E6; border: 1px solid black; font-size: 12px;");
        freezer->setAlignment(Qt::AlignCenter);
        kitchenLayout->addWidget(freezer, 4, 5, Qt::AlignRight);






            // --- Rectangle "Commande" , "plat pret" et "Plat sale" ---
        // Ajout du rectangle "Commande"
        auto *comptoirCuisineCommande = new QLabel("Commandes");
        comptoirCuisineCommande->setFixedSize(100, 60);
        comptoirCuisineCommande->setStyleSheet("background-color: #C3E4CD; border: 2px solid #8B4513; font-size: 16px; font-weight: bold;");
        comptoirCuisineCommande->setAlignment(Qt::AlignCenter);

        // Ajout du rectangle "Plat pret"
        auto *comptoirPlatPretCuisine = new QLabel("Plat pret");
        comptoirPlatPretCuisine->setFixedSize( 100, 60);
        comptoirPlatPretCuisine->setStyleSheet("background-color: #AFCBE3; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        comptoirPlatPretCuisine->setAlignment(Qt::AlignCenter);


        // Ajout du rectangle "Plat salle"
        auto *comptoirPlatSaleCuisine = new QLabel("Plat sale");
        comptoirPlatSaleCuisine->setFixedSize(100, 60);
        comptoirPlatSaleCuisine->setStyleSheet("background-color: #D9D9D9; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        comptoirPlatSaleCuisine->setAlignment(Qt::AlignCenter);

        // Créer un layout horizontal pour coller "Accueil" et "Zone d'attente" ensemble
        auto *comptoirLayoutCuisine = new QHBoxLayout();
        comptoirLayoutCuisine->addWidget(comptoirCuisineCommande);
        comptoirLayoutCuisine->addSpacing(20); // Espacement entre les rectangles
        comptoirLayoutCuisine->addWidget(comptoirPlatPretCuisine);
        comptoirLayoutCuisine->addSpacing(20); // Espacement entre les rectangles
        comptoirLayoutCuisine->addWidget(comptoirPlatSaleCuisine);


        // Widget qui contient le layout de l'accueil et de la zone d'attente
        auto *comptoirCuisineWidget = new QWidget();
        comptoirCuisineWidget->setLayout(comptoirLayoutCuisine);
        comptoirCuisineWidget->setStyleSheet("border: none;");

        // Placer les zones en bas à gauche de la cuisine, collées au mur

        kitchenLayout->addWidget(comptoirCuisineWidget, 5, 0, Qt::AlignCenter);



        mainWidgetLayout->addWidget(kitchenFrame);

        // --- Salle de restauration ---
        auto *diningFrame = new QFrame();
        diningFrame->setFrameShape(QFrame::Box);
        diningFrame->setStyleSheet("border: 5px solid #8B4513; background-color: #FFE4B5;");

        auto *diningLayout = new QGridLayout(diningFrame);
        diningLayout->setContentsMargins(20, 20, 20, 20);
        diningLayout->setHorizontalSpacing(60);  // Réduction de l'espacement horizontal
        diningLayout->setVerticalSpacing(60); // Espacement vertical pour le couloir

        // --- Rectangle "Accueil" et "Zone d'attente" ---
        // Ajout du rectangle "Accueil"
        auto *receptionArea = new QLabel("Accueil");
        receptionArea->setFixedSize(150, 80);
        receptionArea->setStyleSheet("background-color: #FFD700; border: 2px solid #8B4513; font-size: 16px; font-weight: bold;");
        receptionArea->setAlignment(Qt::AlignCenter);

        // Ajout du rectangle "Zone d'attente"
        auto *waitingArea = new QLabel("Zone d'attente");
        waitingArea->setFixedSize(200, 80);
        waitingArea->setStyleSheet("background-color: #FFA07A; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        waitingArea->setAlignment(Qt::AlignCenter);

        // Créer un layout horizontal pour coller "Accueil" et "Zone d'attente" ensemble
        auto *receptionLayout = new QHBoxLayout();
        receptionLayout->addWidget(receptionArea);
        receptionLayout->addSpacing(20); // Espacement entre les rectangles
        receptionLayout->addWidget(waitingArea);


        // Widget qui contient le layout de l'accueil et de la zone d'attente
        auto *receptionWidget = new QWidget();
        receptionWidget->setLayout(receptionLayout);
        receptionLayout->setContentsMargins(20, 20, 20, 20);
        receptionWidget->setStyleSheet("border: none;");

        // Placer les zones en haut à droite de la salle de restaurant, collées au mur
        diningLayout->addWidget(receptionWidget, 9, 3, 1, 2, Qt::AlignBottom | Qt::AlignRight);



        // --- Rectangle "Commande" , "plat pret" et "Plat sale" ---
        // Ajout du rectangle "Commande"
        auto *comptoirCommande = new QLabel("Commandes");
        comptoirCommande->setFixedSize(100, 60);
        comptoirCommande->setStyleSheet("background-color: #C3E4CD; border: 2px solid #8B4513; font-size: 16px; font-weight: bold;");
        comptoirCommande->setAlignment(Qt::AlignCenter);

        // Ajout du rectangle "Plat pret"
        auto *comptoirPlatPret = new QLabel("Plat pret");
        comptoirPlatPret->setFixedSize( 100, 60);
        comptoirPlatPret->setStyleSheet("background-color: #AFCBE3; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        comptoirPlatPret->setAlignment(Qt::AlignCenter);


        // Ajout du rectangle "Plat salle"
        auto *comptoirPlatSale = new QLabel("Plat sale");
        comptoirPlatSale->setFixedSize(100, 60);
        comptoirPlatSale->setStyleSheet("background-color: #D9D9D9; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        comptoirPlatSale->setAlignment(Qt::AlignCenter);

        // Créer un layout horizontal pour coller "Accueil" et "Zone d'attente" ensemble
        auto *comptoirLayout = new QHBoxLayout();
        comptoirLayout->addWidget(comptoirCommande);
        comptoirLayout->addSpacing(20); // Espacement entre les rectangles
        comptoirLayout->addWidget(comptoirPlatPret);
        comptoirLayout->addSpacing(20); // Espacement entre les rectangles
        comptoirLayout->addWidget(comptoirPlatSale);


        // Widget qui contient le layout de l'accueil et de la zone d'attente
        auto *comptoirWidget = new QWidget();
        comptoirWidget->setLayout(comptoirLayout);
        comptoirWidget->setStyleSheet("border: none;");



        // Placer les zones en haut à droite de la salle de restaurant, collées au mur
        diningLayout->addWidget(comptoirWidget, 0, 3, 1, 2, Qt::AlignTop | Qt::AlignRight);



        // Widget qui contient le layout du Carrer 1
        auto *carrer1Widget = new QWidget();
        carrer1Widget->setFixedSize(1000, 300);
        // Widget qui contient le layout du Carrer 1
        auto *carrer2Widget = new QWidget();
        carrer2Widget->setFixedSize(1000, 300);


        // Créer un layout pour le Carre 1
        auto *carrerLayout1 = new QGridLayout();
        carrerLayout1->setSpacing(0);

        // Créer un layout pour le Carre 2
        auto *carrerLayout2 = new QGridLayout();
        carrerLayout1->setSpacing(0);



        // --- Ajout des tables rondes ---
        for (int row = 0; row < 2; ++row) {
            for (int col = 0; col < 8; ++col) {
                auto *tableGroup = new QWidget();
                tableGroup->setFixedSize(80, 80);
                auto *groupLayout = new QGridLayout(tableGroup);
                groupLayout->setContentsMargins(0, 0, 0, 0);
                groupLayout->setSpacing(0);

                auto *table = new QLabel();
                table->setFixedSize(30, 30);
                table->setStyleSheet("background-color: #D2B48C; border-radius: 40px; border: 2px solid #8B4513;");
                groupLayout->addWidget(table, 1, 1, Qt::AlignCenter);

                for (int i = 0; i < 4; ++i) {
                    auto *chair = new QLabel();
                    chair->setFixedSize(10, 10);
                    chair->setStyleSheet("background-color: #8B4513; border-radius: 5px;");
                    if (i == 0) groupLayout->addWidget(chair, 0, 1, Qt::AlignCenter);
                    else if (i == 1) groupLayout->addWidget(chair, 1, 2, Qt::AlignCenter);
                    else if (i == 2) groupLayout->addWidget(chair, 2, 1, Qt::AlignCenter);
                    else groupLayout->addWidget(chair, 1, 0, Qt::AlignCenter);
                }

                carrerLayout1->addWidget(tableGroup,row+1,col+1, Qt::AlignCenter);
                carrer1Widget->setLayout(carrerLayout1);

                diningLayout->addWidget(carrer1Widget, row, col, Qt::AlignCenter);
            }
        }


        // --- Ajout des tables rondes ---
        for (int row = 5; row < 7; ++row) {
            for (int col = 0; col < 8; ++col) {
                auto *tableGroup2 = new QWidget();
                tableGroup2->setFixedSize(80, 80);
                auto *groupLayout2 = new QGridLayout(tableGroup2);
                groupLayout2->setContentsMargins(0, 0, 0, 0);
                groupLayout2->setSpacing(0);

                auto *table = new QLabel();
                table->setFixedSize(30, 30);
                table->setStyleSheet("background-color: #D2B48C; border-radius: 40px; border: 2px solid #8B4513;");
                groupLayout2->addWidget(table, 1, 1, Qt::AlignCenter);

                for (int i = 0; i < 4; ++i) {
                    auto *chair = new QLabel();
                    chair->setFixedSize(10, 10);
                    chair->setStyleSheet("background-color: #8B4513; border-radius: 5px;");
                    if (i == 0) groupLayout2->addWidget(chair, 0, 1, Qt::AlignCenter);
                    else if (i == 1) groupLayout2->addWidget(chair, 1, 2, Qt::AlignCenter);
                    else if (i == 2) groupLayout2->addWidget(chair, 2, 1, Qt::AlignCenter);
                    else groupLayout2->addWidget(chair, 1, 0, Qt::AlignCenter);
                }
                carrerLayout2->addWidget(tableGroup2,row,col, Qt::AlignCenter);

                carrer2Widget->setLayout(carrerLayout2);
                diningLayout->addWidget(carrer2Widget, row, col, Qt::AlignCenter);
            }
        }

        // Ajout d'une image dans la salle
        auto *maitreHotelImage = createImageWidget(
            "C:\\Users\\lione\\CLionProjects\\RestaurantManagement\\images\\maitrehoteldown.png",
            60, // Largeur souhaitée
            70  // Hauteur souhaitée
        );

        diningLayout->addWidget(maitreHotelImage, 7, 3, Qt::AlignCenter);
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





// Formulaire principal
class Formulaire : public QWidget {
public:
    Formulaire(QWidget *parent = nullptr) : QWidget(parent) {
        auto *mainLayout = new QVBoxLayout(this);

        // Formulaire
        auto *formLayout = new QFormLayout();

        // Style global pour les champs et labels
        QString inputStyle = "padding: 8px; border: 1px solid #8B4513; border-radius: 5px; background-color: #FFF8DC; font-size: 14px;";
        QString labelStyle = "font-size: 16px; font-weight: bold; color: #8B4513;";

        // Champ : Nombre de places
        auto *placeInput = new QSpinBox();
        placeInput->setMinimum(1);
        placeInput->setMaximum(50);
        placeInput->setValue(4);
        placeInput->setStyleSheet(inputStyle);
        auto *placeLabel = new QLabel("Nombre de places :");
        placeLabel->setStyleSheet(labelStyle);
        formLayout->addRow(placeLabel, placeInput);

        // Champ : Numéro de table
        auto *tableInput = new QSpinBox();
        tableInput->setMinimum(1);
        tableInput->setMaximum(100);
        tableInput->setValue(1);
        tableInput->setStyleSheet(inputStyle);
        auto *tableLabel = new QLabel("Numéro de table :");
        tableLabel->setStyleSheet(labelStyle);
        formLayout->addRow(tableLabel, tableInput);

        // Champ : Liste des plats
        auto *dishInput = new QComboBox();
        dishInput->addItems({"Pizza", "Burger", "Salade", "Pâtes", "Sushi"});
        dishInput->setStyleSheet(inputStyle);
        auto *dishLabel = new QLabel("Plat :");
        dishLabel->setStyleSheet(labelStyle);
        formLayout->addRow(dishLabel, dishInput);

        // Champ : Temps de simulation
        auto *timeInput = new QSpinBox();
        timeInput->setMinimum(1);
        timeInput->setMaximum(120);
        timeInput->setValue(10);
        timeInput->setStyleSheet(inputStyle);
        auto *timeLabel = new QLabel("Temps de simulation (min) :");
        timeLabel->setStyleSheet(labelStyle);
        formLayout->addRow(timeLabel, timeInput);

        // Ajouter le formulaire au layout principal
        mainLayout->addLayout(formLayout);

        // Bouton pour démarrer la simulation
        auto *startButton = new QPushButton("Démarrer la simulation");
        startButton->setStyleSheet(
            "background-color: #8B4513; color: white; font-size: 16px; font-weight: bold; padding: 10px; border-radius: 5px; "
            "border: 1px solid #5A3220; cursor: pointer;"
        );
        startButton->setCursor(Qt::PointingHandCursor);
        startButton->setFixedHeight(50);
        mainLayout->addWidget(startButton, 0, Qt::AlignCenter);

        // Connecter le bouton pour afficher MainWindow
        connect(startButton, &QPushButton::clicked, this, [=]() {
            auto *simulationWindow = new MainWindow();
            simulationWindow->show();
        });

        // Style général de la fenêtre
        setStyleSheet("background-color: #FDF5E6;");
        setLayout(mainLayout);
        setWindowTitle("Formulaire de simulation");
        resize(400, 300);
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

    QApplication app(argc, argv);

    Formulaire formulaire;
    formulaire.show();

    return app.exec();
}