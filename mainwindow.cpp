#include "mainwindow.h"
#include "QPushButton"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new PaintScene();
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  QPushButton* clearButton = new QPushButton("clear", this);
  clearButton->setGeometry(60, 10, 100, 30);
  connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearScene);

  QPushButton* triangleButton = new QPushButton("triangle", this);
  triangleButton->setGeometry(10, 10, 100, 30);
  connect(triangleButton, &QPushButton::clicked, this,
          &MainWindow::handleTriangleButtonClick);

  QPushButton* squareButton = new QPushButton("square", this);
  squareButton->setGeometry(160, 10, 100, 30);
  connect(squareButton, &QPushButton::clicked, this,
          &MainWindow::handleSquareButtonClick);

  QPushButton* rombButton = new QPushButton("romb", this);
  rombButton->setGeometry(320, 10, 100, 30);
  connect(rombButton, &QPushButton::clicked, this,
          &MainWindow::handleRombButtonClick);

  QPushButton* rectButton = new QPushButton("rectangle", this);
  rectButton->setGeometry(500, 10, 150, 30);
  connect(rectButton, &QPushButton::clicked, this,
          &MainWindow::handleRectangleButtonClick);

  QPushButton* circleButton = new QPushButton("circle", this);
  circleButton->setGeometry(650, 10, 100, 30);
  connect(circleButton, &QPushButton::clicked, this,
          &MainWindow::handleCircleButtonClick);

  QPushButton* five_startButton = new QPushButton("five_start", this);
  five_startButton->setGeometry(650, 90, 100, 30);
  connect(five_startButton, &QPushButton::clicked, this,
          &MainWindow::handleFive_StarButtonClick);

  QPushButton* six_starButton = new QPushButton("six_star", this);
  six_starButton->setGeometry(500, 90, 100, 30);
  connect(six_starButton, &QPushButton::clicked, this,
          &MainWindow::handleSix_StarButtonClick);

  QPushButton* eight_starButton = new QPushButton("eight_star", this);
  eight_starButton->setGeometry(700, 90, 100, 30);
  connect(eight_starButton, &QPushButton::clicked, this,
          &MainWindow::handleEight_StarButtonClick);

  QPushButton* hexagonButton = new QPushButton("hexagon", this);
  eight_starButton->setGeometry(180, 150, 100, 30);
  connect(hexagonButton, &QPushButton::clicked, this,
          &MainWindow::handleHexagonButtonClick);

  timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
  timer->start(100);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::slotTimer() {
  timer->stop();
  scene->setSceneRect(0, 0, ui->graphicsView->width() - 20,
                      ui->graphicsView->height() - 20);
}

void MainWindow::clearScene() {
  scene->clear();
  scene->update();
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  timer->start(100);
  QMainWindow::resizeEvent(event);
}

void MainWindow::handleRombButtonClick() {
  scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::handleSquareButtonClick() {
  scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::handleTriangleButtonClick() {
  scene->setTypeFigure(PaintScene::TriangleType);
}

void MainWindow::handleRectangleButtonClick() {
  scene->setTypeFigure(PaintScene::RectangleType);
}

void MainWindow::handleCircleButtonClick() {
  scene->setTypeFigure(PaintScene::CircleType);
}

void MainWindow::handleFive_StarButtonClick() {
  scene->setTypeFigure(PaintScene::Five_StarType);
}

void MainWindow::handleSix_StarButtonClick() {
  scene->setTypeFigure(PaintScene::Six_StarType);
}

void MainWindow::handleEight_StarButtonClick() {
  scene->setTypeFigure(PaintScene::Eight_StarType);
}

void MainWindow::handleHexagonButtonClick() {
  scene->setTypeFigure(PaintScene::HexagonType);
}
