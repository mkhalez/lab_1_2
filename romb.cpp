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
