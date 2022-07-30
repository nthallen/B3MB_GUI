#ifndef SWITCH_H
#define SWITCH_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Switch : public QGraphicsItem
{
public:
  Switch(QGraphicsScene *scene, qreal x, qreal y, qreal scale);
  virtual QRectF boundingRect() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  inline qreal right() { return bounds.right(); }
protected:
  qreal x, y, scale;
  QRectF bounds;
};

#endif // SWITCH_H
