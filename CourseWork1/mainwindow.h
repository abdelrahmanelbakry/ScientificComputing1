#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_action_Load_Input_triggered();

    void on_actionLinear_Regression_triggered();

    void on_actionQuit_triggered();

    void on_actionPolynominal_Regression_triggered();

    void on_actionNewton_Interpolation_triggered();

    void on_actionCubic_Splines_triggered();

    void on_actionAbout_triggered();

    void on_actionClear_triggered();

private:
    Ui::MainWindow *ui;
    void openFile();
    int currentGraph_;
};

#endif // MAINWINDOW_H
