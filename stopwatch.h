#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    QTimer* timer;
    bool get_Flag_Start();
    void set_Flag_Start();
    QString get_Time();
    void set_Time();
    QString get_Lap();
    void set_Lap();
    QString get_TimeLastLape();
public slots:
    void Clear();


signals:
    void sig_Timer();
    void sig_lapTimer();
    void sig_clearTimer();
private:
    uint h = 0;
    uint m = 0;
    uint s = 0;
    uint time = 0;

    uint last_h = 0;
    uint last_m = 0;
    uint last_s = 0;
    uint last_time = 0;
    bool flag_start = false;
    uint lap = 0;
};

#endif // STOPWATCH_H
