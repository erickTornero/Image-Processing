/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
    QLabel *labelConv;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1658, 872);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(468, 410, 101, 41));
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
        label->setGeometry(QRect(180, 0, 201, 31));
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
        labelPolFilter->setGeometry(QRect(600, 50, 371, 341));
        labelPolFilter->setAutoFillBackground(true);
        labelPolFilter->setFrameShape(QFrame::Box);
        labelPolFilter->setAlignment(Qt::AlignCenter);
        labelConv = new QLabel(centralWidget);
        labelConv->setObjectName(QStringLiteral("labelConv"));
        labelConv->setGeometry(QRect(50, 460, 401, 291));
        labelConv->setFrameShape(QFrame::WinPanel);
        labelConv->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 760, 131, 41));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(60, 50, 429, 329));
        labelImage->setFrameShape(QFrame::Box);
        labelImage->setScaledContents(false);
        labelImage->setAlignment(Qt::AlignCenter);
        labelImage->setMargin(0);
        labelCanny = new QLabel(centralWidget);
        labelCanny->setObjectName(QStringLiteral("labelCanny"));
        labelCanny->setGeometry(QRect(590, 460, 361, 291));
        labelCanny->setFrameShape(QFrame::Panel);
        labelCanny->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(740, 760, 89, 25));
        labelFourier = new QLabel(centralWidget);
        labelFourier->setObjectName(QStringLiteral("labelFourier"));
        labelFourier->setGeometry(QRect(1090, 50, 321, 341));
        labelFourier->setFrameShape(QFrame::Box);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1210, 390, 89, 25));
        labelH = new QLabel(centralWidget);
        labelH->setObjectName(QStringLiteral("labelH"));
        labelH->setGeometry(QRect(1030, 470, 181, 271));
        labelH->setFrameShape(QFrame::Panel);
        labelS = new QLabel(centralWidget);
        labelS->setObjectName(QStringLiteral("labelS"));
        labelS->setGeometry(QRect(1250, 470, 181, 261));
        labelS->setFrameShape(QFrame::Panel);
        labelV = new QLabel(centralWidget);
        labelV->setObjectName(QStringLiteral("labelV"));
        labelV->setGeometry(QRect(1470, 470, 171, 261));
        labelV->setFrameShape(QFrame::Box);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1250, 760, 141, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1658, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Load Image", 0));
        polFilter->setText(QApplication::translate("MainWindow", "Pol Filter", 0));
        p2Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", "Raw Image", 0));
        label_2->setText(QApplication::translate("MainWindow", "Polinomial Filter", 0));
        labelPolFilter->setText(QString());
        labelConv->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Convolution", 0));
        labelImage->setText(QString());
        labelCanny->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Canny", 0));
        labelFourier->setText(QString());
        pushButton_4->setText(QApplication::translate("MainWindow", "Fourier", 0));
        labelH->setText(QString());
        labelS->setText(QString());
        labelV->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindow", "HSV transform", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
