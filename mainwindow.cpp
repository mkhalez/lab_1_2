#include "mainwindow.h"
#include "QPushButton"
#include "figure.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new PaintScene();
  //scene->GiveSelectedItem()->perimeter();
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  // Добавляем QLabel в конструктор
  perimeterLabel = new QLabel("Perimeter: 0", this);
  perimeterLabel->setGeometry(300, 10, 150, 30);  // Размещение на окне

  areaLabel = new QLabel("Area: 0", this);
  areaLabel->setGeometry(500, 10, 150, 30);  // Размещение на окне

  centerOfMassLabel = new QLabel("Center of Mass: (0, 0)", this);
  centerOfMassLabel->setGeometry(700, 10, 200, 30);

  xCoordinateInput = new QLineEdit(this);
  xCoordinateInput->setGeometry(900, 10, 50, 30);
  xCoordinateInput->setPlaceholderText("X");

  yCoordinateInput = new QLineEdit(this);
  yCoordinateInput->setGeometry(960, 10, 50, 30);
  yCoordinateInput->setPlaceholderText("Y");

  moveButton = new QPushButton("Move", this);
  moveButton->setGeometry(1020, 10, 80, 30);
  connect(moveButton, &QPushButton::clicked, this,
          &MainWindow::moveFigureToCoordinates);

  // Создаем кнопку для выбора фигуры
  shapeButton = new QToolButton(this);
  shapeButton->setText("Select Shape");
  shapeButton->setGeometry(10, 10, 150, 30);

  // Создаем меню для кнопки
  shapeMenu = new QMenu(this);

  // Добавляем действия в меню для каждой фигуры
  shapeMenu->addAction("None");
  shapeMenu->addAction("Triangle");
  shapeMenu->addAction("Square");
  shapeMenu->addAction("Romb");
  shapeMenu->addAction("Rectangle");
  shapeMenu->addAction("Circle");
  shapeMenu->addAction("Five Star");
  shapeMenu->addAction("Six Star");
  shapeMenu->addAction("Eight Star");
  shapeMenu->addAction("Hexagon");
  shapeMenu->addAction("Parallelogram");

  // Устанавливаем меню для кнопки
  shapeButton->setMenu(shapeMenu);
  shapeButton->setPopupMode(QToolButton::InstantPopup);

  // Подключаем сигнал выбора действия к слоту
  connect(shapeMenu, &QMenu::triggered, this,
          &MainWindow::handleShapeSelection);

  // Кнопка для очистки сцены
  QPushButton* clearButton = new QPushButton("Clear", this);
  clearButton->setGeometry(180, 10, 100, 30);
  connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearScene);

  connect(scene, &PaintScene::centerOfMassChanged, this,
          &MainWindow::updateCenterOfMass);

  timer1 = new QTimer();
  connect(timer1, &QTimer::timeout, this, &MainWindow::updatePerimeter);
  timer1->start(10);

  timer2 = new QTimer();
  connect(timer1, &QTimer::timeout, this, &MainWindow::updateArea);
  timer2->start(10);

  timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
  timer->start(100);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::slotTimer() {
  timer->stop();
  scene->setSceneRect(0, 0, ui->graphicsView->width(),
                      ui->graphicsView->height());
}

void MainWindow::clearScene() {
  scene->clear();
  scene->setSelectedItem(nullptr);  // Сбрасываем указатель на выбранный элемент
  scene->update();
  xCoordinateInput->clear();
  yCoordinateInput->clear();
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  timer->start(100);
  QMainWindow::resizeEvent(event);
}

// Слот для обработки выбора фигуры
void MainWindow::handleShapeSelection(QAction* action) {
  QString shapeName = action->text();
  if (shapeName == "Triangle") {
    scene->setTypeFigure(PaintScene::TriangleType);
  } else if (shapeName == "None") {
    scene->setTypeFigure(PaintScene::None);
  } else if (shapeName == "Square") {
    scene->setTypeFigure(PaintScene::SquareType);
  } else if (shapeName == "Romb") {
    scene->setTypeFigure(PaintScene::RombType);
  } else if (shapeName == "Rectangle") {
    scene->setTypeFigure(PaintScene::RectangleType);
  } else if (shapeName == "Circle") {
    scene->setTypeFigure(PaintScene::CircleType);
  } else if (shapeName == "Five Star") {
    scene->setTypeFigure(PaintScene::Five_StarType);
  } else if (shapeName == "Six Star") {
    scene->setTypeFigure(PaintScene::Six_StarType);
  } else if (shapeName == "Eight Star") {
    scene->setTypeFigure(PaintScene::Eight_StarType);
  } else if (shapeName == "Hexagon") {
    scene->setTypeFigure(PaintScene::HexagonType);
  } else if (shapeName == "Parallelogram") {
    scene->setTypeFigure(PaintScene::ParallelogramType);
  }
}

void MainWindow::updatePerimeter() {
  if (scene->GiveSelectedItem() != nullptr) {
    qDebug() << "Updated perimeter:"
             << static_cast<Figure*>(scene->GiveSelectedItem())->perimeter();
    perimeterLabel->setText(
        QString("Perimeter: %1")
            .arg(static_cast<Figure*>(scene->GiveSelectedItem())->perimeter()));
  };
}

void MainWindow::updateArea() {
  if (scene->GiveSelectedItem() != nullptr) {
    qDebug() << "Updated Area:"
             << static_cast<Figure*>(scene->GiveSelectedItem())->area();
    areaLabel->setText(
        QString("Area: %1")
            .arg(static_cast<Figure*>(scene->GiveSelectedItem())->area()));
  };
}

void MainWindow::updateCenterOfMass() {
  if (scene->GiveSelectedItem() != nullptr) {
    QPointF center = scene->GiveSelectedItem()->boundingRect().center();
    centerOfMassLabel->setText(
        QString("Center of Mass: (%1, %2)").arg(center.x()).arg(center.y()));
  }
}

void MainWindow::moveFigureToCoordinates() {
  if (scene->GiveSelectedItem() != nullptr) {
    bool okX, okY;
    qreal x = xCoordinateInput->text().toDouble(&okX);
    qreal y = yCoordinateInput->text().toDouble(&okY);

    if (okX && okY) {
      QPointF newPos(
          x - scene->GiveSelectedItem()->boundingRect().width() / 2,
          y - scene->GiveSelectedItem()->boundingRect().height() / 2);
      scene->GiveSelectedItem()->setPos(newPos);
      scene->update();
      updateCenterOfMass();
    }
  }
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
  Figure* item = scene->GiveSelectedItem();
  if (item != nullptr) {
    item->setTransformOriginPoint(item->boundingRect().x(),
                                  item->boundingRect().y());
    qDebug() << "Transform Point: " << item->transformOriginPoint();
    item->setRotation(value * 3.6);
  };
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value) {
  Figure* item = scene->GiveSelectedItem();
  if (item != nullptr) {
    item->setTransformOriginPoint(item->boundingRect().x(),
                                  item->boundingRect().y());
    item->setScale(value * 0.02);
  };
}
