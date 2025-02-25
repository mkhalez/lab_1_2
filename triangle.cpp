#include "triangle.h"
#include <QLineF>
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

double Triangle::perimer() {
  QRectF rect(startPoint(), endPoint());

  // Вершины треугольника
  QPointF top(rect.center().x(), rect.top());  // Верхняя вершина
  QPointF bottomLeft(rect.left(), rect.bottom());  // Левая нижняя вершина
  QPointF bottomRight(rect.right(), rect.bottom());  // Правая нижняя вершина

  // Вычисляем длины сторон
  double side1 =
      QLineF(top, bottomLeft).length();  // Сторона 1: верхняя -> левая нижняя
  double side2 = QLineF(bottomLeft, bottomRight)
                     .length();  // Сторона 2: левая нижняя -> правая нижняя
  double side3 =
      QLineF(bottomRight, top).length();  // Сторона 3: правая нижняя -> верхняя

  // Периметр треугольника: P = сторона1 + сторона2 + сторона3
  return side1 + side2 + side3;
}
