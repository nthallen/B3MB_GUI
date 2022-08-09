#include "fuse.h"
#include "qpainter.h"

// A Fuse is a widget logically representing a fuse in a circuit
// Its graphical representation is the schematic symbol for a fuse.
// If the fuse blows, a different representation will replace it.
// The Fuse will respond to a command to reset it by clicking on it.

Fuse::Fuse(QGraphicsScene *scene, qreal x, qreal y, qreal scale)
  : QGraphicsItem(),
    x(x), y(y), scale(scale),
    bounds(0, -scale, 6*scale, 2*scale),
    myPen(QBrush(Qt::NoBrush), 2.0),
    closed(true)
{
  bounds.adjust(x,y,x,y);
  scene->addItem(this);
}

QRectF Fuse::boundingRect() const {
  return bounds;
}

void Fuse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  // qreal width = 2;
  painter->save();
  myPen.setColor(QColor(0,0,0));
  painter->setPen(myPen);
  painter->drawLine(x, y, x+scale, y);
  painter->drawLine(x+5*scale, y, x+6*scale, y);
  if (closed) {
    myPen.setColor(QColor(0,175,0));
    painter->setPen(myPen);
    painter->drawArc(QRectF(x+scale,y-scale,2*scale,2*scale), 0*16, 180*16);
    painter->drawArc(QRectF(x+3*scale,y-scale,2*scale,2*scale),0*16,-180*16);
  } else {
    myPen.setColor(QColor(255,0,125));
    painter->setPen(myPen);
    painter->drawArc(QRectF(x,y-2*scale,2*scale,2*scale),0*16,-90*16);
    painter->drawArc(QRectF(x+4*scale,y,2*scale,2*scale),90*16,180*16);
  }
  painter->restore();
}

void Fuse::setClosed(bool isClosed) {
  if (closed != isClosed) {
    closed = isClosed;
    update(bounds);
  }
}

void Fuse::toggle() {
  setClosed(!closed);
}

void Fuse::mousePressEvent(QGraphicsSceneMouseEvent *event) {

}

void Fuse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  toggle();
}
