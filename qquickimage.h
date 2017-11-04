#ifndef QQUICKIMAGE_H
#define QQUICKIMAGE_H

#include <QQuickImageProvider>
#include <QDebug>

#include "context.h"


class QQuickImage : public QQuickImageProvider
{
public:
    QQuickImage() : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {

    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
       QPixmap pixel;

       if (id.toInt())
       {
           pixel = ctx->xwindowIcon(id.toInt());

           if (pixel.isNull())
           {
                QProcess process;
                process.start("xfconf-query -c xsettings -p /Net/IconThemeName");
                process.waitForFinished();
                QString theme = process.readLine().replace("\n", "");
                QImage image("/usr/share/icons/" + theme + "/apps/scalable/default-application.svg");
                pixel.convertFromImage(image);
           }
       }

        return pixel;
    }

    Context *ctx;
};

#endif // QQUICKIMAGE_H
