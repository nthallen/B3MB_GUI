#include "switch.h"

Switch::Switch(QGraphicsScene *scene, qreal x, qreal y, qreal scale)
  : QGraphicsItem(),
  x(x), y(y), scale(scale),
  bounds(0, -1.5*scale, 4*scale, 1.5*scale+2)
{
  setPos(x,y);
  bounds.adjust(x,y,x,y);
  scene->addItem(this);
}

QRectF Switch::boundingRect() const {
  return bounds;
}

void Switch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawLine(0, 0, scale, 0);
  painter->drawLine(3*scale, 0, 4*scale, 0);
  painter->drawLine(scale, 0, (1+1.414)*scale, -1.414*scale);
}
