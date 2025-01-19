#ifndef VILLE_H
#define VILLE_H
#include "batiment.h"
#include <vector>

class Ville {
private:
    std::string nom;
    double budget;
    int population;
    double satisfaction;
    double consommationEnergie; // Ajout de l'attribut
    std::vector<Batiment*> batiments;

public:
    Ville(std::string n, double b, int p, double s, std::vector<Batiment*> bat = {});
    ~Ville();

    void ajouterBatiment(Batiment* b);
    void supprimerBatiment(int id);
    double calculerConsommationTotale() const;
    double calculerSatisfaction() const;
    void afficherDetails() const;
    std::string getNom() const;
    double getBudget() const;
    int getPopulation() const;
    void setSatisfaction(double s);
    void setConsommationEnergie(double c);
};

#endif // VILLE_H
