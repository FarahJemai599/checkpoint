#include "mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),ville("Ville Virtuelle", 10000, 0, 0), simulation(ville, 0)
{
    // Initialisation des composants de l'interface
    ajouterBatimentButton = new QPushButton("Ajouter un Bâtiment");
    supprimerBatimentButton = new QPushButton("Supprimer un Bâtiment");
    afficherDetailsButton = new QPushButton("Afficher les Détails");
    demarrerCycleButton = new QPushButton("Démarrer un Cycle");
    declencherEvenementButton = new QPushButton("Déclencher un Événement");

    idInput = new QLineEdit;
    nomInput = new QLineEdit;
    typeInput = new QLineEdit;
    consommationEauInput = new QLineEdit;
    consommationElectriciteInput = new QLineEdit;
    effetSatisfactionInput = new QLineEdit;

    statusLabel = new QLabel("État : En attente...");
    batimentsListWidget = new QListWidget();

    // Disposition de l'interface
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("ID", idInput);
    formLayout->addRow("Nom", nomInput);
    formLayout->addRow("Type", typeInput);
    formLayout->addRow("Consommation d'eau", consommationEauInput);
    formLayout->addRow("Consommation d'électricité", consommationElectriciteInput);
    formLayout->addRow("Effet Satisfaction", effetSatisfactionInput);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(ajouterBatimentButton);
    mainLayout->addWidget(supprimerBatimentButton);
    mainLayout->addWidget(afficherDetailsButton);
    mainLayout->addWidget(demarrerCycleButton);
    mainLayout->addWidget(declencherEvenementButton);
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(batimentsListWidget);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connecter les boutons aux slots
    connect(ajouterBatimentButton, &QPushButton::clicked, this, &MainWindow::onAjouterBatiment);
    connect(supprimerBatimentButton, &QPushButton::clicked, this, &MainWindow::onSupprimerBatiment);
    connect(afficherDetailsButton, &QPushButton::clicked, this, &MainWindow::onAfficherDetails);
    connect(demarrerCycleButton, &QPushButton::clicked, this, &MainWindow::onDemarrerCycle);
    connect(declencherEvenementButton, &QPushButton::clicked, this, &MainWindow::onDeclencherEvenement);
}

MainWindow::~MainWindow() {
    // Destructeur
}

void MainWindow::onAjouterBatiment() {
    bool ok;
    int id = idInput->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    QString nom = nomInput->text();
    QString type = typeInput->text();
    double consommationEau = consommationEauInput->text().toDouble();
    double consommationElectricite = consommationElectriciteInput->text().toDouble();
    double effetSatisfaction = effetSatisfactionInput->text().toDouble();

    // Ajouter un bâtiment à la ville selon le type
    if (type == "Maison") {
        Maison* maison = new Maison(id, nom.toStdString(), type.toStdString(), consommationEau, consommationElectricite, effetSatisfaction, 4, 2);
        ville.ajouterBatiment(maison);
    } else if (type == "Usine") {
        Usine* usine = new Usine(id, nom.toStdString(), type.toStdString(), consommationEau, consommationElectricite, effetSatisfaction, 100, 50);
        ville.ajouterBatiment(usine);
    } else if (type == "Parc") {
        Parc* parc = new Parc(id, nom.toStdString(), type.toStdString(), consommationEau, consommationElectricite, effetSatisfaction, 200, 10);
        ville.ajouterBatiment(parc);
    }

    statusLabel->setText("Bâtiment ajouté.");
    ville.afficherDetails();
}

void MainWindow::onSupprimerBatiment() {
    bool ok;
    int id = idInput->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    ville.supprimerBatiment(id);
    statusLabel->setText("Bâtiment supprimé.");
    ville.afficherDetails();
}

void MainWindow::onAfficherDetails() {
    ville.afficherDetails();
}

void MainWindow::onDemarrerCycle() {
    simulation.demarrerCycle();
}

void MainWindow::onDeclencherEvenement() {
    simulation.declencherEvenement();
}
