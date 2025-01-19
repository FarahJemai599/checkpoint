#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <iostream>
#include "ville.h"
#include "simulation.h"
#include "batiment.h"
#include "maison.h"
#include "usine.h"
#include "parc.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAjouterBatiment();
    void onSupprimerBatiment();
    void onAfficherDetails();
    void onDemarrerCycle();
    void onDeclencherEvenement();

private:

    // Composants de l'interface
    QPushButton *ajouterBatimentButton;
    QPushButton *supprimerBatimentButton;
    QPushButton *afficherDetailsButton;
    QPushButton *demarrerCycleButton;
    QPushButton *declencherEvenementButton;
    QLineEdit *idInput;
    QLineEdit *nomInput;
    QLineEdit *typeInput;
    QLineEdit *consommationEauInput;
    QLineEdit *consommationElectriciteInput;
    QLineEdit *effetSatisfactionInput;
    QLabel *statusLabel;
    QListWidget *batimentsListWidget;

    // Objets Ville et Simulation
    Ville ville;
    Simulation simulation;
};

#endif // MAINWINDOW_H
