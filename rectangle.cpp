#include "rectangle.h"

#include <QPainter>

Rectangle::Rectangle(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Rectangle::~Rectangle() {}

void Rectangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                      QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());

  QPolygonF polygon;
  polygon << QPointF(rect.right(), rect.top())
          << QPointF(rect.left(), rect.top())
          << QPointF(rect.left(), rect.bottom())
          << QPointF(rect.right(), rect.bottom());

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

double Rectangle::perimeter() {
  QRectF rect(startPoint(), endPoint());
  double width = qAbs(rect.width());
  double height = qAbs(rect.height());
  return 2.0 * (width + height);
}

double Rectangle::area() {
  QRectF rect(startPoint(), endPoint());
  double width = qAbs(rect.width());
  double height = qAbs(rect.height());
  return width * height;
}
