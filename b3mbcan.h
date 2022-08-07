#ifndef B3MBCAN_H
#define B3MBCAN_H

#include <QObject>
#include "b3mbchannel.h"

class b3mbCan : public QObject
{
  Q_OBJECT
public:
  explicit b3mbCan(QGraphicsScene *scene, qreal wireLen, qreal x, qreal y,
                   QObject *parent = nullptr);
  inline qreal bottom() { return max_y; }
  inline qreal right() { return max_x; }

signals:
private:
  QGraphicsScene *scene;
  qreal wireLen;
  qreal x, y;
  qreal max_x, max_y;
  B3MBChannel *Chan[4];
};

#endif // B3MBCAN_H
