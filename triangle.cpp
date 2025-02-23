#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Triangle::~Triangle() {}

void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                     QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());

  QPolygonF polygon;
  polygon << QPointF(rect.center().x(), rect.top())
          << QPointF(rect.left(), rect.bottom())
          << QPointF(rect.right(), rect.bottom());

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
