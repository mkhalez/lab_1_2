#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Square : public Figure {
  Q_OBJECT

 public:
  explicit Square(QPointF point, QObject* parent = 0);
  ~Square();

 private:
  // Для Ромба реализуем только саму отрисовку
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
};

#endif  // SQUARE_H
