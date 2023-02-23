#include "simulation.h"
#include "qpoint.h"
#include <QtMath>

Simulation::Simulation(QObject *parent) : QObject(parent)
{

}

QVector<QPointF> Simulation::runSimulation(QString material, QString type, QString treatment, double time, double temperature, QString shape, QVector<double> dimensions)
{
    QVector<QPointF> data;
    double t = 0;
    double dt = 0.1;
    double T = temperature;
    while (T > 25 && t <= time) {
        // Effectuer le calcul de refroidissement en fonction des paramètres d'entrée
        double coolingRate = 0.5;  // Calculer le taux de refroidissement en fonction des paramètres d'entrée
        T -= coolingRate * dt;
        data.append(QPointF(t, T));  // Ajouter les données de simulation
        t += dt;
    }
    return data;
}

