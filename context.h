#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>
#include <QDebug>
#include <QScreen>
#include <QPoint>
#include <QScreen>
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QSettings>
#include <QIcon>
#include <QStringList>
#include <QString>
#include <QProcess>
#include <QWindow>
#include <QColor>
#include <QRgb>


#include "xlibutil.h"


class Context : public QObject, public Xlibutil
{

    Q_OBJECT

public:
    Q_INVOKABLE QStringList addLauncher(QString app);
    Q_INVOKABLE int mouseX();
    Q_INVOKABLE int mouseY();
    Q_INVOKABLE int exec(QString pro);
    Q_INVOKABLE void minimize(int win);
    Q_INVOKABLE void active(int pid);
    Q_INVOKABLE void manyMinimizes(QString pidname);
    Q_INVOKABLE void minimizes(int win);
    Q_INVOKABLE int isMinimized(QString wmclass);
    Q_INVOKABLE void manyActives(QString pidname);
    Q_INVOKABLE void actives(int pid);
    Q_INVOKABLE void changeThemeColor(QString rgb);

protected:
    Window windowId(int pid);

private:
    void changeColorBtnMin(QRgb color);
    void changeColorBtnMax(QRgb color);
    void changeColorBtnClose(QRgb color);
    void changeColor(int w, int h, QRgb color, QString s);
    QString launcherFix(QString pro);
    QScreen *screen = QApplication::screens().at(0);
    Display *display;

signals:
    void test();
};

#endif // CONTEXT_H
