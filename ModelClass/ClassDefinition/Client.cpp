#include "../classDeclaration/Client.h"
#include "../classDeclaration/Plat.h"

Client::Client(int id, const std::string& type)
    : id(id), type(type) {}

// Méthode pour commander un plat
Plat Client::Commander(Menu& menu) {
    // Simulation : récupérer un plat dans le menu
    // (Cette implémentation peut être ajustée en fonction des exigences spécifiques)
    Plat plat = menu.GetPlatDisponible(); // Appel fictif pour un plat disponible
    return plat;
}
