#include "context.h"



void Context::changeColorBtnMin(QRgb color)
{
    QImage img("/home/shenoisz/.themes/dinamic-color/xfwm4/bk/hide-active.xpm", "xpm");
    img.setColor(0, color);
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/hide-active.xpm", "xpm");

    QColor cor;
    int r, g, b;
    cor = img.color(0);

    r = cor.red();
    g = cor.green();
    b = cor.blue();

    bool red, green, blue;

    if (cor.red() > cor.green() && cor.red() > cor.blue()) red = true;
    if (cor.green() > cor.red() && cor.green() > cor.blue()) green = true;
    if (cor.blue() > cor.red() && cor.blue() > cor.green()) blue = true;

    if (cor.red() > 30 && cor.red() < 225 && red) r += 30;
    if (cor.green() > 30 && cor.green() < 225 && green) g += 30;
    if (cor.blue() > 30 && cor.blue() < 225 && blue) b += 30;

    img.setColor(0, qRgb(r, g, b));

    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/hide-prelight.xpm", "xpm");
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/hide-pressed.xpm", "xpm");
}

void Context::changeColorBtnMax(QRgb color)
{
    QImage img("/home/shenoisz/.themes/dinamic-color/xfwm4/bk/maximize-active.xpm", "xpm");
    img.setColor(0, color);
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/maximize-active.xpm", "xpm");

    QColor cor;
    int r, g, b;
    cor = img.color(0);

    r = cor.red();
    g = cor.green();
    b = cor.blue();

    bool red, green, blue;

    if (cor.red() > cor.green() && cor.red() > cor.blue()) red = true;
    if (cor.green() > cor.red() && cor.green() > cor.blue()) green = true;
    if (cor.blue() > cor.red() && cor.blue() > cor.green()) blue = true;

    if (cor.red() > 30 && cor.red() < 225 && red) r += 30;
    if (cor.green() > 30 && cor.green() < 225 && green) g += 30;
    if (cor.blue() > 30 && cor.blue() < 225 && blue) b += 30;

    img.setColor(0, qRgb(r, g, b));

    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/maximize-prelight.xpm", "xpm");
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/maximize-pressed.xpm", "xpm");
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/maximize-toggled-prelight.xpm", "xpm");
}

void Context::changeColorBtnClose(QRgb color)
{
    QImage img("/home/shenoisz/.themes/dinamic-color/xfwm4/bk/close-active.xpm", "xpm");
    img.setColor(0, color);
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/close-active.xpm", "xpm");

    QColor cor;
    int r, g, b;
    cor = img.color(0);

    r = cor.red();
    g = cor.green();
    b = cor.blue();;

    bool red, green, blue;

    if (cor.red() > cor.green() && cor.red() > cor.blue()) red = true;
    if (cor.green() > cor.red() && cor.green() > cor.blue()) green = true;
    if (cor.blue() > cor.red() && cor.blue() > cor.green()) blue = true;

    if (cor.red() > 30 && cor.red() < 225 && red) r += 30;
    if (cor.green() > 30 && cor.green() < 225 && green) g += 30;
    if (cor.blue() > 30 && cor.blue() < 225 && blue) b += 30;

    img.setColor(0, qRgb(r, g, b));

    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/close-prelight.xpm", "xpm");
    img.save("/home/shenoisz/.themes/dinamic-color/xfwm4/close-pressed.xpm", "xpm");
}

void Context::changeColor(int w, int h, QRgb color, QString s)
{
    QImage img(w, h, QImage::Format_RGB888);

    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            img.setPixel(x, y, color);
        }
    }

    img.save(s, "xpm");
}

