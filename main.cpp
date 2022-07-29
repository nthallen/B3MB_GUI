#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QApplication>
#include "DataField.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QGraphicsScene scene;
  const qreal wireLen = 15;
  const qreal padding = 15;
  dataField VBatt(&scene, "Batt V", padding, padding);
//dataField *VBatt = new dataField(&scene, "Batt V", 0, 0);
  qreal x1, y1, x2;
  x1 = VBatt.right();
  y1 = VBatt.midY();
  x2 = x1 + wireLen;
  scene.addLine(x1,y1,x2,y1);
  dataField IBatt(&scene, "Batt A", x2, VBatt.top());
  x1 = IBatt.right();
  y1 = IBatt.midY();
  x2 = x1 + 8*wireLen;
  scene.addLine(x1,y1,x2,y1);
  dataField ILoad(&scene, "Load A", x2, VBatt.top());
  x1 = ILoad.right();
  x2 = x1 + wireLen;
  scene.addLine(x1,y1,x2,y1);
  dataField VLoad(&scene, "Load V", x2, VBatt.top());

  QGraphicsView view(&scene,&w);
  view.setMinimumHeight(VBatt.bottom()+padding);
  view.setMinimumWidth(VLoad.right()+padding);
  w.show();
  return a.exec();
}
