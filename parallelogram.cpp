#include "parallelogram.h"

#include <QPainter>

Parallelogram::Parallelogram(QPointF point, QObject* parent)
    : Figure(point, parent) {
  Q_UNUSED(point)
}

Parallelogram::~Parallelogram() {}

void Parallelogram::paint(QPainter* painter,
                          const QStyleOptionGraphicsItem* option,
                          QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());

  qreal offset = rect.width() / 3;

  QPolygonF polygon;
  polygon << QPointF(rect.left() + offset, rect.top())
          << QPointF(rect.right(), rect.top())
          << QPointF(rect.right() - offset, rect.bottom())
          << QPointF(rect.left(), rect.bottom());

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

double Parallelogram::perimeter() {
  QRectF rect(startPoint(), endPoint());

  // Смещение для создания параллелограмма
  double offset = rect.width() / 3.0;

  // Создаем полигон для параллелограмма
  QPolygonF polygon;
  polygon << QPointF(rect.left() + offset, rect.top())
          << QPointF(rect.right(), rect.top())
          << QPointF(rect.right() - offset, rect.bottom())
          << QPointF(rect.left(), rect.bottom());

  // Вычисляем длины сторон
  double side1 = QLineF(polygon[0], polygon[1]).length();  // Верхняя сторона
  double side2 = QLineF(polygon[1], polygon[2]).length();  // Правая сторона
  double side3 = QLineF(polygon[2], polygon[3]).length();  // Нижняя сторона
  double side4 = QLineF(polygon[3], polygon[0]).length();  // Левая сторона

  // Периметр — сумма длин всех сторон
  return side1 + side2 + side3 + side4;
}
