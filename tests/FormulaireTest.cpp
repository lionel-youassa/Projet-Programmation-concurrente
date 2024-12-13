#include <gtest/gtest.h>
#include <QSpinBox>
#include "../View/formulaire.h"

class TestFormulaire : public ::testing::Test {
protected:
    Formulaire *formulaire;

    // Setup avant chaque test
    void SetUp() override {
        formulaire = new Formulaire();
    }

    // Cleanup après chaque test
    void TearDown() override {
        delete formulaire;
    }
};

TEST_F(TestFormulaire, TestFormulaireCreation) {
    // Vérification de la création des champs
    EXPECT_NE(formulaire->findChild<QSpinBox*>("placeInput"), nullptr)
        << "Le champ 'placeInput' n'a pas été correctement créé.";
    EXPECT_NE(formulaire->findChild<QSpinBox*>("tableInput"), nullptr)
        << "Le champ 'tableInput' n'a pas été correctement créé.";
    EXPECT_NE(formulaire->findChild<QSpinBox*>("timeInput"), nullptr)
        << "Le champ 'timeInput' n'a pas été correctement créé.";
}
