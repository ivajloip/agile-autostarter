#ifndef __main_window_h__

#define __main_window_h__

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();
};

#endif
