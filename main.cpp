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
#include "b3mbchannel.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QGraphicsScene scene;
  QGraphicsView view(&scene,&w);
  view.setRenderHints(QPainter::Antialiasing);
  const qreal wireLen = 30;
  const qreal padding = 150;

//  QPushButton *next = new QPushButton("Next");
//  QGraphicsProxyWidget *nextp = scene.addWidget(next);
//  nextp->setPos(QPointF(padding/2,padding/2));

  B3MBChannel Chan1(&scene, wireLen, padding, padding);

  scene.setSceneRect(QRectF(0, 0, Chan1.right()+padding, Chan1.bottom()+padding));
  view.setMinimumHeight(Chan1.bottom()+padding+10);
  view.setMinimumWidth(Chan1.right()+padding+10);
  w.show();
  return a.exec();
}
