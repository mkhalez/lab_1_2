#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject* parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Square::~Square() {}

// Реализуем метод отрисовки
void Square::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->setPen(QPen(Qt::black, 2));

  // Получаем прямоугольник, ограничивающий квадрат
  QRectF rect(startPoint(), endPoint());

  // Вычисляем сторону квадрата (минимальная из ширины и высоты прямоугольника)
  qreal side = qMin(rect.width(), rect.height());

  // Создаем новый прямоугольник с одинаковыми шириной и высотой (квадрат)
  QRectF squareRect(rect.topLeft(), QSizeF(side, side));

  // Рисуем квадрат
  painter->drawRect(squareRect);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
