#include "switch.h"

Switch::Switch(QGraphicsScene *scene, qreal x, qreal y, qreal scale)
  : QGraphicsItem(),
  x(x), y(y), scale(scale),
  Sbounds(0, -1.5*scale, 4*scale, 1.5*scale+2),
  myPen(QBrush(Qt::NoBrush), 2.1),
  closed(false)
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
  if (closed) {
      myPen.setColor(QColor(0,175,0));
      painter->setPen(myPen);
    painter->drawLine(x+scale, y, x+3*scale, y);
  } else {
    myPen.setColor(QColor(255,0,125));
    painter->setPen(myPen);
    painter->drawLine(x+scale, y, x+(1+1.414)*scale, y-1.414*scale);
  }
  painter->restore();
}

void Switch::setClosed(bool isClosed) {
  if (closed != isClosed) {
    closed = isClosed;
    update(Sbounds);
  }
}

void Switch::toggle() {
  setClosed(!closed);
}

void Switch::mousePressEvent(QGraphicsSceneMouseEvent *event) {

}

void Switch::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  toggle();
}
