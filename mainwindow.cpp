#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stopwath(new Stopwatch)
{
    ui->setupUi(this);
    ui->lb_Timer->setText(QString(stopwath->get_Time()));
    ui->pb_Start->setText(QString("Старт"));
    ui->pb_Lap->setText(QString("Круг"));
    ui->pb_Lap->setEnabled(stopwath->get_Flag_Start());
    ui->pb_Clear->setText(QString("Очистить"));
    connect(stopwath->timer, &QTimer::timeout, this, &MainWindow::timerWork);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_Lap_clicked()
{
    stopwath->set_Lap();
    ui->te_logTimer->append(QString("Круг %1: %2").arg(stopwath->get_Lap(), stopwath->get_TimeLastLape()));
}


void MainWindow::on_pb_Clear_clicked()
{
    stopwath->Clear();
    ui->lb_Timer->setText(QString(stopwath->get_Time()));
    ui->te_logTimer->clear();

}


void MainWindow::on_pb_Start_clicked()
{
    stopwath->set_Flag_Start();
    if(stopwath->get_Flag_Start() == true)
    {

        stopwath->timer->start(100);
        ui->pb_Lap->setEnabled(stopwath->get_Flag_Start());
        ui->pb_Start->setText(QString("Стоп"));
    }
    else
    {
        stopwath->timer->stop();
        ui->pb_Lap->setEnabled(stopwath->get_Flag_Start());
        ui->pb_Start->setText(QString("Старт"));
    }
}

void MainWindow::timerWork()
{
    stopwath->set_Time();
    ui->lb_Timer->setText(QString(stopwath->get_Time()));
}

