#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
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
    void on_pushButton_clicked();

    void on_polFilter_clicked();
    void showImageM(unsigned char * data, int w, int h, QLabel * l);

private:
    unsigned char * data;
    int width, height;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
