#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QApplication>
#include "DataField.h"
#include "fuse.h"
#include "switch.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QGraphicsScene scene;
  const qreal wireLen = 15;
  const qreal padding = 150;

  dataField Batt(&scene, "Batt1", padding, padding);
  qreal x1, y1, x2, y2;
  x1 = Batt.right();
  y1 = Batt.midY();
  x2 = x1 + wireLen;
  y2 = y1 + Batt.bottom() - Batt.top();
  scene.addLine(x2,y1,x2,y2);

  dataField VBatt(&scene, "Batt V", x2, y2);
  VBatt.moveRefToTop();

  x2 = x1 + 2*wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  Switch S11(&scene,x1,y1,wireLen/3);
  x1 = S11.right();

  x2 = x1 + wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  Fuse F11(&scene,x1,y1,wireLen/3);
  x1 = F11.right();

  x2 = x1 + wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  dataField IBatt(&scene, "Batt A", x1, Batt.top());
  x1 = IBatt.right();
  y1 = IBatt.midY();

  x2 = x1 + 2*wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  Switch S12(&scene,x1,y1,wireLen/3);
  x1 = S12.right();

  x2 = x1 + wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  Fuse F12(&scene,x1,y1,wireLen/3);
  x1 = F12.right();

  x2 = x1 + wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  dataField ILoad(&scene, "Load A", x1, Batt.top());
  x1 = ILoad.right();

  x2 = x1 + wireLen;
  y2 = y1 + Batt.bottom() - Batt.top();
  scene.addLine(x2,y1,x2,y2);

  dataField VLoad(&scene, "Load V", x2, y2);
  VLoad.moveRefToTop();

  x2 = x1 + 2*wireLen;
  scene.addLine(x1,y1,x2,y1);
  x1 = x2;

  dataField Load(&scene, "Load1", x1, Batt.top());

  //scene.setSceneRect(QRectF(0, 0, VBatt.bottom()+padding, Load.right()+padding));

  QGraphicsView view(&scene,&w);
  view.setMinimumHeight(VBatt.bottom()+padding);
  view.setMinimumWidth(Load.right()+padding);
  // view.setMinimumWidth(IBatt.right()+padding);
  w.show();
  return a.exec();
}
