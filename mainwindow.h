#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ProfileButton_clicked();

    void on_MapButton_clicked();

    void on_LotTableButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
