#include "RestaurantDashboard.h"

#include <QScrollArea>

RestaurantDashboard::RestaurantDashboard(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Supervision Restaurant");
    //setFixedSize(900, 900);



    setStyleSheet(" background-color: #FDF5E6;");

    // Mise en page principale
    auto *mainLayout = new QVBoxLayout(this);





    // Section Tables
    auto *tableSection = createTableSection(32); // 32 tables
    mainLayout->addWidget(tableSection);

    // Section Personnel
    auto *staffSection = createStaffSection();
    mainLayout->addWidget(staffSection);

    // Section Machines
    auto *machineSection = createMachineSection();
    mainLayout->addWidget(machineSection);

    // Section Statistiques
    auto *statisticsSection = createStatisticsSection();
    mainLayout->addWidget(statisticsSection);

    auto *contentWidget = new QWidget(this);
    auto *contentLayout = new QVBoxLayout(contentWidget);

    // Ajouter toutes les sections au layout du conteneur
    contentLayout->addWidget(tableSection);
    contentLayout->addWidget(staffSection);
    contentLayout->addWidget(machineSection);
    contentLayout->addWidget(statisticsSection);
    contentWidget->setLayout(contentLayout);

    // Ajoutez le conteneur au QScrollArea
    auto *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(contentWidget);

    mainLayout->addWidget(scrollArea);


    setLayout(mainLayout);



}

// Crée la section des tables
QWidget *RestaurantDashboard::createTableSection(int numTables) {
    auto *section = new QWidget();
    auto *layout = new QVBoxLayout(section);


    QLabel *titleLabel = new QLabel("État des Tables");
    titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    layout->addWidget(titleLabel);

    auto *grid = new QGridLayout();
    for (int i = 0; i < numTables; ++i) {
        QPushButton *tableButton = new QPushButton(QString("Table %1").arg(i + 1));
        tableButton->setFixedSize(100, 50);
        tableButton->setStyleSheet("background-color: #CCCCCC; color: black; font-weight: bold;"); // Non occupée
        tableButtons[i] = tableButton;
        grid->addWidget(tableButton, i / 8, i % 8); // 8 tables par ligne
    }
    layout->addLayout(grid);
    return section;
}

// Crée la section du personnel
QWidget *RestaurantDashboard::createStaffSection() {
    auto *section = new QWidget();
    auto *layout = new QVBoxLayout(section);

    QLabel *titleLabel = new QLabel("État du Personnel");
    titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    layout->addWidget(titleLabel);

    auto *grid = new QGridLayout();

    QMap<QString, int> staff = {
        {"Chef de rang 1", 1},{"Chef de rang 2", 1}, {"Serveur 2", 1}, {"Serveur 1", 1},{"Commis de salle", 1},{"Commis de salle", 1},
        {"Commis de cuisine", 1},{"Commis de cuisine", 1}, {"Chef de cuisine", 1}, {"Cuisinier", 1},{"Cuisinier", 1}, {"Plongeur", 1}, {"Maître d'hôtel", 1}
    };

    int row = 0;
    for (auto it = staff.begin(); it != staff.end(); ++it) {
        QLabel *roleLabel = new QLabel(it.key());
        roleLabel->setStyleSheet("font-size: 14px;");
        grid->addWidget(roleLabel, row, 0);

        QPushButton *statusButton = new QPushButton("Repos");
        statusButton->setFixedSize(100, 30);
        statusButton->setStyleSheet("background-color: #FF0000; color: white; font-weight: bold;");
        staffButtons[it.key()] = statusButton;
        grid->addWidget(statusButton, row, 1);
        ++row;
    }
    layout->addLayout(grid);
    return section;
}

// Crée la section des machines
QWidget *RestaurantDashboard::createMachineSection() {
    auto *section = new QWidget();
    auto *layout = new QVBoxLayout(section);

    QLabel *titleLabel = new QLabel("État des Machines");
    titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    layout->addWidget(titleLabel);

    QStringList machines = {"Lave-vaisselle", "Machine à laver"};
    for (const auto &machine : machines) {
        QLabel *machineLabel = new QLabel(machine);
        machineLabel->setStyleSheet("font-size: 14px;");

        QPushButton *statusButton = new QPushButton("Repos");
        statusButton->setFixedSize(100, 30);
        statusButton->setStyleSheet("background-color: #FF0000; color: white; font-weight: bold;");
        machineButtons[machine] = statusButton;

        auto *rowLayout = new QHBoxLayout();
        rowLayout->addWidget(machineLabel);
        rowLayout->addWidget(statusButton);
        layout->addLayout(rowLayout);
    }
    return section;
}

// Crée la section des statistiques
QWidget *RestaurantDashboard::createStatisticsSection() {
    auto *section = new QWidget();
    auto *layout = new QVBoxLayout(section);

    QLabel *titleLabel = new QLabel("Statistiques");
    titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    layout->addWidget(titleLabel);

    cleanDishesLabel = new QLabel("Assiettes propres : 0");
    dirtyDishesLabel = new QLabel("Assiettes sales : 0");
    pendingOrdersLabel = new QLabel("Commandes en cours : 0");

    cleanDishesLabel->setStyleSheet("font-size: 14px;");
    dirtyDishesLabel->setStyleSheet("font-size: 14px;");
    pendingOrdersLabel->setStyleSheet("font-size: 14px;");

    layout->addWidget(cleanDishesLabel);
    layout->addWidget(dirtyDishesLabel);
    layout->addWidget(pendingOrdersLabel);

    return section;
}

// Mise à jour de l’état des tables
void RestaurantDashboard::updateTableState(int tableIndex, const QString &state) {
    if (tableButtons.contains(tableIndex)) {
        QString color;
        if (state == "Non occupee") color = "#CCCCCC";
        else if (state == "En nettoyage") color = "#FFFF00";
        else if (state == "Occupee") color = "#00FF00";
        tableButtons[tableIndex]->setStyleSheet(QString("background-color: %1; color: black;").arg(color));
    }
}

// Mise à jour de l’état du personnel
void RestaurantDashboard::updateStaffState(const QString &role, bool isActive) {
    if (staffButtons.contains(role)) {
        staffButtons[role]->setText(isActive ? "Actif" : "Repos");
        staffButtons[role]->setStyleSheet(QString("background-color: %1; color: %2;")
                                              .arg(isActive ? "#00FF00" : "#FF0000")
                                              .arg(isActive ? "black" : "white"));
    }
}

// Mise à jour de l’état des machines
void RestaurantDashboard::updateMachineState(const QString &machineName, bool isActive) {
    if (machineButtons.contains(machineName)) {
        machineButtons[machineName]->setText(isActive ? "Actif" : "Repos");
        machineButtons[machineName]->setStyleSheet(QString("background-color: %1; color: %2;")
                                                       .arg(isActive ? "#00FF00" : "#FF0000")
                                                       .arg(isActive ? "black" : "white"));
    }
}

// Mise à jour des statistiques
void RestaurantDashboard::updateStatistics(int cleanDishes, int dirtyDishes, int pendingOrders) {
    cleanDishesLabel->setText(QString("Assiettes propres : %1").arg(cleanDishes));
    dirtyDishesLabel->setText(QString("Assiettes sales : %1").arg(dirtyDishes));
    pendingOrdersLabel->setText(QString("Commandes en cours : %1").arg(pendingOrders));
}


