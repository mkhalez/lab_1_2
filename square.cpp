#include "square.h"
#include <QLineF>
#include <QPainter>

Square::Square(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Square::~Square() {}

void Square::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());
  QPolygonF polygon;

  polygon << QPointF(rect.right(), rect.top())
          << QPointF(rect.left(), rect.top())
          << QPointF(rect.left(), rect.top() + rect.right() - rect.left())
          << QPointF(rect.right(), rect.top() + rect.right() - rect.left());

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

double Square::perimeter() {
  QRectF rect(startPoint(), endPoint());

  // Вычисляем длину стороны квадрата
  double side = qAbs(rect.width());  // Ширина прямоугольника (сторона квадрата)

  // Периметр квадрата: P = 4 * длина стороны
  return 4 * side;
}

qreal Square::area() {
  QRectF rect(startPoint(), endPoint());

  // Вычисляем длину стороны квадрата
  double side = qAbs(rect.width());  // Ширина прямоугольника (сторона квадрата)

  // Периметр квадрата: P = 4 * длина стороны
  return side * side;
}
