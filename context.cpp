#include "context.h"


QImage Context::imageOverlay(const QImage& baseImage, const QImage& overlayImage)
{
    QImage imageWithOverlay = QImage(baseImage.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&imageWithOverlay);

    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(imageWithOverlay.rect(), Qt::transparent);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, baseImage);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, overlayImage);

    painter.end();

    return imageWithOverlay;
}

void Context::changeColorBtnMenu(QRgb color)
{
    QImage img(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/menu-active2.xpm", "xpm");
    img.setColor(0, color);
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/menu-active.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/menu-inactive.xpm", "xpm");
}

void Context::changeColorBtnMin(QRgb color)
{
    QImage bg(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/Min-transparent.xpm", "xpm");
    bg.setColor(0, color);

    QImage overlay(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/Min.png", "png");
    QImage img = this->imageOverlay(bg, overlay);

    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/hide-active.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/hide-inactive.xpm", "xpm");

    QColor cor;
    int r, g, b;
    cor = bg.color(0);

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

    bg.setColor(0, qRgb(r, g, b));
    img = this->imageOverlay(bg, overlay);

    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/hide-prelight.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/hide-pressed.xpm", "xpm");
}

void Context::changeColorBtnMax(QRgb color)
{
    QImage bg(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/Max-transparent.xpm", "xpm");
    bg.setColor(0, color);

    QImage overlay(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/Max.png", "png");
    QImage img = this->imageOverlay(bg, overlay);

    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/maximize-active.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/maximize-inactive.xpm", "xpm");

    QColor cor;
    int r, g, b;
    cor = bg.color(0);

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

    bg.setColor(0, qRgb(r, g, b));
    img = this->imageOverlay(bg, overlay);

    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/maximize-prelight.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/maximize-pressed.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/maximize-toggled-prelight.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/maximize-toggled-pressed.xpm", "xpm");
}

void Context::changeColorBtnClose(QRgb color)
{
    QImage bg(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/Close-transparent.xpm", "xpm");
    bg.setColor(0, color);

    QImage overlay(QDir::homePath() + "/.themes/dinamic-color/xfwm4/novos/Close.png", "png");
    QImage img = this->imageOverlay(bg, overlay);

    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/close-active.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/close-inactive.xpm", "xpm");

    QColor cor;
    int r, g, b;
    cor = bg.color(0);

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

    bg.setColor(0, qRgb(r, g, b));
    img = this->imageOverlay(bg, overlay);

    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/close-prelight.xpm", "xpm");
    img.save(QDir::homePath() + "/.themes/dinamic-color/xfwm4/close-pressed.xpm", "xpm");
}

void Context::showMoreWindows(int winId, int h)
{
    this->xreservedSpace(winId, h);
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

    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-1-active.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-2-active.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-3-active.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-4-active.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-5-active.xpm");

    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-1-inactive.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-2-inactive.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-3-inactive.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-4-inactive.xpm");
    this->changeColor(20, 24, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/title-5-inactive.xpm");

    this->changeColor(2, 25, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/top-left-active.xpm");
    this->changeColor(2, 25, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/top-left-inactive.xpm");
    this->changeColor(2, 25, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/top-right-active.xpm");
    this->changeColor(2, 25, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/top-right-inactive.xpm");

    this->changeColor(4, 16, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/left-active.xpm");
    this->changeColor(4, 16, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/left-inactive.xpm");
    this->changeColor(4, 16, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/right-active.xpm");
    this->changeColor(4, 16, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/right-inactive.xpm");

    this->changeColor(3, 4, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/bottom-active.xpm");
    this->changeColor(3, 4, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/bottom-inactive.xpm");

    this->changeColor(2, 2, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/bottom-right-inactive.xpm");
    this->changeColor(2, 2, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/bottom-right-active.xpm");
    this->changeColor(2, 2, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/bottom-left-inactive.xpm");
    this->changeColor(2, 2, color, QDir::homePath() + "/.themes/dinamic-color/xfwm4/bottom-left-active.xpm");

    this->changeColorBtnClose(color);
    this->changeColorBtnMax(color);
    this->changeColorBtnMin(color);
    this->changeColorBtnMenu(color);

    QProcess process;
    process.start("xfconf-query -c xfwm4 -p /general/theme");
    process.waitForFinished();
    QString theme = process.readLine().replace("\n", "");
    process.close();

    if (theme == "dinamic-color")
    {
        process.start("xfconf-query -c xfwm4 -p /general/theme -s tmp");
        process.waitForFinished();
        process.close();

        process.start("xfconf-query -c xfwm4 -p /general/theme -s dinamic-color");
        process.waitForFinished();
        process.close();
    }
}

QString Context::launcherFix(QString exec)
{
    QStringList list;
    list << "google-chrome-stable" << "google-chrome";
    //list << "TelegramDesktop" << "Telegram";

    for(int i = 1; i <= list.length(); i++)
    {
        if (list.at(i - 1) == exec && i % 2 == 1)
        {
            return list.at(i);
        }
    }

    return exec;
}

QString Context::basePath() const
{
    return this->basepath;
}

void Context::exec(QString pro)
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
    //process->waitForStarted();
    //return process->processId();
}

void Context::addDesktopFile(int pid, QString desktopFile)
{
    if (!desktopFile.isEmpty()) {
        this->xaddDesktopFile(pid, desktopFile.remove("file://"));
    }
}

QList<int> Context::windowsBywmclass(QString wmclass)
{
    Display *display = QX11Info::display();
    QList<int> list;

    if (display)
    {
        Atom atom = XInternAtom(display, "_NET_CLIENT_LIST", True);
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
                list.append(lists[i]);
            }
        }

        XFree(prop);
        XFlush(display);
    }

    return list;
}

QString Context::windowName(int window)
{
    return QString(this->xwindowName(window));
}

void Context::windowActive(int window)
{
    this->xactive(window);
}

void Context::windowClose(int window)
{
    this->xwindowClose(window);
}

QString Context::defaultIcon()
{
    QProcess process;
    process.start("xfconf-query -c xsettings -p /Net/IconThemeName");
    process.waitForFinished();
    this->defaultIconTheme = process.readLine().replace("\n", "");
    process.close();

    return "/usr/share/icons/" + this->defaultIconTheme + "/apps/scalable/default-application.svg";
}

QStringList Context::addLauncher(QString app)
{
    QStringList list, nitems;
    app = app.replace("file://", "");
    QFileInfo f(app);

    QString nome, icone, tmp, exec, wmclass, iconDefault;

    iconDefault = this->defaultIcon();

    if (f.suffix() == "desktop")
    {
        QLocale locale;
        QSettings settings(app, QSettings::NativeFormat);
        settings.setIniCodec("UTF-8");
        settings.beginGroup("Desktop Entry");

        nome = settings.value("Name[" + locale.name() + "]").toString();
        if (nome.isEmpty()) nome = settings.value("Name").toString();

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

                    icone = path + "/" + this->defaultIconTheme + "/apps/scalable/" + tmp + ext;
                    f.setFile(icone);

                    if (f.exists()) {
                        stop = true;
                        break;
                    }

                    if(!stop) icone = "";
                }

                if (icone.isEmpty()) {

                    foreach (QString ext, exts) {

                        icone = "/usr/share/pixmaps/" + tmp + ext;
                        f.setFile(icone);

                        if (f.exists()) {
                            stop = true;
                            break;
                        }

                        if(!stop) icone = "";
                    }
                }

                if (icone.isEmpty()) {
                    icone = iconDefault;
                }

                if (stop) break;
            }

            list << nome << "file://" + icone << exec << wmclass.toLower();
        }
        else
        {
            if (tmp.contains(".ico")) tmp = iconDefault;
            if (tmp == "/") tmp = iconDefault;

            list << nome << "file://" + tmp << exec << wmclass.toLower();
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
    XFlush(display);
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
                if ((const char *)this->xwindowState(lists[i]) == "_NET_WM_STATE_HIDDEN")
                {
                    XFlush(display);
                    return 1;
                }
            }
        }
    }

    XFlush(display);
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

    XFlush(display);
}

void Context::minimize(int pid)
{
    Display *display = QX11Info::display();
    Window id = this->xwindowID(pid);

    if (id)
    {
        this->xminimize(id);
    }

    XFlush(display);
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

    XFlush(display);
}

void Context::active(int pid)
{
    Display *display = QX11Info::display();
    Window id = this->xwindowID(pid);

    if (id)
    {
       this->xactive(id);
    }

    XFlush(display);
}

int Context::isActive(QString pidname)
{
    return this->xisActive(pidname);
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

QStringList Context::applications()
{
    QStringList list, tmp, appsPath;

    appsPath << "/usr/share/applications/" << QDir::homePath() + "/.local/share/applications/";

    foreach (QString path, appsPath) {

        QDir dir(path);
        QFileInfoList filelist = dir.entryInfoList(QDir::Files);

        for (int i = 0; i < filelist.length(); i++)
        {
            tmp = this->addLauncher(filelist.at(i).filePath());
            list << tmp.at(0) + ";" + tmp.at(1) + ";" + tmp.at(2) + ";" + filelist.at(i).filePath();
        }
    }

    return list;
}

void Context::dragDrop(QString icone, QString app)
{

    QMimeData *mimeData = new QMimeData;
    QList<QUrl> url;

    url.append(QUrl(app));
    mimeData->setUrls(url);

    QImage img(icone, icone.split(".").at(1).toUtf8());
    QImage image = img.scaled(48, 48, Qt::KeepAspectRatio);

    QPixmap pixel;
    pixel.convertFromImage(image);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixel);

    QPoint p;
    p.setX(pixel.width() / 2);
    p.setY(pixel.height() / 2);
    drag->setHotSpot(p);

    //drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
    drag->exec(drag->defaultAction());
}

QString Context::userName()
{
    return qgetenv("USER").toUpper();
}

QString Context::userAvatar()
{
    QString ava;
    ava = "file://home/" + qgetenv("USER") + "/.face";
    return ava;
}
