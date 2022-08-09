#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QApplication>
#include "DataField.h"
#include "fuse.h"
#include "switch.h"
// #include "b3mbchannel.h"
#include "b3mbcan.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  a.setStyleSheet("QLabel { font: bold 14px monospace; padding: 3px; border: 2px solid black; background-color: white }");
  MainWindow w;
  QGraphicsScene scene;
  QGraphicsView view(&scene,&w);
  view.setRenderHints(QPainter::Antialiasing);
  const qreal wireLen = 30;
  const qreal padding = 50;

//  QPushButton *next = new QPushButton("Next");
//  QGraphicsProxyWidget *nextp = scene.addWidget(next);
//  nextp->setPos(QPointF(padding/2,padding/2));

  // B3MBChannel Chan1(&scene, wireLen, padding, padding);
  b3mbCan Can1(&scene, wireLen, padding, padding, true);

  scene.setSceneRect(QRectF(0, 0, Can1.right()+padding, Can1.bottom()+padding));
  view.setMinimumHeight(Can1.bottom()+padding+10);
  view.setMinimumWidth(Can1.right()+padding+10);
  w.show();
  return a.exec();
}
