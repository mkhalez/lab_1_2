#ifndef FIVE_STAR_H
#define FIVE_STAR_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Five_Star : public Figure {
  Q_OBJECT

 public:
  explicit Five_Star(QPointF point, QObject* parent = 0);
  ~Five_Star();

 private:
  // Для Ромба реализуем только саму отрисовку
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  double perimeter();
};

#endif  // SQUARE_H
