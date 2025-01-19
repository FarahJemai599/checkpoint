#ifndef MAISON_H
#define MAISON_H
#include "batiment.h"

class Maison : public Batiment {
private:
    int capaciteHabitants;
    int habitantsActuels;

public:
    Maison(int id, string n, string t, double cEau, double cElectricite, double ES, int cHabitants, int habitantsA);
    void ajouterHabitants(int nb);
    void retirerHabitants(int nb);
    void afficherDetails() const override;
    double calculerImpactRessources() const override;
};
#endif // MAISON_H_INCLUDED
