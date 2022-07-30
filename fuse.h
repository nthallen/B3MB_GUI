#ifndef FUSE_H
#define FUSE_H
#include <QGraphicsItem>
#include <QGraphicsScene>

class Fuse : public QGraphicsItem
{
public:
  Fuse(QGraphicsScene *scene, qreal x, qreal y, qreal scale);
  virtual QRectF boundingRect() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  inline qreal right() { return bounds.right(); }
protected:
  qreal x, y, scale;
  QRectF bounds;
};

#endif // FUSE_H
