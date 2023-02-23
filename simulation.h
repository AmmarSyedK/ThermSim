#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QVector>

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = nullptr);

    // Function to simulate cooling time
    QVector<QPointF> runSimulation(QString material, QString type, QString treatment, double time, double temperature, QString shape, QVector<double> dimensions);

signals:

};

#endif // SIMULATION_H