void Context::changeThemeColor(QString rgb)
{
    QColor cor(rgb);
    QRgb color = qRgb(cor.red(), cor.green(), cor.blue());

    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-1-active.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-2-active.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-3-active.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-4-active.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-5-active.xpm");

    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-1-inactive.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-2-inactive.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-3-inactive.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-4-inactive.xpm");
    this->changeColor(20, 24, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/title-5-inactive.xpm");

    this->changeColor(2, 25, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/top-left-active.xpm");
    this->changeColor(2, 25, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/top-left-inactive.xpm");
    this->changeColor(2, 25, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/top-right-active.xpm");
    this->changeColor(2, 25, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/top-right-inactive.xpm");

    this->changeColor(4, 16, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/left-active.xpm");
    this->changeColor(4, 16, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/left-inactive.xpm");
    this->changeColor(4, 16, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/right-active.xpm");
    this->changeColor(4, 16, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/right-inactive.xpm");

    this->changeColor(3, 4, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/bottom-active.xpm");
    this->changeColor(3, 4, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/bottom-inactive.xpm");

    this->changeColor(2, 2, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/bottom-right-inactive.xpm");
    this->changeColor(2, 2, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/bottom-right-active.xpm");
    this->changeColor(2, 2, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/bottom-left-inactive.xpm");
    this->changeColor(2, 2, color, "/home/shenoisz/.themes/dinamic-color/xfwm4/bottom-left-active.xpm");

    this->changeColorBtnClose(color);
    this->changeColorBtnMax(color);
    this->changeColorBtnMin(color);

    QProcess process;
    process.start("xfconf-query -c xfwm4 -p /general/theme");
    process.waitForFinished();
    QString theme = process.readLine().replace("\n", "");
    process.close();

    process.start("xfconf-query -c xfwm4 -p /general/theme -s tmp");
    process.waitForFinished();
    process.close();

    process.start("xfconf-query -c xfwm4 -p /general/theme -s \"" + theme + "\"");
    process.waitForFinished();
    process.close();
}

QString Context::launcherFix(QString exec)
{
    QStringList list;
    list << "google-chrome-stable" << "google-chrome";
    //list << "other" << "other";

    for(int i = 1; i <= list.length(); i++)
    {
        if (list.at(i - 1) == exec && i % 2 == 1)
        {
            return list.at(i);
        }
    }

    return exec;
}

int Context::exec(QString pro)
{
    QString list;

    if (pro.contains("%"))
    {
        list = pro.split(" %")[0];
    }
    else
    {
        list = pro;
    }

    QProcess *process = new QProcess();
    process->start(list);
    process->waitForStarted();

    return process->pid();
}


QStringList Context::addLauncher(QString app)
{
    QStringList list, nitems;
    app = app.replace("file://", "");
    QFileInfo f(app);

    QString nome, icone, tmp, exec, wmclass;

    if (f.suffix() == "desktop")
    {
        QSettings settings(app, QSettings::NativeFormat);
        settings.beginGroup("Desktop Entry");
        nome = settings.value("Name").toString();
        tmp = settings.value("Icon").toString();
        exec = settings.value("Exec").toString();
        wmclass = settings.value("StartupWMClass").toString();
        settings.endGroup();

        if (wmclass.isEmpty()) {
            if (exec.contains(" "))
            {
                wmclass = exec.split(" ")[0];
            }
            else
            {
                wmclass = exec;
            }

            if (wmclass.contains("/"))
            {
                nitems = wmclass.split("/");
                wmclass = nitems[nitems.length() - 1];
            }

            wmclass = this->launcherFix(wmclass);
        }


        if (!tmp.startsWith("/")) {

            if (tmp.endsWith(".png")) tmp = tmp.remove(".png");
            if (tmp.endsWith(".svg")) tmp = tmp.remove(".png");
            if (tmp.endsWith(".xpm")) tmp = tmp.remove(".png");

            QIcon icon;
            foreach (QString path, icon.themeSearchPaths()) {

                bool stop = false;
                QStringList exts;
                exts << ".svg" << ".png" << ".xpm";

                foreach (QString ext, exts) {

                    icone = path + "/xatane-icons" + "/apps/scalable/" + tmp + ext;
                    f.setFile(icone);

                    if (f.exists()) {
                        stop = true;
                        break;
                    }
                }

                if (stop) break;
            }

            list << nome << "file://" + icone << exec << wmclass;
        }
        else
        {
            list << nome << "file://" + tmp << exec << wmclass;
        }
    }
    else
    {
        list << "" << "" << "" << "";
    }

    return list;
}

Window Context::windowId(int pid)
{
    Display *display = QX11Info::display();
    int pro_id;
    Window winId;
    int status;
    unsigned long *desktop;
    unsigned long size;

    XFlush(display);

    Window *client_list = this->xwindows(display, &size);

    if (client_list != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            Window tmpId = client_list[i];
            pro_id = this->xwindowPid(tmpId);

            if (pro_id == pid)
            {
                winId = tmpId;
                break;
            }
        }
    }

    XFree(client_list);
    return winId;
}

int Context::isMinimized(QString wmclass)
{
    Display *display = QX11Info::display();

    if (display)
    {
        unsigned long nitems;

        Window *lists = this->xwindows(display, &nitems);

        for (int i = 0; i < nitems; i++)
        {
            if (wmclass == QString(this->xwindowClass(lists[i])))
            {
                if (this->xwindowState(lists[i]) != 0x0)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void Context::manyMinimizes(QString pidname)
{
    this->xminimizeByClass(pidname);
}

void Context::minimizes(int pid)
{
    Display *display = QX11Info::display();
    Window id = this->xwindowID(pid);

    if (id)
    {
        this->xminimizeByClass(QString(this->xwindowClass(id)));
    }
}

void Context::minimize(int pid)
{
    Display *display = QX11Info::display();
    Window id = this->xwindowID(pid);

    if (id)
    {
        this->xminimize(id);
    }
}

void Context::manyActives(QString pidname)
{
    this->xactiveByClass(pidname);
}

void Context::actives(int pid)
{
    Display *display = QX11Info::display();
    Window id = this->xwindowID(pid);

    if (id)
    {
        this->xactiveByClass(QString(this->xwindowClass(id)));
    }
}

void Context::active(int pid)
{
    Display *display = QX11Info::display();
    Window id = this->xwindowID(pid);

    if (id)
    {
       this->xactive(id);
    }
}

int Context::mouseX()
{
    QPoint Mouse = QCursor::pos(this->screen);
    return Mouse.x();
}

int Context::mouseY()
{
    QPoint Mouse = QCursor::pos(this->screen);
    return Mouse.y();
}
