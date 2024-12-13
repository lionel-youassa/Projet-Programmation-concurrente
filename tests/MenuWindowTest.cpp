#include <gtest/gtest.h>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "../View/MenuWindows.h"

class TestMenuWindow : public ::testing::Test {
protected:
    MenuWindow *menuWindow;

    // Configuration avant chaque test
    void SetUp() override {
        menuWindow = new MenuWindow();
    }

    // Nettoyage après chaque test
    void TearDown() override {
        delete menuWindow;
    }
};

TEST_F(TestMenuWindow, TestWindowCreation) {
    // Vérification de la création de la fenêtre
    ASSERT_NE(menuWindow, nullptr) << "La fenêtre 'MenuWindow' n'a pas été créée.";

    // Vérification des composants de la fenêtre
    EXPECT_NE(menuWindow->findChild<QLabel*>("menuTitleLabel"), nullptr)
        << "Le label 'menuTitleLabel' est manquant.";
    EXPECT_NE(menuWindow->findChild<QGridLayout*>("menuLayout"), nullptr)
        << "Le layout 'menuLayout' est manquant.";
    EXPECT_NE(menuWindow->findChild<QPushButton*>("closeButton"), nullptr)
        << "Le bouton 'closeButton' est manquant.";
}

TEST_F(TestMenuWindow, TestDisplayMenu) {
    // Simuler des plats à afficher
    QList<Dish> dishes = {
        {"Pizza", "/path/to/pizza.png"},
        {"Burger", "/path/to/burger.png"},
        {"Pasta", "/path/to/pasta.png"}
    };

    menuWindow->displayMenu(dishes);

    // Vérification du layout
    QGridLayout *layout = menuWindow->findChild<QGridLayout*>("menuLayout");
    ASSERT_NE(layout, nullptr) << "Le layout 'menuLayout' est introuvable.";

    // Vérification des plats affichés
    int dishCount = 0;
    for (const Dish &dish : dishes) {
        QLabel *dishLabel = menuWindow->findChild<QLabel*>(dish.name);
        ASSERT_NE(dishLabel, nullptr) << "Le label pour le plat '" << dish.name.toStdString() << "' est introuvable.";
        EXPECT_EQ(dishLabel->text(), dish.name)
            << "Le texte du label pour le plat '" << dish.name.toStdString() << "' est incorrect.";
        dishCount++;
    }

    EXPECT_EQ(dishCount, dishes.size()) << "Le nombre de plats affichés est incorrect.";
}
