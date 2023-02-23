#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>

class Display : public QObject
{
    Q_OBJECT
public:
    explicit Display(QObject *parent = nullptr);

    QStringList getTypes(const QString &material);
    QStringList getMaterials();
    QStringList getHeatTreatments();
    QStringList getMaterialShape();

private:
    QStringList m_steelTypes;
    QStringList m_brassTypes;
    QStringList m_aluminumTypes;
    QStringList materials;
    QStringList heatTreatments;
    QStringList materialShape;
};

#endif // DISPLAY_H
