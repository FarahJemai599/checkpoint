#include "parc.h"
#include <iostream>

Parc::Parc(int id, string n, string t, double cEau, double cElectricite, double ES, double S, double eBE)
    : Batiment(id, n, t, cEau, cElectricite, ES), surface(S), effetBienEtre(eBE) {}

void Parc::afficherDetails() const {
    Batiment::afficherDetails();
    cout << "Surface: " << surface << "\nEffet Bien-Être: " << effetBienEtre << endl;
}

double Parc::calculerImpactRessources() const {
    return Batiment::calculerImpactRessources();
}

void Parc::ameliorerBienEtre() {
    cout << "Le parc améliore le bien-être de : " << effetBienEtre << " points." << endl;
}
