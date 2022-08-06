#include "b3mbchannel.h"

B3MBChannel::B3MBChannel(QGraphicsScene *scene, qreal wireLen, qreal x, qreal y,
                         QObject *parent)
  : scene(scene),
    wireLen(wireLen),
    x(x), y(y),
    max_x(0), max_y(0),
    QObject{parent}
{

  Batt = new dataField(scene, "Batt1", x, y);
  qreal x1, y1, x2, y2;
  x1 = Batt->right();
  y1 = Batt->midY();
  x2 = x1 + wireLen;
  y2 = y1 + Batt->bottom() - Batt->top();
  scene->addLine(x2,y1,x2,y2);

  VBatt = new dataField(scene, "Batt V", x2, y2);
  VBatt->moveRefToTop();
  max_y = VBatt->bottom();

  x2 = x1 + 2*wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  S11 = new Switch(scene,x1,y1,wireLen/3);
  x1 = S11->right();

  x2 = x1 + wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  F11 = new Fuse(scene,x1,y1,wireLen/3);
  x1 = F11->right();

  x2 = x1 + wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  IBatt = new dataField(scene, "Batt A", x1, Batt->top());
  x1 = IBatt->right();
  y1 = IBatt->midY();

  x2 = x1 + 2*wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  S12 = new Switch(scene,x1,y1,wireLen/3);
  x1 = S12->right();

  x2 = x1 + wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  F12 = new Fuse(scene,x1,y1,wireLen/3);
  x1 = F12->right();

  x2 = x1 + wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  ILoad = new dataField(scene, "Load A", x1, Batt->top());
  x1 = ILoad->right();

  x2 = x1 + wireLen;
  y2 = y1 + Batt->bottom() - Batt->top();
  scene->addLine(x2,y1,x2,y2);

  VLoad = new dataField(scene, "Load V", x2, y2);
  VLoad->moveRefToTop();

  x2 = x1 + 2*wireLen;
  scene->addLine(x1,y1,x2,y1);
  x1 = x2;

  Load = new dataField(scene, "Load1", x1, Batt->top());
  max_x = Load->right();

}
