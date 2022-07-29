#include "fuse.h"

Fuse::Fuse(QGraphicsScene *scene, qreal x, qreal y, qreal scale)
  : QGraphicsItem(),
    x(x), y(y),
    bounds(0, -scale, 6*scale, 2*scale)
{
}

QRectF Fuse::boundingRect() {
  return bounds;
}

void Fuse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}
