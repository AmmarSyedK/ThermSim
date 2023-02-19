#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fillTypeComboBox(QString material);

private:
    Ui::MainWindow *ui;
    QStringList materials = {"Steel", "Brass", "Aluminum"};
    QStringList heatTreatments = {"Quenching", "Annealing"};
    QStringList carbonTypes = {"Hypo-eutectoid", "Eutectoid", "Hyper-eutectoid"};

};
#endif // MAINWINDOW_H
