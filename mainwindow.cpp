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

  timer1 = new QTimer();
  connect(timer1, &QTimer::timeout, this, &MainWindow::updatePerimeter);
  timer1->start(10);

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
  //scene->update();
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
             << static_cast<Figure*>(scene->GiveSelectedItem())
                    ->perimeter();  // Отладка
    perimeterLabel->setText(
        QString("Perimeter: %1")
            .arg(static_cast<Figure*>(scene->GiveSelectedItem())->perimeter()));
  };
}
