#include "MenuWindows.h"
#include <QVBoxLayout>
#include <QPixmap>
#include "../Model/ClassDeclaration/Plat.h"

MenuWindow::MenuWindow(QWidget *parent) : QMainWindow(parent) {

    // Configuration de la fenêtre principale
    setWindowTitle("Menu du Jour");
    resize(800, 600);

    // Création du widget central
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Titre du menu
    menuTitleLabel = new QLabel("<h1 style='color: #8B0000;'>Menu du Jour</h1>", this);
    menuTitleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(menuTitleLabel);

    // Layout pour afficher les plats
    menuLayout = new QGridLayout();
    mainLayout->addLayout(menuLayout);

    // Bouton pour rafraîchir l'affichage
    closeButton = new QPushButton("Fermer", this);
    closeButton->setStyleSheet("background-color: #8B0000; color: white; padding: 10px; border-radius: 5px;");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    mainLayout->addWidget(closeButton, 0, Qt::AlignCenter);

    // Définir le widget central
    setCentralWidget(centralWidget);
}



void MenuWindow::displayMenu(const QList<Dish> &dishes) {
    // Nettoyer la disposition précédente
    QLayoutItem *child;
    while ((child = menuLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Parcourir la liste des plats et les afficher
    for (int i = 0; i < dishes.size(); ++i) {
        const Dish &dish = dishes[i];

        // Afficher l'image du plat
        QLabel *imageLabel = new QLabel(this);
        QPixmap pixmap(dish.imagePath);

        // Vérifier si l'image est valide
        if (pixmap.isNull()) {
            qDebug() << "Erreur lors du chargement de l'image :" << dish.imagePath;
            pixmap.load("../images/default.jpg"); // Charger une image par défaut
        }
        imageLabel->setPixmap(pixmap.scaled(120, 120, Qt::KeepAspectRatio));
        menuLayout->addWidget(imageLabel, i / 2, (i % 2));

        // Afficher le nom du plat
        QLabel *nameLabel = new QLabel(dish.name, this);
        nameLabel->setStyleSheet("font-size: 16px; color: #333;");
        nameLabel->setAlignment(Qt::AlignCenter);
        menuLayout->addWidget(nameLabel, i / 2, (i % 2));
    }
}
