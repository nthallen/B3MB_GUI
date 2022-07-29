#include "DataField.h"

dataField::dataField(QGraphicsScene *scene, const char *label, qreal x, qreal y) {
  Text = scene->addText(label);
  boundRec = Text->boundingRect();
  Text->setPos(QPointF(x,y));
  boundRec.adjust(x,y,x,y);
  scene->addRect(boundRec);
}
