#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentGraph_ = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   // Controller::getSharedController()->RunTest();
}

void MainWindow::on_action_Load_Input_triggered()
{
    openFile();
}
void MainWindow::openFile()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open Document"),
                QDir::currentPath(),
                tr("Document files (*.txt);;All files (*.*)") );
    if( !filename.isNull() )
    {
        qDebug( filename.toAscii() );
        Controller::getSharedController()->ReadInput(filename.toStdString().c_str());
    }
}

void MainWindow::on_actionLinear_Regression_triggered()
{
    vector<Point>pnts = Controller::getSharedController()->applyCurveFitting(LINEAR_REG);

    // create graph and assign data to it:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->legend->setPositionStyle(QCPLegend::psRight);
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    QVector<double> x(pnts.size()), y(pnts.size());
    for (int i=0; i<pnts.size(); i++)
    {
        x[i] = pnts[i].getX();
        y[i] = pnts[i].getY();
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(currentGraph_)->setName("Fit");
    ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
    ui->customPlot->graph(currentGraph_)->setScatterSize(pnts.size());
    ui->customPlot->graph(currentGraph_)->setData(x,y);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->graph(currentGraph_)->rescaleAxes(true);

   // ui->customPlot->xAxis->setRange(-10, 10);
  //  ui->customPlot->yAxis->setRange(-10, 10);



  QPen pen;

  ui->customPlot->addGraph();
  currentGraph_++;

  pen.setColor(QColor(0, 255,0));
  ui->customPlot->graph(currentGraph_)->setPen(pen);
  ui->customPlot->graph(currentGraph_)->setName("Original Points");
  ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsNone);
  ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
  ui->customPlot->graph(currentGraph_)->setScatterSize(Controller::getSharedController()->getInputPoints().size());
  // generate data:
  QVector<double> originalx(Controller::getSharedController()->getInputPoints().size()), originaly(Controller::getSharedController()->getInputPoints().size());
  for (int j=0; j<Controller::getSharedController()->getInputPoints().size(); j++)
  {
      originalx[j] = Controller::getSharedController()->getInputPoints()[j].getX();
      originaly[j] = Controller::getSharedController()->getInputPoints()[j].getY();
  }
  ui->customPlot->graph(currentGraph_)->setData(originalx, originaly);
  ui->customPlot->graph()->rescaleAxes(true);

  ui->customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setInteraction(QCustomPlot::iSelectPlottables);

  ui->customPlot->replot();
  currentGraph_++;

}

void MainWindow::on_actionQuit_triggered()
{
    delete Controller::getSharedController();
    QApplication::quit();
}

void MainWindow::on_actionPolynominal_Regression_triggered()
{
    vector<Point>pnts = Controller::getSharedController()->applyCurveFitting(POLY_REG);

    // create graph and assign data to it:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->legend->setPositionStyle(QCPLegend::psRight);
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    QVector<double> x(pnts.size()), y(pnts.size());
    for (int i=0; i<pnts.size(); i++)
    {
        x[i] = pnts[i].getX();
        y[i] = pnts[i].getY();
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(currentGraph_)->setName("Fit");
    ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
    ui->customPlot->graph(currentGraph_)->setScatterSize(pnts.size());
    ui->customPlot->graph(currentGraph_)->setData(x,y);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->graph(currentGraph_)->rescaleAxes(true);

   // ui->customPlot->xAxis->setRange(-10, 10);
  //  ui->customPlot->yAxis->setRange(-10, 10);



  QPen pen;

  ui->customPlot->addGraph();
  currentGraph_++;

  pen.setColor(QColor(0, 255,0));
  ui->customPlot->graph(currentGraph_)->setPen(pen);
  ui->customPlot->graph(currentGraph_)->setName("Original Points");
  ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsNone);
  ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
  ui->customPlot->graph(currentGraph_)->setScatterSize(Controller::getSharedController()->getInputPoints().size());
  // generate data:
  QVector<double> originalx(Controller::getSharedController()->getInputPoints().size()), originaly(Controller::getSharedController()->getInputPoints().size());
  for (int j=0; j<Controller::getSharedController()->getInputPoints().size(); j++)
  {
      originalx[j] = Controller::getSharedController()->getInputPoints()[j].getX();
      originaly[j] = Controller::getSharedController()->getInputPoints()[j].getY();
  }
  ui->customPlot->graph(currentGraph_)->setData(originalx, originaly);
  ui->customPlot->graph()->rescaleAxes(true);

  ui->customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setInteraction(QCustomPlot::iSelectPlottables);

  ui->customPlot->replot();
  currentGraph_++;

}

