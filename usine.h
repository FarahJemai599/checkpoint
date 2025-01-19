#ifndef USINE_H
#define USINE_H
#include "batiment.h"

class Usine : public Batiment {
private:
    double productionRessource;
    double pollution;

public:
    Usine(int id, string n, string t, double cEau, double cElectricite, double ES, double PR, double P);
    void afficherDetails() const override;
    double calculerImpactRessources() const override;
    double produireRessources();
    double calculerPollution() const;
};
#endif // USINE_H_INCLUDED
