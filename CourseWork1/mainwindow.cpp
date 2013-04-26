#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->customPlot->graph(0)->setName("Fit");
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setScatterStyle(QCP::ssCross);
    ui->customPlot->graph(0)->setScatterSize(pnts.size());
    ui->customPlot->graph(0)->setData(x,y);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->graph(0)->rescaleAxes(true);

   // ui->customPlot->xAxis->setRange(-10, 10);
  //  ui->customPlot->yAxis->setRange(-10, 10);



  QPen pen;

  ui->customPlot->addGraph();
  pen.setColor(QColor(0, 255,0));
  ui->customPlot->graph(1)->setPen(pen);
  ui->customPlot->graph(1)->setName("Original Points");
  ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
  ui->customPlot->graph(1)->setScatterStyle(QCP::ssCross);
  ui->customPlot->graph(1)->setScatterSize(Controller::getSharedController()->getInputPoints().size());
  // generate data:
  QVector<double> originalx(Controller::getSharedController()->getInputPoints().size()), originaly(Controller::getSharedController()->getInputPoints().size());
  for (int j=0; j<Controller::getSharedController()->getInputPoints().size(); j++)
  {
      originalx[j] = Controller::getSharedController()->getInputPoints()[j].getX();
      originaly[j] = Controller::getSharedController()->getInputPoints()[j].getY();
  }
  ui->customPlot->graph(1)->setData(originalx, originaly);
  ui->customPlot->graph()->rescaleAxes(true);

  ui->customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);
  ui->customPlot->setInteraction(QCustomPlot::iSelectPlottables);

  ui->customPlot->replot();
}
