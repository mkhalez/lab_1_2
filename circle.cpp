#include "circle.h"
#include <QPainter>

Circle::Circle(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Circle::~Circle() {}

void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  qreal radius = QLineF(startPoint(), endPoint()).length();

  painter->drawEllipse(startPoint(), radius, radius);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
