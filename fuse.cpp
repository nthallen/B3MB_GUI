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
  // setPos(x,y);
  bounds.adjust(x,y,x,y);
  scene->addItem(this);
}

QRectF Fuse::boundingRect() const {
  return bounds;
}

void Fuse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  qreal oldWidth = painter->pen().widthF();
  QPen const &pen = painter->pen();
  pen.setWidthF(2);
  painter->drawLine(x, y, x+scale, y);
  painter->drawLine(x+5*scale, y, x+6*scale, y);
  painter->drawArc(QRectF(x+scale,y-scale,2*scale,2*scale), 0*16, 180*16);
  painter->drawArc(QRectF(x+3*scale,y-scale,2*scale,2*scale),0*16,-180*16);
  painter->pen().setWidth(oldWidth);
}
