#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "display.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Display display;
    ui->setupUi(this);
    // Adding material items for selection
    ui->materialComboBox->addItems(display.getArray(materials));
    // Adding heat treatment items
    ui->treatmentComboBox->addItems(display.getArray(heatTreatments));
    // Set the default value to "Steel"
    ui->typeComboBox->addItems(display.getTypes("Steel"));
    // Fill the typeComboBox depending on the material
    connect(ui->materialComboBox, &QComboBox::currentTextChanged, this, &MainWindow::fillTypeComboBox);

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
