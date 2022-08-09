#ifndef FUSE_H
#define FUSE_H
#include <QGraphicsItem>
#include <QGraphicsScene>

class Fuse : public QGraphicsItem
{
public:
  Fuse(QGraphicsScene *scene, qreal x, qreal y, qreal scale);
  virtual QRectF boundingRect() const override;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  inline qreal right() { return bounds.right(); }
  void setClosed(bool isClosed);
  void toggle();

  enum { Type = UserType + 1 };
  int type() const override
  {
      // Enable the use of qgraphicsitem_cast with this item.
      return Type;
  }
protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  qreal x, y, scale;
  QRectF bounds;
  QPen myPen;
  bool closed;
};

#endif // FUSE_H
