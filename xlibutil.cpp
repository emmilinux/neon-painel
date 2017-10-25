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
    unsigned char *data = 0;
    int status;

    status = XGetWindowProperty(display, window, nameAtom, 0l, 1l,
                                         false, XA_ATOM, &type, &format,
                                         &nitems, &after, &data);
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

    status = XGetWindowProperty(display, window, nameAtom, 0l, LONG_MAX,
                                         false, XA_ATOM, &type, &format,
                                         &nitems, &after, &data);
    Atom prop = ((Atom *)data)[0];
    data = (unsigned char *)XGetAtomName(display, prop);
    return data;
}

char* Xlibutil::xwindowClass(Window window)
{
    Display *display = QX11Info::display();
    int status;
    unsigned long nitems;
    return (char*)this->windowProperty(display, window, "WM_CLASS", &nitems, &status);
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
    XFlush(display);
    Window *client_list;
    unsigned char *data;
    int status;

    data = this->windowProperty(display, DefaultRootWindow(display), "_NET_CLIENT_LIST", size, &status);

    client_list = (Window *)((unsigned long *)data);

    return client_list;
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
            if (wmclass == QString(this->xwindowClass(lists[i])))
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
            if (wmclass == QString(this->xwindowClass(lists[i])))
            {
                XFree(prop);
                return true;
            }
        }
    }

    return false;
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
            if (wmclass == QString(this->xwindowClass(lists[i])))
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
            if (wmclass == QString(this->xwindowClass(lists[i])))
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
            if (wmclass == QString(this->xwindowClass(lists[i])))
            {
                XFree(prop);
                return true;
            }
        }

        XFree(prop);
    }

    return false;
}

