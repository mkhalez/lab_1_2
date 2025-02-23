#include "paintscene.h"
#include "circle.h"
#include "eight_star.h"
#include "five_star.h"
#include "hexagon.h"
#include "rectangle.h"
#include "romb.h"
#include "six_star.h"
#include "square.h"
#include "triangle.h"

PaintScene::PaintScene(QObject* parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

int PaintScene::typeFigure() const {
  return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type) {
  m_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
  /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
  tempFigure->setEndPoint(event->scenePos());
  /* Обновляем содержимое сцены,
     * необходимо для устранения артефактов при отрисовке фигур
     * */
  this->update(QRectF(0, 0, this->width(), this->height()));
}

/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
 * и помещаем её на сцену, сохранив указатель на неё в переменной
 * tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  switch (m_typeFigure) {
    case SquareType: {
      Square* item = new Square(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case RombType: {
      Romb* item = new Romb(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case TriangleType: {
      Triangle* item = new Triangle(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case RectangleType: {
      Rectangle* item = new Rectangle(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case CircleType: {
      Circle* item = new Circle(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case Five_StarType: {
      Five_Star* item = new Five_Star(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case Six_StarType: {
      Six_Star* item = new Six_Star(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case Eight_StarType: {
      Eight_Star* item = new Eight_Star(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    case HexagonType: {
      Hexagon* item = new Hexagon(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    default: {
      Square* item = new Square(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
  }
  this->addItem(tempFigure);
}
