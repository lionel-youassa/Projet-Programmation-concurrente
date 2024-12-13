#include <gtest/gtest.h>
#include "../Controller/Factory.h"

class TestFactory : public ::testing::Test {
protected:
    Factory *factory;

    // Setup avant chaque test
    void SetUp() override {
        factory = new Factory();
    }

    // Cleanup après chaque test
    void TearDown() override {
        delete factory;
    }
};

TEST_F(TestFactory, TestCreaTable) {
    factory->creaTable();
    EXPECT_FALSE(factory->tables.empty()) << "La liste des tables ne devrait pas être vide après creaTable.";
}

TEST_F(TestFactory, TestGetTable) {
    factory->creaTable();
    std::vector<Table> tables = factory->get_table_();
    EXPECT_EQ(tables.size(), factory->tables.size()) << "La taille des tables retournées ne correspond pas.";
    EXPECT_FALSE(tables.empty()) << "La liste des tables retournées ne devrait pas être vide.";
}
