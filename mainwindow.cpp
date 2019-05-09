#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setupConsole();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_action_Exit_triggered() {
  QApplication::instance()->exit();
}

void MainWindow::sl_console_finished() {
  qDebug() << "sl_console_finished";
  this->on_action_Exit_triggered();
}

void MainWindow::sl_console_output(const QString &text) {}

void MainWindow::setupConsole() {
  if (console != nullptr) {
    console->deleteLater();
    console = nullptr;
  }

  console = new QTermWidget(this);

  QFont font = QApplication::font();
  font.setFamily("Monospace");
  font.setPointSize(12);

  console->setTerminalFont(font);
  console->setScrollBarPosition(QTermWidget::ScrollBarRight);
  console->setColorScheme("WhiteOnBlack");

  ui->tabWidget->addTab(console, "Console");
  connect(console, &QTermWidget::finished, this,
          &MainWindow::sl_console_finished);
}

void MainWindow::on_ptn_mirror_clicked() {
  ui->tabWidget->setCurrentWidget(console);
  console->sendText("sudo pacman-mirrors -i -c China -m rank\n");
}
