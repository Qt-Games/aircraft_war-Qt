#include "status.h"

Status::Status(qreal w, qreal h, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    : UnFlyer(parent), m_w(w), m_h(h), m_pixpos(0)
{
    for (int i = 0; i < pixs.size(); i++) {
        QPixmap temp(pixs.at(i)), t;
        t = temp.scaled(m_w, m_h, Qt::KeepAspectRatioByExpanding);
        m_pixs.append(t);
    }
    scene->addItem(this);
}

Status::~Status()
{

}

QRectF Status::boundingRect() const
{
    return m_pixs.at(0).rect();
//    QRect rect(0, 0, 0, 0);
//    return rect;
}

QPainterPath Status::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Status::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

void Status::advance(int)
{
    QPointF pos = scenePos();
    setPos(pos);
}
