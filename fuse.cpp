#include "fuse.h"
#include "qpainter.h"

// A Fuse is a widget logically representing a fuse in a circuit
// Its graphical representation is the schematic symbol for a fuse.
// If the fuse blows, a different representation will replace it.
// The Fuse will respond to a command to reset it by clicking on it.

Fuse::Fuse(QGraphicsScene *scene, qreal x, qreal y, qreal scale)
  : QGraphicsItem(),
    x(x), y(y), scale(scale),
    bounds(0, -scale, 6*scale, 2*scale)
{
  // update();
  setPos(x,y);
  bounds.adjust(x,y,x,y);
  scene->addItem(this);
}

QRectF Fuse::boundingRect() const {
  return bounds;
}

void Fuse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  painter->drawLine(0, 0, scale, 0);
  painter->drawLine(5*scale, 0, 6*scale, 0);
  painter->drawArc(QRectF(scale,-scale,2*scale,2*scale), 0*16, 180*16);
  painter->drawArc(QRectF(3*scale,-scale,2*scale,2*scale),0*16,-180*16);
}
