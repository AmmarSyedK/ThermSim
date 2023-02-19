#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>

class Display : public QObject
{
    Q_OBJECT
public:
    explicit Display(QObject *parent = nullptr);

    QStringList getMaterials();
    QStringList getHeatTreatments();
    QStringList getTypes(const QString &material);
    QStringList getArray(QStringList array);

private:
    QStringList materials;
    QStringList heatTreatments;
    QStringList m_steelTypes;
    QStringList m_brassTypes;
    QStringList m_aluminumTypes;
};

#endif // DISPLAY_H
