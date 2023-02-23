#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "display.h"
#include "simulation.h"
#include <QGraphicsSimpleTextItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Display display;
    ui->setupUi(this);
    // Adding material items for selection
    ui->materialComboBox->addItems(display.getMaterials());
    // Adding heat treatment items
    ui->treatmentComboBox->addItems(display.getHeatTreatments());
    // Adding material shape items
    ui->shapeComboBox->addItems(display.getMaterialShape());
    // Set the default value to "Steel"
    ui->typeComboBox->addItems(display.getTypes("Steel"));
    // Fill the typeComboBox dependinwg on the material
    connect(ui->materialComboBox, &QComboBox::currentTextChanged, this, &MainWindow::fillTypeComboBox);
    connect(ui->simButton, &QPushButton::clicked, this, &MainWindow::startSimulation);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTypeComboBox(QString material)
{
    QStringList types;

    Display display;
    types = display.getTypes(material);

    ui->typeComboBox->clear();
    ui->typeComboBox->addItems(types);
}

// Slot to start the simulation
void MainWindow::startSimulation()
{
    // Obtenir les paramètres d'entrée de l'interface utilisateur
    QString material = ui->materialComboBox->currentText();
    QString type = ui->typeComboBox->currentText();
    QString treatment = ui->treatmentComboBox->currentText();
    QString shape = ui->shapeComboBox->currentText();
    double time = ui->timeSpinBox->value();
    double temperature = ui->temperatureDoubleSpinBox->value();
    QVector<double> dimensions {ui->lengthDoubleSpinBox->value(), ui->widthDoubleSpinBox->value(), ui->heightDoubleSpinBox->value()};

    // Effectuer la simulation
    Simulation simulation;
    QVector<QPointF> data = simulation.runSimulation(material, type, treatment, time, temperature, shape, dimensions);

    // Ajouter une légende
    QFont font;
    font.setBold(true);
    font.setPointSize(12);
    QScopedPointer<QGraphicsScene> scene(new QGraphicsScene(this));
    scene->addSimpleText("Simulation results", font)->setPos(10, 10);

    QGraphicsSimpleTextItem *xAxisLegend = new QGraphicsSimpleTextItem();
    xAxisLegend->setText("Temps (s)");
    xAxisLegend->setPos(ui->graphicsView->width() - 60, ui->graphicsView->height() - 20);
    scene->addItem(xAxisLegend);

    QGraphicsSimpleTextItem *yAxisLegend = new QGraphicsSimpleTextItem();
    yAxisLegend->setText("Température (°C)");
    yAxisLegend->setPos(5, 5);
    scene->addItem(yAxisLegend);

    // Mettre à jour la vue graphique
    ui->graphicsView->setScene(scene.data());

    QPen pen(Qt::red);  // Exemple de stylo, à remplacer par le style souhaité
    for (int i = 0; i < data.size() - 1; i++) {
        scene->addLine(data[i].x(), data[i].y(), data[i+1].x(), data[i+1].y(), pen);
        ui->graphicsView->setScene(scene.data());          // Mettre à jour la vue graphique à chaque étape de la simulation
        QCoreApplication::processEvents();  // Permettre à l'interface utilisateur de répondre pendant la simulation
    }
}
