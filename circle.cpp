#include "circle.h"
#include <QPainter>

Circle::Circle(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Circle::~Circle() {}

void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));
  if (endPoint().x() < endPoint().y())
    endPoint().rx() = endPoint().ry();

  painter->drawEllipse(startPoint().x(), startPoint().y(),
                       endPoint().x() - startPoint().x(),
                       endPoint().x() - startPoint().x());

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

double Circle::perimer() {
  // Вычисляем радиус как расстояние между начальной и конечной точками

  // Периметр круга (длина окружности) = 2 * π * радиус
  return 2.0 * M_PI * radius;
}
