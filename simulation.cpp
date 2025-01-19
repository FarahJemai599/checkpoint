#include "simulation.h"
#include <iostream>
#include <ctime>
using namespace std;
Simulation::Simulation(Ville& v, int cycle) : ville(v), cycleActuel(cycle) {
    srand(time(0));
}

void Simulation::demarrerCycle() {
    cout << "Cycle " << cycleActuel << " démarré." << endl;
    double consommation = ville.calculerConsommationTotale();
    double satisfaction= ville.calculerSatisfaction();
    cout << "Consommation totale: " << consommation << endl;
    cout <<"Satisfaction totale: "<< satisfaction<<endl;

    cycleActuel++;
}
void Simulation::terminerCycle(){
    cout<<"Cycle "<< cycleActuel<<" terminer"<<endl;
}

void Simulation::declencherEvenement() {
    std::srand(std::time(nullptr));
    int eventID = std::rand() % 5;

    switch (eventID) {
    case 0: {
        std::cout << "Une nuée de pigeons géants envahit votre ville !" << std::endl;
        double satisfaction = ville.calculerSatisfaction() - 15;
        ville.setSatisfaction(satisfaction); // Appliquer la modification
        break;
    }
    case 1: {
        std::cout << "Une panne de courant fait grimper la consommation d’énergie de 50 %." << std::endl;
        double consommationEnergie = ville.calculerConsommationTotale() * 1.5;
        ville.setConsommationEnergie(consommationEnergie); // Appliquer la modification
        break;
    }
    case 2: {
        std::cout << "Les jardiniers de la ville sont en grève !" << std::endl;
        double satisfaction = ville.calculerSatisfaction() - 20;
        ville.setSatisfaction(satisfaction); // Appliquer la modification
        break;
    }
    case 3: {
        std::cout << "Une panne géante de transports publics bloque la ville !" << std::endl;
        double satisfaction = ville.calculerSatisfaction() - 30;
        ville.setSatisfaction(satisfaction); // Appliquer la modification
        break;
    }
    case 4: {
        std::cout << "Une tempête de neige imprévue bloque les routes et les usines." << std::endl;
        double satisfaction = ville.calculerSatisfaction() - 10;
        ville.setSatisfaction(satisfaction); // Appliquer la modification
        break;
    }
    default:
        std::cout << "Aucun événement ne s'est produit." << std::endl;
    }
}
Ville& Simulation::getVille() {
    return ville;
}
