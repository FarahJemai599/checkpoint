#ifndef PARC_H
#define PARC_H
#include "batiment.h"

class Parc : public Batiment {
private:
    double surface;
    double effetBienEtre;

public:
    Parc(int id, string n, string t, double cEau, double cElectricite, double ES, double S, double eBE);
    void afficherDetails() const override;
    double calculerImpactRessources() const override;
    void ameliorerBienEtre();
};

#endif // PARC_H
