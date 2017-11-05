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
#include <QQuickImageProvider>
#include <QList>
#include <QVariant>

#include "context.h"


class Threads : public QThread
{

    Q_OBJECT

public:
    void run();
    QWindow *main;

signals:
    void onCreate();
    void onDestroy();
    void onDesktopWindow(QString nome, QString wmclass, int winId);
    void onClearWindows();
};

#endif // THREADS_H
