#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bmphandle.h"
#include "Filters.hpp"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showImageM(unsigned char * d, int w, int h, QLabel * lbl){
    if(d != nullptr){
        int wdt = w;
        int hgh = h;

        QImage image(w, h, QImage::Format_RGB888);
        for(int x = 0; x < image.width(); x++){
            for(int y = 0; y < image.height(); y++){
                //image.setPixelColor(x, y, QColor(0, 255, 0));
                image.setPixelColor(x, y, QColor(d[y*wdt*3 + x*3 +0],d[y*wdt*3+x*3 +1],d[y*wdt*3+x*3 +2]));
                //image.setPixelColor(x,y,QColor(mat[y][x].red, mat[y][x].green, mat[y][x].blue));
            }
        }
        QPixmap pix = QPixmap::fromImage(image);
        lbl->setPixmap(pix);
    }
}
void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    ImageFormatHeader head;
    if(QString::compare(filename, QString()) != 0){
        //int  height, width, size;
        int size;
        data = ReadBMP(filename.toStdString(), height, width, size);

        head.set(height, width, size);
        //unsigned char * data = readBMP(filename.toStdString(), head);
        //RGB_ ** mat = getImageMatrix(filename.toStdString(), head);
        if(data != nullptr){
            int wdt = head.width;
            int hgh = head.heigh;

            QImage image(head.width, head.heigh, QImage::Format_RGB888);
            for(int x = 0; x < image.width(); x++){
                for(int y = 0; y < image.height(); y++){
                    //image.setPixelColor(x, y, QColor(0, 255, 0));
                    image.setPixelColor(x, y, QColor(data[y*wdt*3 + x*3 +0],data[y*wdt*3+x*3 +1],data[y*wdt*3+x*3 +2]));
                    //image.setPixelColor(x,y,QColor(mat[y][x].red, mat[y][x].green, mat[y][x].blue));
                }
            }
            //bool valid = image.load(filename);
            QPixmap pix = QPixmap::fromImage(image);
            //bool valid = pix->loadFromData(QByteArray::fromRawData((const char*)data, sizeImage));
            //bool valid = image.loadFromData(data, sizeImage);
            //if(valid){
                ui->labelImage->setPixmap(pix);
                //ui->
            //}
            //else{
            //    std::cout<<"Error loading image"<<std::endl;
            //}
            //delete data;
        }
    }

    //unsigned char * data = readBMP("../Other files/cat50x50.bmp",sizeImage);
    //delete data;
}

void MainWindow::on_polFilter_clicked()
{
    std::vector<double> coef;
    bool ok;
    double a = ui->p2Edit->toPlainText().toDouble(&ok);
    if(ok)
        coef.push_back(a);
    else
        coef.push_back(0);
    a = ui->p1Edit->toPlainText().toDouble(&ok);
    if(ok)
        coef.push_back(a);
    else
        coef.push_back(1);
    a = ui->p0Edit->toPlainText().toDouble(&ok);
    if(ok)
        coef.push_back(a);
    else
        coef.push_back(0);

    unsigned char * filtered = PolinomialTransform(coef, data, width, height);
    showImageM(filtered, width, height, ui->labelPolFilter);
    delete filtered;
}
