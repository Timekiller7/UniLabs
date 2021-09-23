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
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionReverse_Upper_triggered();
    void on_actionReverse_Lower_triggered();
    void on_actionReverse_All_triggered();

    void on_actionConcat_Up_And_Low_triggered();
    void on_actionConcat_Low_And_Up_triggered();

    void on_actionCopy_To_Upper_triggered();

    void erase();
    void both();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
