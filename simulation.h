#ifndef SIMULATION_H
#define SIMULATION_H
#include "ville.h"
#include <cstdlib>
#include <ctime>

class Simulation {
private:
    Ville& ville;
    int cycleActuel;

public:
    Simulation(Ville& v, int cycle = 0);
    void demarrerCycle();
    void terminerCycle();
    void declencherEvenement();
    Ville& getVille();
};

#endif // SIMULATION_H
