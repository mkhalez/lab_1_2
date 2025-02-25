#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
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
  QToolButton* shapeButton;  // Кнопка для выбора фигуры
  QMenu* shapeMenu;          // Меню с выбором фигур

 private:
  void resizeEvent(QResizeEvent* event);

 private slots:
  void slotTimer();
  void handleShapeSelection(
      QAction* action);  // Слот для обработки выбора фигуры
  void clearScene();
};

#endif  // MAINWINDOW_H
