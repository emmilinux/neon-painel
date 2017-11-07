#include "xlibutil.h"

Xlibutil::Xlibutil()
{

}

void Xlibutil::xreservedSpace(Window window, int h)
{
    Display *display = QX11Info::display();

    // set in xorg reserved space in desktop
    long prop[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    prop[3] = h;

    XChangeProperty(display, window,
                    XInternAtom(display, "_NET_WM_STRUT", False),
                    XA_CARDINAL, 32, PropModeReplace, (unsigned char *)&prop, 4);
}

void Xlibutil::xchange(Window window, const char * atom)
{
    Display *display = QX11Info::display();

    Atom tmp = XInternAtom(display, atom, False);

    XChangeProperty(display, window,
                    XInternAtom(display, "_NET_WM_WINDOW_TYPE", False),
                    XA_ATOM, 32, PropModeReplace, (unsigned char *)&tmp, 1);
}

char* Xlibutil::xwindowType(Window window)
{
    /*
        (:_NET_WM_WINDOW_TYPE_DESKTOP . :desktop)
        (:_NET_WM_WINDOW_TYPE_DOCK . :dock)
        (:_NET_WM_WINDOW_TYPE_TOOLBAR . :toolbar)
        (:_NET_WM_WINDOW_TYPE_MENU . :menu)
        (:_NET_WM_WINDOW_TYPE_UTILITY . :utility)
        (:_NET_WM_WINDOW_TYPE_SPLASH . :splash)
        (:_NET_WM_WINDOW_TYPE_DIALOG . :dialog)
        (:_NET_WM_WINDOW_TYPE_NORMAL . :normal))
   */

    Display *display = QX11Info::display();
    Atom nameAtom = XInternAtom(display,"_NET_WM_WINDOW_TYPE",false);
    Atom type;
    int format;
    unsigned long nitems, after;
    unsigned char *data;
    int status;

    status = XGetWindowProperty(display, window, nameAtom, 0L, LONG_MAX,
                                         false, XA_ATOM, &type, &format,
                                         &nitems, &after, &data);

    if (status != Success || nitems == 0) return "_NET_WM_WINDOW_TYPE_NORMAL";

    Atom prop = ((Atom *)data)[0];
    data = (unsigned char *)XGetAtomName(display, prop);

    return (char *)data;
}

unsigned char* Xlibutil::xwindowState(Window window)
{
    Display *display = QX11Info::display();
    Atom nameAtom = XInternAtom(display,"_NET_WM_STATE", True);
    Atom type;
    int format;
    unsigned long nitems, after;
    unsigned char *data = 0;
    int status;

    status = XGetWindowProperty(display, window, nameAtom, 0L, LONG_MAX,
                                         false, XA_ATOM, &type, &format,
                                         &nitems, &after, &data);

    if (status != Success || nitems == 0) return 0x0;

    Atom prop = ((Atom *)data)[0];
    data = (unsigned char *)XGetAtomName(display, prop);

    return data;
}

char* Xlibutil::xwindowClass(Window window)
{
    Display *display = QX11Info::display();
    int status;
    unsigned long nitems;
    unsigned char* data;
    data = this->windowProperty(display, window, "WM_CLASS", &nitems, &status);

    if (status != Success || nitems == 0) return "unknow";
    return (char*)data;
}

char* Xlibutil::xwindowName(Window window)
{
     Display *display = QX11Info::display();
     Atom nameAtom = XInternAtom(display,"_NET_WM_NAME",false);
     Atom utf8Atom = XInternAtom(display,"UTF8_STRING",false);
     Atom type;
     int format;
     unsigned long nitems, after;
     unsigned char *data;
     int status;

    status = XGetWindowProperty(display, window, nameAtom, 0, 65536,
                                         false, utf8Atom, &type, &format,
                                         &nitems, &after, &data);

    if (status != Success || nitems == 0) return "unknow";
    return (char *)data;
}

int Xlibutil::xwindowPid(Window window)
{
    Display *display = QX11Info::display();
    unsigned char *data;
    unsigned long nitems;
    int window_pid = 0;
    int status;

    data = this->windowProperty(display, window, "_NET_WM_PID", &nitems, &status);
    window_pid = (int) *((unsigned long *)data);

    if (status != Success || nitems == 0) return 0;
    return window_pid;
}

unsigned char* Xlibutil::windowProperty(Display *display, Window window, const char *arg, unsigned long *nitems, int *status)
{
    Atom type;
    int size, actual_format;
    //unsigned long nitems;
    unsigned char *data;

    /*unsigned long nbytes;*/
    unsigned long bytes_after; /* unused */

    Atom tmp = XInternAtom(display, arg, False);

    // 4096 / 4 , (~0L)

    *status = XGetWindowProperty(display, window,tmp, 0, (~0L),
                                  False, AnyPropertyType, &type,
                                  &actual_format, nitems, &bytes_after,
                                  &data);
    return data;
}

XWindowAttributes Xlibutil::attrWindow(Display *display, Window window)
{
    XWindowAttributes attr;
    XGetWindowAttributes(display, window, &attr);
    return attr;
}

void Xlibutil::resizeWindow(Display *display, Window window, int x, int y, unsigned int w, unsigned int h)
{
    XMoveResizeWindow(display, window, x, y, w, h);
}

void Xlibutil::xactive(Window window)
{
    Display *display = QX11Info::display();
    XEvent xev;
    Atom wm_state  =  XInternAtom(display, "_NET_ACTIVE_WINDOW", False);
    Atom win_min  =  XInternAtom(display, "_NET_ACTIVE_WINDOW", False);

    memset(&xev, 0, sizeof(xev));
    xev.type = ClientMessage;
    xev.xclient.window = window;
    xev.xclient.message_type = wm_state;
    xev.xclient.format = 32;
    xev.xclient.data.l[0] = win_min;
    xev.xclient.data.l[1] = CurrentTime;

    XSendEvent(display, DefaultRootWindow(display), False, SubstructureNotifyMask, &xev);
}

void Xlibutil::xminimize(Window window)
{
    Display *display = QX11Info::display();
    int screen;
    XWindowAttributes attr = this->attrWindow(display, window);
    screen = XScreenNumberOfScreen(attr.screen);
    XIconifyWindow(display, window, screen);
}

Window* Xlibutil::xwindows(Display *display, unsigned long *size)
{
    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, size, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);
        return lists;
    }

    return NULL;
}

