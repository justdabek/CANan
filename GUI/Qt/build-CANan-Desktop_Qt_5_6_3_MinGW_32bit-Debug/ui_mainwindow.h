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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Clear;
    QSplitter *splitter;
    QPushButton *Connect;
    QPushButton *pushButton;
    QTableWidget *Trace;
    QTableWidget *MsgDef;
    QPushButton *SaveToTxt;
    QPushButton *SaveToCsv;
    QCheckBox *checkBox;
    QRadioButton *SingleFrameRadio;
    QRadioButton *RangeRadio;
    QLineEdit *SingleFrameLine;
    QLineEdit *RangeMinLine;
    QLineEdit *RangeMaxLine;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(806, 559);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(20, 530, 75, 23));
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
        Trace = new QTableWidget(centralWidget);
        if (Trace->columnCount() < 5)
            Trace->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Trace->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Trace->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Trace->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Trace->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Trace->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        Trace->setObjectName(QStringLiteral("Trace"));
        Trace->setGeometry(QRect(20, 240, 761, 281));
        Trace->setSelectionBehavior(QAbstractItemView::SelectRows);
        MsgDef = new QTableWidget(centralWidget);
        if (MsgDef->columnCount() < 6)
            MsgDef->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        MsgDef->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        MsgDef->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        MsgDef->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        MsgDef->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        MsgDef->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        MsgDef->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        if (MsgDef->rowCount() < 5)
            MsgDef->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        MsgDef->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        MsgDef->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        MsgDef->setItem(0, 2, __qtablewidgetitem13);
        MsgDef->setObjectName(QStringLiteral("MsgDef"));
        MsgDef->setGeometry(QRect(220, 80, 561, 151));
        MsgDef->setAutoScroll(true);
        MsgDef->setAlternatingRowColors(false);
        MsgDef->setSelectionBehavior(QAbstractItemView::SelectRows);
        MsgDef->setRowCount(5);
        SaveToTxt = new QPushButton(centralWidget);
        SaveToTxt->setObjectName(QStringLiteral("SaveToTxt"));
        SaveToTxt->setGeometry(QRect(100, 20, 90, 25));
        SaveToTxt->setCheckable(true);
        SaveToCsv = new QPushButton(centralWidget);
        SaveToCsv->setObjectName(QStringLiteral("SaveToCsv"));
        SaveToCsv->setGeometry(QRect(100, 50, 90, 25));
        SaveToCsv->setCheckable(true);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 90, 91, 17));
        SingleFrameRadio = new QRadioButton(centralWidget);
        SingleFrameRadio->setObjectName(QStringLiteral("SingleFrameRadio"));
        SingleFrameRadio->setGeometry(QRect(20, 120, 91, 17));
        RangeRadio = new QRadioButton(centralWidget);
        RangeRadio->setObjectName(QStringLiteral("RangeRadio"));
        RangeRadio->setGeometry(QRect(20, 170, 82, 17));
        SingleFrameLine = new QLineEdit(centralWidget);
        SingleFrameLine->setObjectName(QStringLiteral("SingleFrameLine"));
        SingleFrameLine->setGeometry(QRect(55, 140, 41, 20));
        RangeMinLine = new QLineEdit(centralWidget);
        RangeMinLine->setObjectName(QStringLiteral("RangeMinLine"));
        RangeMinLine->setGeometry(QRect(85, 200, 41, 20));
        RangeMaxLine = new QLineEdit(centralWidget);
        RangeMaxLine->setObjectName(QStringLiteral("RangeMaxLine"));
        RangeMaxLine->setGeometry(QRect(165, 200, 41, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(35, 200, 31, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(135, 200, 21, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 140, 20, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 200, 16, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 200, 20, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = Trace->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Timestamp", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = Trace->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = Trace->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Rx/Tx", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = Trace->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "DLC", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = Trace->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = MsgDef->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = MsgDef->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "DLC", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = MsgDef->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = MsgDef->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Cycle Time", Q_NULLPTR));

        const bool __sortingEnabled = MsgDef->isSortingEnabled();
        MsgDef->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = MsgDef->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = MsgDef->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = MsgDef->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "00 00 00 00 00 00 00 00", Q_NULLPTR));
        MsgDef->setSortingEnabled(__sortingEnabled);

        SaveToTxt->setText(QApplication::translate("MainWindow", "Save to .txt", Q_NULLPTR));
        SaveToCsv->setText(QApplication::translate("MainWindow", "Save to .csv", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Enable Filter", Q_NULLPTR));
        SingleFrameRadio->setText(QApplication::translate("MainWindow", "Single Frame", Q_NULLPTR));
        RangeRadio->setText(QApplication::translate("MainWindow", "Range", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "To", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "0x", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "0x", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "0x", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
