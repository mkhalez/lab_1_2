#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene {
  Q_OBJECT
  // Свойство текущего типа используемой фигуры
  Q_PROPERTY(int typeFigure READ typeFigure WRITE setTypeFigure NOTIFY
                 typeFigureChanged)

 public:
  explicit PaintScene(QObject* parent = 0);
  ~PaintScene();

  Figure* currentFigure() const;

  int typeFigure() const;  // Возвращение текущего типа
  void setTypeFigure(const int type);  // Установка текущего типа
  Figure* GiveSelectedItem();

  // Перечисление типов используемых фигур
  enum FigureTypes {
    SquareType,
    RombType,
    TriangleType,
    RectangleType,
    CircleType,
    Five_StarType,
    Six_StarType,
    Eight_StarType,
    HexagonType,
    ParallelogramType,
    None
  };

 signals:
  void typeFigureChanged();  // Сигнал об изменении типа текущей фигуры
      //void perimeterChanged(double perimeter);
  void centerOfMassChanged(const QPointF& center);

 public:
  void setSelectedItem(Figure* item);

 private:
  /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
  Figure* tempFigure;
  Figure* selectedCastomItem;
  int m_typeFigure;  // текущий тип фигуры

 private:
  // Для рисования используем события мыши
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
};

#endif  // PAINTSCENE_H
