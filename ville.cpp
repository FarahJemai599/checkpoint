#include "ville.h"
#include <iostream>

Ville::Ville(std::string n, double b, int p, double s, std::vector<Batiment*> bat)
    : nom(n), budget(b), population(p), satisfaction(s), consommationEnergie(0), batiments(bat) {}

Ville::~Ville() {
    for (auto b : batiments) delete b;
}

void Ville::ajouterBatiment(Batiment* b) {
    batiments.push_back(b);
    std::cout << "Bâtiment ajouté." << std::endl;
}

void Ville::supprimerBatiment(int id) {
    for (auto it = batiments.begin(); it != batiments.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            batiments.erase(it);
            std::cout << "Bâtiment supprimé." << std::endl;
            return;
        }
    }
    std::cout << "Aucun bâtiment trouvé avec cet ID." << std::endl;
}

double Ville::calculerConsommationTotale() const {
    double total = 0;
    for (auto b : batiments) {
        total += b->calculerImpactRessources();
    }
    return total;
}

double Ville::calculerSatisfaction() const {
    double total = satisfaction;
    for (auto b : batiments) {
        total += b->getEffetSatisfaction();
    }
    return total;
}

void Ville::afficherDetails() const {
    std::cout << "Ville: " << nom
              << "\nBudget: " << budget
              << "\nPopulation: " << population
              << "\nSatisfaction: " << satisfaction
              << "\nConsommation d'énergie: " << consommationEnergie << std::endl;
    for (auto b : batiments) {
        b->afficherDetails();
    }
}

std::string Ville::getNom() const {
    return nom;
}

double Ville::getBudget() const {
    return budget;
}

int Ville::getPopulation() const {
    return population;
}

void Ville::setSatisfaction(double s) {
    satisfaction = s;
}

void Ville::setConsommationEnergie(double c) {
    consommationEnergie = c;
}
