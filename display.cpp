#include "display.h"

Display::Display(QObject *parent)
    : QObject{parent}
{
    // Initializing the data

    // Materials
    materials = {"Steel", "Brass", "Aluminum"};
    // Heat treatments
    heatTreatments = {"Quenching", "Annealing"};
    // Types available for each material
    m_steelTypes = {"Hypo-eutectoid", "Eutectoid", "Hyper-eutectoid"};
    m_brassTypes = {"Alpha", "Beta", "Gamma"};
    m_aluminumTypes = {"2000 series", "6000 series", "7000 series"};
}

QStringList Display::getArray(QStringList array)
{
    // Return the list of available materials
    return array;
}

QStringList Display::getHeatTreatments()
{
    // Return the list of available heat treatments
    return heatTreatments;
}

QStringList Display::getTypes(const QString &material)
{
    // Return the list of available types for the given material
    if (material == "Steel") {
        return m_steelTypes;
    } else if (material == "Brass") {
        return m_brassTypes;
    } else if (material == "Aluminum") {
        return m_aluminumTypes;
    } else {
        return {};
    }
}
