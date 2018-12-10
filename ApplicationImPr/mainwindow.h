#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
extern "C"
unsigned char * DFTimageCuda(unsigned char * data, int width, int height);

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
    void showImageM(unsigned char * data, int w, int h, QLabel * l, int type);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    unsigned char * data = nullptr;
    int width, height;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
