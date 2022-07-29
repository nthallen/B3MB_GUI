#ifndef FUSE_H
#define FUSE_H
#include "qgraphicsitem.h"
#include <QGraphicsScene>

class Fuse : public QGraphicsItem
{
public:
  Fuse(QGraphicsScene *scene, qreal x, qreal y, qreal scale);
  QRectF boundingRect();
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
  qreal x, y;
  QRectF bounds;
};

#endif // FUSE_H
