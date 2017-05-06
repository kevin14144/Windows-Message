/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *lbShowMessage;
    QPushButton *btnSetWindowTitle;
    QPushButton *btnSendMessage;
    QLineEdit *leWindowTitle;
    QLineEdit *leSendText;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leTargeWindowTitle;
    QSpinBox *sbMessageType;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lbShowMessage = new QLabel(centralWidget);
        lbShowMessage->setObjectName(QStringLiteral("lbShowMessage"));
        lbShowMessage->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lbShowMessage, 4, 2, 1, 1);

        btnSetWindowTitle = new QPushButton(centralWidget);
        btnSetWindowTitle->setObjectName(QStringLiteral("btnSetWindowTitle"));

        gridLayout->addWidget(btnSetWindowTitle, 1, 0, 1, 1);

        btnSendMessage = new QPushButton(centralWidget);
        btnSendMessage->setObjectName(QStringLiteral("btnSendMessage"));

        gridLayout->addWidget(btnSendMessage, 2, 0, 1, 1);

        leWindowTitle = new QLineEdit(centralWidget);
        leWindowTitle->setObjectName(QStringLiteral("leWindowTitle"));

        gridLayout->addWidget(leWindowTitle, 1, 2, 1, 1);

        leSendText = new QLineEdit(centralWidget);
        leSendText->setObjectName(QStringLiteral("leSendText"));

        gridLayout->addWidget(leSendText, 2, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        leTargeWindowTitle = new QLineEdit(centralWidget);
        leTargeWindowTitle->setObjectName(QStringLiteral("leTargeWindowTitle"));
        leTargeWindowTitle->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));

        gridLayout->addWidget(leTargeWindowTitle, 0, 2, 1, 1);

        sbMessageType = new QSpinBox(centralWidget);
        sbMessageType->setObjectName(QStringLiteral("sbMessageType"));

        gridLayout->addWidget(sbMessageType, 3, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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
        lbShowMessage->setText(QString());
        btnSetWindowTitle->setText(QApplication::translate("MainWindow", "SetWindowTitle", 0));
        btnSendMessage->setText(QApplication::translate("MainWindow", "SendMessage", 0));
        label->setText(QApplication::translate("MainWindow", "Show message", 0));
        label_2->setText(QApplication::translate("MainWindow", "Target Window", 0));
        leTargeWindowTitle->setText(QApplication::translate("MainWindow", "MainWindow", 0));
        label_3->setText(QApplication::translate("MainWindow", "Message Type", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
