#ifndef EIGHT_STAR_H
#define EIGHT_STAR_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Eight_Star : public Figure {
  Q_OBJECT

 public:
  explicit Eight_Star(QPointF point, QObject* parent = 0);
  ~Eight_Star();

 private:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  double perimeter();
  double area();
};

#endif  // SQUARE_H
