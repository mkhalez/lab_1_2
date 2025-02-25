#ifndef SIX_STAR_H
#define SIX_STAR_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

class Six_Star : public Figure {
  Q_OBJECT

 public:
  explicit Six_Star(QPointF point, QObject* parent = 0);
  ~Six_Star();

 private:
  // Для Ромба реализуем только саму отрисовку
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  double perimer();
};

#endif  // SQUARE_H
