#ifndef DATAFIELD_H
#define DATAFIELD_H
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QLabel>

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
  inline qreal midX() { return (boundRec.left()+boundRec.right())/2; }
  inline void moveBy(qreal dx, qreal dy) { W->moveBy(dx, dy); }
protected:
  QLabel *Text;
  // QGraphicsTextItem *Text;
  // QGraphicsRectItem *Rect;
  QGraphicsProxyWidget *W;
  QRectF boundRec;
};

#endif // DATAFIELD_H
