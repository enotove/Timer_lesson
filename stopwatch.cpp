#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{

    timer = new QTimer(this);


}

bool Stopwatch::get_Flag_Start()
{
    return flag_start;
}

void Stopwatch::set_Flag_Start()
{

    if(flag_start == false)
    {
        flag_start = true;
    }
    else
    {
        flag_start = false;
    }


}

QString Stopwatch::get_Time()
{
    if(time >= 10)
    {
        time = 0;
        s++;
    }
    if(s >= 60)
    {
        s = 0;
        m++;
    }
    if(m >= 60)
    {
        m = 0;
        h++;
    }
    return QString("%1:%2:%3:%4").arg(QString::number(h),QString::number(m),QString::number(s),QString::number(time));
}

void Stopwatch::set_Time()
{
    time++;
}

QString Stopwatch::get_Lap()
{
    return QString::number(lap);
}

void Stopwatch::set_Lap()
{
    lap++;
    lap_h = h - last_h;
    lap_m = m - last_m;
    lap_s = s - last_s;
    lap_time = time >= last_time ?time - last_time : last_time - time;
    last_h = h;
    last_m = m;
    last_s = s;
    last_time = time;

}

QString Stopwatch::get_TimeLastLape()
{
    return QString("%1:%2:%3:%4").arg(QString::number(lap_h),QString::number(lap_m),QString::number(lap_s),QString::number(lap_time));;
}

void Stopwatch::Clear()
{
    m = 0;
    s= 0;
    h = 0;
    time = 0;
    lap = 0;


}

