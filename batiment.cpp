#include "batiment.h"
#include <iostream>

Batiment::Batiment(int id, string n, string t, double cEau, double cElectricite, double ES)
    : id(id), nom(n), type(t), consommationEau(cEau), consommationElectricite(cElectricite), effetSatisfaction(ES) {}

void Batiment::afficherDetails() const {
    cout << "ID: " << id << "\nNom: " << nom << "\nType: " << type << endl;
}

double Batiment::calculerImpactRessources() const {
    return consommationEau + consommationElectricite;
}

int Batiment::getId() const {
    return id;
}

double Batiment::getEffetSatisfaction() const {
    return effetSatisfaction;
}

