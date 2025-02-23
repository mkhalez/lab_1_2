#ifndef HEXAGON_H
#define HEXAGON_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Hexagon : public Figure {
  Q_OBJECT

 public:
  explicit Hexagon(QPointF point, QObject* parent = 0);
  ~Hexagon();

 private:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
};

#endif
