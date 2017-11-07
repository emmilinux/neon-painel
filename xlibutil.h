#ifndef XUTIL_H
#define XUTIL_H

#include <QX11Info>
#include <QWindow>
#include <QScreen>
#include <QDebug>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <QPixmap>
#include <QImage>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>


class Xlibutil
{

public:
    Xlibutil();
    void xactive(Window window);
    void xminimize(Window window);
    Window* xwindows(Display *display, unsigned long *size);
    int xwindowPid(Window window);
    char* xwindowClass(Window window);
    char* xwindowName(Window window);
    char* xwindowType(Window window);
    unsigned char* xwindowState(Window window);
    Window xwindowID(int pid);
    void xminimizeByClass(QString wmclass);
    void xactiveByClass(QString wmclass);
    bool xwindowExist(QString wmclass);
    bool xisActive(QString wmclass);
    Window xwindowIdByClass(QString wmclass);
    bool xsingleActive(QString wmclass);
    void xchange(Window window, const char * atom);
    void xreservedSpace(Window window, int h);
    unsigned char* windowProperty(Display *display, Window window, const char *arg, unsigned long *nitems, int *status);
    QString xwindowLauncher(Window window);
    void xaddDesktopFile(int pid, QString arg);
    QPixmap xwindowIcon(Window window);
    XWindowAttributes attrWindow(Display *display, Window window);
    void resizeWindow(Display *display, Window window, int x, int y, unsigned int w, unsigned int h);

private:
    QThread t;
};

#endif // XUTIL_H
