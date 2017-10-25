#include <QDesktopWidget>

#include "threads.h"
#include "context.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDesktopWidget desktop;
    Context ctx;
    Threads *threads = new Threads();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Context", &ctx);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *main = engine.rootObjects().first();
    QWindow *window = qobject_cast<QWindow *>(main); // (QWindow *)main
    window->setGeometry(0, desktop.height() - 40, desktop.width(), 40);
    window->setProperty("mainId", window->winId());
    window->xChanged(Qt::WA_X11DoNotAcceptFocus | Qt::WA_X11NetWmWindowTypeDock);

    app.setAttribute(Qt::AA_X11InitThreads);

    threads->main = window;
    threads->start();

    ctx.xchange(window->winId(), "_NET_WM_WINDOW_TYPE_DOCK");
    ctx.xreservedSpace(window->winId(), window->height());

    return app.exec();
}
