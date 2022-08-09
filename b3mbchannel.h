#ifndef B3MBCHANNEL_H
#define B3MBCHANNEL_H

#include <QGraphicsScene>
#include <QObject>
#include "DataField.h"
#include "fuse.h"
#include "switch.h"

class B3MBChannel : public QObject
{
  Q_OBJECT
public:
  explicit B3MBChannel(QGraphicsScene *scene, qreal wireLen, qreal x, qreal y,
                       bool hasBattery, QObject *parent = nullptr);
  inline qreal bottom() { return max_y; }
  inline qreal right() { return max_x; }

signals:

private:
  QGraphicsScene *scene;
  qreal wireLen;
  qreal x, y;
  qreal max_x, max_y;
  bool hasBattery;
  dataField *Batt, *VBatt, *IBatt, *ILoad, *VLoad, *Load;
  Fuse *F11, *F12;
  Switch *S11, *S12;
};

#endif // B3MBCHANNEL_H
