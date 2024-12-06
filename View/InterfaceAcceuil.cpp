#include "formulaire.h"

Formulaire::Formulaire(QWidget *parent) : QWidget(parent) {
    auto *mainLayout = new QVBoxLayout(this);

    // Création et configuration du formulaire
    auto *formLayout = new QFormLayout();
    setupFormLayout(formLayout);
    mainLayout->addLayout(formLayout);

    // Bouton de démarrage
    setupStartButton(mainLayout);

    // Style général de la fenêtre
    setStyleSheet("background-color: #FDF5E6;");
    setLayout(mainLayout);
    setWindowTitle("Formulaire de simulation");
    resize(400, 300);
}

void Formulaire::setupFormLayout(QFormLayout *formLayout) {
    QString inputStyle = "padding: 8px; border: 1px solid #8B4513; border-radius: 5px; background-color: #FFF8DC; font-size: 14px;";
    QString labelStyle = "font-size: 16px; font-weight: bold; color: #8B4513;";

    // Champ : Nombre de clients
    placeInput = new QSpinBox();
    placeInput->setMinimum(1);
    placeInput->setMaximum(50);
    placeInput->setValue(4);
    placeInput->setStyleSheet(inputStyle);
    auto *placeLabel = new QLabel("Nombre de clients :");
    placeLabel->setStyleSheet(labelStyle);
    formLayout->addRow(placeLabel, placeInput);

    // Champ : Nombre de vagues
    tableInput = new QSpinBox();
    tableInput->setMinimum(1);
    tableInput->setMaximum(100);
    tableInput->setValue(1);
    tableInput->setStyleSheet(inputStyle);
    auto *tableLabel = new QLabel("Nombre de vagues :");
    tableLabel->setStyleSheet(labelStyle);
    formLayout->addRow(tableLabel, tableInput);

    // Champ : Temps de simulation
    timeInput = new QSpinBox();
    timeInput->setMinimum(1);
    timeInput->setMaximum(120);
    timeInput->setValue(10);
    timeInput->setStyleSheet(inputStyle);
    auto *timeLabel = new QLabel("Temps de simulation (min) :");
    timeLabel->setStyleSheet(labelStyle);
    formLayout->addRow(timeLabel, timeInput);
}

void Formulaire::setupStartButton(QVBoxLayout *mainLayout) {
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
}
