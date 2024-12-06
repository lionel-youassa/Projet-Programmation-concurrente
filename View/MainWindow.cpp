#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
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
        kitchenFrame->setFixedSize(1500, 400);

        auto *kitchenLayout = new QGridLayout(kitchenFrame);
        kitchenLayout->setContentsMargins(5, 10, 5, 10);
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
        comptoirCuisineCommande->setFixedSize(100, 40);
        comptoirCuisineCommande->setStyleSheet("background-color: #C3E4CD; border: 2px solid #8B4513; font-size: 16px; font-weight: bold;");
        comptoirCuisineCommande->setAlignment(Qt::AlignCenter);

        // Ajout du rectangle "Plat pret"
        auto *comptoirPlatPretCuisine = new QLabel("Plat pret");
        comptoirPlatPretCuisine->setFixedSize( 100, 40);
        comptoirPlatPretCuisine->setStyleSheet("background-color: #AFCBE3; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        comptoirPlatPretCuisine->setAlignment(Qt::AlignCenter);


        // Ajout du rectangle "Plat salle"
        auto *comptoirPlatSaleCuisine = new QLabel("Plat sale");
        comptoirPlatSaleCuisine->setFixedSize(100, 40);
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

        kitchenLayout->addWidget(comptoirCuisineWidget, 5, 1, Qt::AlignCenter);



        mainWidgetLayout->addWidget(kitchenFrame);

        // --- Salle de restauration ---
        auto *diningFrame = new QFrame();
        diningFrame->setFrameShape(QFrame::Box);
        diningFrame->setStyleSheet("border: 5px solid #8B4513; background-color: #FFE4B5;");
        diningFrame->setFixedSize(1500, 1300);

        auto *diningLayout = new QGridLayout(diningFrame);
        diningLayout->setContentsMargins(5, 10, 10, 5); // Pas de marges autour du layout
        diningLayout->setHorizontalSpacing(0);       // Espacement horizontal
        diningLayout->setVerticalSpacing(40);         // Espacement vertical

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
        receptionLayout->setContentsMargins(20, 5, 5 ,20);
        receptionWidget->setStyleSheet("border: none;");

        // Placer les zones en haut à droite de la salle de restaurant, collées au mur
        diningLayout->addWidget(receptionWidget, 9, 1, 1, 2, Qt::AlignBottom | Qt::AlignRight);



        // --- Rectangle "Commande" , "plat pret" et "Plat sale" ---
        // Ajout du rectangle "Commande"
        auto *comptoirCommande = new QLabel("Commandes");
        comptoirCommande->setFixedSize(100, 40);
        comptoirCommande->setStyleSheet("background-color: #C3E4CD; border: 2px solid #8B4513; font-size: 16px; font-weight: bold;");
        comptoirCommande->setAlignment(Qt::AlignCenter);

        // Ajout du rectangle "Plat pret"
        auto *comptoirPlatPret = new QLabel("Plat pret");
        comptoirPlatPret->setFixedSize( 100, 40);
        comptoirPlatPret->setStyleSheet("background-color: #AFCBE3; border: 2px solid #8B4513; font-size: 14px; font-weight: bold;");
        comptoirPlatPret->setAlignment(Qt::AlignCenter);


        // Ajout du rectangle "Plat salle"
        auto *comptoirPlatSale = new QLabel("Plat sale");
        comptoirPlatSale->setFixedSize(100, 40);
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
        diningLayout->addWidget(comptoirWidget, 0, 1, 1, 2, Qt::AlignTop | Qt::AlignRight);

        // Définir une hauteur minimale pour chaque ligne
        for (int row = 0; row < diningLayout->rowCount(); ++row) {
            diningLayout->setRowMinimumHeight(row, 500); // 100 pixels par ligne
        }

        // Ajout de la rangée de tables à la row 1
        auto *rangeTable = createRangeTable(4,8);
        rangeTable->setParent(diningFrame);
        diningLayout->addWidget(rangeTable, 1, 3, 1, 8, Qt::AlignTop | Qt::AlignCenter);

        // Ajout de la rangée de tables (4 chaises) à la row 2
        auto *rangeTable2 = createRangeTable(4,2);
        rangeTable->setParent(diningFrame);
        diningLayout->addWidget(rangeTable2, 2, 3, 1, 3, Qt::AlignTop | Qt::AlignCenter);


        // // Ajout de la rangée de tables (6 chaises) à la row 2
         auto *rangeTable3 = createRangeTable(6,5);
        rangeTable->setParent(diningFrame);
        diningLayout->addWidget(rangeTable3 , 2, 5, 1,5, Qt::AlignTop | Qt::AlignCenter);


        // // Ajout de la rangée de tables à la row 3
        auto *rangeTable4 = createRangeTable(2,8);
        rangeTable->setParent(diningFrame);
        diningLayout->addWidget(rangeTable4 , 4, 3, 1,8, Qt::AlignTop | Qt::AlignCenter);

        // Ajout de la rangée de tables (2 chaises) à la row 2
        auto *rangeTable5 = createRangeTable(2,2);
        rangeTable5->setParent(diningFrame);
        diningLayout->addWidget(rangeTable5, 5, 3, 1, 3, Qt::AlignTop | Qt::AlignCenter);


        // // Ajout de la rangée de tables à la row 3
        auto *rangeTable6 = createRangeTable(8,5);
        rangeTable6->setParent(diningFrame);
        diningLayout->addWidget(rangeTable6 , 5, 5, 1,5, Qt::AlignTop | Qt::AlignCenter);










        mainWidgetLayout->addWidget(diningFrame);


        // Positionnement manuel pour les images
        //Maitre hotel
        insertPng("../images/maitrehoteldown.png",mainWidget,100, 1500, 60, 70);



        //Chef de rang 1 attente
        insertPng("../images/RangeChief.png",mainWidget,300, 1500, 60, 70);



        //Serveur rang 2
        insertPng("../images/serveurmovingright.png",mainWidget,500, 1040, 60, 70 );


        // Chef de rang 2
        insertPng("../images/RangechiefLeft.png",mainWidget,800, 1000, 60, 70 );

        //Serveur Rang 2
        insertPng("../images/serveurmovingright.png",mainWidget,500, 1040, 60, 70 );

        //Serveur Rang 1
        insertPng("../images/serveurmovingleft.png",mainWidget,1000, 600, 60, 70 );




        //Serveur Chef cuisine
        insertPng("../images/MasterChefDown.png",mainWidget,100, 200, 60, 70 );




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

QWidget* MainWindow::createRangeTable(int numChairs, int numTables) {
    auto *lineTableWidget = new QWidget();
    lineTableWidget->setStyleSheet("border: none;");
    lineTableWidget->setContentsMargins(0, 0, 0, 0);

    auto *lineTableLayout = new QGridLayout(lineTableWidget);
    lineTableLayout->setContentsMargins(0, 0, 0, 0); // Suppression des marges

    lineTableLayout->setVerticalSpacing(10); // Espacement entre les tables
    lineTableLayout->setHorizontalSpacing(30);

    // --- Ajout des tables rondes ---
    for (int col = 0; col < numTables; ++col) {
        auto *tableGroup = new QWidget();
        tableGroup->setFixedSize(80, 80);
        tableGroup->setStyleSheet("border: 3px solid #8B4513;");

        auto *groupLayout = new QGridLayout(tableGroup);
        groupLayout->setContentsMargins(0, 0, 0, 0);
        groupLayout->setSpacing(0);

        auto *table = new QLabel();
        table->setFixedSize(30, 30);
        table->setStyleSheet("background-color: #D2B48C; border-radius: 20px; border: 2px solid #8B4513;");
        groupLayout->addWidget(table, 1, 1, Qt::AlignCenter);

        // Calcul de la position des chaises
        for (int i = 0; i < numChairs; ++i) {
            auto *chair = new QLabel();
            chair->setFixedSize(10, 10);
            chair->setStyleSheet("background-color: #8B4513; border-radius: 10px;");

            // Angle de chaque chaise autour de la table (en radians)
            double angle = (2 * M_PI * i) / numChairs;

            // Conversion des coordonnées polaires en indices de grille
            int rowOffset = static_cast<int>(1 + std::round(std::sin(angle)));
            int colOffset = static_cast<int>(1 + std::round(std::cos(angle)));

            groupLayout->addWidget(chair, rowOffset, colOffset, Qt::AlignCenter);
        }

        lineTableLayout->addWidget(tableGroup, 0, col);
    }

    return lineTableWidget;
}

QWidget* MainWindow::createImageWidget(const QString &imagePath, int width, int height) {
    QLabel *imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("border: none;");

    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("Image introuvable");
    }

    imageLabel->setFixedSize(width, height);
    return imageLabel;
}

void MainWindow::insertPng(const std::string &pngPath, QWidget *parent, int ax, int ay, int aw, int ah) {
    auto *imageWidget = createImageWidget(QString::fromStdString(pngPath), aw, ah);
    imageWidget->setParent(parent);
    imageWidget->setGeometry(ax, ay, aw, ah);
}
