#ifndef SWITCH_H
#define SWITCH_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Switch : public QGraphicsItem
{
public:
  Switch(QGraphicsScene *scene, qreal x, qreal y, qreal scale);
  virtual QRectF boundingRect() const override;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  inline qreal right() { return Sbounds.right(); }
  enum { Type = UserType + 2 };

  int type() const override
  {
      // Enable the use of qgraphicsitem_cast with this item.
      return Type;
  }
protected:
  qreal x, y, scale;
  QRectF Sbounds;
};

#endif // SWITCH_H
