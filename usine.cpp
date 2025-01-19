#include "usine.h"
#include <iostream>
Usine::Usine(int id, string n, string t, double cEau, double cElectricite, double ES, double PR, double P)
    : Batiment(id, n, t, cEau, cElectricite, ES), productionRessource(PR), pollution(P) {}

void Usine::afficherDetails() const {
    Batiment::afficherDetails();
    cout << "Production Ressource: " << productionRessource
         << "\nPollution: " << pollution << endl;
}

double Usine::calculerImpactRessources() const {
    return Batiment::calculerImpactRessources() + pollution;
}

double Usine::produireRessources() {
    return productionRessource;
}

double Usine::calculerPollution() const {
    return pollution;
}
