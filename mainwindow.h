#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_Lap_clicked();

    void on_pb_Clear_clicked();

    void on_pb_Start_clicked();

    void timerWork();

private:
    Ui::MainWindow *ui;
    Stopwatch* stopwath;



};
#endif // MAINWINDOW_H
