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
public slots:
    void Clear();


signals:
    void sig_stopTimer();
    void sig_lapTimer();
    void sig_clearTimer();
private:
    uint h;
    uint m;
    uint s;
    uint time;
    bool flag_start = false;
    uint lap = 0;
};

#endif // STOPWATCH_H
