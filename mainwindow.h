#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QTimer>

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

 private:
  void resizeEvent(QResizeEvent* event);

 private slots:
  void slotTimer();
  void handleRombButtonClick();
  void handleSquareButtonClick();
  void handleTriangleButtonClick();
  void handleRectangleButtonClick();
  void handleCircleButtonClick();
  void handleFive_StarButtonClick();
  void handleSix_StarButtonClick();
  void handleEight_StarButtonClick();
  void handleHexagonButtonClick();
  void clearScene();
};

#endif  // MAINWINDOW_H
