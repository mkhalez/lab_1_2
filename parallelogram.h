#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Parallelogram : public Figure {
  Q_OBJECT

 public:
  explicit Parallelogram(QPointF point, QObject* parent = 0);
  ~Parallelogram();

 private:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  double perimeter();
};

#endif
