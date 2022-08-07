#include "switch.h"

Switch::Switch(QGraphicsScene *scene, qreal x, qreal y, qreal scale)
  : QGraphicsItem(),
  x(x), y(y), scale(scale),
  Sbounds(0, -1.5*scale, 4*scale, 1.5*scale+2),
  myPen(QBrush(Qt::NoBrush), 2.1)
{
  // setPos(x,y);
  Sbounds.adjust(x,y,x,y);
  scene->addItem(this);
}

QRectF Switch::boundingRect() const {
  return Sbounds;
}

void Switch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->save();
  myPen.setColor(QColor(0,0,0));
  painter->setPen(myPen);
  painter->drawLine(x, y, x+scale, y);
  painter->drawLine(x+3*scale, y, x+4*scale, y);
  myPen.setColor(QColor(255,0,125));
  painter->setPen(myPen);
  painter->drawLine(x+scale, y, x+(1+1.414)*scale, y-1.414*scale);
  painter->restore();
}
