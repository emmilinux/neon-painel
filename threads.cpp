#include "threads.h"


void Threads::run()
{
    Display *display = XOpenDisplay(0);

    if (display)
    {
        Context ctx;
        XSelectInput(display, DefaultRootWindow(display), SubstructureNotifyMask);

        while (true)
        {
            XEvent e;
            XNextEvent(display, &e);
            Threads *t[99], *m[99], *n;

            //e.type == CreateNotify

            if (e.type == CreateNotify || e.type == DestroyNotify)
            {
                QThread::msleep(300);

                QList<QVariant> list = this->main->property("launcher").toList();

                for(int i= 0; i < list.length(); i++)
                {
                    QObject *obj = qvariant_cast<QObject *>(list.at(i));
                    t[i] = new Threads;

                    if (!ctx.xwindowExist(obj->property("pidname").toString()))
                    {
                        obj->setProperty("_instance", false);
                        obj->connect(t[i], SIGNAL(onDestroy()), obj, SIGNAL(destroy()));
                        t[i]->onDestroy();
                    }
                    else
                    {
                        obj->setProperty("_instance", true);
                        obj->connect(t[i], SIGNAL(onCreate()), obj, SIGNAL(create()));
                        t[i]->onCreate();
                    }
                }

                //qDebug() << ctx.xwindowName(e.xmap.window);
                Display *display = QX11Info::display();
                unsigned long size;

                Window *client_list = ctx.xwindows(display, &size);

                if (client_list != NULL)
                {
                    this->main->setProperty("windowVerify", true);

                    bool noWindow = true;

                    for (int i = 0; i < size; i++)
                    {
                        QString type = ctx.xwindowType(client_list[i]);

                        if (type == "_NET_WM_WINDOW_TYPE_NORMAL" || type == "_KDE_NET_WM_WINDOW_TYPE_OVERRIDE")
                        {
                            noWindow = false;
                            m[i] = new Threads;
                            this->main->connect(m[i], SIGNAL(onDesktopWindow(QString, QString, int)), this->main, SIGNAL(desktopWindow(QString, QString, int)));
                            m[i]->onDesktopWindow(ctx.xwindowName(client_list[i]), QString(ctx.xwindowClass(client_list[i])).toLower(), (int)client_list[i]);
                        }
                    }

                    if (noWindow)
                    {
                        n = new Threads;
                        this->main->connect(n, SIGNAL(onClearWindows()), this->main, SIGNAL(clearWindows()));
                        n->onClearWindows();
                    }

                    XFree(client_list);
                }

                XFlush(display);
            }
        }
    }
}
