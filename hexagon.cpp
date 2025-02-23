#include "hexagon.h"

#include <QPainter>

Hexagon::Hexagon(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Hexagon::~Hexagon() {}

void Hexagon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());
  QPointF center = rect.center();

  // Радиус шестиугольника (половина минимальной стороны прямоугольника)
  qreal radius = qMin(rect.width(), rect.height()) / 2;

  // Угол между вершинами (360 градусов / 6 вершин = 60 градусов)
  qreal angle = 2 * M_PI / 6;

  QPolygonF polygon;

  // Вычисляем координаты вершин шестиугольника
  for (int i = 0; i < 6; ++i) {
    qreal x = center.x() + radius * cos(i * angle - M_PI / 2);
    qreal y = center.y() + radius * sin(i * angle - M_PI / 2);
    polygon << QPointF(x, y);
  }

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
