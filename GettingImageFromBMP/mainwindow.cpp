#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bmphandle.h"
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

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    ImageFormatHeader head;
    if(QString::compare(filename, QString()) != 0){
        unsigned char * data = readBMP(filename.toStdString(), head);
        //RGB_ ** mat = getImageMatrix(filename.toStdString(), head);
        if(data != nullptr){
            int wdt = head.width;
            int hgh = head.heigh;
            QImage image(head.heigh, head.width, QImage::Format_RGB888);
            for(int x = 0; x < image.height(); x++){
                for(int y = 0; y < image.width(); y++){
                    image.setPixelColor(x, y, QColor(data[x*hgh*3 + y*3 +0],data[x*hgh*3+y*3 +1],data[x*hgh*3+y*3 +2]));
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