Window Xlibutil::xwindowID(int pid)
{
    Display *display = QX11Info::display();

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);

        for (int i = 0; i < nitems; i++)
        {
            if (pid == this->xwindowPid(lists[i]))
            {
                XFree(prop);
                return lists[i];
            }
        }
    }

    return NULL;
}

Window Xlibutil::xwindowIdByClass(QString wmclass)
{
    Display *display = QX11Info::display();

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);

        for (int i = 0; i < nitems; i++)
        {
            if (wmclass == QString(this->xwindowClass(lists[i])).toLower())
            {
                XFree(prop);
                return lists[i];
            }
        }
    }

    return NULL;
}

bool Xlibutil::xsingleActive(QString wmclass)
{
    Display *display = QX11Info::display();
    Atom atom = XInternAtom(display, "_NET_ACTIVE_WINDOW", True);
    XFlush(display);
    Atom actual_type;
    int actual_format;
    unsigned long nitems;
    unsigned long bytes_after;
    unsigned char *prop;

    int status = XGetWindowProperty(display, this->xwindowIdByClass(wmclass), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

    if ((unsigned char*)prop != 0x0) {
        XFree(prop);
        return true;
    }

    XFree(prop);
    return false;
}

bool Xlibutil::xisActive(QString wmclass)
{
    Display *display = QX11Info::display();

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_ACTIVE_WINDOW", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);

        for (int i = 0; i < nitems; i++)
        {
            if (wmclass == QString(this->xwindowClass(lists[i])).toLower())
            {
                XFree(prop);
                return 1;
            }
        }
    }

    return 0;
}

void Xlibutil::xminimizeByClass(QString wmclass)
{
    Display *display = QX11Info::display();

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);

        for (int i = 0; i < nitems; i++)
        {
            if (wmclass == QString(this->xwindowClass(lists[i])).toLower())
            {
                this->xminimize(lists[i]);
            }
        }

        XFree(prop);
    }
}

void Xlibutil::xactiveByClass(QString wmclass)
{
    Display *display = QX11Info::display();

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);

        for (int i = 0; i < nitems; i++)
        {
            if (wmclass == QString(this->xwindowClass(lists[i])).toLower())
            {
                this->xactive(lists[i]);
            }
        }

        XFree(prop);
    }
}

bool Xlibutil::xwindowExist(QString wmclass)
{
    Display *display = QX11Info::display();

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
        XFlush(display);
        Atom actual_type;
        int actual_format;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;

        int status = XGetWindowProperty(display, DefaultRootWindow(display), atom, 0, 4096 / 4, False, AnyPropertyType, &actual_type, &actual_format, &nitems, &bytes_after, &prop);

        Window *lists = (Window *)((unsigned long *)prop);

        for (int i = 0; i < nitems; i++)
        {
            if (wmclass == QString(this->xwindowClass(lists[i])).toLower())
            {
                XFree(prop);
                return true;
            }
        }

        XFree(prop);
    }

    return false;
}

QString Xlibutil::xwindowLauncher(Window window)
{
    Display *display = QX11Info::display();
    unsigned char *data;
    unsigned long nitems;
    QString launcher;
    int status;

    data = this->windowProperty(display, window, "_BAMF_DESKTOP_FILE", &nitems, &status);
    launcher = (char *)data;

    return launcher;
}

void Xlibutil::xaddDesktopFile(int pid, QString arg)
{
    Display *display = QX11Info::display();
    //unsigned char* deskfile = (unsigned char*)"/usr/share/applications/xfce4-terminal.desktop";
    unsigned char* deskfile = (unsigned char*)arg.toUtf8().constData();
    int status;

    if(display)
    {
        XFlush(display);
        Atom atom = XInternAtom(display, "_BAMF_DESKTOP_FILE", False);
        status = XChangeProperty(display, this->xwindowID(pid), atom, XA_STRING, 8, PropModeReplace, deskfile, arg.length());
    }
}

QPixmap Xlibutil::xwindowIcon(Window window)
{
    Display *display = QX11Info::display();
    Atom type;
    int format;
    unsigned long bytes_after;
    ulong* data;
    unsigned long nitems;

    Atom prop = XInternAtom(display, "_NET_WM_ICON", False);

    XGetWindowProperty(display, window, prop, 0, LONG_MAX, False, AnyPropertyType,
                       &type, &format, &nitems, &bytes_after, (uchar**)&data);

    QPixmap map;

    if (data != 0x0)
    {
        QImage image (data[0], data[1], QImage::Format_ARGB32);

        for (int i=0; i<image.byteCount() / 4; ++i)
        {
            ((uint*)image.bits())[i] = data[i + 2];
        }

        map.convertFromImage(image);
        //map.scaled(48, 48, Qt::IgnoreAspectRatio);
    }

    XFree(data);
    return map;
}
