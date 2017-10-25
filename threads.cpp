#include "threads.h"


void Threads::run()
{
    Display *display = XOpenDisplay(0);

    if (display)
    {
        Threads *t[50];
        Context ctx;
        XSelectInput(display, DefaultRootWindow(display), SubstructureNotifyMask);

        while (true)
        {
            XEvent e;
            XNextEvent(display, &e);

            //e.type == CreateNotify
            //qDebug() << "create Window - " << ctx.windowName(e.xmap.window);

            if (e.type == CreateNotify || e.type == DestroyNotify)
            {
                usleep(100000);

                QList<QVariant> list = main->property("launcher").toList();


                    for(int i= 0; i < list.length(); i++)
                    {
                        t[i] = new Threads;

                        QObject *obj = qvariant_cast<QObject *>(list.at(i));
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
            }
        }
    }
}
