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

    void on_actionReverse_Top_Box_triggered();
    void on_actionReverse_Bottom_Box_triggered();
    void on_actionReverse_All_triggered();

    void on_actionConcat_Top_With_Bottom_triggered();
    void on_actionConcat_Bottom_With_Top_triggered();

    void on_actionCopy_To_Upper_triggered();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
