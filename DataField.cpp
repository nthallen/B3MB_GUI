#include "DataField.h"

dataField::dataField(QGraphicsScene *scene, const char *label, qreal x, qreal y) {
  Text = scene->addText(label);
  boundRec = Text->boundingRect();
  Text->setPos(QPointF(x,y));
  boundRec.adjust(x,y,x,y);
  Rect = scene->addRect(boundRec);
}

void dataField::moveRefToTop()
{
  qreal dx = (left() - right())/2;
  qreal dy = 0;
  Text->moveBy(dx,dy);
  Rect->moveBy(dx,dy);
  boundRec.adjust(dx,dy,dx,dy);
}
