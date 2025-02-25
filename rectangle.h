#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Rectangle : public Figure {
  Q_OBJECT

 public:
  explicit Rectangle(QPointF point, QObject* parent = 0);
  ~Rectangle();

 private:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  double perimeter();
};

#endif
