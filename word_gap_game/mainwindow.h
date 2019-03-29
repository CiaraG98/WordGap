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

<<<<<<< HEAD
=======
private slots:
    void on_pushButton_clicked();

>>>>>>> 962a4f464dc4e061e20c60242296c72ed0ceb421
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
