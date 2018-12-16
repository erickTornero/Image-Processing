/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *polFilter;
    QTextEdit *p2Edit;
    QTextEdit *p1Edit;
    QTextEdit *p0Edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelPolFilter;
    QPushButton *pushButton_2;
    QLabel *labelImage;
    QLabel *labelCanny;
    QPushButton *pushButton_3;
    QLabel *labelFourier;
    QPushButton *pushButton_4;
    QLabel *labelH;
    QLabel *labelS;
    QLabel *labelV;
    QPushButton *pushButton_5;
    QLabel *labelBilinear;
    QPushButton *pushButton_6;
    QSlider *horizontalSlider;
    QLabel *labelConv;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1833, 872);
        MainWindow->setWindowOpacity(2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 0, 101, 41));
        QPalette palette;
        QBrush brush(QColor(85, 87, 83, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        pushButton->setPalette(palette);
        pushButton->setAutoFillBackground(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        polFilter = new QPushButton(centralWidget);
        polFilter->setObjectName(QStringLiteral("polFilter"));
        polFilter->setGeometry(QRect(770, 390, 141, 31));
        p2Edit = new QTextEdit(centralWidget);
        p2Edit->setObjectName(QStringLiteral("p2Edit"));
        p2Edit->setGeometry(QRect(650, 390, 41, 31));
        p1Edit = new QTextEdit(centralWidget);
        p1Edit->setObjectName(QStringLiteral("p1Edit"));
        p1Edit->setGeometry(QRect(690, 390, 41, 31));
        p0Edit = new QTextEdit(centralWidget);
        p0Edit->setObjectName(QStringLiteral("p0Edit"));
        p0Edit->setGeometry(QRect(730, 390, 41, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 0, 201, 31));
        QFont font;
        font.setPointSize(25);
        font.setItalic(true);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(640, 0, 251, 31));
        QFont font1;
        font1.setPointSize(23);
        font1.setItalic(true);
        label_2->setFont(font1);
        labelPolFilter = new QLabel(centralWidget);
        labelPolFilter->setObjectName(QStringLiteral("labelPolFilter"));
        labelPolFilter->setGeometry(QRect(560, 50, 451, 341));
        labelPolFilter->setAutoFillBackground(true);
        labelPolFilter->setFrameShape(QFrame::Box);
        labelPolFilter->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 760, 131, 31));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(60, 50, 451, 329));
        labelImage->setFrameShape(QFrame::Box);
        labelImage->setScaledContents(false);
        labelImage->setAlignment(Qt::AlignCenter);
        labelImage->setMargin(0);
        labelCanny = new QLabel(centralWidget);
        labelCanny->setObjectName(QStringLiteral("labelCanny"));
        labelCanny->setGeometry(QRect(560, 460, 431, 291));
        labelCanny->setFrameShape(QFrame::Panel);
        labelCanny->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 760, 121, 31));
        labelFourier = new QLabel(centralWidget);
        labelFourier->setObjectName(QStringLiteral("labelFourier"));
        labelFourier->setGeometry(QRect(1040, 50, 381, 341));
        labelFourier->setFrameShape(QFrame::Box);
        labelFourier->setAlignment(Qt::AlignCenter);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1210, 390, 89, 25));
        labelH = new QLabel(centralWidget);
        labelH->setObjectName(QStringLiteral("labelH"));
        labelH->setGeometry(QRect(1030, 470, 211, 271));
        labelH->setFrameShape(QFrame::Panel);
        labelH->setAlignment(Qt::AlignCenter);
        labelS = new QLabel(centralWidget);
        labelS->setObjectName(QStringLiteral("labelS"));
        labelS->setGeometry(QRect(1250, 470, 201, 271));
        labelS->setFrameShape(QFrame::Panel);
        labelS->setAlignment(Qt::AlignCenter);
        labelV = new QLabel(centralWidget);
        labelV->setObjectName(QStringLiteral("labelV"));
        labelV->setGeometry(QRect(1470, 470, 201, 271));
        labelV->setFrameShape(QFrame::Box);
        labelV->setAlignment(Qt::AlignCenter);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1290, 770, 141, 31));
        labelBilinear = new QLabel(centralWidget);
        labelBilinear->setObjectName(QStringLiteral("labelBilinear"));
        labelBilinear->setGeometry(QRect(1430, 50, 391, 341));
        labelBilinear->setFrameShape(QFrame::Box);
        labelBilinear->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1610, 400, 89, 25));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(150, 740, 251, 20));
        horizontalSlider->setMinimum(-8);
        horizontalSlider->setMaximum(8);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        labelConv = new QLabel(centralWidget);
        labelConv->setObjectName(QStringLiteral("labelConv"));
        labelConv->setGeometry(QRect(60, 440, 451, 291));
        labelConv->setFrameShape(QFrame::WinPanel);
        labelConv->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 400, 331, 31));
        QFont font2;
        font2.setPointSize(17);
        font2.setItalic(true);
        label_3->setFont(font2);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(710, 430, 131, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setItalic(true);
        label_4->setFont(font3);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1130, 6, 241, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1510, 0, 271, 31));
        label_6->setFont(font2);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1280, 430, 121, 31));
        QFont font4;
        font4.setPointSize(16);
        font4.setItalic(true);
        label_7->setFont(font4);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1833, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Load Image", Q_NULLPTR));
        polFilter->setText(QApplication::translate("MainWindow", "Pol Filter", Q_NULLPTR));
        p2Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Raw Image", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Polinomial Filter", Q_NULLPTR));
        labelPolFilter->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Convolution", Q_NULLPTR));
        labelImage->setText(QString());
        labelCanny->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Edge Detector", Q_NULLPTR));
        labelFourier->setText(QString());
        pushButton_4->setText(QApplication::translate("MainWindow", "Fourier", Q_NULLPTR));
        labelH->setText(QString());
        labelS->setText(QString());
        labelV->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindow", "HSV transform", Q_NULLPTR));
        labelBilinear->setText(QString());
        pushButton_6->setText(QApplication::translate("MainWindow", "Bilinear", Q_NULLPTR));
        labelConv->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Convolution: Perfil - Smoothing", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Edge detector", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Fourier Transformation", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Geometric Transformation", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Color Space", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
