#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Circle : public Figure {
  Q_OBJECT

 public:
  explicit Circle(QPointF point, QObject* parent = 0);
  ~Circle();

 private:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
};

#endif  // SQUARE_H
