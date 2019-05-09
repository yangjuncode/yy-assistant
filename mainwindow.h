#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <qtermwidget5/qtermwidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_action_Exit_triggered();

  void sl_console_finished();

  void sl_console_output(const QString &text);

  void on_ptn_mirror_clicked();

protected:
  void setupConsole();

private:
  Ui::MainWindow *ui = nullptr;

  QTermWidget *console = nullptr;
};

#endif // MAINWINDOW_H
