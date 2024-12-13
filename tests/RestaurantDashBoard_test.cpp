#include <gtest/gtest.h>
#include <QtTest/QtTest>
#include "../View/RestaurantDashboard.h"

class TestRestaurantDashboard : public ::testing::Test {
protected:
    RestaurantDashboard *dashboard;

    // Configuration avant chaque test
    void SetUp() override {
        dashboard = new RestaurantDashboard();
    }

    // Nettoyage après chaque test
    void TearDown() override {
        delete dashboard;
    }
};

TEST_F(TestRestaurantDashboard, TestDashboardCreation) {
    // Vérification de la création de la fenêtre
    ASSERT_NE(dashboard, nullptr) << "La fenêtre 'RestaurantDashboard' n'a pas été créée.";

    // Vérification des composants de la fenêtre
    EXPECT_NE(dashboard->findChild<QLabel*>("cleanDishesLabel"), nullptr)
        << "Le label 'cleanDishesLabel' est manquant.";
    EXPECT_NE(dashboard->findChild<QLabel*>("dirtyDishesLabel"), nullptr)
        << "Le label 'dirtyDishesLabel' est manquant.";
    EXPECT_NE(dashboard->findChild<QLabel*>("pendingOrdersLabel"), nullptr)
        << "Le label 'pendingOrdersLabel' est manquant.";
}

TEST_F(TestRestaurantDashboard, TestUpdateTableState) {
    // Mise à jour de l'état d'une table
    dashboard->updateTableState(1, "Occupied");

    QPushButton *tableButton = dashboard->findChild<QPushButton*>("table_1");
    ASSERT_NE(tableButton, nullptr) << "Le bouton pour la table 1 est introuvable.";

    // Vérification que l'état de la table a bien été mis à jour
    EXPECT_EQ(tableButton->text(), QString("Occupied"))
        << "Le texte du bouton de la table 1 n'est pas 'Occupied'.";
}

TEST_F(TestRestaurantDashboard, TestUpdateStaffState) {
    // Mise à jour de l'état d'un membre du personnel
    dashboard->updateStaffState("Chef", true);

    QPushButton *staffButton = dashboard->findChild<QPushButton*>("staff_Chef");
    ASSERT_NE(staffButton, nullptr) << "Le bouton pour le personnel 'Chef' est introuvable.";

    // Vérification que l'état du personnel a bien été mis à jour
    EXPECT_EQ(staffButton->text(), QString("Active"))
        << "Le texte du bouton du personnel 'Chef' n'est pas 'Active'.";
}

TEST_F(TestRestaurantDashboard, TestUpdateMachineState) {
    // Mise à jour de l'état de la machine
    dashboard->updateMachineState("Dishwasher", false);

    QPushButton *machineButton = dashboard->findChild<QPushButton*>("machine_Dishwasher");
    ASSERT_NE(machineButton, nullptr) << "Le bouton pour la machine 'Dishwasher' est introuvable.";

    // Vérification que l'état de la machine a bien été mis à jour
    EXPECT_EQ(machineButton->text(), QString("Inactive"))
        << "Le texte du bouton de la machine 'Dishwasher' n'est pas 'Inactive'.";
}

TEST_F(TestRestaurantDashboard, TestUpdateStatistics) {
    // Mise à jour des statistiques
    dashboard->updateStatistics(10, 5, 3);

    QLabel *cleanDishesLabel = dashboard->findChild<QLabel*>("cleanDishesLabel");
    QLabel *dirtyDishesLabel = dashboard->findChild<QLabel*>("dirtyDishesLabel");
    QLabel *pendingOrdersLabel = dashboard->findChild<QLabel*>("pendingOrdersLabel");

    ASSERT_NE(cleanDishesLabel, nullptr) << "Le label 'cleanDishesLabel' est introuvable.";
    ASSERT_NE(dirtyDishesLabel, nullptr) << "Le label 'dirtyDishesLabel' est introuvable.";
    ASSERT_NE(pendingOrdersLabel, nullptr) << "Le label 'pendingOrdersLabel' est introuvable.";

    // Vérification des textes des labels
    EXPECT_EQ(cleanDishesLabel->text(), QString("Clean Dishes: 10"))
        << "Le texte du label 'cleanDishesLabel' est incorrect.";
    EXPECT_EQ(dirtyDishesLabel->text(), QString("Dirty Dishes: 5"))
        << "Le texte du label 'dirtyDishesLabel' est incorrect.";
    EXPECT_EQ(pendingOrdersLabel->text(), QString("Pending Orders: 3"))
        << "Le texte du label 'pendingOrdersLabel' est incorrect.";
}
