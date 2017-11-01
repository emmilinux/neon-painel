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
            QStringList launchers;
            Threads *t[99], *m[99], *n[99], *d[99];

            //e.type == CreateNotify
            //qDebug() << "create Window - " << ctx.windowName(e.xmap.window);

            if (e.type == CreateNotify || e.type == DestroyNotify)
            {
                QThread::msleep(300);
                //usleep(300000);

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

                XFlush(display);

                Window *client_list = ctx.xwindows(display, &size);

                if (client_list != NULL)
                {
                    this->main->setProperty("windowVerify", true);

                    for (int i = 0; i < size; i++)
                    {
                        QString launcher = ctx.xwindowLauncher(client_list[i]);

                        if (!launcher.isEmpty())
                        {
                            if (!launchers.contains(launcher) && launcher != "%")
                            {  
                                //qDebug() << ctx.xwindowName(e.xmap.window);
                                //qDebug() << "launcher" << launcher;
                                launchers << launcher;
                                m[i] = new Threads;
                                this->main->connect(m[i], SIGNAL(onDesktopWindow(int, QString, QString, QString)), this->main, SIGNAL(desktopWindow(int, QString, QString, QString)));
                                m[i]->onDesktopWindow(1, "", launcher, ctx.xwindowClass(client_list[i]));
                            }
                        }
                        else
                        {
                            int pid = this->main->property("subWindowPid").toInt();
                            QString desktopFile = this->main->property("subWindowLauncher").toString();
                            Window win = ctx.xwindowID(pid);

                            if (client_list[i] == win)
                            {
                                if (!launchers.contains(desktopFile) && desktopFile != "%")
                                {
                                    launchers << desktopFile;
                                    n[i] = new Threads;
                                    this->main->connect(n[i], SIGNAL(onDesktopWindow(int, QString, QString, QString)), this->main, SIGNAL(desktopWindow(int, QString, QString, QString)));
                                    n[i]->onDesktopWindow(1, "", desktopFile, ctx.xwindowClass(win));

                                    Display *display = QX11Info::display();
                                    unsigned char* deskfile = (unsigned char*)desktopFile.toUtf8().constData();
                                    int status;

                                    if(display)
                                    {
                                        XFlush(display);
                                        Atom atom = XInternAtom(display, "_BAMF_DESKTOP_FILE", False);
                                        status = XChangeProperty(display, client_list[i], atom, XA_STRING, 8, PropModeReplace, deskfile, desktopFile.length());
                                    }
                                }
                            }
                            else
                            {
                                if (QString(ctx.xwindowType(client_list[i])) == "_NET_WM_WINDOW_TYPE_NORMAL")
                                {
                                    d[i] = new Threads;
                                    this->main->connect(d[i], SIGNAL(onDesktopWindow(int, QString, QString, QString)), this->main, SIGNAL(desktopWindow(int, QString, QString, QString)));
                                    // nome - url - exec - pidname
                                    QString attrs;
                                    attrs = QString(ctx.xwindowName(client_list[i])) + ";file:///usr/share/icons/xatane-icons/apps/scalable/default-application.svg;;";
                                    d[i]->onDesktopWindow(0, attrs, "", ctx.xwindowClass(client_list[i]));
                                }
                            }
                        }
                    }

                    XFree(client_list);
                }
            }
        }
    }
}
