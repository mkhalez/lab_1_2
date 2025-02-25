#include "six_star.h"

#include <QPainter>

Six_Star::Six_Star(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Six_Star::~Six_Star() {}

void Six_Star::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                     QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());

  // Центр прямоугольника
  QPointF center = rect.center();

  // Радиус звезды
  qreal radius = qMin(rect.width(), rect.height()) / 2;

  // Угол между лучами звезды
  qreal angle = 2 * M_PI / 6;

  // Создаем полигон для звезды
  QPolygonF polygon;

  for (int i = 0; i < 6; ++i) {
    // Внешняя точка
    QPointF outerPoint(center.x() + radius * cos(i * angle - M_PI / 2),
                       center.y() + radius * sin(i * angle - M_PI / 2));
    polygon << outerPoint;

    // Внутренняя точка
    QPointF innerPoint(
        center.x() + (radius / 2) * cos((i + 0.5) * angle - M_PI / 2),
        center.y() + (radius / 2) * sin((i + 0.5) * angle - M_PI / 2));
    polygon << innerPoint;
  }

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

double Six_Star::perimeter() {
  QRectF rect(startPoint(), endPoint());

  // Центр прямоугольника
  QPointF center = rect.center();

  // Радиус звезды
  double radius = qMin(rect.width(), rect.height()) / 2;

  // Угол между лучами звезды
  double angle = 2 * M_PI / 6;

  // Создаем полигон для звезды
  QPolygonF polygon;

  for (int i = 0; i < 6; ++i) {
    // Внешняя точка
    QPointF outerPoint(center.x() + radius * cos(i * angle - M_PI / 2),
                       center.y() + radius * sin(i * angle - M_PI / 2));
    polygon << outerPoint;

    // Внутренняя точка
    QPointF innerPoint(
        center.x() + (radius / 2) * cos((i + 0.5) * angle - M_PI / 2),
        center.y() + (radius / 2) * sin((i + 0.5) * angle - M_PI / 2));
    polygon << innerPoint;
  }

  // Вычисляем периметр как сумму длин всех сторон
  double perimeter = 0.0;
  for (int i = 0; i < polygon.size(); ++i) {
    int nextIndex =
        (i + 1) % polygon.size();  // Следующая точка (с замыканием на первую)
    perimeter += QLineF(polygon[i], polygon[nextIndex]).length();
  }

  return perimeter;
}

double Six_Star::area() {
  QRectF rect(startPoint(), endPoint());

  // Центр прямоугольника
  QPointF center = rect.center();

  // Радиус звезды (расстояние от центра до внешней вершины)
  double radius = qMin(rect.width(), rect.height()) / 2;

  // Площадь шестиконечной звезды
  double area = 3 * (sqrt(3) / 2) * radius * radius;

  return area;
}
