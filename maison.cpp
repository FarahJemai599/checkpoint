#include "maison.h"
#include <iostream>
Maison::Maison(int id, string n, string t, double cEau, double cElectricite, double ES, int cHabitants, int habitantsA)
    : Batiment(id, n, t, cEau, cElectricite, ES), capaciteHabitants(cHabitants), habitantsActuels(habitantsA) {}

void Maison::ajouterHabitants(int nb) {
    if (habitantsActuels + nb <= capaciteHabitants) {
        habitantsActuels += nb;
    } else {
        cout << "Capacité maximale atteinte." << endl;
    }
}

void Maison::retirerHabitants(int nb) {
    if (habitantsActuels - nb >= 0) {
        habitantsActuels -= nb;
    } else {
        cout << "Impossible de retirer autant d'habitants." << endl;
    }
}

void Maison::afficherDetails() const {
    Batiment::afficherDetails();
    cout << "Capacité: " << capaciteHabitants
         << ", Habitants Actuels: " << habitantsActuels << endl;
}

double Maison::calculerImpactRessources() const {
    return Batiment::calculerImpactRessources();
}
