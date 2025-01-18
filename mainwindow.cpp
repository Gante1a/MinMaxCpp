#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chrt = new QChart;
    ui->vchrt->setChart(chrt);
    chrt->setTitle("4x-log(x)");
    chrt->legend()->hide();
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(1, 4);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-2, 20);

    QLineSeries* series1 = new QLineSeries();
    for(int i=-1000; i<1000; i++)
    {
        series1->append(i, 4*i-log(i));
    }


    chrt->addSeries(series1);
    chrt->setAxisX(axisX, series1);
    chrt->setAxisY(axisY, series1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

double function(double x) {
    return 4*x - log(x);}

void MainWindow::on_pushButton_clicked()
{
    QString a1 = ui->lineEdit->text();
    double a;
    a=a1.toDouble();
    QString b1 = ui->lineEdit_2->text();
    double b;
    b=b1.toDouble();
    QString e1 = ui->lineEdit_3->text();
    double e;
    e=e1.toDouble();
    double x1;
    double x2;
    x1 = a + (1 - 0.618) * (b - a);
    x2 = a + 0.618 * (b - a);
    double xf1;
    double xf2;
    xf1 = function(x1);
    xf2 = function(x2);
    P:
    if(xf1 >= xf2)
            {
                    a = x1;
                    x1 = x2;
                    xf1 = function(x2);
                    x2 = a + 0.618 * (b - a);
                    xf2 = function(x2);
            }
            else
            {
                    b = x2;
                    x2 = x1;
                    xf2 = xf1;
                    x1 = a + (1 - 0.618) * (b - a);
                    xf1 = function(x1);
            }
            if(fabs(b - a) < e)
            {
                QString c1;
                c1=QString::number(x1);
                a1 = c1;
                double d = function(x1);
                QString d1;
                d1=QString::number(d);
                b1 = d1;
                ui->label->setText(a1 + "  " + b1);
            }
            else
    goto P;
    }

