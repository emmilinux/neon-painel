#include "xlibutil.h"

Xlibutil::Xlibutil()
{

}

void Xlibutil::active(Display *display, Window window)
{
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

void Xlibutil::minimize(Display *display)
{
    int screen;
    XWindowAttributes attr = getAttrWindow(display, window);
    screen = XScreenNumberOfScreen(attr.screen);
    XIconifyWindow(display, window, screen);
}
