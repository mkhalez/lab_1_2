#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QPushButton>
#include <QResizeEvent>
#include <QTimer>
#include <QToolButton>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  PaintScene* scene;
  QTimer* timer;
  QTimer* timer1;
  QTimer* timer2;
  QToolButton* shapeButton;  // Кнопка для выбора фигуры
  QMenu* shapeMenu;          // Меню с выбором фигур
  QLabel* perimeterLabel;
  QLabel* areaLabel;

  QLabel* centerOfMassLabel;
  QLineEdit* xCoordinateInput;
  QLineEdit* yCoordinateInput;
  QPushButton* moveButton;

 private:
  void resizeEvent(QResizeEvent* event);

 private slots:
  void slotTimer();
  void handleShapeSelection(
      QAction* action);  // Слот для обработки выбора фигуры
  void clearScene();
  void updatePerimeter();  // Новый слот
  void updateArea();
  void updateCenterOfMass();
  void moveFigureToCoordinates();
  void on_horizontalSlider_valueChanged(int value);
  void on_horizontalSlider_2_valueChanged(int value);
};

#endif  // MAINWINDOW_H
