#include "romb.h"
#include <QPainter>

Romb::Romb(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Romb::~Romb() {}

// Реализуем метод отрисовки
void Romb::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                 QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());  // Создаём прямоугольник
  QPointF center = rect.center();         // Находим его центр

  QPolygonF polygon;
  polygon << QPointF(center.x(), rect.top())    // Верхняя вершина
          << QPointF(rect.right(), center.y())  // Правая вершина
          << QPointF(center.x(), rect.bottom())  // Нижняя вершина
          << QPointF(rect.left(), center.y());   // Левая вершина

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

double Romb::perimeter() {
  QRectF rect(startPoint(), endPoint());
  double width = qAbs(rect.width());
  double height = qAbs(rect.height());

  // Периметр ромба равен 4 * длина стороны
  // Длина стороны ромба вычисляется как половина диагонали
  double side =
      qSqrt((width / 2.0) * (width / 2.0) + (height / 2.0) * (height / 2.0));
  return 4.0 * side;
}

double Romb::area() {
  QRectF rect(startPoint(), endPoint());

  // Длина стороны ромба
  double side = qSqrt((rect.width() / 2.0) * (rect.width() / 2.0) +
                      (rect.height() / 2.0) * (rect.height() / 2.0));

  // Высота ромба (можно вычислить через площадь, но это менее эффективно)
  double height = (rect.height() / 2.0);

  // Площадь ромба
  return side * height;
}
