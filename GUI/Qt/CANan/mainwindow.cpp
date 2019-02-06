#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QThread>

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    QStringList titles;
    titles<<"Time stamp"<<"Tx/Rx"<<"ID"<<"DLC"<<"Data";
    ui->Trace->setColumnCount(5);
    ui->Trace->setHorizontalHeaderLabels(titles);

    ui->MsgDef->setRowCount(10);
    ui->MsgDef->setColumnCount(3);

    QStringList titles2;
    titles2<<"ID"<<"DLC"<<"Data";
    ui->MsgDef->setHorizontalHeaderLabels(titles2);
    ui->MsgDef->setShowGrid(true);
    ui->MsgDef->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->MsgDef->setGeometry(QApplication::desktop()->screenGeometry());

}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

void MainWindow::serialReceived(){
    QByteArray line;
    line=serial->readLine();

    //serial->readLine();



    buffer.append(line);
    ui->textEdit->setText(buffer);

}

void MainWindow::on_Connect_clicked()
{
    serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));

}

void MainWindow::on_Clear_released()
{
    buffer.clear();
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_released()
{
    serial->close();
}

void MainWindow::on_send_released()
{
    QRegExp rx ("[0-9a-fA-F]+");
    if (rx.exactMatch(ui->STDid->text()))
    {
        ui->send->setEnabled (true);
    }
    else
    {
        ui->send->setEnabled (false);
    }
    bool ok;
    char cArr[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    cArr[3]=ui->STDid->text().toUInt(&ok,16);
    cArr[7]=ui->DLC->text().toUInt(&ok,16);
    cArr[8]=ui->Data0->text().toUInt(&ok,16);
    cArr[9]=ui->Data1->text().toUInt(&ok,16);
    cArr[10]=ui->Data2->text().toUInt(&ok,16);
    cArr[11]=ui->Data3->text().toUInt(&ok,16);
    cArr[12]=ui->Data4->text().toUInt(&ok,16);
    cArr[13]=ui->Data5->text().toUInt(&ok,16);
    cArr[14]=ui->Data6->text().toUInt(&ok,16);
    cArr[15]=ui->Data7->text().toUInt(&ok,16);




    QByteArray Msg(cArr,16);

    serial->write(Msg);

}

void MainWindow::textChangedLineEdit(QString text)
{
    QRegExp rx ("[0-9a-fA-F]+");
    if (rx.exactMatch(text))
    {
        ui->send->setEnabled (true);
    }
    else
    {
        ui->send->setEnabled (false);
    }
}


