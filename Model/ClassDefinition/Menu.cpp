//
// Created by siefo on 10/12/2024.
//
#include "../classDeclaration/Menu.h"

Menu::Menu(int id, const std::string& date)
    : id(id), date(date) {}

void Menu::AjouterPlat(const Plat& plat) {
    plats.push_back(plat);
}