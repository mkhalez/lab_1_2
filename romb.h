#ifndef ROMB_H
#define ROMB_H

#include <QGraphicsItem>
#include <QObject>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Romb : public Figure {
  Q_OBJECT

 public:
  explicit Romb(QPointF point, QObject* parent = 0);
  ~Romb();

 private:
  // Для Ромба реализуем только саму отрисовку
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  double perimeter();
  double area();
};

#endif  // ROMB_H
