#ifndef THREADS_H
#define THREADS_H

#include <QThread>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>
#include <QObject>
#include <QDebug>
#include <QX11Info>

#include "context.h"
#include <QObject>
#include <QList>
#include <QVariant>


class Threads : public QThread
{

    Q_OBJECT

public:
    void run();
    QWindow *main;

signals:
    void onCreate();
    void onDestroy();
    void onDesktopWindow(int isLauncher, QString attrs, QString args, QString wmclass);
};

#endif // THREADS_H