void MainWindow::on_actionNewton_Interpolation_triggered()
{
    vector<Point>pnts = Controller::getSharedController()->Controller::applyNewtonInterpol();

    // create graph and assign data to it:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->legend->setPositionStyle(QCPLegend::psRight);
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    QVector<double> x(pnts.size()), y(pnts.size());
    for (int i=0; i<pnts.size(); i++)
    {
        x[i] = pnts[i].getX();
        y[i] = pnts[i].getY();
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(currentGraph_)->setName("Fit");
    ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
    ui->customPlot->graph(currentGraph_)->setScatterSize(pnts.size());
    ui->customPlot->graph(currentGraph_)->setData(x,y);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->graph(currentGraph_)->rescaleAxes(true);

   // ui->customPlot->xAxis->setRange(-10, 10);
  //  ui->customPlot->yAxis->setRange(-10, 10);



  QPen pen;

  ui->customPlot->addGraph();
  currentGraph_++;
  pen.setColor(QColor(0, 255,0));
  ui->customPlot->graph(currentGraph_)->setPen(pen);
  ui->customPlot->graph(currentGraph_)->setName("Original Points");
  ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsNone);
  ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
  ui->customPlot->graph(currentGraph_)->setScatterSize(Controller::getSharedController()->getInputPoints().size());
  // generate data:
  QVector<double> originalx(Controller::getSharedController()->getInputPoints().size()), originaly(Controller::getSharedController()->getInputPoints().size());
  for (int j=0; j<Controller::getSharedController()->getInputPoints().size(); j++)
  {
      originalx[j] = Controller::getSharedController()->getInputPoints()[j].getX();
      originaly[j] = Controller::getSharedController()->getInputPoints()[j].getY();
  }
  ui->customPlot->graph(currentGraph_)->setData(originalx, originaly);
  ui->customPlot->graph()->rescaleAxes(true);

  ui->customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setInteraction(QCustomPlot::iSelectPlottables);

  ui->customPlot->replot();

  currentGraph_++;

}

void MainWindow::on_actionCubic_Splines_triggered()
{
    vector<Point>pnts = Controller::getSharedController()->Controller::applyCubicSpline();

    // create graph and assign data to it:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->legend->setPositionStyle(QCPLegend::psRight);
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    QVector<double> x(pnts.size()), y(pnts.size());
    for (int i=0; i<pnts.size(); i++)
    {
        x[i] = pnts[i].getX();
        y[i] = pnts[i].getY();
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(currentGraph_)->setName("Fit");
    ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
    ui->customPlot->graph(currentGraph_)->setScatterSize(pnts.size());
    ui->customPlot->graph(currentGraph_)->setData(x,y);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->graph(currentGraph_)->rescaleAxes(true);

   // ui->customPlot->xAxis->setRange(-10, 10);
  //  ui->customPlot->yAxis->setRange(-10, 10);



  QPen pen;

  ui->customPlot->addGraph();
  currentGraph_++;
  pen.setColor(QColor(0, 255,0));
  ui->customPlot->graph(currentGraph_)->setPen(pen);
  ui->customPlot->graph(currentGraph_)->setName("Original Points");
  ui->customPlot->graph(currentGraph_)->setLineStyle(QCPGraph::lsNone);
  ui->customPlot->graph(currentGraph_)->setScatterStyle(QCP::ssCross);
  ui->customPlot->graph(currentGraph_)->setScatterSize(Controller::getSharedController()->getInputPoints().size());
  // generate data:
  QVector<double> originalx(Controller::getSharedController()->getInputPoints().size()), originaly(Controller::getSharedController()->getInputPoints().size());
  for (int j=0; j<Controller::getSharedController()->getInputPoints().size(); j++)
  {
      originalx[j] = Controller::getSharedController()->getInputPoints()[j].getX();
      originaly[j] = Controller::getSharedController()->getInputPoints()[j].getY();
  }
  ui->customPlot->graph(currentGraph_)->setData(originalx, originaly);
  ui->customPlot->graph()->rescaleAxes(true);

  ui->customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setInteraction(QCustomPlot::iSelectPlottables);

  ui->customPlot->replot();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("About");
    msgBox.setInformativeText("CurveFitter v1.0\nTeam Members:\nAbdelrahman Mohamed \nAhmed Naglah");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
        //int ret =
    msgBox.exec();
}

void MainWindow::on_actionClear_triggered()
{
    currentGraph_=0;
    ui->customPlot->clearGraphs();
}
