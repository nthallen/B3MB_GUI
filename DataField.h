#ifndef DATAFIELD_H
#define DATAFIELD_H
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class dataField {
public:
  dataField(QGraphicsScene *scene, const char *label, qreal x, qreal y);
  void moveRefToTop();
  void setVisible(bool isVisible);
  inline qreal right() { return boundRec.right(); }
  inline qreal left() { return boundRec.left(); }
  inline qreal top() { return boundRec.top(); }
  inline qreal bottom() { return boundRec.bottom(); }
  inline qreal midY() { return (boundRec.top()+boundRec.bottom())/2; }
  inline qreal mixX() { return (boundRec.left()+boundRec.right())/2; }
protected:
  QGraphicsTextItem *Text;
  QGraphicsRectItem *Rect;
  QRectF boundRec;
};

#endif // DATAFIELD_H
