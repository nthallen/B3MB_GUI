#include "b3mbcan.h"
#include <stdlib.h>

b3mbCan::b3mbCan(QGraphicsScene *scene, qreal wireLen, qreal x, qreal y,
                 bool is100V, QObject *parent)
  : scene(scene),
    wireLen(wireLen),
    x(x), y(y),
    is100V(is100V),
    max_x(0), max_y(0),
    QObject{parent}
{
  qreal x1 = x;
  qreal y1 = y;
  Chan[0] = new B3MBChannel(scene, wireLen, x1, y1, true, parent);
  max_x = Chan[0]->right();
  max_y = Chan[0]->bottom();
  for (int i = 1; i < 4; ++i) {
    y1 = Chan[i-1]->bottom() + wireLen;
    Chan[i] = new B3MBChannel(scene, wireLen, x1, y1, !is100V, parent);
    max_x = __max(max_x, Chan[i]->right());
    max_y = __max(max_y, Chan[i]->bottom());
  }
}
