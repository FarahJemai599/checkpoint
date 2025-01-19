
#ifndef BATIMENT_H
#define BATIMENT_H
#include <string>
#include <iostream>
using namespace std;

class Batiment
{
protected:
    int id;
    string nom;
    string type;
    double consommationEau;
    double consommationElectricite;
    double effetSatisfaction;

public:
    Batiment(int id, string n, string t, double cEau, double cElectricite, double ES);
    virtual ~Batiment() = default;

    virtual void afficherDetails() const;
    virtual double calculerImpactRessources() const;
    int getId() const;
    double getEffetSatisfaction() const;
};

#endif // BATIMENT_H_INCLUDED
