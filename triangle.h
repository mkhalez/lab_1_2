#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Triangle : public Figure {
  Q_OBJECT

 public:
  explicit Triangle(QPointF point, QObject* parent = 0);
  ~Triangle();

 private:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  double perimeter();
  double area();
};

#endif  // TRIANGLE_H
