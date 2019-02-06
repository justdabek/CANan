/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QPushButton *Clear;
    QSplitter *splitter;
    QPushButton *Connect;
    QPushButton *pushButton;
    QPushButton *send;
    QTableWidget *Trace;
    QTableWidget *MsgDef;
    QLineEdit *Data5;
    QLineEdit *Data2;
    QLineEdit *Data3;
    QLineEdit *Data4;
    QLineEdit *DLC;
    QLineEdit *STDid;
    QLineEdit *Data6;
    QLineEdit *Data0;
    QLineEdit *Data8;
    QLineEdit *Data1;
    QLineEdit *Data7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(737, 602);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 240, 681, 211));
        textEdit->setReadOnly(true);
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(100, 20, 75, 23));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 20, 75, 46));
        splitter->setOrientation(Qt::Vertical);
        Connect = new QPushButton(splitter);
        Connect->setObjectName(QStringLiteral("Connect"));
        splitter->addWidget(Connect);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter->addWidget(pushButton);
        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(540, 20, 75, 23));
        Trace = new QTableWidget(centralWidget);
        Trace->setObjectName(QStringLiteral("Trace"));
        Trace->setGeometry(QRect(20, 470, 681, 71));
        MsgDef = new QTableWidget(centralWidget);
        MsgDef->setObjectName(QStringLiteral("MsgDef"));
        MsgDef->setGeometry(QRect(20, 80, 681, 151));
        Data5 = new QLineEdit(centralWidget);
        Data5->setObjectName(QStringLiteral("Data5"));
        Data5->setGeometry(QRect(382, 20, 20, 20));
        Data5->setMaxLength(2);
        Data2 = new QLineEdit(centralWidget);
        Data2->setObjectName(QStringLiteral("Data2"));
        Data2->setGeometry(QRect(295, 20, 20, 20));
        Data2->setMaxLength(2);
        Data3 = new QLineEdit(centralWidget);
        Data3->setObjectName(QStringLiteral("Data3"));
        Data3->setGeometry(QRect(324, 20, 20, 20));
        Data3->setMaxLength(2);
        Data4 = new QLineEdit(centralWidget);
        Data4->setObjectName(QStringLiteral("Data4"));
        Data4->setGeometry(QRect(353, 20, 20, 20));
        Data4->setMaxLength(2);
        DLC = new QLineEdit(centralWidget);
        DLC->setObjectName(QStringLiteral("DLC"));
        DLC->setGeometry(QRect(179, 20, 20, 20));
        DLC->setMaxLength(1);
        STDid = new QLineEdit(centralWidget);
        STDid->setObjectName(QStringLiteral("STDid"));
        STDid->setGeometry(QRect(208, 20, 20, 20));
        STDid->setMaxLength(3);
        Data6 = new QLineEdit(centralWidget);
        Data6->setObjectName(QStringLiteral("Data6"));
        Data6->setGeometry(QRect(411, 20, 20, 20));
        Data6->setMaxLength(2);
        Data0 = new QLineEdit(centralWidget);
        Data0->setObjectName(QStringLiteral("Data0"));
        Data0->setGeometry(QRect(237, 20, 20, 20));
        Data0->setMaxLength(2);
        Data8 = new QLineEdit(centralWidget);
        Data8->setObjectName(QStringLiteral("Data8"));
        Data8->setGeometry(QRect(470, 19, 20, 21));
        Data8->setMaxLength(2);
        Data1 = new QLineEdit(centralWidget);
        Data1->setObjectName(QStringLiteral("Data1"));
        Data1->setGeometry(QRect(266, 20, 20, 20));
        Data1->setMaxLength(2);
        Data7 = new QLineEdit(centralWidget);
        Data7->setObjectName(QStringLiteral("Data7"));
        Data7->setGeometry(QRect(440, 20, 21, 20));
        Data7->setMaxLength(2);
        MainWindow->setCentralWidget(centralWidget);
        textEdit->raise();
        Clear->raise();
        splitter->raise();
        send->raise();
        Trace->raise();
        DLC->raise();
        MsgDef->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 737, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        send->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        STDid->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
