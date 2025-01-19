#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Initialisation de l'application Qt

    MainWindow window; // Création de la fenêtre principale
    window.show(); // Affichage de la fenêtre

    return app.exec(); // Lancement de la boucle d'événements
}
