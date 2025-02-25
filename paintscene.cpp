#include "paintscene.h"
#include <QDebug>
#include "circle.h"
#include "eight_star.h"
#include "five_star.h"
#include "hexagon.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "romb.h"
#include "six_star.h"
#include "square.h"
#include "triangle.h"

PaintScene::PaintScene(QObject* parent) : QGraphicsScene(parent) {
  selectedCastomItem = nullptr;
}

PaintScene::~PaintScene() {}

int PaintScene::typeFigure() const {
  return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type) {
  m_typeFigure = type;
}

Figure* PaintScene::GiveSelectedItem() {
  return selectedCastomItem;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
  /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
  if (tempFigure == nullptr) {
    if (selectedCastomItem != nullptr)
      qDebug() << event->scenePos() << ' '
               << selectedCastomItem->boundingRect();
    QPointF pos = event->scenePos();
    selectedCastomItem->setPos(
        QPointF(pos.x() - selectedCastomItem->boundingRect().x() -
                    (selectedCastomItem->boundingRect().width() - 30) / 2,
                pos.y() - selectedCastomItem->boundingRect().y() -
                    (selectedCastomItem->boundingRect().height() - 30) / 2));
    return;
  }
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
  tempFigure = nullptr;
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
      qDebug() << tempFigure->boundingRect();
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
    case ParallelogramType: {
      Parallelogram* item = new Parallelogram(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;
      break;
    }
    default: {
      /*Square* item = new Square(event->scenePos());
      item->setPos(event->pos());
      tempFigure = item;*/
      break;
    }
  }
  if (tempFigure != nullptr) {
    this->addItem(tempFigure);
    return;
  };
  selectedCastomItem =
      static_cast<Figure*>(this->itemAt(event->scenePos(), QTransform()));
  qDebug() << (selectedCastomItem == nullptr);

  //selectedCastomItem->setPos(event->scenePos());
}
