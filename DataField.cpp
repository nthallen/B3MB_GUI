#include "DataField.h"

dataField::dataField(QGraphicsScene *scene, const char *label, qreal x, qreal y) {
  QLabel *Text = new QLabel(label);
  // Text = scene->addText(label);
  boundRec = Text->frameGeometry();
  W = scene->addWidget(Text);
  W->setPos(QPointF(x,y));
  boundRec = W->boundingRect();
  boundRec.adjust(x,y,x,y);
  // Rect = scene->addRect(boundRec);
}

void dataField::moveRefToTop()
{
  qreal dx = (left() - right())/2;
  qreal dy = 0;
  W->moveBy(dx,dy);
  // Rect->moveBy(dx,dy);
  boundRec.adjust(dx,dy,dx,dy);
}

void dataField::setVisible(bool isVisible) {
  W->setVisible(isVisible);
  // Rect->setVisible(isVisible);
}
