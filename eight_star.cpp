#include "eight_star.h"
#include <QPainter>

Eight_Star::Eight_Star(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Eight_Star::~Eight_Star() {}

void Eight_Star::paint(QPainter* painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(startPoint(), endPoint());

  // Центр прямоугольника
  QPointF center = rect.center();

  // Радиус звезды
  qreal radius = qMin(rect.width(), rect.height()) / 2;

  // Угол между лучами звезды
  qreal angle = M_PI / 4;

  // Создаем полигон для звезды
  QPolygonF polygon;

  for (int i = 0; i < 8; ++i) {
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

double Eight_Star::perimeter() {
  QRectF rect(startPoint(), endPoint());

  // Центр прямоугольника
  QPointF center = rect.center();

  // Радиус звезды
  double radius = qMin(rect.width(), rect.height()) / 2.0;

  // Угол между лучами звезды
  double angle = M_PI / 4.0;

  // Создаем полигон для звезды
  QPolygonF polygon;

  for (int i = 0; i < 8; ++i) {
    // Внешняя точка
    QPointF outerPoint(center.x() + radius * cos(i * angle - M_PI / 2.0),
                       center.y() + radius * sin(i * angle - M_PI / 2.0));
    polygon << outerPoint;

    // Внутренняя точка
    QPointF innerPoint(
        center.x() + (radius / 2.0) * cos((i + 0.5) * angle - M_PI / 2.0),
        center.y() + (radius / 2.0) * sin((i + 0.5) * angle - M_PI / 2.0));
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

double Eight_Star::area() {
  QRectF rect(startPoint(), endPoint());

  // Центр прямоугольника
  QPointF center = rect.center();

  // Радиус звезды
  double radius = qMin(rect.width(), rect.height()) / 2.0;

  // Угол между лучами звезды
  double angle = M_PI / 4.0;

  // Создаем полигон для звезды
  QPolygonF polygon;

  for (int i = 0; i < 8; ++i) {
    // Внешняя точка
    QPointF outerPoint(center.x() + radius * cos(i * angle - M_PI / 2.0),
                       center.y() + radius * sin(i * angle - M_PI / 2.0));
    polygon << outerPoint;

    // Внутренняя точка
    QPointF innerPoint(
        center.x() + (radius / 2.0) * cos((i + 0.5) * angle - M_PI / 2.0),
        center.y() + (radius / 2.0) * sin((i + 0.5) * angle - M_PI / 2.0));
    polygon << innerPoint;
  }

  // Вычисляем площадь многоугольника по формуле Гаусса
  double area = 0.0;
  for (int i = 0; i < polygon.size(); ++i) {
    int nextIndex = (i + 1) % polygon.size();  // Следующая точка
    area += (polygon[i].x() * polygon[nextIndex].y() -
             polygon[nextIndex].x() * polygon[i].y());
  }

  // Возвращаем абсолютное значение площади, деленное на 2
  return qAbs(area) / 2.0;
}
