#ifndef XUTIL_H
#define XUTIL_H

#include <QX11Info>
#include <QWindow>
#include <QScreen>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xrender.h>
#include <X11/extensions/Xcomposite.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <assert.h>



class Xlibutil
{
public:
    Xlibutil();
    void active(Display *display, Window window);
    void minimize(Display *display, Window window);
};

#endif // XUTIL_H
