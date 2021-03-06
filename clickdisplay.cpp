#include "clickdisplay.h"


using namespace std;

ClickDisplay::ClickDisplay(QWidget* parent): QLabel(parent)
{
    this->setMouseTracking(true);
    QPixmap pixmap;
    this->setPixmap(pixmap);
}

void ClickDisplay::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos_label = mouse_event->pos();
    QPoint mouse_pos;
    if (mouse_pos_label.x() <= this->size().width() && mouse_pos_label.y() <= this->size().height())
    {
        mouse_pos.setX(mouse_pos_label.x() * this->pixmap()->width() / this->size().width());
        mouse_pos.setY(mouse_pos_label.y() * this->pixmap()->height() / this->size().height());

        if (mouse_pos.x() >= 0 && mouse_pos.y() >= 0) {
            emit sendMousePosition(mouse_pos);

        }
    }
}

void ClickDisplay::mousePressEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_click = mouse_event->pos();
    if (mouse_event->button() == Qt::LeftButton)
    {
        int pixmapWidth = this->pixmap()->width();
        int sizeWidth = this->size().width();
        QString message = "pixmap width: " + QString::number(pixmapWidth);
        QString message2 = "size width: " + QString::number(sizeWidth);
        qDebug() << message;
        qDebug() << message2;
        mouse_click.setX(mouse_click.x() * this->pixmap()->width() / this->size().width());
        mouse_click.setY(mouse_click.y() * this->pixmap()->height() / this->size().height());
        emit sendClickPosition(mouse_click);
    }
}
