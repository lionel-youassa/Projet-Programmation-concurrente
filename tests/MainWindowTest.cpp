#include <gtest/gtest.h>
#include <QLabel>
#include <QToolBar>
#include "../View/MainWindow.h"

class TestMainWindow : public ::testing::Test {
protected:
    MainWindow *mainWindow;

    // Configuration avant chaque test
    void SetUp() override {
        mainWindow = new MainWindow();
    }

    // Nettoyage après chaque test
    void TearDown() override {
        delete mainWindow;
    }
};

TEST_F(TestMainWindow, TestMainWindowCreation) {
    // Vérification de la création de la fenêtre principale
    ASSERT_NE(mainWindow, nullptr) << "La fenêtre principale n'a pas été créée.";

    // Vérification des widgets spécifiques
    EXPECT_NE(mainWindow->findChild<QLabel*>("countdownLabel"), nullptr)
        << "Le widget 'countdownLabel' n'a pas été trouvé dans la fenêtre principale.";

    EXPECT_EQ(mainWindow->findChild<QToolBar*>("navbar"), nullptr)
        << "Une 'navbar' a été trouvée, mais elle ne devrait pas exister.";
}
